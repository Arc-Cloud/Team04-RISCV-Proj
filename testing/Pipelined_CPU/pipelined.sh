#!/bin/sh

# cleanup
rm -rf obj_dir
rm CPU.vcd

# run Verilator to translate Verilog to C++, including C++ testbench

# fetch
verilator -Wall --cc ../../rtl_pipelined/PC.sv
verilator -Wall --cc ../../rtl_pipelined/inst_mem.sv
verilator -Wall --cc -I"../../rtl_pipelined" ../../rtl_pipelined/fetch.sv

# cache
verilator -Wall --cc ../../cache/direct_mapped.sv

# decode pipeline
verilator -Wall --cc ../../rtl_pipelined/decode_pipeline.sv

# decode
verilator -Wall --cc ../../rtl_pipelined/control_unit.sv
verilator -Wall --cc ../../rtl_pipelined/register_file.sv
verilator -Wall --cc ../../rtl_pipelined/extend.sv
verilator -Wall --cc -I"../../rtl_pipelined" ../../rtl_pipelined/decode.sv

# execute pipeline
verilator -Wall --cc ../../rtl_pipelined/execute_pipeline.sv

# execute
verilator -Wall --cc ../../rtl_pipelined/mux.sv
verilator -Wall --cc ../../rtl_pipelined/alu.sv
verilator -Wall --cc -I"../../rtl_pipelined" ../../rtl_pipelined/execute.sv

# memory pipeline
verilator -Wall --cc ../../rtl_pipelined/memory_pipeline.sv

# memory
verilator -Wall --cc ../../rtl_pipelined/data_mem.sv
verilator -Wall --cc -I../../rtl_pipelined ../../rtl_pipelined/memory.sv

# writeback pipeline
verilator -Wall --cc ../../rtl_pipelined/writeback_pipeline.sv

# writeback
verilator -Wall --cc -I../../rtl_pipelined ../../rtl_pipelined/writeback.sv

# hazard detection
verilator -Wall --cc ../../rtl_pipelined/hazard_unit.sv

# master
verilator -Wall --cc --trace -I../../rtl_pipelined -I../../cache ../../rtl_pipelined/pipelined_cpu.sv --exe pipe_cpu_tb.cpp

# build C++ project via make automatically generated by Verilator
make -j -C obj_dir -f Vpipelined_cpu.mk Vpipelined_cpu
    
#run executable simulation file
obj_dir/Vpipelined_cpu
