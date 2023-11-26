// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VORANGE__SYMS_H_
#define VERILATED_VORANGE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vorange.h"

// INCLUDE MODULE CLASSES
#include "Vorange___024root.h"

// SYMS CLASS (contains all model state)
class Vorange__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vorange* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vorange___024root              TOP;

    // CONSTRUCTORS
    Vorange__Syms(VerilatedContext* contextp, const char* namep, Vorange* modelp);
    ~Vorange__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
