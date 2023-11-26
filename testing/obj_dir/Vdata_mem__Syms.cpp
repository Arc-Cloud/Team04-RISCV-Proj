// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vdata_mem__Syms.h"
#include "Vdata_mem.h"
#include "Vdata_mem___024root.h"

// FUNCTIONS
Vdata_mem__Syms::~Vdata_mem__Syms()
{
}

Vdata_mem__Syms::Vdata_mem__Syms(VerilatedContext* contextp, const char* namep, Vdata_mem* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
