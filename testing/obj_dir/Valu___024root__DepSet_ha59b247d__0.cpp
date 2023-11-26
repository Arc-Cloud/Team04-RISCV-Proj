// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu.h for the primary calling header

#include "verilated.h"

#include "Valu___024root.h"

VL_INLINE_OPT void Valu___024root___combo__TOP__0(Valu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___combo__TOP__0\n"); );
    // Body
    if ((8U & (IData)(vlSelf->ALUcontrol))) {
        if ((4U & (IData)(vlSelf->ALUcontrol))) {
            vlSelf->ALUresult = 0U;
        } else if ((2U & (IData)(vlSelf->ALUcontrol))) {
            if ((1U & (IData)(vlSelf->ALUcontrol))) {
                vlSelf->ALUresult = 0U;
            } else {
                vlSelf->alu__DOT__u_SRCA = vlSelf->SRCA;
                vlSelf->alu__DOT__u_SRCB = vlSelf->SRCB;
                vlSelf->ALUresult = (vlSelf->alu__DOT__u_SRCA 
                                     >= vlSelf->alu__DOT__u_SRCB);
            }
        } else {
            vlSelf->ALUresult = ((1U & (IData)(vlSelf->ALUcontrol))
                                  ? (vlSelf->SRCA >= vlSelf->SRCB)
                                  : ((IData)(vlSelf->shift_right_type)
                                      ? ((0x1fU >= vlSelf->SRCB)
                                          ? (vlSelf->SRCA 
                                             >> vlSelf->SRCB)
                                          : 0U) : (
                                                   (0x1fU 
                                                    >= vlSelf->SRCB)
                                                    ? 
                                                   (vlSelf->SRCA 
                                                    >> vlSelf->SRCB)
                                                    : 0U)));
        }
    } else if ((4U & (IData)(vlSelf->ALUcontrol))) {
        if ((2U & (IData)(vlSelf->ALUcontrol))) {
            if ((1U & (IData)(vlSelf->ALUcontrol))) {
                vlSelf->ALUresult = ((0x1fU >= vlSelf->SRCB)
                                      ? (vlSelf->SRCA 
                                         << vlSelf->SRCB)
                                      : 0U);
            } else {
                vlSelf->alu__DOT__u_SRCA = vlSelf->SRCA;
                vlSelf->alu__DOT__u_SRCB = vlSelf->SRCB;
                vlSelf->ALUresult = (vlSelf->alu__DOT__u_SRCA 
                                     < vlSelf->alu__DOT__u_SRCB);
            }
        } else {
            vlSelf->ALUresult = ((1U & (IData)(vlSelf->ALUcontrol))
                                  ? (vlSelf->SRCA < vlSelf->SRCB)
                                  : (vlSelf->SRCA ^ vlSelf->SRCB));
        }
    } else {
        vlSelf->ALUresult = ((2U & (IData)(vlSelf->ALUcontrol))
                              ? ((1U & (IData)(vlSelf->ALUcontrol))
                                  ? (vlSelf->SRCA | vlSelf->SRCB)
                                  : (vlSelf->SRCA & vlSelf->SRCB))
                              : ((1U & (IData)(vlSelf->ALUcontrol))
                                  ? (vlSelf->SRCA - vlSelf->SRCB)
                                  : (vlSelf->SRCA + vlSelf->SRCB)));
    }
    vlSelf->zero = (0U == vlSelf->ALUresult);
}

void Valu___024root___eval(Valu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval\n"); );
    // Body
    Valu___024root___combo__TOP__0(vlSelf);
}

#ifdef VL_DEBUG
void Valu___024root___eval_debug_assertions(Valu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->ALUcontrol & 0xf0U))) {
        Verilated::overWidthError("ALUcontrol");}
    if (VL_UNLIKELY((vlSelf->shift_right_type & 0xfeU))) {
        Verilated::overWidthError("shift_right_type");}
}
#endif  // VL_DEBUG
