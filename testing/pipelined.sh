#!/bin/sh

# cleanup
rm -rf obj_dir

# run Verilator to translate Verilog to C++, including C++ testbench

verilator -Wall --cc 