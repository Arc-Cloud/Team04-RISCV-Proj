#!/bin/bash

# FILEPATH: /Users/ism/Repositories/Team04-RISCV-Proj/testing/master_script.sh

echo "Welcome to Team 04's RISC-V CPU:"
echo "Select option by entering the number"
echo "1. PDF reference program"
echo "2. F1 program"
echo "3. Test B-J"
echo "4. Test I"
echo "5. Test I-S"
echo "6. Test R"

read -p "Enter your choice (1-6): " choice

case $choice in
    1)

        inst_path=$(realpath "../Ref_program_test/pdf.mem")
        printf "%s" "$inst_path" > ../../rtl/instmem_path.txt
        printf "%s" "$inst_path" > ../../rtl_pipelined/instmem_path.txt
        #printf "%s" "$inst_path" > ../../rtl_cached/instmem_path.txt 

     


        echo "Select which data to use"
        echo "1. Gaussian"
        echo "2. Noisy"
        echo "3. Sine"
        echo "4. Triangle"

        read -p "Enter your choice (1-4): " choice2

        case $choice2 in
            1)
                data_path=$(realpath "../Ref_program_test/gaussian.mem")
                ;;
            2)
                data_path=$(realpath "../Ref_program_test/noisy.mem")
                ;;
            3)
                data_path=$(realpath "../Ref_program_test/sine.mem")
                ;;
            4)
                data_path=$(realpath "../Ref_program_test/triangle.mem")
                ;;
            *)
                echo "Invalid choice"
                exit 1
                ;;
        esac

        # Check if the file exists
        if [ ! -e "$data_path" ]; then
            echo "Error: File not found: $data_path"
            exit 1
        fi

        # Write absolute path to file
        printf "%s" "$data_path" > ../../rtl/datamem_path.txt
        printf "%s" "$data_path" > ../../rtl_pipelined/datamem_path.txt
        #printf "%s" "$data_path" > ../../rtl_cached/datamem_path.txt
        ;;
    2)
        
        inst_path=$(realpath "../F1 program test/f1.mem")
        printf "%s" "$inst_path" > ../../rtl/instmem_path.txt
        printf "%s" "$inst_path" > ../../rtl_pipelined/instmem_path.txt
        #printf "%s" "$inst_path" > ../../rtl_cached/instmem_path.txt

        ;;
    3)
        inst_path=$(realpath "../Type B-J test/b_test.mem")
        printf "%s" "$inst_path" > ../../rtl/instmem_path.txt
        printf "%s" "$inst_path" > ../../rtl_pipelined/instmem_path.txt
        #printf "%s" "$inst_path" > ../../rtl_cached/instmem_path.txt
        ;;
    4)
        inst_path=$(realpath "../Type I test/i_test.mem")
        printf "%s" "$inst_path" > ../../rtl/instmem_path.txt
        printf "%s" "$inst_path" > ../../rtl_pipelined/instmem_path.txt
        #printf "%s" "$inst_path" > ../../rtl_cached/instmem_path.txt
        ;;
    5)
        inst_path=$(realpath "../Type I-S test/is_test.mem")
        printf "%s" "$inst_path" > ../../rtl/instmem_path.txt
        printf "%s" "$inst_path" > ../../rtl_pipelined/instmem_path.txt
        #printf "%s" "$inst_path" > ../../rtl_cached/instmem_path.txt
        ;;
    6)
        inst_path=$(realpath "../Type R test/r_test.mem")
        printf "%s" "$inst_path" > ../../rtl/instmem_path.txt
        printf "%s" "$inst_path" > ../../rtl_pipelined/instmem_path.txt
        #printf "%s" "$inst_path" > ../../rtl_cached/instmem_path.txt
        ;;
    *)
        echo "Invalid choice"
        exit 1
        ;;
esac

# Ask for CPU

echo "Select which CPU to use"
echo "1. Single cycle CPU"
echo "2. Pipelined CPU with instruction cache"

read -p "Enter your choice (1-2): " choice3

case $choice3 in
    1)
        # cleanup
        rm -rf obj_dir
        rm -f MasterCPU.vcd

        # run Verilator to translate Veriliog to C++, including C++ testbench

        verilator -Wall --cc -I../../rtl ../../rtl/alu.sv
        verilator -Wall --cc -I../../rtl  ../../rtl/reg_file.sv
        verilator -Wall --cc -I../../rtl  ../../rtl/data_mem.sv
        verilator -Wall --cc -I../../rtl  ../../rtl/orange.sv 

        verilator -Wall --cc -I../../rtl ../../rtl/P_C.sv

        verilator -Wall --cc -I../../rtl  ../../rtl/sextend.sv
        verilator -Wall --cc -I../../rtl  ../../rtl/inst_mem.sv
        verilator -Wall --cc -I../../rtl  ../../rtl/control.sv
        verilator -Wall --cc -I../../rtl ../../rtl/green.sv

        # build C++ project via make automatically generated by Verilator
        verilator -Wall --cc -I../../rtl --trace ../../rtl/master.sv --exe cpu_tb.cpp

        make -j -C obj_dir -f Vmaster.mk Vmaster

        #run executable simulation file
        obj_dir/Vmaster
        ;;
    2)
        # cleanup
        rm -rf obj_dir
        rm CPU.vcd

        # run Verilator to translate Verilog to C++, including C++ testbench

        # fetch
        verilator -Wall --cc ../../rtl_pipelined/PC.sv
        verilator -Wall --cc ../../rtl_pipelined/inst_mem.sv
        verilator -Wall --cc -I../../rtl_pipelined ../../rtl_pipelined/fetch.sv

        # cache
        verilator -Wall --cc ../../cache/direct_mapped.sv
        verilator -Wall --cc ../../cache/Nway_assos.sv

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
        verilator -Wall --cc --trace -I../../rtl_pipelined ../../rtl_pipelined/pipelined_cpu.sv --exe pipe_cpu_tb.cpp

        # build C++ project via make
        make -j -C obj_dir -f Vpipelined_cpu.mk Vpipelined_cpu

        #run executable simulation file
        obj_dir/Vpipelined_cpu
        ;;

    *)
        echo "Invalid choice"
        exit 1
        ;;
esac
