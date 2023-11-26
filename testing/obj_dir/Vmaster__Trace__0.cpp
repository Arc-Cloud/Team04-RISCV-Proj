// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmaster__Syms.h"


void Vmaster___024root__trace_chg_sub_0(Vmaster___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vmaster___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster___024root__trace_chg_top_0\n"); );
    // Init
    Vmaster___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmaster___024root*>(voidSelf);
    Vmaster__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vmaster___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vmaster___024root__trace_chg_sub_0(Vmaster___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaster__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->master__DOT__orange__DOT__ReadData),32);
        bufp->chgIData(oldp+1,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[0]),32);
        bufp->chgIData(oldp+2,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[1]),32);
        bufp->chgIData(oldp+3,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[2]),32);
        bufp->chgIData(oldp+4,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[3]),32);
        bufp->chgIData(oldp+5,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[4]),32);
        bufp->chgIData(oldp+6,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[5]),32);
        bufp->chgIData(oldp+7,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[6]),32);
        bufp->chgIData(oldp+8,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[7]),32);
        bufp->chgIData(oldp+9,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[8]),32);
        bufp->chgIData(oldp+10,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[9]),32);
        bufp->chgIData(oldp+11,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[10]),32);
        bufp->chgIData(oldp+12,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[11]),32);
        bufp->chgIData(oldp+13,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[12]),32);
        bufp->chgIData(oldp+14,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[13]),32);
        bufp->chgIData(oldp+15,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[14]),32);
        bufp->chgIData(oldp+16,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[15]),32);
        bufp->chgIData(oldp+17,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[16]),32);
        bufp->chgIData(oldp+18,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[17]),32);
        bufp->chgIData(oldp+19,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[18]),32);
        bufp->chgIData(oldp+20,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[19]),32);
        bufp->chgIData(oldp+21,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[20]),32);
        bufp->chgIData(oldp+22,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[21]),32);
        bufp->chgIData(oldp+23,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[22]),32);
        bufp->chgIData(oldp+24,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[23]),32);
        bufp->chgIData(oldp+25,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[24]),32);
        bufp->chgIData(oldp+26,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[25]),32);
        bufp->chgIData(oldp+27,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[26]),32);
        bufp->chgIData(oldp+28,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[27]),32);
        bufp->chgIData(oldp+29,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[28]),32);
        bufp->chgIData(oldp+30,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[29]),32);
        bufp->chgIData(oldp+31,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[30]),32);
        bufp->chgIData(oldp+32,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[31]),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+33,(vlSelf->master__DOT__Instr),32);
        bufp->chgIData(oldp+34,(vlSelf->master__DOT__PC),32);
        bufp->chgIData(oldp+35,(vlSelf->master__DOT__PCPlus4),32);
        bufp->chgBit(oldp+36,(vlSelf->master__DOT__PCsrc));
        bufp->chgCData(oldp+37,((1U & (IData)(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__Resultsrc))),2);
        bufp->chgBit(oldp+38,(vlSelf->master__DOT__MemWrite));
        bufp->chgCData(oldp+39,((1U & (IData)(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ALUControl))),4);
        bufp->chgBit(oldp+40,(vlSelf->master__DOT__ALUSrc));
        bufp->chgBit(oldp+41,(vlSelf->master__DOT__RegWrite));
        bufp->chgIData(oldp+42,(vlSelf->master__DOT__ImmExt),32);
        bufp->chgBit(oldp+43,(vlSelf->master__DOT__Zero));
        bufp->chgIData(oldp+44,(vlSelf->master__DOT__P_C__DOT__PCNext),32);
        bufp->chgIData(oldp+45,(vlSelf->master__DOT__P_C__DOT__PCTarget),32);
        bufp->chgBit(oldp+46,((1U & (IData)(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ALUControl))));
        bufp->chgBit(oldp+47,((1U & (IData)(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__Resultsrc))));
        bufp->chgCData(oldp+48,((3U & (IData)(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ImmSrc))),2);
        bufp->chgCData(oldp+49,((0x7fU & vlSelf->master__DOT__Instr)),7);
        bufp->chgCData(oldp+50,((7U & (vlSelf->master__DOT__Instr 
                                       >> 0xcU))),4);
        bufp->chgCData(oldp+51,((3U & (vlSelf->master__DOT__Instr 
                                       >> 0x19U))),2);
        bufp->chgCData(oldp+52,(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ALUControl),4);
        bufp->chgCData(oldp+53,(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__Resultsrc),2);
        bufp->chgCData(oldp+54,(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ImmSrc),3);
        bufp->chgIData(oldp+55,((vlSelf->master__DOT__Instr 
                                 >> 7U)),25);
        bufp->chgCData(oldp+56,((3U & (IData)(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ImmSrc))),3);
        bufp->chgCData(oldp+57,((0x1fU & (vlSelf->master__DOT__Instr 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+58,((0x1fU & (vlSelf->master__DOT__Instr 
                                          >> 0x14U))),5);
        bufp->chgCData(oldp+59,((0x1fU & (vlSelf->master__DOT__Instr 
                                          >> 7U))),5);
        bufp->chgIData(oldp+60,(vlSelf->master__DOT__orange__DOT__ALUresult),32);
        bufp->chgIData(oldp+61,(vlSelf->master__DOT__orange__DOT__SrcA),32);
        bufp->chgIData(oldp+62,(vlSelf->master__DOT__orange__DOT__Reg_DATA_IN),32);
        bufp->chgIData(oldp+63,(vlSelf->master__DOT__orange__DOT____Vcellinp__ALU__SRCB),32);
        bufp->chgIData(oldp+64,(vlSelf->master__DOT__orange__DOT__ALU__DOT__u_SRCA),32);
        bufp->chgIData(oldp+65,(vlSelf->master__DOT__orange__DOT__ALU__DOT__u_SRCB),32);
    }
    bufp->chgBit(oldp+66,(vlSelf->clk));
    bufp->chgBit(oldp+67,(vlSelf->rst));
    bufp->chgBit(oldp+68,(vlSelf->trigger));
    bufp->chgCData(oldp+69,(vlSelf->testRegAddress),5);
    bufp->chgIData(oldp+70,(vlSelf->Result),32);
    bufp->chgIData(oldp+71,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file
                            [(0x1fU & (vlSelf->master__DOT__Instr 
                                       >> 0x14U))]),32);
}

void Vmaster___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster___024root__trace_cleanup\n"); );
    // Init
    Vmaster___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmaster___024root*>(voidSelf);
    Vmaster__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
