// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vorange.h for the primary calling header

#ifndef VERILATED_VORANGE___024ROOT_H_
#define VERILATED_VORANGE___024ROOT_H_  // guard

#include "verilated.h"

class Vorange__Syms;

class Vorange___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rs1,4,0);
    VL_IN8(rs2,4,0);
    VL_IN8(rd,4,0);
    VL_IN8(AluSrc,0,0);
    VL_IN8(ALUControl,3,0);
    VL_IN8(WE,0,0);
    VL_IN8(WE3,0,0);
    VL_IN8(ResultSrc,1,0);
    VL_IN8(shift_right_type,0,0);
    VL_IN8(testRegAddress,4,0);
    VL_OUT8(zero,0,0);
    CData/*0:0*/ orange__DOT__ALUcontrol;
    CData/*0:0*/ __Vclklast__TOP__clk;
    VL_IN(ImmExt,31,0);
    VL_IN(PCPlus4,31,0);
    VL_OUT(Result,31,0);
    IData/*31:0*/ orange__DOT__ALUresult;
    IData/*31:0*/ orange__DOT__ReadData;
    IData/*31:0*/ orange__DOT__Reg_DATA_IN;
    IData/*31:0*/ orange__DOT__ALU__DOT__u_SRCA;
    IData/*31:0*/ orange__DOT__ALU__DOT__u_SRCB;
    VlUnpacked<IData/*31:0*/, 32> orange__DOT__RegFile__DOT__register_file;
    VlUnpacked<IData/*31:0*/, 131072> orange__DOT__DATA_MEMORY__DOT__ram_array;

    // INTERNAL VARIABLES
    Vorange__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vorange___024root(Vorange__Syms* symsp, const char* name);
    ~Vorange___024root();
    VL_UNCOPYABLE(Vorange___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
