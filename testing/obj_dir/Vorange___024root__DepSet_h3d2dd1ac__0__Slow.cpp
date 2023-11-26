// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vorange.h for the primary calling header

#include "verilated.h"

#include "Vorange___024root.h"

VL_ATTR_COLD void Vorange___024root___settle__TOP__0(Vorange___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vorange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vorange___024root___settle__TOP__0\n"); );
    // Init
    IData/*31:0*/ orange__DOT__SrcA;
    IData/*31:0*/ orange__DOT____Vcellinp__ALU__SRCB;
    // Body
    VL_WRITEF("dest data: %x\n",32,vlSelf->orange__DOT__RegFile__DOT__register_file
              [0xaU]);
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

VL_ATTR_COLD void Vorange___024root___eval_initial(Vorange___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vorange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vorange___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vorange___024root___eval_settle(Vorange___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vorange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vorange___024root___eval_settle\n"); );
    // Body
    Vorange___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vorange___024root___final(Vorange___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vorange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vorange___024root___final\n"); );
}

VL_ATTR_COLD void Vorange___024root___ctor_var_reset(Vorange___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vorange__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vorange___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->rs1 = VL_RAND_RESET_I(5);
    vlSelf->rs2 = VL_RAND_RESET_I(5);
    vlSelf->rd = VL_RAND_RESET_I(5);
    vlSelf->ImmExt = VL_RAND_RESET_I(32);
    vlSelf->PCPlus4 = VL_RAND_RESET_I(32);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->AluSrc = VL_RAND_RESET_I(1);
    vlSelf->ALUControl = VL_RAND_RESET_I(4);
    vlSelf->WE = VL_RAND_RESET_I(1);
    vlSelf->WE3 = VL_RAND_RESET_I(1);
    vlSelf->ResultSrc = VL_RAND_RESET_I(2);
    vlSelf->shift_right_type = VL_RAND_RESET_I(1);
    vlSelf->testRegAddress = VL_RAND_RESET_I(5);
    vlSelf->zero = VL_RAND_RESET_I(1);
    vlSelf->Result = VL_RAND_RESET_I(32);
    vlSelf->orange__DOT__ALUresult = VL_RAND_RESET_I(32);
    vlSelf->orange__DOT__ReadData = VL_RAND_RESET_I(32);
    vlSelf->orange__DOT__Reg_DATA_IN = VL_RAND_RESET_I(32);
    vlSelf->orange__DOT__ALUcontrol = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->orange__DOT__RegFile__DOT__register_file[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->orange__DOT__ALU__DOT__u_SRCA = VL_RAND_RESET_I(32);
    vlSelf->orange__DOT__ALU__DOT__u_SRCB = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<131072; ++__Vi0) {
        vlSelf->orange__DOT__DATA_MEMORY__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(32);
    }
}
