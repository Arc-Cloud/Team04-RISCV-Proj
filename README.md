# Team04-RISCV-CPU

## Joint Statement

### Overall Approach
  - Complete lab 4 with design that works for 2 instructions, although not scalable
  - Restart with design that easily scales for more instructions
  - Start and complete single cycle CPU with as many instructions as possible
  

## Repo Structure 
```
.
├── imgs
│   ├── mem_dump2.png
│   └── mem_dump.png
├── README.md
├── rtl
│   ├── alu.sv
│   ├── control.sv
│   ├── data_mem.sv
│   ├── green.sv
│   ├── instmem.sv
│   ├── instr.mem
│   ├── master.sv
│   ├── orange.sv
│   ├── P_C.sv
│   ├── reg_file.sv
│   ├── sextend.sv
│   └── test_data.mem
├── statements
│   ├── Hanif.md
│   ├── Idrees.md
│   ├── Ilan.md
│   └── Maximilian.md
├── testing
│   ├── cpu_tb.cpp
│   ├── CPU.vcd
│   ├── doit.sh
│   ├── f1_asm.s
│   ├── SingleCycleCpuTest.asm
│   ├── TestingForPC
│   │   ├── PC_testbench.cpp
│   │   └── PC_test.sh
│   ├── vbuddy.cfg
│   └── vbuddy.cpp
└── tree.txt
```

## Details & Personal Statements
| Name &nbsp; &nbsp; | Github | CID &nbsp; &nbsp; &nbsp;| Email &nbsp; | Link to Personal Statements|
| -------- | -------- | -------- | -------- | -------- |
| Maximilian | | | | [Max's Statement](statements/Maximilian.md)
| Ilan | | | | [Ilan's Statement](statements/Ilan.md) 
| Idrees | | | | [Idrees's Statement](statements/Idrees.md) 
| Hanif | | | | [Hanif's Statement](statements/Hanif.md) 


# Single Cylce RV32I Design
### Contributions
| Component | Maximilian &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| Ilan &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| Hanif &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| Idrees &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| -------- | :--------: | :--------: | :--------: | :--------: |
| alu.sv | | L | |
| control.sv | C | | L |
| data_mem.sv | C | L | C |
| green.sv | | C | L |
| instmem.sv | | L | C |
| master.sv | | C | | L
| orange.sv | | L | |
| P_C.sv | L | | |
| reg_file.sv | | L | |
| sextend.sv | | | L |

Legend: `L` = Lead `C` = Contributor
## Planning

### Teamwork things ...

## Implementation

### F1 ASM
As a team we produced the following F1.ASM file:

### ALU

[Implemented here](rtl/alu.sv)

The ALU contains arithmetic and logic operations on 2 operands. All arithmetic operations needed for all RISCV instructions have been added. Although not all are used. This is in order to make it easy to add instruction implementations in the future if time allows.  
| ALU control | Result |
| -------- | :--------: |
| 0000 | SrcA + SrcB |
| 0001 | SrcA - SrcB | 
| 0010 | SrcA & SrcB |
| 0011 | SrcA or SrcB |
| 0100 | SrcA ^ SrcB |
| 0101 | SrcA < SrcB |
| 0110 | uSrcA < uSrcB |
| 0111 | SrcA << SrcB[4:0] |
| 1000 | SrcA >> SrcB[4:0] |
| 1001 | SrcA >= SrcB |
| 1010 | uSrcA >= uSrcB |
| 1011 | SrcA >>> SrcB[4:0] |

SrcA and SrcB are the 2 inputs to the ALU. SrcB could be an immediate value, this is decided by the ALUSrc signal. *u* prepended to the name means it is treated as an unsigned value. 

There's a `Zero` flag that connects to the control unit, which is high whenever the result from the ALU is zero. This is used for effecting branches.

### PC

### Control Unit

### Memory

The single cycle CPU uses data memory, instruction memory, and registers. The [register file](rtl/reg_file.sv) implements 32 32-bit registers, that have synchronous write enable, and asynchronous read. 

The data and instruction memory were initially modelled as 32-bit words per memeory location. This worked well for Lab4 and initially for the project, but not so well when we decided that we wanted to implement all load/store half and byte instructions. A load-store unit was suggested by Max, which would work by masking out relevant bits from a 32-bit word in the case of half / byte addressing. Hanif suggested modelling all memory as a byte per memory location, which would simplify things greatly. Ilan implemented this for the [data memory](rtl/data_mem.sv), and [instruction memory](rtl/instmem.sv). 

Now, byte addressing becomes trivial, half addressing is a matter of accessing 2 consecutive memory locations, and word addressing is a matter of accessing 4 consecutive memory locations. 

Reading and writing to data memory has some subtle caveats.

![mem dump](imgs/mem_dump.png)  
*Acquired  from: https://github.com/johnwinans/rvalp*

Say register `a10` is `0x00002650`.

The instruction `lh x12, -2(a10)` should set `x12` to `0x00004307`. Notice how the word is made up of bytes from higher to lower addresses?

Say `x12 = 0x12345678` then the instruction `sh x12,2(a10)` will change the data at address `0x00002652` from 0x0000 to 0x5678 resulting in

![memdump2](imgs/mem_dump2.png)  
*Acquired  from: https://github.com/johnwinans/rvalp*

Using these examples, memory was implmented correctly.

### Testing

GTK wave outputs can go here
 
## Design Decisions

### Decoder Table
| Instruction| OP | ... | ... | ...
| -------- | :--------: | :--------: | :--------: | :--------: |
| | | | |
| | | | |
| | | | |

### Sign Extension
| ImmSrc| ImmExt | Instruction Type 
| -------- | :--------: | :--------: | 
| | | 
| | | 
| | | 
## Final Schematic

schematic image goes here ...

### Implemented Instructions 
#### R-Type
`add` `sub` `sll` `slt` `sltu` `xor` `srl` `sra` `or` `and`
#### B-Type
`beq` `bne`
#### I-Type
`addi` `slli` `slti` `sltiu` `xori` `srli` `srai` `ori` `andi` `lb` `lh` `lw` `lbu` `lhu` `jalr`
#### J-Type
`jal`
#### S-Type
`sb` `sh` `sw`

# Pipelined RV32I Design

| Component | Maximilian | Ilan | Hanif | Idrees |
| -------- | :--------: | :--------: | :--------: | :--------: |
| | | | |
| | | | |
| | | | |

Legend: L = Lead C = Contributor


Info on Pipelined RV32I Design ....

# Data Memory Cache

| Component | Maximilian | Ilan | Hanif | Idrees |
| -------- | :--------: | :--------: | :--------: | :--------: |
| | | | |
| | | | |
| | | | |

Legend: L = Lead C = Contributor


Info on Data Memory Cache ....




