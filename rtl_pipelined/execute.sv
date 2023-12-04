module execute #(
    parameter DATA_WIDTH = 32,
    parameter REG_FILE_ADDRESS_WIDTH = 5
)(
    input logic RegWriteE,
    input logic [1:0] ResultSrc,
    input logic MemWriteE,
    input logic JumpE,
    input logic BranchE,
    input logic [3:0] ALUControl,
    input logic AluSrcE,
    input logic [REG_FILE_ADDRESS_WIDTH-1:0] RD1E,
    input logic [REG_FILE_ADDRESS_WIDTH-1:0] RD2E,
    input logic [DATA_WIDTH-1:0] PCE,
    input logic [REG_FILE_ADDRESS_WIDTH-1:0] RdE,
    input logic [DATA_WIDTH-1:0] ExtImmE,
    input logic [DATA_WIDTH-1:0] PCPlus4E,
    input logic [1:0] ForwardAE,
    input logic [1:0] ForwardBE, 

    output logic [REG_FILE_ADDRESS_WIDTH-1:0] Rs1E,
    output logic [REG_FILE_ADDRESS_WIDTH-1:0] Rs2E,




);



endmodule