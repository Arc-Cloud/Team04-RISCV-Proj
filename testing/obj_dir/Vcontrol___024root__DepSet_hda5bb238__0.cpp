// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcontrol.h for the primary calling header

#include "verilated.h"

#include "Vcontrol___024root.h"

VL_INLINE_OPT void Vcontrol___024root___combo__TOP__0(Vcontrol___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol___024root___combo__TOP__0\n"); );
    // Body
    if ((0x33U != (IData)(vlSelf->op))) {
        if ((0x63U == (IData)(vlSelf->op))) {
            vlSelf->ImmSrc = 2U;
        } else if ((0x13U == (IData)(vlSelf->op))) {
            vlSelf->ImmSrc = 0U;
        } else if ((0x6fU == (IData)(vlSelf->op))) {
            vlSelf->ImmSrc = 3U;
        } else if ((3U == (IData)(vlSelf->op))) {
            vlSelf->ImmSrc = 0U;
        } else if ((0x23U == (IData)(vlSelf->op))) {
            vlSelf->ImmSrc = 0U;
        }
    }
    if ((0x33U == (IData)(vlSelf->op))) {
        vlSelf->Resultsrc = 0U;
        vlSelf->MemWrite = 0U;
        vlSelf->ALUSrc = 0U;
        vlSelf->RegWrite = 1U;
        if ((0U == (IData)(vlSelf->funct3))) {
            vlSelf->ALUControl = 0U;
        } else if ((4U == (IData)(vlSelf->funct3))) {
            vlSelf->ALUControl = 4U;
        } else if ((6U == (IData)(vlSelf->funct3))) {
            vlSelf->ALUControl = 3U;
        } else if ((7U == (IData)(vlSelf->funct3))) {
            vlSelf->ALUControl = 2U;
        }
        vlSelf->PCSrc = 0U;
    } else {
        if ((0x63U != (IData)(vlSelf->op))) {
            if ((0x13U == (IData)(vlSelf->op))) {
                vlSelf->Resultsrc = 0U;
            } else if ((0x6fU == (IData)(vlSelf->op))) {
                vlSelf->Resultsrc = 2U;
            } else if ((3U == (IData)(vlSelf->op))) {
                vlSelf->Resultsrc = 1U;
            }
        }
        if ((0x63U == (IData)(vlSelf->op))) {
            vlSelf->MemWrite = 0U;
            vlSelf->ALUSrc = 0U;
            vlSelf->RegWrite = 0U;
            vlSelf->ALUControl = 1U;
            if ((0U == (IData)(vlSelf->funct3))) {
                vlSelf->PCSrc = vlSelf->zero;
            } else if ((1U == (IData)(vlSelf->funct3))) {
                vlSelf->PCSrc = (1U & (~ (IData)(vlSelf->zero)));
            }
        } else if ((0x13U == (IData)(vlSelf->op))) {
            vlSelf->MemWrite = 0U;
            vlSelf->ALUSrc = 1U;
            vlSelf->RegWrite = 1U;
            if ((0U == (IData)(vlSelf->funct3))) {
                vlSelf->ALUControl = 0U;
            } else if ((4U == (IData)(vlSelf->funct3))) {
                vlSelf->ALUControl = 4U;
            } else if ((6U == (IData)(vlSelf->funct3))) {
                vlSelf->ALUControl = 3U;
            } else if ((7U == (IData)(vlSelf->funct3))) {
                vlSelf->ALUControl = 2U;
            }
            vlSelf->PCSrc = 0U;
        } else {
            if ((0x6fU == (IData)(vlSelf->op))) {
                vlSelf->MemWrite = 0U;
                vlSelf->RegWrite = 1U;
                vlSelf->PCSrc = 1U;
            } else if ((3U == (IData)(vlSelf->op))) {
                vlSelf->MemWrite = 0U;
                vlSelf->RegWrite = 1U;
                vlSelf->PCSrc = 0U;
            } else if ((0x23U == (IData)(vlSelf->op))) {
                vlSelf->MemWrite = 1U;
                vlSelf->RegWrite = 0U;
                vlSelf->PCSrc = 0U;
            }
            if ((0x6fU != (IData)(vlSelf->op))) {
                if ((3U == (IData)(vlSelf->op))) {
                    vlSelf->ALUSrc = 1U;
                    vlSelf->ALUControl = 0U;
                } else if ((0x23U == (IData)(vlSelf->op))) {
                    vlSelf->ALUSrc = 1U;
                    vlSelf->ALUControl = 0U;
                }
            }
        }
    }
}

void Vcontrol___024root___eval(Vcontrol___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol___024root___eval\n"); );
    // Body
    Vcontrol___024root___combo__TOP__0(vlSelf);
}

#ifdef VL_DEBUG
void Vcontrol___024root___eval_debug_assertions(Vcontrol___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->zero & 0xfeU))) {
        Verilated::overWidthError("zero");}
    if (VL_UNLIKELY((vlSelf->op & 0x80U))) {
        Verilated::overWidthError("op");}
    if (VL_UNLIKELY((vlSelf->funct3 & 0xf0U))) {
        Verilated::overWidthError("funct3");}
    if (VL_UNLIKELY((vlSelf->funct7 & 0xfcU))) {
        Verilated::overWidthError("funct7");}
}
#endif  // VL_DEBUG
