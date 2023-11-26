// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmaster.h for the primary calling header

#include "verilated.h"

#include "Vmaster___024root.h"

VL_INLINE_OPT void Vmaster___024root___sequent__TOP__0(Vmaster___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaster__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster___024root___sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__master__DOT__orange__DOT__RegFile__DOT__register_file__v0;
    IData/*31:0*/ __Vdlyvval__master__DOT__orange__DOT__RegFile__DOT__register_file__v0;
    CData/*0:0*/ __Vdlyvset__master__DOT__orange__DOT__RegFile__DOT__register_file__v0;
    // Body
    __Vdlyvset__master__DOT__orange__DOT__RegFile__DOT__register_file__v0 = 0U;
    if (vlSelf->master__DOT__MemWrite) {
        vlSelf->master__DOT__orange__DOT__ReadData 
            = vlSelf->master__DOT__orange__DOT__DATA_MEMORY__DOT__ram_array
            [(0x1ffffU & vlSelf->master__DOT__orange__DOT__ALUresult)];
    }
    if (vlSelf->master__DOT__RegWrite) {
        __Vdlyvval__master__DOT__orange__DOT__RegFile__DOT__register_file__v0 
            = vlSelf->master__DOT__orange__DOT__Reg_DATA_IN;
        __Vdlyvset__master__DOT__orange__DOT__RegFile__DOT__register_file__v0 = 1U;
        __Vdlyvdim0__master__DOT__orange__DOT__RegFile__DOT__register_file__v0 
            = (0x1fU & (vlSelf->master__DOT__Instr 
                        >> 7U));
    }
    if (__Vdlyvset__master__DOT__orange__DOT__RegFile__DOT__register_file__v0) {
        vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[__Vdlyvdim0__master__DOT__orange__DOT__RegFile__DOT__register_file__v0] 
            = __Vdlyvval__master__DOT__orange__DOT__RegFile__DOT__register_file__v0;
    }
    VL_WRITEF("dest data: %x\n",32,vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file
              [0xaU]);
}

