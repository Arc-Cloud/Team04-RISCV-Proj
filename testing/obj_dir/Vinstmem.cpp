// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vinstmem.h"
#include "Vinstmem__Syms.h"

//============================================================
// Constructors

Vinstmem::Vinstmem(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vinstmem__Syms(contextp(), _vcname__, this)}
    , A{vlSymsp->TOP.A}
    , RD{vlSymsp->TOP.RD}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vinstmem::Vinstmem(const char* _vcname__)
    : Vinstmem(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vinstmem::~Vinstmem() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vinstmem___024root___eval_initial(Vinstmem___024root* vlSelf);
void Vinstmem___024root___eval_settle(Vinstmem___024root* vlSelf);
void Vinstmem___024root___eval(Vinstmem___024root* vlSelf);
#ifdef VL_DEBUG
void Vinstmem___024root___eval_debug_assertions(Vinstmem___024root* vlSelf);
#endif  // VL_DEBUG
void Vinstmem___024root___final(Vinstmem___024root* vlSelf);

static void _eval_initial_loop(Vinstmem__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vinstmem___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vinstmem___024root___eval_settle(&(vlSymsp->TOP));
        Vinstmem___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vinstmem::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vinstmem::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vinstmem___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vinstmem___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vinstmem::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vinstmem::final() {
    Vinstmem___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vinstmem::hierName() const { return vlSymsp->name(); }
const char* Vinstmem::modelName() const { return "Vinstmem"; }
unsigned Vinstmem::threads() const { return 1; }
