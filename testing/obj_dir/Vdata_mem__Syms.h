// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VDATA_MEM__SYMS_H_
#define VERILATED_VDATA_MEM__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vdata_mem.h"

// INCLUDE MODULE CLASSES
#include "Vdata_mem___024root.h"

// SYMS CLASS (contains all model state)
class Vdata_mem__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vdata_mem* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vdata_mem___024root            TOP;

    // CONSTRUCTORS
    Vdata_mem__Syms(VerilatedContext* contextp, const char* namep, Vdata_mem* modelp);
    ~Vdata_mem__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