VL_INLINE_OPT void Vmaster___024root___sequent__TOP__1(Vmaster___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaster__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster___024root___sequent__TOP__1\n"); );
    // Body
    vlSelf->master__DOT__PC = ((IData)(vlSelf->rst)
                                ? 0U : vlSelf->master__DOT__P_C__DOT__PCNext);
    vlSelf->master__DOT__Instr = vlSelf->master__DOT__green__DOT__memory__DOT__rom
        [(0xfffU & vlSelf->master__DOT__PC)];
    vlSelf->master__DOT__orange__DOT__SrcA = vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file
        [(0x1fU & (vlSelf->master__DOT__Instr >> 0xfU))];
    if ((0x33U != (0x7fU & vlSelf->master__DOT__Instr))) {
        if ((0x63U == (0x7fU & vlSelf->master__DOT__Instr))) {
            vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ImmSrc = 2U;
        } else if ((0x13U == (0x7fU & vlSelf->master__DOT__Instr))) {
            vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ImmSrc = 0U;
        } else if ((0x6fU == (0x7fU & vlSelf->master__DOT__Instr))) {
            vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ImmSrc = 3U;
        } else if ((3U == (0x7fU & vlSelf->master__DOT__Instr))) {
            vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ImmSrc = 0U;
        } else if ((0x23U == (0x7fU & vlSelf->master__DOT__Instr))) {
            vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ImmSrc = 0U;
        }
    }
    vlSelf->master__DOT__ImmExt = ((2U & (IData)(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ImmSrc))
                                    ? ((1U & (IData)(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ImmSrc))
                                        ? (((- (IData)(
                                                       (vlSelf->master__DOT__Instr 
                                                        >> 0x1fU))) 
                                            << 0x14U) 
                                           | ((0xff000U 
                                               & vlSelf->master__DOT__Instr) 
                                              | ((0x800U 
                                                  & (vlSelf->master__DOT__Instr 
                                                     >> 9U)) 
                                                 | (0x7feU 
                                                    & (vlSelf->master__DOT__Instr 
                                                       >> 0x14U)))))
                                        : (((- (IData)(
                                                       (vlSelf->master__DOT__Instr 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | ((0x800U 
                                               & (vlSelf->master__DOT__Instr 
                                                  << 4U)) 
                                              | ((0x7e0U 
                                                  & (vlSelf->master__DOT__Instr 
                                                     >> 0x14U)) 
                                                 | (0x1eU 
                                                    & (vlSelf->master__DOT__Instr 
                                                       >> 7U))))))
                                    : ((1U & (IData)(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ImmSrc))
                                        ? (((- (IData)(
                                                       (vlSelf->master__DOT__Instr 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | ((0xfe0U 
                                               & (vlSelf->master__DOT__Instr 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlSelf->master__DOT__Instr 
                                                    >> 7U))))
                                        : (((- (IData)(
                                                       (vlSelf->master__DOT__Instr 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | (vlSelf->master__DOT__Instr 
                                              >> 0x14U))));
    if ((0x33U == (0x7fU & vlSelf->master__DOT__Instr))) {
        if ((0U == (7U & (vlSelf->master__DOT__Instr 
                          >> 0xcU)))) {
            vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ALUControl = 0U;
        } else if ((4U == (7U & (vlSelf->master__DOT__Instr 
                                 >> 0xcU)))) {
            vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ALUControl = 4U;
        } else if ((6U == (7U & (vlSelf->master__DOT__Instr 
                                 >> 0xcU)))) {
            vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ALUControl = 3U;
        } else if ((7U == (7U & (vlSelf->master__DOT__Instr 
                                 >> 0xcU)))) {
            vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ALUControl = 2U;
        }
        vlSelf->master__DOT__MemWrite = 0U;
        vlSelf->master__DOT__RegWrite = 1U;
        vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__Resultsrc = 0U;
        vlSelf->master__DOT__ALUSrc = 0U;
    } else {
        if ((0x63U == (0x7fU & vlSelf->master__DOT__Instr))) {
            vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ALUControl = 1U;
            vlSelf->master__DOT__MemWrite = 0U;
            vlSelf->master__DOT__RegWrite = 0U;
            vlSelf->master__DOT__ALUSrc = 0U;
        } else if ((0x13U == (0x7fU & vlSelf->master__DOT__Instr))) {
            if ((0U == (7U & (vlSelf->master__DOT__Instr 
                              >> 0xcU)))) {
                vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ALUControl = 0U;
            } else if ((4U == (7U & (vlSelf->master__DOT__Instr 
                                     >> 0xcU)))) {
                vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ALUControl = 4U;
            } else if ((6U == (7U & (vlSelf->master__DOT__Instr 
                                     >> 0xcU)))) {
                vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ALUControl = 3U;
            } else if ((7U == (7U & (vlSelf->master__DOT__Instr 
                                     >> 0xcU)))) {
                vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ALUControl = 2U;
            }
            vlSelf->master__DOT__MemWrite = 0U;
            vlSelf->master__DOT__RegWrite = 1U;
            vlSelf->master__DOT__ALUSrc = 1U;
        } else {
            if ((0x6fU != (0x7fU & vlSelf->master__DOT__Instr))) {
                if ((3U == (0x7fU & vlSelf->master__DOT__Instr))) {
                    vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ALUControl = 0U;
                    vlSelf->master__DOT__ALUSrc = 1U;
                } else if ((0x23U == (0x7fU & vlSelf->master__DOT__Instr))) {
                    vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ALUControl = 0U;
                    vlSelf->master__DOT__ALUSrc = 1U;
                }
            }
            if ((0x6fU == (0x7fU & vlSelf->master__DOT__Instr))) {
                vlSelf->master__DOT__MemWrite = 0U;
                vlSelf->master__DOT__RegWrite = 1U;
            } else if ((3U == (0x7fU & vlSelf->master__DOT__Instr))) {
                vlSelf->master__DOT__MemWrite = 0U;
                vlSelf->master__DOT__RegWrite = 1U;
            } else if ((0x23U == (0x7fU & vlSelf->master__DOT__Instr))) {
                vlSelf->master__DOT__MemWrite = 1U;
                vlSelf->master__DOT__RegWrite = 0U;
            }
        }
        if ((0x63U != (0x7fU & vlSelf->master__DOT__Instr))) {
            if ((0x13U == (0x7fU & vlSelf->master__DOT__Instr))) {
                vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__Resultsrc = 0U;
            } else if ((0x6fU == (0x7fU & vlSelf->master__DOT__Instr))) {
                vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__Resultsrc = 2U;
            } else if ((3U == (0x7fU & vlSelf->master__DOT__Instr))) {
                vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__Resultsrc = 1U;
            }
        }
    }
    vlSelf->master__DOT__orange__DOT____Vcellinp__ALU__SRCB 
        = ((IData)(vlSelf->master__DOT__ALUSrc) ? vlSelf->master__DOT__ImmExt
            : vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file
           [(0x1fU & (vlSelf->master__DOT__Instr >> 0x14U))]);
    if ((8U & (IData)(vlSelf->master__DOT__orange__DOT__ALUcontrol))) {
        if ((4U & (IData)(vlSelf->master__DOT__orange__DOT__ALUcontrol))) {
            vlSelf->master__DOT__orange__DOT__ALUresult = 0U;
        } else if ((2U & (IData)(vlSelf->master__DOT__orange__DOT__ALUcontrol))) {
            if (vlSelf->master__DOT__orange__DOT__ALUcontrol) {
                vlSelf->master__DOT__orange__DOT__ALUresult = 0U;
            } else {
                vlSelf->master__DOT__orange__DOT__ALU__DOT__u_SRCA 
                    = vlSelf->master__DOT__orange__DOT__SrcA;
                vlSelf->master__DOT__orange__DOT__ALU__DOT__u_SRCB 
                    = vlSelf->master__DOT__orange__DOT____Vcellinp__ALU__SRCB;
                vlSelf->master__DOT__orange__DOT__ALUresult 
                    = (vlSelf->master__DOT__orange__DOT__ALU__DOT__u_SRCA 
                       >= vlSelf->master__DOT__orange__DOT__ALU__DOT__u_SRCB);
            }
        } else {
            vlSelf->master__DOT__orange__DOT__ALUresult 
                = ((IData)(vlSelf->master__DOT__orange__DOT__ALUcontrol)
                    ? (vlSelf->master__DOT__orange__DOT__SrcA 
                       >= vlSelf->master__DOT__orange__DOT____Vcellinp__ALU__SRCB)
                    : ((0x1fU >= vlSelf->master__DOT__orange__DOT____Vcellinp__ALU__SRCB)
                        ? (vlSelf->master__DOT__orange__DOT__SrcA 
                           >> vlSelf->master__DOT__orange__DOT____Vcellinp__ALU__SRCB)
                        : 0U));
        }
    } else if ((4U & (IData)(vlSelf->master__DOT__orange__DOT__ALUcontrol))) {
        if ((2U & (IData)(vlSelf->master__DOT__orange__DOT__ALUcontrol))) {
            if (vlSelf->master__DOT__orange__DOT__ALUcontrol) {
                vlSelf->master__DOT__orange__DOT__ALUresult 
                    = ((0x1fU >= vlSelf->master__DOT__orange__DOT____Vcellinp__ALU__SRCB)
                        ? (vlSelf->master__DOT__orange__DOT__SrcA 
                           << vlSelf->master__DOT__orange__DOT____Vcellinp__ALU__SRCB)
                        : 0U);
            } else {
                vlSelf->master__DOT__orange__DOT__ALU__DOT__u_SRCA 
                    = vlSelf->master__DOT__orange__DOT__SrcA;
                vlSelf->master__DOT__orange__DOT__ALU__DOT__u_SRCB 
                    = vlSelf->master__DOT__orange__DOT____Vcellinp__ALU__SRCB;
                vlSelf->master__DOT__orange__DOT__ALUresult 
                    = (vlSelf->master__DOT__orange__DOT__ALU__DOT__u_SRCA 
                       < vlSelf->master__DOT__orange__DOT__ALU__DOT__u_SRCB);
            }
        } else {
            vlSelf->master__DOT__orange__DOT__ALUresult 
                = ((IData)(vlSelf->master__DOT__orange__DOT__ALUcontrol)
                    ? (vlSelf->master__DOT__orange__DOT__SrcA 
                       < vlSelf->master__DOT__orange__DOT____Vcellinp__ALU__SRCB)
                    : (vlSelf->master__DOT__orange__DOT__SrcA 
                       ^ vlSelf->master__DOT__orange__DOT____Vcellinp__ALU__SRCB));
        }
    } else {
        vlSelf->master__DOT__orange__DOT__ALUresult 
            = ((2U & (IData)(vlSelf->master__DOT__orange__DOT__ALUcontrol))
                ? ((IData)(vlSelf->master__DOT__orange__DOT__ALUcontrol)
                    ? (vlSelf->master__DOT__orange__DOT__SrcA 
                       | vlSelf->master__DOT__orange__DOT____Vcellinp__ALU__SRCB)
                    : (vlSelf->master__DOT__orange__DOT__SrcA 
                       & vlSelf->master__DOT__orange__DOT____Vcellinp__ALU__SRCB))
                : ((IData)(vlSelf->master__DOT__orange__DOT__ALUcontrol)
                    ? (vlSelf->master__DOT__orange__DOT__SrcA 
                       - vlSelf->master__DOT__orange__DOT____Vcellinp__ALU__SRCB)
                    : (vlSelf->master__DOT__orange__DOT__SrcA 
                       + vlSelf->master__DOT__orange__DOT____Vcellinp__ALU__SRCB)));
    }
    vlSelf->master__DOT__Zero = (0U == vlSelf->master__DOT__orange__DOT__ALUresult);
    if ((0x33U == (0x7fU & vlSelf->master__DOT__Instr))) {
        vlSelf->master__DOT__PCsrc = 0U;
    } else if ((0x63U == (0x7fU & vlSelf->master__DOT__Instr))) {
        if ((0U == (7U & (vlSelf->master__DOT__Instr 
                          >> 0xcU)))) {
            vlSelf->master__DOT__PCsrc = vlSelf->master__DOT__Zero;
        } else if ((1U == (7U & (vlSelf->master__DOT__Instr 
                                 >> 0xcU)))) {
            vlSelf->master__DOT__PCsrc = (1U & (~ (IData)(vlSelf->master__DOT__Zero)));
        }
    } else if ((0x13U == (0x7fU & vlSelf->master__DOT__Instr))) {
        vlSelf->master__DOT__PCsrc = 0U;
    } else if ((0x6fU == (0x7fU & vlSelf->master__DOT__Instr))) {
        vlSelf->master__DOT__PCsrc = 1U;
    } else if ((3U == (0x7fU & vlSelf->master__DOT__Instr))) {
        vlSelf->master__DOT__PCsrc = 0U;
    } else if ((0x23U == (0x7fU & vlSelf->master__DOT__Instr))) {
        vlSelf->master__DOT__PCsrc = 0U;
    }
    if ((1U & (IData)(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__Resultsrc))) {
        if ((1U & (IData)(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__Resultsrc))) {
            vlSelf->master__DOT__orange__DOT__Reg_DATA_IN 
                = vlSelf->master__DOT__orange__DOT__ReadData;
        }
    } else {
        vlSelf->master__DOT__orange__DOT__Reg_DATA_IN 
            = vlSelf->master__DOT__orange__DOT__ALUresult;
    }
    vlSelf->master__DOT__P_C__DOT__PCTarget = (vlSelf->master__DOT__PC 
                                               + vlSelf->master__DOT__ImmExt);
    vlSelf->master__DOT__PCPlus4 = ((IData)(4U) + vlSelf->master__DOT__PC);
    vlSelf->master__DOT__P_C__DOT__PCNext = ((IData)(vlSelf->master__DOT__PCsrc)
                                              ? vlSelf->master__DOT__P_C__DOT__PCTarget
                                              : vlSelf->master__DOT__PCPlus4);
}

VL_INLINE_OPT void Vmaster___024root___combo__TOP__0(Vmaster___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaster__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->Result = vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file
        [vlSelf->testRegAddress];
}

void Vmaster___024root___eval(Vmaster___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaster__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vmaster___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vmaster___024root___sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    Vmaster___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void Vmaster___024root___eval_debug_assertions(Vmaster___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaster__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->trigger & 0xfeU))) {
        Verilated::overWidthError("trigger");}
    if (VL_UNLIKELY((vlSelf->testRegAddress & 0xe0U))) {
        Verilated::overWidthError("testRegAddress");}
}
#endif  // VL_DEBUG
