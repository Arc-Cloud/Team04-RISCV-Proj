// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vorange.h for the primary calling header

#include "verilated.h"

#include "Vorange___024root.h"

VL_INLINE_OPT void Vorange___024root___sequent__TOP__0(Vorange___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vorange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vorange___024root___sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__orange__DOT__RegFile__DOT__register_file__v0;
    IData/*31:0*/ __Vdlyvval__orange__DOT__RegFile__DOT__register_file__v0;
    CData/*0:0*/ __Vdlyvset__orange__DOT__RegFile__DOT__register_file__v0;
    // Body
    __Vdlyvset__orange__DOT__RegFile__DOT__register_file__v0 = 0U;
    if (vlSelf->WE) {
        vlSelf->orange__DOT__ReadData = vlSelf->orange__DOT__DATA_MEMORY__DOT__ram_array
            [(0x1ffffU & vlSelf->orange__DOT__ALUresult)];
    }
    if (vlSelf->WE3) {
        __Vdlyvval__orange__DOT__RegFile__DOT__register_file__v0 
            = vlSelf->orange__DOT__Reg_DATA_IN;
        __Vdlyvset__orange__DOT__RegFile__DOT__register_file__v0 = 1U;
        __Vdlyvdim0__orange__DOT__RegFile__DOT__register_file__v0 
            = vlSelf->rd;
    }
    if (__Vdlyvset__orange__DOT__RegFile__DOT__register_file__v0) {
        vlSelf->orange__DOT__RegFile__DOT__register_file[__Vdlyvdim0__orange__DOT__RegFile__DOT__register_file__v0] 
            = __Vdlyvval__orange__DOT__RegFile__DOT__register_file__v0;
    }
    VL_WRITEF("dest data: %x\n",32,vlSelf->orange__DOT__RegFile__DOT__register_file
              [0xaU]);
}

