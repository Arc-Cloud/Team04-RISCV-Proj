# Team04-RISCV-CPU

[Jump](#single-cycle-rv32i-design) to Single Cycle CPU Documentation 

[Jump](#pipelined-rv32i-design) to Pipelined CPU Documentation

[Jump](#cache) to Cached CPU Documentation

**Important: `rtl_pipelined` implements pipelining with cache functionality.**

## Repo Structure & Logic

As a team we decided to manage our repo in the following manner:
- Maintain a main branch containing the latest finalized and tested implementations of all CPU versions in their respective folders.
- Once a cpu version has been complemeted we merge all relevant branches into the main and then delete all unessecary branches for repo cleanliness before moving onto the next version of the cpu

This approach provides a clear overview of our current progress, ensuring a clean and easily interpretable repository during examination.

## Details & Personal Statements
| Name &nbsp; &nbsp; | Github | CID &nbsp; &nbsp; &nbsp;| Email &nbsp; | Link to Personal Statements|
| -------- | -------- | -------- | -------- | -------- |
| Maximilian | [Arc-Cloud](https://github.com/Arc-Cloud)| 02286647 | maximilian.adam22@imperial.ac.uk | [Max's Statement](statements/Maximilian.md)
| Ilan | [Ilan's github](https://github.com/IlanIwumbwe) | 02211662 | ilan.iwumbwe22@imperial.ac.uk | [Ilan's Statement](statements/Ilan.md) 
| Idrees | [idrees-mahmood](https://github.com/idrees-mahmood) | 02061101| idrees.mahmood22@imperial.ac.uk | [Idrees's Statement](statements/Idrees.md) 
| Hanif | [Xylemeister](https://github.com/Xylemeister)| 02234780 | hanif.rais22@imperial.ac.uk | [Hanif's Statement](statements/Hanif.md) 

## Overall CPU Schematic

![CPU with Pipelining and Integrated Cache](/imgs/Overall%20CPU%20Design.jpeg)

## Testing the CPU

- There is a script located in the root of the directory called start.sh
- This links to a master script contained within /testing/Master_test
- Executing the script displays a menu that enables the execution of various programs on the specified CPU.

In order to view values in a particular register of the CPU, we added a signal `testRegAddress` which is controlled at the top level module, and outputs data from a given register at the signal `testRegData`. This allows use to use register data to view outputs on vbuddy, which is useful for pdf plots and f1 program.

### When testing F1 and pdf:

- Move into the `testing/Master_test` directory
- Choose the `cpu_tb.cpp` test bench using single cycle, and `pipe_cpu_tb.cpp` if testing pipelined cpu
- Both test benches write to CPU.vcd

Below is a code snippet of the test bench. 

```C++
int main(int argc, char **argv, char **env) {
    int simcyc;
    int tick;

    char prog = argv[argc-1][0];

    Verilated::commandArgs(argc, argv);
    // init top verilog instance
    Vmaster* top = new Vmaster;
    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("CPU.vcd");

    //init Vbuddy
    if (vbdOpen()!=1) {
        std::cout << "vbuddy.cfg located in /testing/Master_test/" << std::endl;
        return(-1);
    }
    vbdHeader("CPU CW");

    // intialise
    top->clk = 1;
    top->rst = 0;
    top->trigger = 0;

    if (prog == 'a') {
        // We run the PDF program
        top->testRegAddress = 10;
        std::cout << "Running PDF program" << std::endl;
    }
    else {
        top->testRegAddress = 21;
        std::cout << "Running other program" << std::endl;
    }
    
    // run simulation for MAX_SIM_CYC clock cycles
    for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
        // dump variables into VCD file and toggle clock
        for (tick=0; tick<2; tick++) {
            tfp->dump (2*simcyc+tick);
            top->clk = !top->clk;
            top->eval ();
        }

        // Test data
        if(simcyc > 1200000){
            vbdPlot(top->Result,0,255);
            vbdBar(top->Result & 0xFF);
            vbdCycle(simcyc);
        }

        // either simulation finished, or 'q' is pressed
        if (Verilated::gotFinish() || vbdGetkey()=='q')
            exit(0);
    }
    vbdClose();
    tfp->close();   
    exit(0);
}
```
- The master script written in /testing/Master_test automatically configures the outputs depending on the program being run by passing arguments on execution

### Testing Write Up
The tests for both single cycle and the pipelined CPU were written up [here](/testing/Test%20results/Testing%20Write%20up.md) and [here](/testing/Test%20results/Pipelining%20tests.md) respectively using programs specified in the testing folder.

### Testing videos
The following videos demonstrate the F1 program's functionality on a pipelined CPU with both data memory cache and instruction memory cache.

#### F1 Program:
https://github.com/Arc-Cloud/Team04-RISCV-Proj/assets/30900019/755c7d9f-5479-4415-ab45-808032728b06
#### PDF for Noisy:
https://github.com/Arc-Cloud/Team04-RISCV-Proj/assets/30900019/9afc98e6-b6ea-4232-8cef-47a439cc9091
#### PDF for gaussian:
https://github.com/Arc-Cloud/Team04-RISCV-Proj/assets/30900019/1cc1c504-8b78-47e6-87dc-b847287084ad
#### PDF for sine:
https://github.com/Arc-Cloud/Team04-RISCV-Proj/assets/30900019/32c66774-a304-4483-9516-941c7c4444fc
#### PDF for Triangle:
https://github.com/Arc-Cloud/Team04-RISCV-Proj/assets/30900019/2f81b514-5a44-40d3-9832-2ad88b173a33
 

# Single Cycle RV32I Design
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
As a team we produced the following [f1_asm.s](testing/F1%20program%20test/f1_asm.s) code. 

Simulating sequential illumination of Formula 1 start lights, where each light is represented by a bit in register s2 that is turned on one after another and then turned off after a specified duration.

The program commences at the `main` label, where the `JAL` instruction jumps to the `init` label, storing the return address in the `ra` register. The infinite loop is established with the `j main` instruction, which causes the program to jump back to `main` continuously.

The `init` label initializes the registers as follows:
- `s2` is set to `0x0` and will be used to track the status of the lights.
- `s3` is loaded with `0xff`, representing the state where all lights are illuminated.
- `s5` is initialized to `0x0` and will store the result of the logical AND operation.
- `s4` is set to `0x4`, serving as a timer for the delay loop.

The `loopi` label marks the start of the light sequence. The `slli` instruction shifts `s2` to the left by one bit, and `addi` then increments `s2` by 1, simulating the activation of the next light in the sequence. The `and` operation updates `s5` with the current lights status.

At the `wait` label, a delay loop is implemented using `s4`. The `addi` instruction decrements `s4` by one until `s4` equals zero, upon which `s4` is reset to `0x4`. If not all the lights have been activated (`s2` does not equal `s3`), the program branches back to `loopi` to continue the sequence.

Once the sequence is complete and all lights are on (`s2` equals `s3`), `s5` is reset to `0`, turning off all the lights. The program then exits the `init` subroutine with the `RET` instruction.

### ALU

[Implemented here](rtl/alu.sv)

The ALU performs arithmetic and logic operations on two operands. While all necessary arithmetic operations for RISCV instructions are implemented, not all are utilised. This design choice facilitates the addition of future instruction implementations if time permits. 
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

The [Program Counter](/rtl/P_C.sv) module serves to control the instruction flow within the processor. The module includes a register to store the PC and combinational logic to determine the next PC value, labelled `PCNext`.

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

The data and instruction memory were initially modelled as 32-bit words per memory location. This worked well for Lab4 and initially for the project, but not so well when we decided that we wanted to implement all load/store half and byte instructions. A load-store unit was suggested by Max, which would work by masking out relevant bits from a 32-bit word in the case of half / byte addressing. Hanif suggested modelling all memory as a byte per memory location, which would simplify things greatly. Ilan implemented this for the [data memory](rtl/data_mem.sv), and [instruction memory](rtl/instmem.sv). 

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
  
*  `blt` `bge` `bgeu` `bltu` have only been implemented in the pipelined version. Single cycle only implements `beq` and `bne`.

## Final Schematic for Single Cycle CPU

![Single Cycle CPU Schematic](imgs/SingleCycleCpu.jpeg)

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
| pipelined_cpu.sv | L | L | | C
| register_file.sv | L | | |
| writeback.sv | | L | | C
| writeback_pipeline.sv | | L | | C
| hazard_unit.sv | | L | | 

`mux.sv` is a 4 input multiplexer used as 3 instances in the architecture.

Legend: `L` = Lead `C` = Contributor

## Planning

We met as a team and began by examining the schematic for the pipelined cpu in lectures, modifying it for our own design.

Once this was done each team member was assigned a stage to work on and we began our implementation of the pipelined cpu, keeping frequent communication between team members to ensure each module interfaced correctly with one another.

## Implementation

### Changes to Existing Modules

#### ALU Pipelined

Additions were made to the [alu block](rtl_pipelined/alu.sv). It implements the rest of the branch type instructions, by setting the `Zero` flag high whenever a branch test is passed for example, for `blt`, if `SrcA < SrcB`, `Zero` is high. This means that if the current instruction in execute stage happens to be a branch type instruction and the test is passed, `BranchE` will be high from the control unit, and so will `Zero` from the ALU. As such, `ALUSrc` will be high, and a branch will be effected. 

#### Control Unit Pipelined

The improvements in the control unit module improve efficiency, readability, and robustness of control logic. This includes better handling of instruction types, streamlined input processing, and the introduction of new control signals for enhanced functionality. 
key differences:

- Rename signals like `RegWrite`, `ALUControl`, `MemWrite`, etc. to `RegWriteD`, `ALUControlD`, `MemWriteD`, to prepare for pipeline integration

- Remove the `zero` input and reduce `funct7` to a single logic bit, streamlining inputs

- Introduce new output signals like `JumpD`, `BranchD`, and `JALRInstrD`. These signals add more control functionality, offering finer control over jump, branch, and JALR (Jump and Link Register) instructions.

- Enhances the control logic for B-type instructions by including additional operations (`blt`, `bge`, `bltu`, `bgeu`). case structure simplified for better readability and maintenance.

- default case added in the main `case` statement, ensuring that all control signals are explicitly set to a known state when an unrecognized opcode is encountered.

- more cleanly structured with consistent indentation and improved commenting, improving code readability and maintainability.

### Pipelining

The pipeline of each stage is the one to its left.

We decided on this convention since we thought it would be easier to reason between stalling and flushing. Stalling implies that the inputs to the stage should remain unchanged, whereas flushing entails zeroing the inputs to the stage. As such, it made sense to define each pipeline of a stage to to the left of its corresponding stage. 

The hazard unit produces `StallFetch`, `StallDecode`, `FlushExecute`, `FlushDecode`. These are inputs to the relevant pipelines for those stages that need to be flushed or stalled. Inside the pipelined, when stall signal is high, the signals at the pipeline's inputs are not passed to the outputs, while when flush signal is high, the outputs are low. 

Each pipeline is in its own module, and those that are flushed / stalled at some point have internal signals to control that. 
Each stage is in its own module; the inputs to the module are those that are actually used for computing some value in that stage, while those that aren't used are connected directly to the next pipeline in the [top level module](rtl_pipelined/pipelined_cpu.sv). 

### Hazard Unit

The [Hazard unit](./rtl_pipelined/hazard_unit.sv) allows for the pipelined CPU to be able to perform instructions correctly without incurring delays for some special cases to ensure that it is as efficient as possible.

There are 3 different cases that we encountered that poses a challenge to pipelining and may result in an error if not taken care of which are the following:
1. When we use a register as an operand that was written to in the previous cycle. (RAW hazard)
2. When we have a branch instruction where we only know if we jump or not two cycles later in the execute stage.
3. Load instructions where it takes an extra cycle to load data. 

Thus, to solve these possible issues that the processor might encounter with pipelining we implement the following in our design:
1. Forwarding: allows the value of a register to be used in an operation right after it was written without having to wait for it to go through all the pipelining stages. 
2. Stalling: Stalling a stage means to maintain its state, so the inputs to the stage should not change on the next clock cycle. This allows for load instruction to have its values from memory to be loaded into the writeback stage so that it can be forwarded onto the execute stage.
3. Flushing: This resets the output of the pipeline flip-flops; This is very useful, for example in the case of branch, we do not know whether to jump or not until the branch instruction is in the execution stage. That means the next instruction in the instruction memory would be loaded onto the decode stage. This would create an error if the jump actually occurs, therefore we need to flush the decode stage when jump happens as if the instruction had never been loaded to the decode stage.

All three solutions/operations mentioned above are implemented in our pipelined CPU. Each operation may be used individually or simultaneously for specific cases/instruction. The control signal for forwarding, flush and stall are all produced/controlled by the hazard unit. RAW hazards are mitigated by forwarding from the Writeback or memory stages into the execute stage. If the current instruction in execute stage has a source register that's the same as the destination register as an instruction currently in writeback or memory stage, we forward data from writeback or memory stages respectively. We also only forward data from instructions that were going to write to a register. The zero register is never forwarded because it never has meaningful data being written to it (as it is hardwired to zero).

Lw issue is solved by stalling the decode and fetch stages. As such, we must flush the execute stage to prevent incorrect data from propagating forward.

If a control hazard is detected, the execute and decode stages are flushed (2 instructions after branch instruction are flushed) before moving to correct instruction. 

### New Instructions

#### B-Type
`blt` `bge` `bgeu` `bltu`

##

## Finalised Pipelined CPU Schematic

![PipelinedCPUSchematic](/imgs/PipelinedCPU.jpeg)

# Cache

## Cache specifications

word = 32

| Version | Capacity(words) | Words written at once | Blocks in cache | Blocks / set | Sets
| -------- | :--------: | :--------: | :--------: | :--------: | :--------: |
| Direct mapped | 8 | 1 | 8 | 1 | 8 |
| 2 way assosiative | 8 | 1 | 8 | 2 | 4 |

*Only new components have been considered in this table.*

| Component | Maximilian | Ilan | Hanif | Idrees |
| -------- | :--------: | :--------: | :--------: | :--------: |
| [direct_mapped.sv](rtl_pipelined/direct_mapped.sv) | | C | L |
| [fetch.sv](rtl_pipelined/fetch.sv) (cache version) | | | L |
| [Nway_assos.sv](rtl_pipelined/Nway_assos.sv) | | L | C |

Legend: L = Lead C = Contributor

We introduced caching mechanisms for both instructions and data. Our initial focus was on configuring the instruction cache due to its relative simplicity; it only required adjustments in one pipelined stage. After successfully implementing and testing the instruction cache, we proceeded to tackle the data cache. We created two SystemVerilog blocks for direct-mapped and two-way associative configurations, seamlessly integrating them into the fetch and execute stages for our instruction and data caches, respectively.


## Proof that cache is being used


**If the following videos do not work, they are contained within the /imgs folder**

https://github.com/Arc-Cloud/Team04-RISCV-Proj/assets/33992400/e28dd883-036e-4780-bffe-a70179a75b80



The video above is a screen capture of waveforms produced when CPU with data cache is tested on [the assembly program from lectures](testing/Data%20cache%20test/dcache.asm).

`PCE` shows memory address of the instruction currently in execute stage. We see that `useCacheM` is high when `PCE = 0x10, 0x14, 0x18`. At these points, the instruction in memory stage is each of the lw instructions, and `useCacheM` is high only for lw instructions, so this works as expected. We also see that we get no hits, as expected.


Next we get cache hits for instructions from `0x08 and 0x14`, but `useCacheM` is high only for `PCE = 0x10, 0x14, 0x18`; only the lw instructions. So the hit we get by the branch instruction is meaningless, we only consider hits by the load instructions. 

Running through the loop, we see that this pattern continues until the loop ends.

The next 2 videos are results for this program:

```
    addi s0, zero, 5
    addi s1, zero, 0
    LOOP: beq s0, zero, DONE
    lw s2, 0x4(s1)
    lw s4, 0x24(s1)
    addi s0, s0, -1
    j LOOP
    DONE:
```
This should give us 100% miss rate on direct mapped cache, and the same waveforms as above for 2 way assosiative.

https://github.com/Arc-Cloud/Team04-RISCV-Proj/assets/56346800/0e2d3c0e-fc50-4caa-a0e8-0e125ea84aee


The video above shows 2 way assosiative cache working as expected. We get the same waveforms as for direct mapped cache without conflicts


https://github.com/Arc-Cloud/Team04-RISCV-Proj/assets/56346800/2055bd05-0e45-4c27-9312-2f3b36f71224


The video above shows direct mapped assosiative 100% miss rate

We see that we always have `useCacheM` high when `PCE = 0x10, 0x14`, which is when either one of the load instructions are in the memory stage. We see that `useCacheM` is always low as expected.

## Cache Schematic

![Cache Integrated with Pipelined CPU](/imgs/Integrated%20Cache.jpeg)
