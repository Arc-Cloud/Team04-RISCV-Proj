// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmaster.h for the primary calling header

#include "verilated.h"

#include "Vmaster__Syms.h"
#include "Vmaster___024root.h"

void Vmaster___024root___ctor_var_reset(Vmaster___024root* vlSelf);

Vmaster___024root::Vmaster___024root(Vmaster__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vmaster___024root___ctor_var_reset(this);
}

void Vmaster___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vmaster___024root::~Vmaster___024root() {
}
