// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vorange.h"
#include "Vorange__Syms.h"

//============================================================
// Constructors

Vorange::Vorange(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vorange__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rs1{vlSymsp->TOP.rs1}
    , rs2{vlSymsp->TOP.rs2}
    , rd{vlSymsp->TOP.rd}
    , AluSrc{vlSymsp->TOP.AluSrc}
    , ALUControl{vlSymsp->TOP.ALUControl}
    , WE{vlSymsp->TOP.WE}
    , WE3{vlSymsp->TOP.WE3}
    , ResultSrc{vlSymsp->TOP.ResultSrc}
    , shift_right_type{vlSymsp->TOP.shift_right_type}
    , testRegAddress{vlSymsp->TOP.testRegAddress}
    , zero{vlSymsp->TOP.zero}
    , ImmExt{vlSymsp->TOP.ImmExt}
    , PCPlus4{vlSymsp->TOP.PCPlus4}
    , Result{vlSymsp->TOP.Result}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vorange::Vorange(const char* _vcname__)
    : Vorange(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vorange::~Vorange() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vorange___024root___eval_initial(Vorange___024root* vlSelf);
void Vorange___024root___eval_settle(Vorange___024root* vlSelf);
void Vorange___024root___eval(Vorange___024root* vlSelf);
#ifdef VL_DEBUG
void Vorange___024root___eval_debug_assertions(Vorange___024root* vlSelf);
#endif  // VL_DEBUG
void Vorange___024root___final(Vorange___024root* vlSelf);

static void _eval_initial_loop(Vorange__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vorange___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vorange___024root___eval_settle(&(vlSymsp->TOP));
        Vorange___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vorange::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vorange::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vorange___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vorange___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vorange::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vorange::final() {
    Vorange___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vorange::hierName() const { return vlSymsp->name(); }
const char* Vorange::modelName() const { return "Vorange"; }
unsigned Vorange::threads() const { return 1; }
