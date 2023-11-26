// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vreg_file.h for the primary calling header

#include "verilated.h"

#include "Vreg_file___024root.h"

VL_INLINE_OPT void Vreg_file___024root___sequent__TOP__0(Vreg_file___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root___sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__reg_file__DOT__register_file__v0;
    IData/*31:0*/ __Vdlyvval__reg_file__DOT__register_file__v0;
    CData/*0:0*/ __Vdlyvset__reg_file__DOT__register_file__v0;
    // Body
    __Vdlyvset__reg_file__DOT__register_file__v0 = 0U;
    if (vlSelf->WE3) {
        __Vdlyvval__reg_file__DOT__register_file__v0 
            = vlSelf->WD3;
        __Vdlyvset__reg_file__DOT__register_file__v0 = 1U;
        __Vdlyvdim0__reg_file__DOT__register_file__v0 
            = vlSelf->AD3;
    }
    if (__Vdlyvset__reg_file__DOT__register_file__v0) {
        vlSelf->reg_file__DOT__register_file[__Vdlyvdim0__reg_file__DOT__register_file__v0] 
            = __Vdlyvval__reg_file__DOT__register_file__v0;
    }
    VL_WRITEF("dest data: %x\n",32,vlSelf->reg_file__DOT__register_file
              [0xaU]);
}

VL_INLINE_OPT void Vreg_file___024root___combo__TOP__0(Vreg_file___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->RD1 = vlSelf->reg_file__DOT__register_file
        [vlSelf->AD1];
    vlSelf->RD2 = vlSelf->reg_file__DOT__register_file
        [vlSelf->AD2];
    vlSelf->testRegData = vlSelf->reg_file__DOT__register_file
        [vlSelf->testRegAddress];
}

void Vreg_file___024root___eval(Vreg_file___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vreg_file___024root___sequent__TOP__0(vlSelf);
    }
    Vreg_file___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vreg_file___024root___eval_debug_assertions(Vreg_file___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->AD1 & 0xe0U))) {
        Verilated::overWidthError("AD1");}
    if (VL_UNLIKELY((vlSelf->AD2 & 0xe0U))) {
        Verilated::overWidthError("AD2");}
    if (VL_UNLIKELY((vlSelf->AD3 & 0xe0U))) {
        Verilated::overWidthError("AD3");}
    if (VL_UNLIKELY((vlSelf->WE3 & 0xfeU))) {
        Verilated::overWidthError("WE3");}
    if (VL_UNLIKELY((vlSelf->testRegAddress & 0xe0U))) {
        Verilated::overWidthError("testRegAddress");}
}
#endif  // VL_DEBUG
