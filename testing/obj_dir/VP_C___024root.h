// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VP_C.h for the primary calling header

#ifndef VERILATED_VP_C___024ROOT_H_
#define VERILATED_VP_C___024ROOT_H_  // guard

#include "verilated.h"

class VP_C__Syms;

class VP_C___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(rst,0,0);
    VL_IN8(clk,0,0);
    VL_IN8(PCsrc,0,0);
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst;
    VL_IN(ImmEXT,31,0);
    VL_OUT(PC,31,0);
    VL_OUT(PCPlus4,31,0);
    IData/*31:0*/ P_C__DOT__PCNext;

    // INTERNAL VARIABLES
    VP_C__Syms* const vlSymsp;

    // CONSTRUCTORS
    VP_C___024root(VP_C__Syms* symsp, const char* name);
    ~VP_C___024root();
    VL_UNCOPYABLE(VP_C___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
