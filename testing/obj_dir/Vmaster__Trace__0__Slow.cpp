// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmaster__Syms.h"


VL_ATTR_COLD void Vmaster___024root__trace_init_sub__TOP__0(Vmaster___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaster__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+67,"clk", false,-1);
    tracep->declBit(c+68,"rst", false,-1);
    tracep->declBit(c+69,"trigger", false,-1);
    tracep->declBus(c+70,"testRegAddress", false,-1, 4,0);
    tracep->declBus(c+71,"Result", false,-1, 31,0);
    tracep->pushNamePrefix("master ");
    tracep->declBus(c+73,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+73,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBit(c+67,"clk", false,-1);
    tracep->declBit(c+68,"rst", false,-1);
    tracep->declBit(c+69,"trigger", false,-1);
    tracep->declBus(c+70,"testRegAddress", false,-1, 4,0);
    tracep->declBus(c+71,"Result", false,-1, 31,0);
    tracep->declBus(c+34,"Instr", false,-1, 31,0);
    tracep->declBus(c+35,"PC", false,-1, 31,0);
    tracep->declBus(c+36,"PCPlus4", false,-1, 31,0);
    tracep->declBit(c+37,"PCsrc", false,-1);
    tracep->declBus(c+38,"ResultSrc", false,-1, 1,0);
    tracep->declBit(c+39,"MemWrite", false,-1);
    tracep->declBus(c+40,"ALUControl", false,-1, 3,0);
    tracep->declBit(c+41,"ALUSrc", false,-1);
    tracep->declBit(c+42,"RegWrite", false,-1);
    tracep->declBus(c+43,"ImmExt", false,-1, 31,0);
    tracep->declBit(c+44,"Zero", false,-1);
    tracep->pushNamePrefix("P_C ");
    tracep->declBus(c+73,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+68,"rst", false,-1);
    tracep->declBit(c+67,"clk", false,-1);
    tracep->declBit(c+37,"PCsrc", false,-1);
    tracep->declBus(c+43,"ImmEXT", false,-1, 31,0);
    tracep->declBus(c+35,"PC", false,-1, 31,0);
    tracep->declBus(c+36,"PCPlus4", false,-1, 31,0);
    tracep->declBus(c+45,"PCNext", false,-1, 31,0);
    tracep->declBus(c+46,"PCTarget", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("green ");
    tracep->declBus(c+73,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+74,"IM_WIDTH", false,-1, 31,0);
    tracep->declBus(c+75,"REGISTER", false,-1, 31,0);
    tracep->declBus(c+35,"A", false,-1, 31,0);
    tracep->declBit(c+44,"Zero", false,-1);
    tracep->declBit(c+39,"MemWrite", false,-1);
    tracep->declBit(c+42,"RegWrite", false,-1);
    tracep->declBit(c+47,"ALUcontrol", false,-1);
    tracep->declBit(c+41,"ALUsrc", false,-1);
    tracep->declBit(c+37,"PCsrc", false,-1);
    tracep->declBit(c+48,"ResultSrc", false,-1);
    tracep->declBus(c+43,"ImmExt", false,-1, 31,0);
    tracep->declBus(c+34,"Instr", false,-1, 31,0);
    tracep->declBus(c+49,"Immsrc", false,-1, 1,0);
    tracep->pushNamePrefix("decode_insr ");
    tracep->declBus(c+73,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+44,"zero", false,-1);
    tracep->declBus(c+50,"op", false,-1, 6,0);
    tracep->declBus(c+51,"funct3", false,-1, 3,0);
    tracep->declBus(c+52,"funct7", false,-1, 1,0);
    tracep->declBit(c+42,"RegWrite", false,-1);
    tracep->declBus(c+53,"ALUControl", false,-1, 3,0);
    tracep->declBit(c+41,"ALUSrc", false,-1);
    tracep->declBit(c+39,"MemWrite", false,-1);
    tracep->declBit(c+37,"PCSrc", false,-1);
    tracep->declBus(c+54,"Resultsrc", false,-1, 1,0);
    tracep->declBus(c+55,"ImmSrc", false,-1, 2,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("memory ");
    tracep->declBus(c+73,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+35,"A", false,-1, 31,0);
    tracep->declBus(c+34,"RD", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("sign_extend ");
    tracep->declBus(c+73,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+56,"Immediate", false,-1, 31,7);
    tracep->declBus(c+57,"ImmSrc", false,-1, 2,0);
    tracep->declBus(c+43,"ImmExt", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("orange ");
    tracep->declBus(c+73,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+58,"rs1", false,-1, 4,0);
    tracep->declBus(c+59,"rs2", false,-1, 4,0);
    tracep->declBus(c+60,"rd", false,-1, 4,0);
    tracep->declBus(c+43,"ImmExt", false,-1, 31,0);
    tracep->declBus(c+36,"PCPlus4", false,-1, 31,0);
    tracep->declBit(c+67,"clk", false,-1);
    tracep->declBit(c+41,"AluSrc", false,-1);
    tracep->declBus(c+40,"ALUControl", false,-1, 3,0);
    tracep->declBit(c+39,"WE", false,-1);
    tracep->declBit(c+42,"WE3", false,-1);
    tracep->declBus(c+38,"ResultSrc", false,-1, 1,0);
    tracep->declBit(c+76,"shift_right_type", false,-1);
    tracep->declBus(c+70,"testRegAddress", false,-1, 4,0);
    tracep->declBit(c+44,"zero", false,-1);
    tracep->declBus(c+71,"Result", false,-1, 31,0);
    tracep->declBus(c+61,"ALUresult", false,-1, 31,0);
    tracep->declBus(c+1,"ReadData", false,-1, 31,0);
    tracep->declBus(c+72,"RD2", false,-1, 31,0);
    tracep->declBus(c+62,"SrcA", false,-1, 31,0);
    tracep->declBus(c+63,"Reg_DATA_IN", false,-1, 31,0);
    tracep->declBit(c+77,"ALUcontrol", false,-1);
    tracep->pushNamePrefix("ALU ");
    tracep->declBus(c+73,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+62,"SRCA", false,-1, 31,0);
    tracep->declBus(c+64,"SRCB", false,-1, 31,0);
    tracep->declBus(c+78,"ALUcontrol", false,-1, 3,0);
    tracep->declBit(c+76,"shift_right_type", false,-1);
    tracep->declBit(c+44,"zero", false,-1);
    tracep->declBus(c+61,"ALUresult", false,-1, 31,0);
    tracep->declBus(c+65,"u_SRCA", false,-1, 31,0);
    tracep->declBus(c+66,"u_SRCB", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("DATA_MEMORY ");
    tracep->declBus(c+73,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+61,"addr", false,-1, 31,0);
    tracep->declBit(c+67,"clk", false,-1);
    tracep->declBit(c+39,"WE", false,-1);
    tracep->declBus(c+1,"RD", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("RegFile ");
    tracep->declBus(c+73,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+75,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBit(c+67,"clk", false,-1);
    tracep->declBus(c+58,"AD1", false,-1, 4,0);
    tracep->declBus(c+59,"AD2", false,-1, 4,0);
    tracep->declBus(c+60,"AD3", false,-1, 4,0);
    tracep->declBit(c+42,"WE3", false,-1);
    tracep->declBus(c+63,"WD3", false,-1, 31,0);
    tracep->declBus(c+70,"testRegAddress", false,-1, 4,0);
    tracep->declBus(c+62,"RD1", false,-1, 31,0);
    tracep->declBus(c+72,"RD2", false,-1, 31,0);
    tracep->declBus(c+71,"testRegData", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+2+i*1,"register_file", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void Vmaster___024root__trace_init_top(Vmaster___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaster__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster___024root__trace_init_top\n"); );
    // Body
    Vmaster___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vmaster___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vmaster___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vmaster___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vmaster___024root__trace_register(Vmaster___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaster__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vmaster___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vmaster___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vmaster___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vmaster___024root__trace_full_sub_0(Vmaster___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vmaster___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster___024root__trace_full_top_0\n"); );
    // Init
    Vmaster___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmaster___024root*>(voidSelf);
    Vmaster__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vmaster___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vmaster___024root__trace_full_sub_0(Vmaster___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vmaster__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmaster___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->master__DOT__orange__DOT__ReadData),32);
    bufp->fullIData(oldp+2,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[0]),32);
    bufp->fullIData(oldp+3,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[1]),32);
    bufp->fullIData(oldp+4,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[2]),32);
    bufp->fullIData(oldp+5,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[3]),32);
    bufp->fullIData(oldp+6,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[4]),32);
    bufp->fullIData(oldp+7,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[5]),32);
    bufp->fullIData(oldp+8,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[6]),32);
    bufp->fullIData(oldp+9,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[7]),32);
    bufp->fullIData(oldp+10,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[8]),32);
    bufp->fullIData(oldp+11,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[9]),32);
    bufp->fullIData(oldp+12,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[10]),32);
    bufp->fullIData(oldp+13,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[11]),32);
    bufp->fullIData(oldp+14,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[12]),32);
    bufp->fullIData(oldp+15,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[13]),32);
    bufp->fullIData(oldp+16,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[14]),32);
    bufp->fullIData(oldp+17,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[15]),32);
    bufp->fullIData(oldp+18,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[16]),32);
    bufp->fullIData(oldp+19,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[17]),32);
    bufp->fullIData(oldp+20,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[18]),32);
    bufp->fullIData(oldp+21,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[19]),32);
    bufp->fullIData(oldp+22,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[20]),32);
    bufp->fullIData(oldp+23,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[21]),32);
    bufp->fullIData(oldp+24,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[22]),32);
    bufp->fullIData(oldp+25,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[23]),32);
    bufp->fullIData(oldp+26,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[24]),32);
    bufp->fullIData(oldp+27,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[25]),32);
    bufp->fullIData(oldp+28,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[26]),32);
    bufp->fullIData(oldp+29,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[27]),32);
    bufp->fullIData(oldp+30,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[28]),32);
    bufp->fullIData(oldp+31,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[29]),32);
    bufp->fullIData(oldp+32,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[30]),32);
    bufp->fullIData(oldp+33,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file[31]),32);
    bufp->fullIData(oldp+34,(vlSelf->master__DOT__Instr),32);
    bufp->fullIData(oldp+35,(vlSelf->master__DOT__PC),32);
    bufp->fullIData(oldp+36,(vlSelf->master__DOT__PCPlus4),32);
    bufp->fullBit(oldp+37,(vlSelf->master__DOT__PCsrc));
    bufp->fullCData(oldp+38,((1U & (IData)(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__Resultsrc))),2);
    bufp->fullBit(oldp+39,(vlSelf->master__DOT__MemWrite));
    bufp->fullCData(oldp+40,((1U & (IData)(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ALUControl))),4);
    bufp->fullBit(oldp+41,(vlSelf->master__DOT__ALUSrc));
    bufp->fullBit(oldp+42,(vlSelf->master__DOT__RegWrite));
    bufp->fullIData(oldp+43,(vlSelf->master__DOT__ImmExt),32);
    bufp->fullBit(oldp+44,(vlSelf->master__DOT__Zero));
    bufp->fullIData(oldp+45,(vlSelf->master__DOT__P_C__DOT__PCNext),32);
    bufp->fullIData(oldp+46,(vlSelf->master__DOT__P_C__DOT__PCTarget),32);
    bufp->fullBit(oldp+47,((1U & (IData)(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ALUControl))));
    bufp->fullBit(oldp+48,((1U & (IData)(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__Resultsrc))));
    bufp->fullCData(oldp+49,((3U & (IData)(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ImmSrc))),2);
    bufp->fullCData(oldp+50,((0x7fU & vlSelf->master__DOT__Instr)),7);
    bufp->fullCData(oldp+51,((7U & (vlSelf->master__DOT__Instr 
                                    >> 0xcU))),4);
    bufp->fullCData(oldp+52,((3U & (vlSelf->master__DOT__Instr 
                                    >> 0x19U))),2);
    bufp->fullCData(oldp+53,(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ALUControl),4);
    bufp->fullCData(oldp+54,(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__Resultsrc),2);
    bufp->fullCData(oldp+55,(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ImmSrc),3);
    bufp->fullIData(oldp+56,((vlSelf->master__DOT__Instr 
                              >> 7U)),25);
    bufp->fullCData(oldp+57,((3U & (IData)(vlSelf->master__DOT__green__DOT____Vcellout__decode_insr__ImmSrc))),3);
    bufp->fullCData(oldp+58,((0x1fU & (vlSelf->master__DOT__Instr 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+59,((0x1fU & (vlSelf->master__DOT__Instr 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+60,((0x1fU & (vlSelf->master__DOT__Instr 
                                       >> 7U))),5);
    bufp->fullIData(oldp+61,(vlSelf->master__DOT__orange__DOT__ALUresult),32);
    bufp->fullIData(oldp+62,(vlSelf->master__DOT__orange__DOT__SrcA),32);
    bufp->fullIData(oldp+63,(vlSelf->master__DOT__orange__DOT__Reg_DATA_IN),32);
    bufp->fullIData(oldp+64,(vlSelf->master__DOT__orange__DOT____Vcellinp__ALU__SRCB),32);
    bufp->fullIData(oldp+65,(vlSelf->master__DOT__orange__DOT__ALU__DOT__u_SRCA),32);
    bufp->fullIData(oldp+66,(vlSelf->master__DOT__orange__DOT__ALU__DOT__u_SRCB),32);
    bufp->fullBit(oldp+67,(vlSelf->clk));
    bufp->fullBit(oldp+68,(vlSelf->rst));
    bufp->fullBit(oldp+69,(vlSelf->trigger));
    bufp->fullCData(oldp+70,(vlSelf->testRegAddress),5);
    bufp->fullIData(oldp+71,(vlSelf->Result),32);
    bufp->fullIData(oldp+72,(vlSelf->master__DOT__orange__DOT__RegFile__DOT__register_file
                             [(0x1fU & (vlSelf->master__DOT__Instr 
                                        >> 0x14U))]),32);
    bufp->fullIData(oldp+73,(0x20U),32);
    bufp->fullIData(oldp+74,(0xcU),32);
    bufp->fullIData(oldp+75,(5U),32);
    bufp->fullBit(oldp+76,(0U));
    bufp->fullBit(oldp+77,(vlSelf->master__DOT__orange__DOT__ALUcontrol));
    bufp->fullCData(oldp+78,(vlSelf->master__DOT__orange__DOT__ALUcontrol),4);
}
