// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vreg_file.h for the primary calling header

#ifndef VERILATED_VREG_FILE___024ROOT_H_
#define VERILATED_VREG_FILE___024ROOT_H_  // guard

#include "verilated.h"

class Vreg_file__Syms;

class Vreg_file___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(AD1,4,0);
    VL_IN8(AD2,4,0);
    VL_IN8(AD3,4,0);
    VL_IN8(WE3,0,0);
    VL_IN8(testRegAddress,4,0);
    CData/*0:0*/ __Vclklast__TOP__clk;
    VL_IN(WD3,31,0);
    VL_OUT(RD1,31,0);
    VL_OUT(RD2,31,0);
    VL_OUT(testRegData,31,0);
    VlUnpacked<IData/*31:0*/, 32> reg_file__DOT__register_file;

    // INTERNAL VARIABLES
    Vreg_file__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vreg_file___024root(Vreg_file__Syms* symsp, const char* name);
    ~Vreg_file___024root();
    VL_UNCOPYABLE(Vreg_file___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
