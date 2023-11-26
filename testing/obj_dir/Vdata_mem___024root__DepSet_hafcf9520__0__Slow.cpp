// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdata_mem.h for the primary calling header

#include "verilated.h"

#include "Vdata_mem___024root.h"

VL_ATTR_COLD void Vdata_mem___024root___eval_initial(Vdata_mem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdata_mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdata_mem___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vdata_mem___024root___eval_settle(Vdata_mem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdata_mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdata_mem___024root___eval_settle\n"); );
}

VL_ATTR_COLD void Vdata_mem___024root___final(Vdata_mem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdata_mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdata_mem___024root___final\n"); );
}

VL_ATTR_COLD void Vdata_mem___024root___ctor_var_reset(Vdata_mem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdata_mem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdata_mem___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->addr = VL_RAND_RESET_I(32);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->WE = VL_RAND_RESET_I(1);
    vlSelf->RD = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<131072; ++__Vi0) {
        vlSelf->data_mem__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(32);
    }
}
