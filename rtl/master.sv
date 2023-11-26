`include "../rtl/orange.sv"
`include "../rtl/green.sv"
`include "../rtl/P_C.sv"

module master #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 32
)(
    input logic clk,
    input logic rst,
    input logic trigger,
    input logic [4:0] testRegAddress,
    output logic [DATA_WIDTH-1:0] Result
);

logic [DATA_WIDTH-1:0] Instr;
logic [ADDR_WIDTH-1:0] PC;
logic [DATA_WIDTH-1:0] PCPlus4;

logic PCsrc;

logic [1:0] ResultSrc;
logic MemWrite;
logic [3:0] ALUControl;
logic ALUSrc;
logic RegWrite;
logic [DATA_WIDTH-1:0] ImmExt;
logic Zero;

P_C P_C(
    //intputs
    .clk(clk),
    .rst(rst),
    .PCsrc(PCsrc),
    .ImmEXT(ImmExt),

    //output
    .PC(PC),
    .PCPlus4(PCPlus4)
);

// green contains Instruction Memory and Control Unit + Extend
green green(
    //inputs
    .A(PC),
    .Zero(Zero),

    //outputs
    .PCsrc(PCsrc),
    .ResultSrc(ResultSrc),
    .MemWrite(MemWrite),
    .ALUcontrol(ALUControl),
    .ALUsrc(ALUSrc),
    .RegWrite(RegWrite),
    .ImmExt(ImmExt),
    .Instr(Instr)
);

// orange contains Register File ALU and Data Memory
orange orange(
    //inputs
    .clk(clk),
    .rs1(Instr[19:15]),
    .rs2(Instr[24:20]),
    .rd(Instr[11:7]),
    .WE3(RegWrite),
    .AluSrc(ALUSrc),
    .ALUControl(ALUControl),
    .ImmExt(ImmExt),
    .WE(MemWrite),
    .ResultSrc(ResultSrc),
    .PCPlus4(PCPlus4),
    .shift_right_type(0),
    .testRegAddress(testRegAddress),

    //outputs
    .zero(Zero),
    .Result(Result)
);

endmodule
