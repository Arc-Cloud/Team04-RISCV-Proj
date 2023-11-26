// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmaster.h for the primary calling header

#ifndef VERILATED_VMASTER___024ROOT_H_
#define VERILATED_VMASTER___024ROOT_H_  // guard

#include "verilated.h"

class Vmaster__Syms;

class Vmaster___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(trigger,0,0);
    VL_IN8(testRegAddress,4,0);
    CData/*0:0*/ master__DOT__PCsrc;
    CData/*0:0*/ master__DOT__MemWrite;
    CData/*0:0*/ master__DOT__ALUSrc;
    CData/*0:0*/ master__DOT__RegWrite;
    CData/*0:0*/ master__DOT__Zero;
    CData/*2:0*/ master__DOT__green__DOT____Vcellout__decode_insr__ImmSrc;
    CData/*1:0*/ master__DOT__green__DOT____Vcellout__decode_insr__Resultsrc;
    CData/*3:0*/ master__DOT__green__DOT____Vcellout__decode_insr__ALUControl;
    CData/*0:0*/ master__DOT__orange__DOT__ALUcontrol;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst;
    VL_OUT(Result,31,0);
    IData/*31:0*/ master__DOT__Instr;
    IData/*31:0*/ master__DOT__PC;
    IData/*31:0*/ master__DOT__PCPlus4;
    IData/*31:0*/ master__DOT__ImmExt;
    IData/*31:0*/ master__DOT__P_C__DOT__PCNext;
    IData/*31:0*/ master__DOT__P_C__DOT__PCTarget;
    IData/*31:0*/ master__DOT__orange__DOT__ALUresult;
    IData/*31:0*/ master__DOT__orange__DOT__ReadData;
    IData/*31:0*/ master__DOT__orange__DOT__SrcA;
    IData/*31:0*/ master__DOT__orange__DOT__Reg_DATA_IN;
    IData/*31:0*/ master__DOT__orange__DOT____Vcellinp__ALU__SRCB;
    IData/*31:0*/ master__DOT__orange__DOT__ALU__DOT__u_SRCA;
    IData/*31:0*/ master__DOT__orange__DOT__ALU__DOT__u_SRCB;
    VlUnpacked<IData/*31:0*/, 4096> master__DOT__green__DOT__memory__DOT__rom;
    VlUnpacked<IData/*31:0*/, 32> master__DOT__orange__DOT__RegFile__DOT__register_file;
    VlUnpacked<IData/*31:0*/, 131072> master__DOT__orange__DOT__DATA_MEMORY__DOT__ram_array;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vmaster__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vmaster___024root(Vmaster__Syms* symsp, const char* name);
    ~Vmaster___024root();
    VL_UNCOPYABLE(Vmaster___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
