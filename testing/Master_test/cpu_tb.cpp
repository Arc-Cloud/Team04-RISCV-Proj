#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vmaster.h" 
#include <iostream>

#include "../vbuddy.cpp"     
#define MAX_SIM_CYC 1500000

int main(int argc, char **argv, char **env) {
    int simcyc;
    int tick;

    char prog = argv[argc-1][0];

    Verilated::commandArgs(argc, argv);
    // init top verilog instance
    Vmaster* top = new Vmaster;
    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("CPU.vcd");

    //init Vbuddy
    if (vbdOpen()!=1) {
        std::cout << "vbuddy.cfg located in /testing/Master_test/" << std::endl;
        return(-1);
    }
    vbdHeader("CPU CW");

    // intialise
    top->clk = 1;
    top->rst = 0;
    top->trigger = 0;

    if (prog == 'a') {
        // We run the PDF program
        top->testRegAddress = 10;
        std::cout << "Running PDF program" << std::endl;
    }
    else {
        top->testRegAddress = 21;
        std::cout << "Running other program" << std::endl;
    }
    
    // run simulation for MAX_SIM_CYC clock cycles
    for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
        // dump variables into VCD file and toggle clock
        for (tick=0; tick<2; tick++) {
            tfp->dump (2*simcyc+tick);
            top->clk = !top->clk;
            top->eval ();
        }

        // Test data
        if(simcyc > 1200000){
            vbdPlot(top->Result,0,255);
            vbdBar(top->Result & 0xFF);
            vbdCycle(simcyc);
        }

        // either simulation finished, or 'q' is pressed
        if (Verilated::gotFinish() || vbdGetkey()=='q')
            exit(0);
    }
    vbdClose();
    tfp->close();   
    exit(0);
}
