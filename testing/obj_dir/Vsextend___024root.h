// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsextend.h for the primary calling header

#ifndef VERILATED_VSEXTEND___024ROOT_H_
#define VERILATED_VSEXTEND___024ROOT_H_  // guard

#include "verilated.h"

class Vsextend__Syms;

class Vsextend___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(ImmSrc,2,0);
    VL_IN(Immediate,31,7);
    VL_OUT(ImmExt,31,0);

    // INTERNAL VARIABLES
    Vsextend__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsextend___024root(Vsextend__Syms* symsp, const char* name);
    ~Vsextend___024root();
    VL_UNCOPYABLE(Vsextend___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
