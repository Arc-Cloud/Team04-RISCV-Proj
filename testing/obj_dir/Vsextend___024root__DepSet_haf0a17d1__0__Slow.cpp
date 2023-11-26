// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsextend.h for the primary calling header

#include "verilated.h"

#include "Vsextend___024root.h"

VL_ATTR_COLD void Vsextend___024root___eval_initial(Vsextend___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsextend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsextend___024root___eval_initial\n"); );
}

void Vsextend___024root___combo__TOP__0(Vsextend___024root* vlSelf);

VL_ATTR_COLD void Vsextend___024root___eval_settle(Vsextend___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsextend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsextend___024root___eval_settle\n"); );
    // Body
    Vsextend___024root___combo__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vsextend___024root___final(Vsextend___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsextend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsextend___024root___final\n"); );
}

VL_ATTR_COLD void Vsextend___024root___ctor_var_reset(Vsextend___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsextend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsextend___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->Immediate = VL_RAND_RESET_I(25);
    vlSelf->ImmSrc = VL_RAND_RESET_I(3);
    vlSelf->ImmExt = VL_RAND_RESET_I(32);
}
