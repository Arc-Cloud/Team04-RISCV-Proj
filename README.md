# Team04-RISCV-CPU

## Joint Statement

### Overall Approach
  - Complete lab 4 with design that works for 2 instructions, although not scalable
  - Restart with design that easily scales for more instructions
  - Start and complete single cycle CPU with as many instructions as possible
  

## Repo Structure & Logic
```
├───imgs/
│
├───rtl/
│
├───rtl_pipelined/
│
├───statements/
│
└───testing
    │   .DS_Store
    │   format_hex.py
    │   real_path.sh
    │   vbuddy.cfg
    │   vbuddy.cpp
    │
    ├───f1_asm test/
    │
    ├───Pipelined_CPU/
    │
    ├───Ref program test/
    │
    ├───Single_cycle_CPU/
    │
    ├───Test results/
    │
    ├───TestingForPC/
    │
    ├───Type B-J test/
    │
    ├───Type I test/
    │
    ├───Type I-S test/
    │
    └───Type R test/
```

As a team we decided to manage our repo in the following manner:
- Have one main where the current latest finalised and tested implementation of all versions of the cpu are kept in their individual folders
- Once a cpu version has been complemeted merge all relevant branches into the main and then delete all unessecary branches for repo cleanliness before moving onto the next version of the cpu

This method allowed us to have a clear insight into our overall current progress, and keep our repo clean and easily interpreted when viewed for examination. 

## Details & Personal Statements
| Name &nbsp; &nbsp; | Github | CID &nbsp; &nbsp; &nbsp;| Email &nbsp; | Link to Personal Statements|
| -------- | -------- | -------- | -------- | -------- |
| Maximilian | | | | [Max's Statement](statements/Maximilian.md)
| Ilan | | | | [Ilan's Statement](statements/Ilan.md) 
| Idrees | | | | [Idrees's Statement](statements/Idrees.md) 
| Hanif | Xylemeister | 02234780 | hhr22@ic.ac.uk | [Hanif's Statement](statements/Hanif.md) 


# Single Cycle RV32I Design
### Contributions
| Component | Maximilian &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| Ilan &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| Hanif &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| Idrees &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| -------- | :--------: | :--------: | :--------: | :--------: |
| alu.sv | C | L | | C
| control.sv | C | | L | C
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

To begin our Single Cycle CPU design we met as a team and outlined the key areas of the design and identified possible issues we might face in our implementation. 

We then created an initial overall logical flow for how our instructions will be intepreted, and drew up our design conventions to ensure compatibilty between individual parts of the CPU we each would proceed to work on.

Responsibilty was then subdivided for parts of the CPU to individual team members and we began working.

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
| 1111 | ALUResult = SrcB |

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

### Control Decoder Table
| Instruction Type | op | RegWrite | ALUSrc | MemWrite | PCSrc | ImmSrc | ResultSrc
| -------- | :--------: | :--------: | :--------: | :--------: | :--------: | :--------: | :--------: 
| R-Type (51) | 0110011 | 1 | 0 | 0 | 00 | xxx | xx
| B-Type (99) | 1100011 | 0 | 0 | 0 | 00/01 | 010 | xx
| I-Type (19) | 0010011 | 1 | 1 | 0 | 00 | 000 | 00
| I-Type (3) | 0000011 | 1 | 1 | 0 | 00 | 000 | 01
| I-Type (103) | 1100111 | 1 | 1 | 0 | 10 | 000 | 10 
| J-Type (111) | 1101111 | 1 | x | 1 | 01 | 011 | 10
| S-Type (35) | 0100011 | 0 | 1 | 1 | 00 | 001 | xx

`AdressingControl` and `ALUControl` Not included as they usually are used to choose case for the Instruction Type being performed 



### Sign Extension
 Immsrc is a control signal produced by the control unit given to the `sextend.sv` module. Its purpose is to reconstruct immediate from the instruction word as each type have their own way of mapping the immediate onto the machine code. This control signal basically tells the `sextend.sv` which type of instruction is currently performed so that the immediate can be extracted accordingly.
 
| ImmSrc| ImmExt | Instruction Type 
| -------- | :--------: | :--------: | 
| 3'b000| {{20{Immediate[31]}}, Immediate[31:20]} | I-type |
| 3'b001| {{20{Immediate[31]}}, Immediate[31:25], Immediate[11:7]}| S-type|
| 3'b010| {{20{Immediate[31]}}, Immediate[7], Immediate[30:25], Immediate[11:8], 1'b0}|  B-type|
| 3'b011| {{12{Immediate[31]}},  Immediate[19:12], Immediate[20], Immediate[30:21], 1'b0} | J-type|
| 3'b100| {Immediate[31:12], 12'b0}| U-type|

### Addressing Control

This control signal is produced by the control unit and is used to choose how we want to construct the bytes onto word in data memory. This is especially useful for instructions such as `lb`, `lh`, `sh`, `sb` where we only want to extract/store a byte or half of the word instead of the entire word.

The addressing control is 3 bits wide, the MSB is to choose between signed or unsigned extension and the remaining bits are used for choosing the different modes and they are allocated for each cases as follows:

| AdddressingControl [1:0] | AddressingControl [2] | Load Instruction type | Store Instruction type |
| -------- | :--------: | :--------: | :--------: |
| 2'b00  | 1'b0 | `lb` | `sb` |
| 2'b00 | 1'b1 |  `lbu` | xx |
| 2'b01 | 1'b0 | `lh` | `sh` |
| 2'b01 | 1'b1 | `lhu` | xx |
| 2'b10 | xx | `lw` | `sw` |

## Final Schematic for Single Cycle CPU

![Single Cycle CPU Schematic](imgs/SingleCycleCpu.jpeg)

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
#### U-Type
`lui`

# Pipelined RV32I Design

### Contributions
| Component | Maximilian &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| Ilan &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| Hanif &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| Idrees &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;|
| -------- | :--------: | :--------: | :--------: | :--------: |
| PC.sv | | | L |
| alu.sv | | L | | C
| control_unit.sv | L | | | C
| data_mem.sv| | | L | C
| decode.sv | L | | | C
| decode_pipeline.sv | | | L | 
| execute.sv | | L | | C
| execute_pipeline.sv | L | | | C
| extend.sv | L | | |
| fetch.sv | | | L |
| instmem.sv | | | L | C
| memory.sv | | | L | C
| memory_pipeline.sv | | L | | C
| mux.sv | | L | |
| pipelined_cpu.sv | L | L | | C
| register_file.sv | L | | |
| writeback.sv | | L | | C
| writeback_pipeline.sv | | L | | C

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




