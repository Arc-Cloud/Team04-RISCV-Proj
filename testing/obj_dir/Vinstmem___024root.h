// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vinstmem.h for the primary calling header

#ifndef VERILATED_VINSTMEM___024ROOT_H_
#define VERILATED_VINSTMEM___024ROOT_H_  // guard

#include "verilated.h"

class Vinstmem__Syms;

class Vinstmem___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN(A,31,0);
    VL_OUT(RD,31,0);
    VlUnpacked<IData/*31:0*/, 4096> instmem__DOT__rom;

    // INTERNAL VARIABLES
    Vinstmem__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vinstmem___024root(Vinstmem__Syms* symsp, const char* name);
    ~Vinstmem___024root();
    VL_UNCOPYABLE(Vinstmem___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
