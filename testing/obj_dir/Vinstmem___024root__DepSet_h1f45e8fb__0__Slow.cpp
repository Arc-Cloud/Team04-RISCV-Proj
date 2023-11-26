// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vinstmem.h for the primary calling header

#include "verilated.h"

#include "Vinstmem___024root.h"

VL_ATTR_COLD void Vinstmem___024root___initial__TOP__0(Vinstmem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vinstmem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstmem___024root___initial__TOP__0\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_h469d1d31__0;
    // Body
    VL_WRITEF("Loading instruction memory...\n");
    __Vtemp_h469d1d31__0[0U] = 0x2e6d656dU;
    __Vtemp_h469d1d31__0[1U] = 0x6e737472U;
    __Vtemp_h469d1d31__0[2U] = 0x746c2f69U;
    __Vtemp_h469d1d31__0[3U] = 0x2e2e2f72U;
    VL_READMEM_N(true, 32, 4096, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_h469d1d31__0)
                 ,  &(vlSelf->instmem__DOT__rom), 0
                 , ~0ULL);
    VL_WRITEF("Instruction memory loaded....\n");
}

VL_ATTR_COLD void Vinstmem___024root___eval_initial(Vinstmem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vinstmem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstmem___024root___eval_initial\n"); );
    // Body
    Vinstmem___024root___initial__TOP__0(vlSelf);
}

void Vinstmem___024root___combo__TOP__0(Vinstmem___024root* vlSelf);

VL_ATTR_COLD void Vinstmem___024root___eval_settle(Vinstmem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vinstmem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstmem___024root___eval_settle\n"); );
    // Body
    Vinstmem___024root___combo__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vinstmem___024root___final(Vinstmem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vinstmem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstmem___024root___final\n"); );
}

VL_ATTR_COLD void Vinstmem___024root___ctor_var_reset(Vinstmem___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vinstmem__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinstmem___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->A = VL_RAND_RESET_I(32);
    vlSelf->RD = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<4096; ++__Vi0) {
        vlSelf->instmem__DOT__rom[__Vi0] = VL_RAND_RESET_I(32);
    }
}
