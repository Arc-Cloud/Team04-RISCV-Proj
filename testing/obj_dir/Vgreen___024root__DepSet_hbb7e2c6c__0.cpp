// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vgreen.h for the primary calling header

#include "verilated.h"

#include "Vgreen___024root.h"

VL_INLINE_OPT void Vgreen___024root___combo__TOP__0(Vgreen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->Instr = vlSelf->green__DOT__memory__DOT__rom
        [(0xfffU & vlSelf->A)];
    if ((0x33U == (0x7fU & vlSelf->Instr))) {
        vlSelf->MemWrite = 0U;
        vlSelf->ALUsrc = 0U;
        vlSelf->RegWrite = 1U;
        vlSelf->PCsrc = 0U;
        if ((0U == (7U & (vlSelf->Instr >> 0xcU)))) {
            vlSelf->green__DOT____Vcellout__decode_insr__ALUControl = 0U;
        } else if ((4U == (7U & (vlSelf->Instr >> 0xcU)))) {
            vlSelf->green__DOT____Vcellout__decode_insr__ALUControl = 4U;
        } else if ((6U == (7U & (vlSelf->Instr >> 0xcU)))) {
            vlSelf->green__DOT____Vcellout__decode_insr__ALUControl = 3U;
        } else if ((7U == (7U & (vlSelf->Instr >> 0xcU)))) {
            vlSelf->green__DOT____Vcellout__decode_insr__ALUControl = 2U;
        }
        vlSelf->green__DOT____Vcellout__decode_insr__Resultsrc = 0U;
    } else {
        if ((0x63U == (0x7fU & vlSelf->Instr))) {
            vlSelf->MemWrite = 0U;
            vlSelf->ALUsrc = 0U;
            vlSelf->RegWrite = 0U;
            if ((0U == (7U & (vlSelf->Instr >> 0xcU)))) {
                vlSelf->PCsrc = vlSelf->Zero;
            } else if ((1U == (7U & (vlSelf->Instr 
                                     >> 0xcU)))) {
                vlSelf->PCsrc = (1U & (~ (IData)(vlSelf->Zero)));
            }
            vlSelf->green__DOT____Vcellout__decode_insr__ALUControl = 1U;
        } else if ((0x13U == (0x7fU & vlSelf->Instr))) {
            vlSelf->MemWrite = 0U;
            vlSelf->ALUsrc = 1U;
            vlSelf->RegWrite = 1U;
            vlSelf->PCsrc = 0U;
            if ((0U == (7U & (vlSelf->Instr >> 0xcU)))) {
                vlSelf->green__DOT____Vcellout__decode_insr__ALUControl = 0U;
            } else if ((4U == (7U & (vlSelf->Instr 
                                     >> 0xcU)))) {
                vlSelf->green__DOT____Vcellout__decode_insr__ALUControl = 4U;
            } else if ((6U == (7U & (vlSelf->Instr 
                                     >> 0xcU)))) {
                vlSelf->green__DOT____Vcellout__decode_insr__ALUControl = 3U;
            } else if ((7U == (7U & (vlSelf->Instr 
                                     >> 0xcU)))) {
                vlSelf->green__DOT____Vcellout__decode_insr__ALUControl = 2U;
            }
        } else {
            if ((0x6fU == (0x7fU & vlSelf->Instr))) {
                vlSelf->MemWrite = 0U;
                vlSelf->RegWrite = 1U;
                vlSelf->PCsrc = 1U;
            } else if ((3U == (0x7fU & vlSelf->Instr))) {
                vlSelf->MemWrite = 0U;
                vlSelf->RegWrite = 1U;
                vlSelf->PCsrc = 0U;
            } else if ((0x23U == (0x7fU & vlSelf->Instr))) {
                vlSelf->MemWrite = 1U;
                vlSelf->RegWrite = 0U;
                vlSelf->PCsrc = 0U;
            }
            if ((0x6fU != (0x7fU & vlSelf->Instr))) {
                if ((3U == (0x7fU & vlSelf->Instr))) {
                    vlSelf->ALUsrc = 1U;
                    vlSelf->green__DOT____Vcellout__decode_insr__ALUControl = 0U;
                } else if ((0x23U == (0x7fU & vlSelf->Instr))) {
                    vlSelf->ALUsrc = 1U;
                    vlSelf->green__DOT____Vcellout__decode_insr__ALUControl = 0U;
                }
            }
        }
        if ((0x63U != (0x7fU & vlSelf->Instr))) {
            if ((0x13U == (0x7fU & vlSelf->Instr))) {
                vlSelf->green__DOT____Vcellout__decode_insr__Resultsrc = 0U;
            } else if ((0x6fU == (0x7fU & vlSelf->Instr))) {
                vlSelf->green__DOT____Vcellout__decode_insr__Resultsrc = 2U;
            } else if ((3U == (0x7fU & vlSelf->Instr))) {
                vlSelf->green__DOT____Vcellout__decode_insr__Resultsrc = 1U;
            }
        }
    }
    if ((0x33U != (0x7fU & vlSelf->Instr))) {
        if ((0x63U == (0x7fU & vlSelf->Instr))) {
            vlSelf->green__DOT____Vcellout__decode_insr__ImmSrc = 2U;
        } else if ((0x13U == (0x7fU & vlSelf->Instr))) {
            vlSelf->green__DOT____Vcellout__decode_insr__ImmSrc = 0U;
        } else if ((0x6fU == (0x7fU & vlSelf->Instr))) {
            vlSelf->green__DOT____Vcellout__decode_insr__ImmSrc = 3U;
        } else if ((3U == (0x7fU & vlSelf->Instr))) {
            vlSelf->green__DOT____Vcellout__decode_insr__ImmSrc = 0U;
        } else if ((0x23U == (0x7fU & vlSelf->Instr))) {
            vlSelf->green__DOT____Vcellout__decode_insr__ImmSrc = 0U;
        }
    }
    vlSelf->ALUcontrol = (1U & (IData)(vlSelf->green__DOT____Vcellout__decode_insr__ALUControl));
    vlSelf->ResultSrc = (1U & (IData)(vlSelf->green__DOT____Vcellout__decode_insr__Resultsrc));
    vlSelf->ImmExt = ((2U & (IData)(vlSelf->green__DOT____Vcellout__decode_insr__ImmSrc))
                       ? ((1U & (IData)(vlSelf->green__DOT____Vcellout__decode_insr__ImmSrc))
                           ? (((- (IData)((vlSelf->Instr 
                                           >> 0x1fU))) 
                               << 0x14U) | ((0xff000U 
                                             & vlSelf->Instr) 
                                            | ((0x800U 
                                                & (vlSelf->Instr 
                                                   >> 9U)) 
                                               | (0x7feU 
                                                  & (vlSelf->Instr 
                                                     >> 0x14U)))))
                           : (((- (IData)((vlSelf->Instr 
                                           >> 0x1fU))) 
                               << 0xcU) | ((0x800U 
                                            & (vlSelf->Instr 
                                               << 4U)) 
                                           | ((0x7e0U 
                                               & (vlSelf->Instr 
                                                  >> 0x14U)) 
                                              | (0x1eU 
                                                 & (vlSelf->Instr 
                                                    >> 7U))))))
                       : ((1U & (IData)(vlSelf->green__DOT____Vcellout__decode_insr__ImmSrc))
                           ? (((- (IData)((vlSelf->Instr 
                                           >> 0x1fU))) 
                               << 0xcU) | ((0xfe0U 
                                            & (vlSelf->Instr 
                                               >> 0x14U)) 
                                           | (0x1fU 
                                              & (vlSelf->Instr 
                                                 >> 7U))))
                           : (((- (IData)((vlSelf->Instr 
                                           >> 0x1fU))) 
                               << 0xcU) | (vlSelf->Instr 
                                           >> 0x14U))));
}

void Vgreen___024root___eval(Vgreen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root___eval\n"); );
    // Body
    Vgreen___024root___combo__TOP__0(vlSelf);
}

#ifdef VL_DEBUG
void Vgreen___024root___eval_debug_assertions(Vgreen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->Zero & 0xfeU))) {
        Verilated::overWidthError("Zero");}
}
#endif  // VL_DEBUG
