// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VP_C.h for the primary calling header

#include "verilated.h"

#include "VP_C___024root.h"

VL_ATTR_COLD void VP_C___024root___eval_initial(VP_C___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VP_C__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VP_C___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

void VP_C___024root___combo__TOP__0(VP_C___024root* vlSelf);

VL_ATTR_COLD void VP_C___024root___eval_settle(VP_C___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VP_C__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VP_C___024root___eval_settle\n"); );
    // Body
    VP_C___024root___combo__TOP__0(vlSelf);
}

VL_ATTR_COLD void VP_C___024root___final(VP_C___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VP_C__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VP_C___024root___final\n"); );
}

VL_ATTR_COLD void VP_C___024root___ctor_var_reset(VP_C___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VP_C__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VP_C___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->PCsrc = VL_RAND_RESET_I(1);
    vlSelf->ImmEXT = VL_RAND_RESET_I(32);
    vlSelf->PC = VL_RAND_RESET_I(32);
    vlSelf->PCPlus4 = VL_RAND_RESET_I(32);
    vlSelf->P_C__DOT__PCNext = VL_RAND_RESET_I(32);
}