VL_INLINE_OPT void Vorange___024root___combo__TOP__0(Vorange___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vorange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vorange___024root___combo__TOP__0\n"); );
    // Init
    IData/*31:0*/ orange__DOT__SrcA;
    IData/*31:0*/ orange__DOT____Vcellinp__ALU__SRCB;
    // Body
    vlSelf->Result = vlSelf->orange__DOT__RegFile__DOT__register_file
        [vlSelf->testRegAddress];
    orange__DOT__SrcA = vlSelf->orange__DOT__RegFile__DOT__register_file
        [vlSelf->rs1];
    orange__DOT____Vcellinp__ALU__SRCB = ((IData)(vlSelf->AluSrc)
                                           ? vlSelf->ImmExt
                                           : vlSelf->orange__DOT__RegFile__DOT__register_file
                                          [vlSelf->rs2]);
    if ((8U & (IData)(vlSelf->orange__DOT__ALUcontrol))) {
        if ((4U & (IData)(vlSelf->orange__DOT__ALUcontrol))) {
            vlSelf->orange__DOT__ALUresult = 0U;
        } else if ((2U & (IData)(vlSelf->orange__DOT__ALUcontrol))) {
            if (vlSelf->orange__DOT__ALUcontrol) {
                vlSelf->orange__DOT__ALUresult = 0U;
            } else {
                vlSelf->orange__DOT__ALU__DOT__u_SRCA 
                    = orange__DOT__SrcA;
                vlSelf->orange__DOT__ALU__DOT__u_SRCB 
                    = orange__DOT____Vcellinp__ALU__SRCB;
                vlSelf->orange__DOT__ALUresult = (vlSelf->orange__DOT__ALU__DOT__u_SRCA 
                                                  >= vlSelf->orange__DOT__ALU__DOT__u_SRCB);
            }
        } else {
            vlSelf->orange__DOT__ALUresult = ((IData)(vlSelf->orange__DOT__ALUcontrol)
                                               ? (orange__DOT__SrcA 
                                                  >= orange__DOT____Vcellinp__ALU__SRCB)
                                               : ((IData)(vlSelf->shift_right_type)
                                                   ? 
                                                  ((0x1fU 
                                                    >= orange__DOT____Vcellinp__ALU__SRCB)
                                                    ? 
                                                   (orange__DOT__SrcA 
                                                    >> orange__DOT____Vcellinp__ALU__SRCB)
                                                    : 0U)
                                                   : 
                                                  ((0x1fU 
                                                    >= orange__DOT____Vcellinp__ALU__SRCB)
                                                    ? 
                                                   (orange__DOT__SrcA 
                                                    >> orange__DOT____Vcellinp__ALU__SRCB)
                                                    : 0U)));
        }
    } else if ((4U & (IData)(vlSelf->orange__DOT__ALUcontrol))) {
        if ((2U & (IData)(vlSelf->orange__DOT__ALUcontrol))) {
            if (vlSelf->orange__DOT__ALUcontrol) {
                vlSelf->orange__DOT__ALUresult = ((0x1fU 
                                                   >= orange__DOT____Vcellinp__ALU__SRCB)
                                                   ? 
                                                  (orange__DOT__SrcA 
                                                   << orange__DOT____Vcellinp__ALU__SRCB)
                                                   : 0U);
            } else {
                vlSelf->orange__DOT__ALU__DOT__u_SRCA 
                    = orange__DOT__SrcA;
                vlSelf->orange__DOT__ALU__DOT__u_SRCB 
                    = orange__DOT____Vcellinp__ALU__SRCB;
                vlSelf->orange__DOT__ALUresult = (vlSelf->orange__DOT__ALU__DOT__u_SRCA 
                                                  < vlSelf->orange__DOT__ALU__DOT__u_SRCB);
            }
        } else {
            vlSelf->orange__DOT__ALUresult = ((IData)(vlSelf->orange__DOT__ALUcontrol)
                                               ? (orange__DOT__SrcA 
                                                  < orange__DOT____Vcellinp__ALU__SRCB)
                                               : (orange__DOT__SrcA 
                                                  ^ orange__DOT____Vcellinp__ALU__SRCB));
        }
    } else {
        vlSelf->orange__DOT__ALUresult = ((2U & (IData)(vlSelf->orange__DOT__ALUcontrol))
                                           ? ((IData)(vlSelf->orange__DOT__ALUcontrol)
                                               ? (orange__DOT__SrcA 
                                                  | orange__DOT____Vcellinp__ALU__SRCB)
                                               : (orange__DOT__SrcA 
                                                  & orange__DOT____Vcellinp__ALU__SRCB))
                                           : ((IData)(vlSelf->orange__DOT__ALUcontrol)
                                               ? (orange__DOT__SrcA 
                                                  - orange__DOT____Vcellinp__ALU__SRCB)
                                               : (orange__DOT__SrcA 
                                                  + orange__DOT____Vcellinp__ALU__SRCB)));
    }
    vlSelf->zero = (0U == vlSelf->orange__DOT__ALUresult);
    if ((0U == (IData)(vlSelf->ResultSrc))) {
        vlSelf->orange__DOT__Reg_DATA_IN = vlSelf->orange__DOT__ALUresult;
    } else if ((1U == (IData)(vlSelf->ResultSrc))) {
        vlSelf->orange__DOT__Reg_DATA_IN = vlSelf->orange__DOT__ReadData;
    } else if ((2U == (IData)(vlSelf->ResultSrc))) {
        vlSelf->orange__DOT__Reg_DATA_IN = vlSelf->PCPlus4;
    }
}

void Vorange___024root___eval(Vorange___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vorange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vorange___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vorange___024root___sequent__TOP__0(vlSelf);
    }
    Vorange___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vorange___024root___eval_debug_assertions(Vorange___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vorange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vorange___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->rs1 & 0xe0U))) {
        Verilated::overWidthError("rs1");}
    if (VL_UNLIKELY((vlSelf->rs2 & 0xe0U))) {
        Verilated::overWidthError("rs2");}
    if (VL_UNLIKELY((vlSelf->rd & 0xe0U))) {
        Verilated::overWidthError("rd");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->AluSrc & 0xfeU))) {
        Verilated::overWidthError("AluSrc");}
    if (VL_UNLIKELY((vlSelf->ALUControl & 0xf0U))) {
        Verilated::overWidthError("ALUControl");}
    if (VL_UNLIKELY((vlSelf->WE & 0xfeU))) {
        Verilated::overWidthError("WE");}
    if (VL_UNLIKELY((vlSelf->WE3 & 0xfeU))) {
        Verilated::overWidthError("WE3");}
    if (VL_UNLIKELY((vlSelf->ResultSrc & 0xfcU))) {
        Verilated::overWidthError("ResultSrc");}
    if (VL_UNLIKELY((vlSelf->shift_right_type & 0xfeU))) {
        Verilated::overWidthError("shift_right_type");}
    if (VL_UNLIKELY((vlSelf->testRegAddress & 0xe0U))) {
        Verilated::overWidthError("testRegAddress");}
}
#endif  // VL_DEBUG
