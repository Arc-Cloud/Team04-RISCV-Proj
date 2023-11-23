#include "verilated.h"
#include "verilated_vcd_c.h"
#include "VP_C.h"

#include <chrono>
#include <thread>
#include "../vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 1000000
#define ADDRESS_WIDTH 9
#define RAM_SZ pow(2,ADDRESS_WIDTH)

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  VP_C* top = new VP_C;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("VP_C.vcd");
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("L4 Test");
  //vbdSetMode(1);        // Flag mode set to one-shot

  // initialize simulation input 
  top->clk = 1;
  top->rst = 0;
  top->PCsrc = 0;
  top->ImmEXT = 0xA;


  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }

    vbdHex(4, (int(top->PC) >> 16) & 0xF);
    vbdHex(3, (int(top->PC) >> 8) & 0xF);
    vbdHex(2, (int(top->PC) >> 4) & 0xF);
    vbdHex(1, int(top->PC) & 0xF);

    if (simcyc < 10) {
        top->PCsrc = 1; 
    } else {
        top->PCsrc = 0; 
    }

    if (simcyc == 5){
      top->rst = 1;
    }
    else{
      top->rst = 0;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // either simulation finished, or 'q' is pressed
    if ((Verilated::gotFinish()) || (vbdGetkey()=='q')) 
      exit(0);
  }

  vbdClose();     // ++++
  tfp->close(); 
  printf("Exiting\n");
  exit(0);
}
