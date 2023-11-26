// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vgreen.h for the primary calling header

#ifndef VERILATED_VGREEN___024ROOT_H_
#define VERILATED_VGREEN___024ROOT_H_  // guard

#include "verilated.h"

class Vgreen__Syms;

class Vgreen___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(Zero,0,0);
    VL_OUT8(MemWrite,0,0);
    VL_OUT8(RegWrite,0,0);
    VL_OUT8(ALUcontrol,0,0);
    VL_OUT8(ALUsrc,0,0);
    VL_OUT8(PCsrc,0,0);
    VL_OUT8(ResultSrc,0,0);
    CData/*2:0*/ green__DOT____Vcellout__decode_insr__ImmSrc;
    CData/*1:0*/ green__DOT____Vcellout__decode_insr__Resultsrc;
    CData/*3:0*/ green__DOT____Vcellout__decode_insr__ALUControl;
    VL_IN(A,31,0);
    VL_OUT(ImmExt,31,0);
    VL_OUT(Instr,31,0);
    VlUnpacked<IData/*31:0*/, 4096> green__DOT__memory__DOT__rom;

    // INTERNAL VARIABLES
    Vgreen__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vgreen___024root(Vgreen__Syms* symsp, const char* name);
    ~Vgreen___024root();
    VL_UNCOPYABLE(Vgreen___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
