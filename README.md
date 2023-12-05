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
| alu.sv | C | L | |
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
As a team we produced the following [f1_asm.s](testing/f1_asm.s) code. 

Simulating sequential illumination of Formula 1 start lights, where each light is represented by a bit in a register that is turned on one after another and then turned off after a specified duration.

The program begins execution at the `main` label, where it jumps to the `init` subroutine using `JAL ra, init`, which also saves the return address in the `ra` register. After initializing the necessary registers, the program returns to `main` and loops indefinitely due to the `jal zero, main` instruction.

In the `init` subroutine:
- `s2` is initialized to 0, which will serve as the iterative light control variable.
- `s3` is set to `0xff` (binary `11111111`), representing all lights being on.
- `s5` is initialized to 0 and will hold the result of the bitwise AND operation between `s2` and `s3`.
- `s4` is set to 8, which will act as a countdown timer for the duration the lights are on.

The `loopi` label begins the process of sequentially turning on the lights. `s2` is shifted left by one position and then incremented by 1, simulating the turning on of the next light. The `and` instruction computes the current state of the lights, which is stored in `s5`.

After setting a light, the program enters the `wait` loop, which decrements `s4` until it reaches zero, acting as a delay. Once the countdown is finished, `s4` is reinitialized to the wait value, and if not all lights are on (checked by comparing `s2` and `s3`), the program jumps back to `loopi` to turn on the next light.

Once all lights are on (when `s2` equals `s3`), `s5` is set to 0, turning off all the lights, and the program returns from the `init` subroutine using the `RET` instruction.

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

---

The Program Counter (PC) module serves to control the instruction flow within the processor. The module includes a register to store the PC and combinational logic to determine the next PC value, labelled `PCNext`.

Inputs to the PC module include:
- `rst`: A reset input that sets the PC to a known start address when activated.
- `clk`: The clock signal that coordinates the updating of the PC register.
- `PCsrc`: A 2-bit signal that selects the next value of the PC.
- `ALUResult`: The output from the ALU for computing jump addresses.
- `ImmEXT`: An immediate value used to calculate the target address for branch instructions.

The `PCNext` value is calculated using a case statement based on the `PCsrc` signal. If `PCsrc` is `00`, the PC is incremented by four for sequential instruction execution. If `PCsrc` is `01`, the PC is set to the sum of the current PC and `ImmEXT`, facilitating immediate branching. If `PCsrc` is `10`, the PC uses the ALU result, aligned to a 4-byte boundary, for jump instructions.

The PC is updated with a sequential `always_ff` block that triggers on the positive edge of the clock or the reset signal. Upon reset, the PC is initialized to `32'hbfc00000`. Otherwise, it takes the value computed as `PCNext`.

This provides the necessary control for sequential execution, branching, and jumping within the processor, supporting our diverse set of instructions.

### Control Unit

The [Control](rtl/control.sv) module, as its name implies, serves to control the flow of data between each module in the processor; this is done by controlling the select signal of multiplexers that are found in between the dfferent modules. In addition, it also sends control signals to the different modules to instruct them which operation does each one of them should perform and which operand should participate in the operation to perform the correct instruction as described by the machine code.

The control unit receives the instruction  from the instruction memory in the form of a 32-bit machine code which it uses to decide which control signal to send to the different modules or multiplexers to ensure the correct operation is being performed by the processor.

These distinct instructions can be uniquely identified by the `opcode`, `funct3` and `funct7` of the machine code from which the control unit based its decision from. 

To implement the control unit, I used the `case` functionality to differentiate the `opcode`, `funct3`, `funct7` and in each instances send different control signals to the rest of the processsor accordingly.

the output control signal is distinct  for different `opcode`, `funct3`,  `funct7`. The control unit in our implementation output the following control signals accordingly to the other modules such that correct operation is performed:

| Control Signal | Function |
| -------- | :--------: |
| `PCsrc` | choose `PC` mode: plus4 (0), immediate (1), ALUresult (2)|
|`ResultSRC`|choose which data to store in the register: ALUresult (0), memory (1), PC (2) |
|`Immsrc`| Choose which bits reconstruction is performed in [sign extend](rtl/sextend.sv) |
| `ALUcontrol`| Choose which type of operation to perform in the ALU as prescribed in ALU section |
| `addressingcontrol`| choose which type of byte reconstruction to perform in data memory for load and store instructions|



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
| 3'b000| {{20{Immediate[31]}}, Immediate[31:20]} | I-type |
| 3'b001| {{20{Immediate[31]}}, Immediate[31:25], Immediate[11:7]}| S-type|
| 3'b010| {{20{Immediate[31]}}, Immediate[7], Immediate[30:25], Immediate[11:8], 1'b0}|  B-type|
| 3'b011| {{12{Immediate[31]}},  Immediate[19:12], Immediate[20], Immediate[30:21], 1'b0} | J-type|
| 3'b100| {Immediate[31:12], 12'b0}| U-type|
## Final Schematic for Single Cycle CPU

![SchematicSingleCycle](https://github.com/Arc-Cloud/Team04-RISCV-Proj/assets/112711409/6a9d08f6-bb25-4a32-a1fb-9c997b6a24d3)


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

### Contributions
| Component | Maximilian &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| Ilan &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| Hanif &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| Idrees &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| -------- | :--------: | :--------: | :--------: | :--------: |
| PC.sv | | | L |
| alu.sv | | L | |
| control_unit.sv | L | | |
| decode.sv | L | | |
| execute.sv | | L | |
| execute_data_file.sv | | L | |
| extend.sv | L | | |
| fetch.sv | | | L |
| instmem.sv | | | L |
| mux.sv | | L | |
| register_file.sv | L | | |
| Data_mem.sv| | | L |
| Memory.sv | | | L |

Legend: `L` = Lead `C` = Contributor


Info on Pipelined RV32I Design ....

# Data Memory Cache

| Component | Maximilian | Ilan | Hanif | Idrees |
| -------- | :--------: | :--------: | :--------: | :--------: |
| | | | |
| | | | |
| | | | |

Legend: L = Lead C = Contributor


Info on Data Memory Cache ....




