#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vpipelined_cpu.h" 
#include <iostream>

#include "../vbuddy.cpp"     
#define MAX_SIM_CYC 1000000

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
    
    // run simulation for MAX_SIM_CYC clock cycles
    for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
        // dump variables into VCD file and toggle clock
        for (tick=0; tick<2; tick++) {
            tfp->dump (2*simcyc+tick);
            top->clk = !top->clk;
            top->eval ();
        }

        // send a0 value to 7 seg display
        vbdHex(4, ((top->ResultW) >> 16) & 0xF);
        vbdHex(3, ((top->ResultW) >> 8) & 0xF);
        vbdHex(2, ((top->ResultW) >> 4) & 0xF);
        vbdHex(1, top->ResultW & 0xF);

        vbdBar(top->ResultW & 0xFF);

        vbdCycle(simcyc);
    
        // either simulation finished, or 'q' is pressed
        if (Verilated::gotFinish() || vbdGetkey()=='q')
            exit(0);
    }

    vbdClose();
    tfp->close();   
    exit(0);

}
