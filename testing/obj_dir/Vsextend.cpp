// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsextend.h"
#include "Vsextend__Syms.h"

//============================================================
// Constructors

Vsextend::Vsextend(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsextend__Syms(contextp(), _vcname__, this)}
    , ImmSrc{vlSymsp->TOP.ImmSrc}
    , Immediate{vlSymsp->TOP.Immediate}
    , ImmExt{vlSymsp->TOP.ImmExt}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsextend::Vsextend(const char* _vcname__)
    : Vsextend(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsextend::~Vsextend() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vsextend___024root___eval_initial(Vsextend___024root* vlSelf);
void Vsextend___024root___eval_settle(Vsextend___024root* vlSelf);
void Vsextend___024root___eval(Vsextend___024root* vlSelf);
#ifdef VL_DEBUG
void Vsextend___024root___eval_debug_assertions(Vsextend___024root* vlSelf);
#endif  // VL_DEBUG
void Vsextend___024root___final(Vsextend___024root* vlSelf);

static void _eval_initial_loop(Vsextend__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vsextend___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vsextend___024root___eval_settle(&(vlSymsp->TOP));
        Vsextend___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vsextend::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsextend::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsextend___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vsextend___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vsextend::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vsextend::final() {
    Vsextend___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsextend::hierName() const { return vlSymsp->name(); }
const char* Vsextend::modelName() const { return "Vsextend"; }
unsigned Vsextend::threads() const { return 1; }
