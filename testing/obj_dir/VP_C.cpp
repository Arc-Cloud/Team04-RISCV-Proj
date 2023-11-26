// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VP_C.h"
#include "VP_C__Syms.h"

//============================================================
// Constructors

VP_C::VP_C(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VP_C__Syms(contextp(), _vcname__, this)}
    , rst{vlSymsp->TOP.rst}
    , clk{vlSymsp->TOP.clk}
    , PCsrc{vlSymsp->TOP.PCsrc}
    , ImmEXT{vlSymsp->TOP.ImmEXT}
    , PC{vlSymsp->TOP.PC}
    , PCPlus4{vlSymsp->TOP.PCPlus4}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VP_C::VP_C(const char* _vcname__)
    : VP_C(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VP_C::~VP_C() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VP_C___024root___eval_initial(VP_C___024root* vlSelf);
void VP_C___024root___eval_settle(VP_C___024root* vlSelf);
void VP_C___024root___eval(VP_C___024root* vlSelf);
#ifdef VL_DEBUG
void VP_C___024root___eval_debug_assertions(VP_C___024root* vlSelf);
#endif  // VL_DEBUG
void VP_C___024root___final(VP_C___024root* vlSelf);

static void _eval_initial_loop(VP_C__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VP_C___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VP_C___024root___eval_settle(&(vlSymsp->TOP));
        VP_C___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void VP_C::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VP_C::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VP_C___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VP_C___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* VP_C::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void VP_C::final() {
    VP_C___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VP_C::hierName() const { return vlSymsp->name(); }
const char* VP_C::modelName() const { return "VP_C"; }
unsigned VP_C::threads() const { return 1; }
