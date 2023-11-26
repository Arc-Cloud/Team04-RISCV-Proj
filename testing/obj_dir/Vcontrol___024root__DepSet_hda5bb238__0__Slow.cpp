// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcontrol.h for the primary calling header

#include "verilated.h"

#include "Vcontrol___024root.h"

VL_ATTR_COLD void Vcontrol___024root___eval_initial(Vcontrol___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol___024root___eval_initial\n"); );
}

void Vcontrol___024root___combo__TOP__0(Vcontrol___024root* vlSelf);

VL_ATTR_COLD void Vcontrol___024root___eval_settle(Vcontrol___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol___024root___eval_settle\n"); );
    // Body
    Vcontrol___024root___combo__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vcontrol___024root___final(Vcontrol___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol___024root___final\n"); );
}

VL_ATTR_COLD void Vcontrol___024root___ctor_var_reset(Vcontrol___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->zero = VL_RAND_RESET_I(1);
    vlSelf->op = VL_RAND_RESET_I(7);
    vlSelf->funct3 = VL_RAND_RESET_I(4);
    vlSelf->funct7 = VL_RAND_RESET_I(2);
    vlSelf->RegWrite = VL_RAND_RESET_I(1);
    vlSelf->ALUControl = VL_RAND_RESET_I(4);
    vlSelf->ALUSrc = VL_RAND_RESET_I(1);
    vlSelf->MemWrite = VL_RAND_RESET_I(1);
    vlSelf->PCSrc = VL_RAND_RESET_I(1);
    vlSelf->Resultsrc = VL_RAND_RESET_I(2);
    vlSelf->ImmSrc = VL_RAND_RESET_I(3);
}
