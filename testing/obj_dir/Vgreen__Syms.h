// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VGREEN__SYMS_H_
#define VERILATED_VGREEN__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vgreen.h"

// INCLUDE MODULE CLASSES
#include "Vgreen___024root.h"

// SYMS CLASS (contains all model state)
class Vgreen__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vgreen* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vgreen___024root               TOP;

    // CONSTRUCTORS
    Vgreen__Syms(VerilatedContext* contextp, const char* namep, Vgreen* modelp);
    ~Vgreen__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
