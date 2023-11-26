// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vinstmem.h for the primary calling header

#include "verilated.h"

#include "Vinstmem__Syms.h"
#include "Vinstmem___024root.h"

void Vinstmem___024root___ctor_var_reset(Vinstmem___024root* vlSelf);

Vinstmem___024root::Vinstmem___024root(Vinstmem__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vinstmem___024root___ctor_var_reset(this);
}

void Vinstmem___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vinstmem___024root::~Vinstmem___024root() {
}
