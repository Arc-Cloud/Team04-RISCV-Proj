// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsextend.h for the primary calling header

#include "verilated.h"

#include "Vsextend__Syms.h"
#include "Vsextend___024root.h"

void Vsextend___024root___ctor_var_reset(Vsextend___024root* vlSelf);

Vsextend___024root::Vsextend___024root(Vsextend__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsextend___024root___ctor_var_reset(this);
}

void Vsextend___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vsextend___024root::~Vsextend___024root() {
}
