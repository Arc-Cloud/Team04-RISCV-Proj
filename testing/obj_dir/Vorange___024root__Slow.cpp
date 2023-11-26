// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vorange.h for the primary calling header

#include "verilated.h"

#include "Vorange__Syms.h"
#include "Vorange___024root.h"

void Vorange___024root___ctor_var_reset(Vorange___024root* vlSelf);

Vorange___024root::Vorange___024root(Vorange__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vorange___024root___ctor_var_reset(this);
}

void Vorange___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vorange___024root::~Vorange___024root() {
}
