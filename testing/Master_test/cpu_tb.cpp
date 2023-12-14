#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vmaster.h" 
#include <iostream>

#include "../vbuddy.cpp"     
#define MAX_SIM_CYC 1500000

int main(int argc, char **argv, char **env) {
    int simcyc;
    int tick;

    Verilated::commandArgs(argc, argv);
    // init top verilog instance
    Vmaster* top = new Vmaster;
    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("CPU.vcd");

    //init Vbuddy
    if (vbdOpen()!=1) return(-1);
    vbdHeader("CPU CW");

    // intialise
    top->clk = 1;
    top->rst = 0;
    top->trigger = 0;
    top->testRegAddress = 21;

    // run simulation for MAX_SIM_CYC clock cycles
    for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
        // dump variables into VCD file and toggle clock
        for (tick=0; tick<2; tick++) {
            tfp->dump (2*simcyc+tick);
            top->clk = !top->clk;
            top->eval ();
        }

        // Use Vbuddy hex display
        // send a0 value to 7 seg display
        //vbdHex(4, ((top->Result) >> 16) & 0xF);
        //vbdHex(3, ((top->Result) >> 8) & 0xF);
        //vbdHex(2, ((top->Result) >> 4) & 0xF);
        //vbdHex(1, top->Result & 0xF);

        // Use Vbuddy bar
        vbdBar(top->Result & 0xFF);
        vbdCycle(simcyc);

        // Test pdf plots
        //if(simcyc > 1200000){vbdPlot(top->testRegData,0,255); vbdCycle(simcyc);}
    
        // either simulation finished, or 'q' is pressed
        if (Verilated::gotFinish() || vbdGetkey()=='q')
            exit(0);
    }

    vbdClose();
    tfp->close();   
    exit(0);

}
