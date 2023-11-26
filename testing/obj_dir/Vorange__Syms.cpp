// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vorange__Syms.h"
#include "Vorange.h"
#include "Vorange___024root.h"

// FUNCTIONS
Vorange__Syms::~Vorange__Syms()
{
}

Vorange__Syms::Vorange__Syms(VerilatedContext* contextp, const char* namep, Vorange* modelp)
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
