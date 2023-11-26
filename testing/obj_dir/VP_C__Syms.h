// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VP_C__SYMS_H_
#define VERILATED_VP_C__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VP_C.h"

// INCLUDE MODULE CLASSES
#include "VP_C___024root.h"

// SYMS CLASS (contains all model state)
class VP_C__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VP_C* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VP_C___024root                 TOP;

    // CONSTRUCTORS
    VP_C__Syms(VerilatedContext* contextp, const char* namep, VP_C* modelp);
    ~VP_C__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
