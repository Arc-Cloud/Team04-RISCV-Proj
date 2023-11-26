// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdata_mem.h for the primary calling header

#include "verilated.h"

#include "Vdata_mem__Syms.h"
#include "Vdata_mem___024root.h"

void Vdata_mem___024root___ctor_var_reset(Vdata_mem___024root* vlSelf);

Vdata_mem___024root::Vdata_mem___024root(Vdata_mem__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vdata_mem___024root___ctor_var_reset(this);
}

void Vdata_mem___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vdata_mem___024root::~Vdata_mem___024root() {
}
