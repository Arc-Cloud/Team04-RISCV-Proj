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

// ---------- PC signals ------------
logic [DATA_WIDTH-1:0] Instr;
logic [ADDR_WIDTH-1:0] PC;
logic [DATA_WIDTH-1:0] PCPlus4;
// -------- control signals ----------
logic [1:0] PCSrc;
logic [1:0] ResultSrc;
logic MemWrite;
logic [3:0] ALUControl;
logic ALUSrc;
logic RegWrite;
// --------- ALU signals -------------
logic [DATA_WIDTH-1:0] ImmExt;
logic [DATA_WIDTH-1:0] ALUResult;
logic Zero;
// -----------------------------------

P_C P_C(
    //inputs
    .rst(rst),
    .clk(clk),
    .PCSrc(PCSrc),
    .ALUResult(ALUResult),
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
    .MemWrite(MemWrite),
    .RegWrite(RegWrite),
    .ALUControl(ALUControl),
    .ALUSrc(ALUSrc),
    .PCSrc(PCSrc),
    .ResultSrc(ResultSrc),
    .ImmExt(ImmExt),
    .Instr(Instr)
);

// orange contains Register File ALU and Data Memory
orange orange(
    //inputs
    .rs1(Instr[19:15]),
    .rs2(Instr[24:20]),
    .rd(Instr[11:7]),
    .ImmExt(ImmExt),
    .PCPlus4(PCPlus4),
    .clk(clk),
    .AluSrc(ALUSrc),
    .ALUControl(ALUControl),
    .WE(MemWrite),
    .WE3(RegWrite),
    .ResultSrc(ResultSrc),
    .shift_right_type(0),
    .testRegAddress(testRegAddress),
    .ALUResult(ALUResult),
    
    //outputs
    .Zero(Zero),
    .Result(Result),
    .ALUResult(ALUResult)
);

endmodule
