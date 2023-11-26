// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VP_C.h for the primary calling header

#include "verilated.h"

#include "VP_C___024root.h"

VL_INLINE_OPT void VP_C___024root___sequent__TOP__0(VP_C___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VP_C__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VP_C___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->PC = ((IData)(vlSelf->rst) ? 0U : vlSelf->P_C__DOT__PCNext);
}

VL_INLINE_OPT void VP_C___024root___combo__TOP__0(VP_C___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VP_C__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VP_C___024root___combo__TOP__0\n"); );
    // Init
    IData/*31:0*/ P_C__DOT__PCTarget;
    // Body
    P_C__DOT__PCTarget = (vlSelf->PC + vlSelf->ImmEXT);
    vlSelf->PCPlus4 = ((IData)(4U) + vlSelf->PC);
    vlSelf->P_C__DOT__PCNext = ((IData)(vlSelf->PCsrc)
                                 ? P_C__DOT__PCTarget
                                 : vlSelf->PCPlus4);
}

void VP_C___024root___eval(VP_C___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VP_C__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VP_C___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        VP_C___024root___sequent__TOP__0(vlSelf);
    }
    VP_C___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void VP_C___024root___eval_debug_assertions(VP_C___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VP_C__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VP_C___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->PCsrc & 0xfeU))) {
        Verilated::overWidthError("PCsrc");}
}
#endif  // VL_DEBUG
