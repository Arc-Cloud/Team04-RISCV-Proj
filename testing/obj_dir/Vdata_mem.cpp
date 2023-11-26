// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdata_mem.h"
#include "Vdata_mem__Syms.h"

//============================================================
// Constructors

Vdata_mem::Vdata_mem(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdata_mem__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , WE{vlSymsp->TOP.WE}
    , addr{vlSymsp->TOP.addr}
    , RD{vlSymsp->TOP.RD}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vdata_mem::Vdata_mem(const char* _vcname__)
    : Vdata_mem(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdata_mem::~Vdata_mem() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vdata_mem___024root___eval_initial(Vdata_mem___024root* vlSelf);
void Vdata_mem___024root___eval_settle(Vdata_mem___024root* vlSelf);
void Vdata_mem___024root___eval(Vdata_mem___024root* vlSelf);
#ifdef VL_DEBUG
void Vdata_mem___024root___eval_debug_assertions(Vdata_mem___024root* vlSelf);
#endif  // VL_DEBUG
void Vdata_mem___024root___final(Vdata_mem___024root* vlSelf);

static void _eval_initial_loop(Vdata_mem__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vdata_mem___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vdata_mem___024root___eval_settle(&(vlSymsp->TOP));
        Vdata_mem___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vdata_mem::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdata_mem::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdata_mem___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vdata_mem___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vdata_mem::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vdata_mem::final() {
    Vdata_mem___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdata_mem::hierName() const { return vlSymsp->name(); }
const char* Vdata_mem::modelName() const { return "Vdata_mem"; }
unsigned Vdata_mem::threads() const { return 1; }
