// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VREG_FILE__SYMS_H_
#define VERILATED_VREG_FILE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vreg_file.h"

// INCLUDE MODULE CLASSES
#include "Vreg_file___024root.h"

// SYMS CLASS (contains all model state)
class Vreg_file__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vreg_file* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vreg_file___024root            TOP;

    // CONSTRUCTORS
    Vreg_file__Syms(VerilatedContext* contextp, const char* namep, Vreg_file* modelp);
    ~Vreg_file__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
