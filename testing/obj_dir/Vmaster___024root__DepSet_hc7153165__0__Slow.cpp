// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmaster.h for the primary calling header

#include "verilated.h"

#include "Vmaster___024root.h"

VL_ATTR_COLD void Vmaster___024root___initial__TOP__0(Vmaster___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaster__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster___024root___initial__TOP__0\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_h469d1d31__0;
    // Body
    VL_WRITEF("Loading instruction memory...\n");
    __Vtemp_h469d1d31__0[0U] = 0x2e6d656dU;
    __Vtemp_h469d1d31__0[1U] = 0x6e737472U;
    __Vtemp_h469d1d31__0[2U] = 0x746c2f69U;
    __Vtemp_h469d1d31__0[3U] = 0x2e2e2f72U;
    VL_READMEM_N(true, 32, 4096, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_h469d1d31__0)
                 ,  &(vlSelf->master__DOT__green__DOT__memory__DOT__rom)
                 , 0, ~0ULL);
    VL_WRITEF("Instruction memory loaded....\n");
}

VL_ATTR_COLD void Vmaster___024root___settle__TOP__0(Vmaster___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaster__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster___024root___settle__TOP__0\n"); );
    // Body
    VL_WRITEF("dest data: %x\n",32,vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file
              [0xaU]);
    vlSelf->Result = vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file
        [vlSelf->testRegAddress];
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

VL_ATTR_COLD void Vmaster___024root___eval_initial(Vmaster___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaster__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster___024root___eval_initial\n"); );
    // Body
    Vmaster___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

VL_ATTR_COLD void Vmaster___024root___eval_settle(Vmaster___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaster__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster___024root___eval_settle\n"); );
    // Body
    Vmaster___024root___settle__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vmaster___024root___final(Vmaster___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaster__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster___024root___final\n"); );
}

VL_ATTR_COLD void Vmaster___024root___ctor_var_reset(Vmaster___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaster__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->trigger = VL_RAND_RESET_I(1);
    vlSelf->testRegAddress = VL_RAND_RESET_I(5);
    vlSelf->Result = VL_RAND_RESET_I(32);
    vlSelf->master__DOT__Instr = VL_RAND_RESET_I(32);
    vlSelf->master__DOT__PC = VL_RAND_RESET_I(32);
    vlSelf->master__DOT__PCPlus4 = VL_RAND_RESET_I(32);
    vlSelf->master__DOT__PCsrc = VL_RAND_RESET_I(1);
    vlSelf->master__DOT__MemWrite = VL_RAND_RESET_I(1);
    vlSelf->master__DOT__ALUSrc = VL_RAND_RESET_I(1);
    vlSelf->master__DOT__RegWrite = VL_RAND_RESET_I(1);
    vlSelf->master__DOT__ImmExt = VL_RAND_RESET_I(32);
    vlSelf->master__DOT__Zero = VL_RAND_RESET_I(1);
    vlSelf->master__DOT__P_C__DOT__PCNext = VL_RAND_RESET_I(32);
    vlSelf->master__DOT__P_C__DOT__PCTarget = VL_RAND_RESET_I(32);
    vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ImmSrc = VL_RAND_RESET_I(3);
    vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__Resultsrc = VL_RAND_RESET_I(2);
    vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ALUControl = VL_RAND_RESET_I(4);
    for (int __Vi0=0; __Vi0<4096; ++__Vi0) {
        vlSelf->master__DOT__green__DOT__memory__DOT__rom[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->master__DOT__orange__DOT__ALUresult = VL_RAND_RESET_I(32);
    vlSelf->master__DOT__orange__DOT__ReadData = VL_RAND_RESET_I(32);
    vlSelf->master__DOT__orange__DOT__SrcA = VL_RAND_RESET_I(32);
    vlSelf->master__DOT__orange__DOT__Reg_DATA_IN = VL_RAND_RESET_I(32);
    vlSelf->master__DOT__orange__DOT____Vcellinp__ALU__SRCB = VL_RAND_RESET_I(32);
    vlSelf->master__DOT__orange__DOT__ALUcontrol = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->master__DOT__orange__DOT__ALU__DOT__u_SRCA = VL_RAND_RESET_I(32);
    vlSelf->master__DOT__orange__DOT__ALU__DOT__u_SRCB = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<131072; ++__Vi0) {
        vlSelf->master__DOT__orange__DOT__DATA_MEMORY__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
