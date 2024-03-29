#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vpipelined_cpu.h" 
#include <iostream>

#include "../vbuddy.cpp"     
#define MAX_SIM_CYC 1500000

int main(int argc, char **argv, char **env) {
    int simcyc;
    int tick;

    Verilated::commandArgs(argc, argv);
    // init top verilog instance
    Vpipelined_cpu* top = new Vpipelined_cpu;
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
    top->testRegAddress = 10;
    
    // run simulation for MAX_SIM_CYC clock cycles
    for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
        // dump variables into VCD file and toggle clock
        for (tick=0; tick<2; tick++) {
            tfp->dump (2*simcyc+tick);
            top->clk = !top->clk;
            top->eval ();
        }

        // send a0 value to 7 seg display
        //vbdHex(4, ((top->testRegData) >> 16) & 0xF);
        //vbdHex(3, ((top->testRegData) >> 8) & 0xF);
        //vbdHex(2, ((top->testRegData) >> 4) & 0xF);
        //vbdHex(1, top->testRegData & 0xF);

        //vbdBar(top->testRegData & 0xFF);

        //vbdCycle(simcyc);

        if(simcyc > 1200000){vbdPlot(top->testRegData, 0, 255); vbdCycle(simcyc); }
    
        // either simulation finished, or 'q' is pressed
        if (Verilated::gotFinish() || vbdGetkey()=='q')
            exit(0);
    }

    vbdClose();
    tfp->close();   
    exit(0);
}
