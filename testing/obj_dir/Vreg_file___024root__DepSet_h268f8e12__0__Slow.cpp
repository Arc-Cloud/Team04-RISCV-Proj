// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vreg_file.h for the primary calling header

#include "verilated.h"

#include "Vreg_file___024root.h"

VL_ATTR_COLD void Vreg_file___024root___settle__TOP__0(Vreg_file___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root___settle__TOP__0\n"); );
    // Body
    VL_WRITEF("dest data: %x\n",32,vlSelf->reg_file__DOT__register_file
              [0xaU]);
    vlSelf->RD1 = vlSelf->reg_file__DOT__register_file
        [vlSelf->AD1];
    vlSelf->RD2 = vlSelf->reg_file__DOT__register_file
        [vlSelf->AD2];
    vlSelf->testRegData = vlSelf->reg_file__DOT__register_file
        [vlSelf->testRegAddress];
}

VL_ATTR_COLD void Vreg_file___024root___eval_initial(Vreg_file___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vreg_file___024root___eval_settle(Vreg_file___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root___eval_settle\n"); );
    // Body
    Vreg_file___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vreg_file___024root___final(Vreg_file___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root___final\n"); );
}

VL_ATTR_COLD void Vreg_file___024root___ctor_var_reset(Vreg_file___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg_file__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_file___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->AD1 = VL_RAND_RESET_I(5);
    vlSelf->AD2 = VL_RAND_RESET_I(5);
    vlSelf->AD3 = VL_RAND_RESET_I(5);
    vlSelf->WE3 = VL_RAND_RESET_I(1);
    vlSelf->WD3 = VL_RAND_RESET_I(32);
    vlSelf->testRegAddress = VL_RAND_RESET_I(5);
    vlSelf->RD1 = VL_RAND_RESET_I(32);
    vlSelf->RD2 = VL_RAND_RESET_I(32);
    vlSelf->testRegData = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->reg_file__DOT__register_file[__Vi0] = VL_RAND_RESET_I(32);
    }
}
