// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VINSTMEM__SYMS_H_
#define VERILATED_VINSTMEM__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vinstmem.h"

// INCLUDE MODULE CLASSES
#include "Vinstmem___024root.h"

// SYMS CLASS (contains all model state)
class Vinstmem__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vinstmem* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vinstmem___024root             TOP;

    // CONSTRUCTORS
    Vinstmem__Syms(VerilatedContext* contextp, const char* namep, Vinstmem* modelp);
    ~Vinstmem__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
