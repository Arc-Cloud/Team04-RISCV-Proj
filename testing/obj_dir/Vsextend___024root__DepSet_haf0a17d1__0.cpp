// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsextend.h for the primary calling header

#include "verilated.h"

#include "Vsextend___024root.h"

VL_INLINE_OPT void Vsextend___024root___combo__TOP__0(Vsextend___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsextend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsextend___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->ImmExt = ((4U & (IData)(vlSelf->ImmSrc))
                       ? ((2U & (IData)(vlSelf->ImmSrc))
                           ? 0U : ((1U & (IData)(vlSelf->ImmSrc))
                                    ? 0U : (0xfffff000U 
                                            & (vlSelf->Immediate 
                                               << 7U))))
                       : ((2U & (IData)(vlSelf->ImmSrc))
                           ? ((1U & (IData)(vlSelf->ImmSrc))
                               ? (((- (IData)((1U & 
                                               (vlSelf->Immediate 
                                                >> 0x18U)))) 
                                   << 0x14U) | ((0xff000U 
                                                 & (vlSelf->Immediate 
                                                    << 7U)) 
                                                | ((0x800U 
                                                    & (vlSelf->Immediate 
                                                       >> 2U)) 
                                                   | (0x7feU 
                                                      & (vlSelf->Immediate 
                                                         >> 0xdU)))))
                               : (((- (IData)((1U & 
                                               (vlSelf->Immediate 
                                                >> 0x18U)))) 
                                   << 0xcU) | ((0x800U 
                                                & (vlSelf->Immediate 
                                                   << 0xbU)) 
                                               | ((0x7e0U 
                                                   & (vlSelf->Immediate 
                                                      >> 0xdU)) 
                                                  | (0x1eU 
                                                     & vlSelf->Immediate)))))
                           : ((1U & (IData)(vlSelf->ImmSrc))
                               ? (((- (IData)((1U & 
                                               (vlSelf->Immediate 
                                                >> 0x18U)))) 
                                   << 0xcU) | ((0xfe0U 
                                                & (vlSelf->Immediate 
                                                   >> 0xdU)) 
                                               | (0x1fU 
                                                  & vlSelf->Immediate)))
                               : (((- (IData)((1U & 
                                               (vlSelf->Immediate 
                                                >> 0x18U)))) 
                                   << 0xcU) | (0xfffU 
                                               & (vlSelf->Immediate 
                                                  >> 0xdU))))));
}

void Vsextend___024root___eval(Vsextend___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsextend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsextend___024root___eval\n"); );
    // Body
    Vsextend___024root___combo__TOP__0(vlSelf);
}

#ifdef VL_DEBUG
void Vsextend___024root___eval_debug_assertions(Vsextend___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsextend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsextend___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->Immediate & 0xfe000000U))) {
        Verilated::overWidthError("Immediate");}
    if (VL_UNLIKELY((vlSelf->ImmSrc & 0xf8U))) {
        Verilated::overWidthError("ImmSrc");}
}
#endif  // VL_DEBUG
