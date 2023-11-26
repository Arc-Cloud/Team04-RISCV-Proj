// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vinstmem.h for the primary calling header

#include "verilated.h"

#include "Vinstmem___024root.h"

VL_INLINE_OPT void Vinstmem___024root___combo__TOP__0(Vinstmem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vinstmem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstmem___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->RD = vlSelf->instmem__DOT__rom[(0xfffU 
                                            & vlSelf->A)];
}

void Vinstmem___024root___eval(Vinstmem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vinstmem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstmem___024root___eval\n"); );
    // Body
    Vinstmem___024root___combo__TOP__0(vlSelf);
}

#ifdef VL_DEBUG
void Vinstmem___024root___eval_debug_assertions(Vinstmem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vinstmem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstmem___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
