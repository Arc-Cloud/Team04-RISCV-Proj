// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcontrol.h for the primary calling header

#ifndef VERILATED_VCONTROL___024ROOT_H_
#define VERILATED_VCONTROL___024ROOT_H_  // guard

#include "verilated.h"

class Vcontrol__Syms;

class Vcontrol___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(zero,0,0);
    VL_IN8(op,6,0);
    VL_IN8(funct3,3,0);
    VL_IN8(funct7,1,0);
    VL_OUT8(RegWrite,0,0);
    VL_OUT8(ALUControl,3,0);
    VL_OUT8(ALUSrc,0,0);
    VL_OUT8(MemWrite,0,0);
    VL_OUT8(PCSrc,0,0);
    VL_OUT8(Resultsrc,1,0);
    VL_OUT8(ImmSrc,2,0);

    // INTERNAL VARIABLES
    Vcontrol__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vcontrol___024root(Vcontrol__Syms* symsp, const char* name);
    ~Vcontrol___024root();
    VL_UNCOPYABLE(Vcontrol___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
