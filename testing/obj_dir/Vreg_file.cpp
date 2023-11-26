// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vreg_file.h"
#include "Vreg_file__Syms.h"

//============================================================
// Constructors

Vreg_file::Vreg_file(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vreg_file__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , AD1{vlSymsp->TOP.AD1}
    , AD2{vlSymsp->TOP.AD2}
    , AD3{vlSymsp->TOP.AD3}
    , WE3{vlSymsp->TOP.WE3}
    , testRegAddress{vlSymsp->TOP.testRegAddress}
    , WD3{vlSymsp->TOP.WD3}
    , RD1{vlSymsp->TOP.RD1}
    , RD2{vlSymsp->TOP.RD2}
    , testRegData{vlSymsp->TOP.testRegData}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vreg_file::Vreg_file(const char* _vcname__)
    : Vreg_file(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vreg_file::~Vreg_file() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vreg_file___024root___eval_initial(Vreg_file___024root* vlSelf);
void Vreg_file___024root___eval_settle(Vreg_file___024root* vlSelf);
void Vreg_file___024root___eval(Vreg_file___024root* vlSelf);
#ifdef VL_DEBUG
void Vreg_file___024root___eval_debug_assertions(Vreg_file___024root* vlSelf);
#endif  // VL_DEBUG
void Vreg_file___024root___final(Vreg_file___024root* vlSelf);

static void _eval_initial_loop(Vreg_file__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vreg_file___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vreg_file___024root___eval_settle(&(vlSymsp->TOP));
        Vreg_file___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vreg_file::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vreg_file::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vreg_file___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vreg_file___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vreg_file::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vreg_file::final() {
    Vreg_file___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vreg_file::hierName() const { return vlSymsp->name(); }
const char* Vreg_file::modelName() const { return "Vreg_file"; }
unsigned Vreg_file::threads() const { return 1; }
