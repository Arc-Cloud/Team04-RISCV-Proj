// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VP_C.h for the primary calling header

#include "verilated.h"

#include "VP_C__Syms.h"
#include "VP_C___024root.h"

void VP_C___024root___ctor_var_reset(VP_C___024root* vlSelf);

VP_C___024root::VP_C___024root(VP_C__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VP_C___024root___ctor_var_reset(this);
}

void VP_C___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VP_C___024root::~VP_C___024root() {
}
