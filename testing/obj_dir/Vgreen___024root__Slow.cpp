// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vgreen.h for the primary calling header

#include "verilated.h"

#include "Vgreen__Syms.h"
#include "Vgreen___024root.h"

void Vgreen___024root___ctor_var_reset(Vgreen___024root* vlSelf);

Vgreen___024root::Vgreen___024root(Vgreen__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vgreen___024root___ctor_var_reset(this);
}

void Vgreen___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vgreen___024root::~Vgreen___024root() {
}
