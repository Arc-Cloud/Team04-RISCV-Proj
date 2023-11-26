// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcontrol.h"
#include "Vcontrol__Syms.h"

//============================================================
// Constructors

Vcontrol::Vcontrol(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vcontrol__Syms(contextp(), _vcname__, this)}
    , zero{vlSymsp->TOP.zero}
    , op{vlSymsp->TOP.op}
    , funct3{vlSymsp->TOP.funct3}
    , funct7{vlSymsp->TOP.funct7}
    , RegWrite{vlSymsp->TOP.RegWrite}
    , ALUControl{vlSymsp->TOP.ALUControl}
    , ALUSrc{vlSymsp->TOP.ALUSrc}
    , MemWrite{vlSymsp->TOP.MemWrite}
    , PCSrc{vlSymsp->TOP.PCSrc}
    , Resultsrc{vlSymsp->TOP.Resultsrc}
    , ImmSrc{vlSymsp->TOP.ImmSrc}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vcontrol::Vcontrol(const char* _vcname__)
    : Vcontrol(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vcontrol::~Vcontrol() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vcontrol___024root___eval_initial(Vcontrol___024root* vlSelf);
void Vcontrol___024root___eval_settle(Vcontrol___024root* vlSelf);
void Vcontrol___024root___eval(Vcontrol___024root* vlSelf);
#ifdef VL_DEBUG
void Vcontrol___024root___eval_debug_assertions(Vcontrol___024root* vlSelf);
#endif  // VL_DEBUG
void Vcontrol___024root___final(Vcontrol___024root* vlSelf);

static void _eval_initial_loop(Vcontrol__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vcontrol___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vcontrol___024root___eval_settle(&(vlSymsp->TOP));
        Vcontrol___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vcontrol::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcontrol::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcontrol___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vcontrol___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vcontrol::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vcontrol::final() {
    Vcontrol___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vcontrol::hierName() const { return vlSymsp->name(); }
const char* Vcontrol::modelName() const { return "Vcontrol"; }
unsigned Vcontrol::threads() const { return 1; }
