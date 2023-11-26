// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSEXTEND__SYMS_H_
#define VERILATED_VSEXTEND__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vsextend.h"

// INCLUDE MODULE CLASSES
#include "Vsextend___024root.h"

// SYMS CLASS (contains all model state)
class Vsextend__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vsextend* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vsextend___024root             TOP;

    // CONSTRUCTORS
    Vsextend__Syms(VerilatedContext* contextp, const char* namep, Vsextend* modelp);
    ~Vsextend__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
