// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vgreen.h for the primary calling header

#include "verilated.h"

#include "Vgreen___024root.h"

VL_ATTR_COLD void Vgreen___024root___initial__TOP__0(Vgreen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root___initial__TOP__0\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_h469d1d31__0;
    // Body
    VL_WRITEF("Loading instruction memory...\n");
    __Vtemp_h469d1d31__0[0U] = 0x2e6d656dU;
    __Vtemp_h469d1d31__0[1U] = 0x6e737472U;
    __Vtemp_h469d1d31__0[2U] = 0x746c2f69U;
    __Vtemp_h469d1d31__0[3U] = 0x2e2e2f72U;
    VL_READMEM_N(true, 32, 4096, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_h469d1d31__0)
                 ,  &(vlSelf->green__DOT__memory__DOT__rom)
                 , 0, ~0ULL);
    VL_WRITEF("Instruction memory loaded....\n");
}

VL_ATTR_COLD void Vgreen___024root___eval_initial(Vgreen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root___eval_initial\n"); );
    // Body
    Vgreen___024root___initial__TOP__0(vlSelf);
}

void Vgreen___024root___combo__TOP__0(Vgreen___024root* vlSelf);

VL_ATTR_COLD void Vgreen___024root___eval_settle(Vgreen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root___eval_settle\n"); );
    // Body
    Vgreen___024root___combo__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vgreen___024root___final(Vgreen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root___final\n"); );
}

VL_ATTR_COLD void Vgreen___024root___ctor_var_reset(Vgreen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->A = VL_RAND_RESET_I(32);
    vlSelf->Zero = VL_RAND_RESET_I(1);
    vlSelf->MemWrite = VL_RAND_RESET_I(1);
    vlSelf->RegWrite = VL_RAND_RESET_I(1);
    vlSelf->ALUcontrol = VL_RAND_RESET_I(1);
    vlSelf->ALUsrc = VL_RAND_RESET_I(1);
    vlSelf->PCsrc = VL_RAND_RESET_I(1);
    vlSelf->ResultSrc = VL_RAND_RESET_I(1);
    vlSelf->ImmExt = VL_RAND_RESET_I(32);
    vlSelf->Instr = VL_RAND_RESET_I(32);
    vlSelf->green__DOT____Vcellout__decode_insr__ImmSrc = VL_RAND_RESET_I(3);
    vlSelf->green__DOT____Vcellout__decode_insr__Resultsrc = VL_RAND_RESET_I(2);
    vlSelf->green__DOT____Vcellout__decode_insr__ALUControl = VL_RAND_RESET_I(4);
    for (int __Vi0=0; __Vi0<4096; ++__Vi0) {
        vlSelf->green__DOT__memory__DOT__rom[__Vi0] = VL_RAND_RESET_I(32);
    }
}
