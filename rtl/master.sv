module master #(
    parameter DATA_WIDTH = 32,
    parameter ADDR_WIDTH = 32
)(
    input logic CLK,
    input logic rst,
    input logic trigger,
    output logic [DATA_WIDTH-1:0] Result
);

logic [DATA_WIDTH-1:0] Instr;
logic [ADDR_WIDTH-1:0] PC;

logic [DATA_WIDTH-1:0] ImmEXT;
logic PCsrc;

logic ResultSrc;
logic MemWrite;
logic [2:0] ALUControl;
logic ALUSrc;
logic RegWrite;
logic [DATA_WIDTH-1:0] ImmExt;
logic Zero;


P_C P_C(
    .CLK(CLK),
    .rst(rst),
    .PCsrc(PCsrc),
    .ImmEXT(ImmEXT),
    .PC(PC)
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
    .ALUControl(ALUControl),
    .ALUSrc(ALUSrc),
    .RegWrite(RegWrite),
    .ImmExt(ImmExt),
    .Instr(Instr)
);

// orange contains Register File ALU and Data Memory
orange orange(
    //inputs
    .CLK(CLK),
    .A1(Instr[19:15]),
    .A2(Instr[24:20]),
    .A3(Instr[11:7]),
    .WE3(RegWrite),
    .ALUSrc(ALUSrc),
    .ALUControl(ALUControl),
    .ImmExt(ImmExt),
    .WE(MemWrite),
    .ResultSrc(ResultSrc),

    //outputs
    .Zero(Zero),
    .Result(Result)
);

endmodule
