// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmaster.h"
#include "Vmaster__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vmaster::Vmaster(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmaster__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , trigger{vlSymsp->TOP.trigger}
    , testRegAddress{vlSymsp->TOP.testRegAddress}
    , Result{vlSymsp->TOP.Result}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vmaster::Vmaster(const char* _vcname__)
    : Vmaster(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmaster::~Vmaster() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vmaster___024root___eval_initial(Vmaster___024root* vlSelf);
void Vmaster___024root___eval_settle(Vmaster___024root* vlSelf);
void Vmaster___024root___eval(Vmaster___024root* vlSelf);
#ifdef VL_DEBUG
void Vmaster___024root___eval_debug_assertions(Vmaster___024root* vlSelf);
#endif  // VL_DEBUG
void Vmaster___024root___final(Vmaster___024root* vlSelf);

static void _eval_initial_loop(Vmaster__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vmaster___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vmaster___024root___eval_settle(&(vlSymsp->TOP));
        Vmaster___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vmaster::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmaster::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmaster___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vmaster___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vmaster::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vmaster::final() {
    Vmaster___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmaster::hierName() const { return vlSymsp->name(); }
const char* Vmaster::modelName() const { return "Vmaster"; }
unsigned Vmaster::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vmaster::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vmaster___024root__trace_init_top(Vmaster___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmaster___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmaster___024root*>(voidSelf);
    Vmaster__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vmaster___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vmaster___024root__trace_register(Vmaster___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vmaster::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vmaster___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
