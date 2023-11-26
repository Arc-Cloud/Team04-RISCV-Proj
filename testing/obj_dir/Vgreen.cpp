// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vgreen.h"
#include "Vgreen__Syms.h"

//============================================================
// Constructors

Vgreen::Vgreen(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vgreen__Syms(contextp(), _vcname__, this)}
    , Zero{vlSymsp->TOP.Zero}
    , MemWrite{vlSymsp->TOP.MemWrite}
    , RegWrite{vlSymsp->TOP.RegWrite}
    , ALUcontrol{vlSymsp->TOP.ALUcontrol}
    , ALUsrc{vlSymsp->TOP.ALUsrc}
    , PCsrc{vlSymsp->TOP.PCsrc}
    , ResultSrc{vlSymsp->TOP.ResultSrc}
    , A{vlSymsp->TOP.A}
    , ImmExt{vlSymsp->TOP.ImmExt}
    , Instr{vlSymsp->TOP.Instr}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vgreen::Vgreen(const char* _vcname__)
    : Vgreen(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vgreen::~Vgreen() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vgreen___024root___eval_initial(Vgreen___024root* vlSelf);
void Vgreen___024root___eval_settle(Vgreen___024root* vlSelf);
void Vgreen___024root___eval(Vgreen___024root* vlSelf);
#ifdef VL_DEBUG
void Vgreen___024root___eval_debug_assertions(Vgreen___024root* vlSelf);
#endif  // VL_DEBUG
void Vgreen___024root___final(Vgreen___024root* vlSelf);

static void _eval_initial_loop(Vgreen__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vgreen___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vgreen___024root___eval_settle(&(vlSymsp->TOP));
        Vgreen___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vgreen::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vgreen::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vgreen___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vgreen___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vgreen::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vgreen::final() {
    Vgreen___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vgreen::hierName() const { return vlSymsp->name(); }
const char* Vgreen::modelName() const { return "Vgreen"; }
unsigned Vgreen::threads() const { return 1; }
