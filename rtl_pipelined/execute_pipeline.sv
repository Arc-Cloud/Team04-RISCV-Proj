module execute_pipeline #(
    parameter DATA_WIDTH = 32
) (
    input logic                   clk,
    input logic                   flush,
    // control signals
    input logic                   RegWriteD,
    input logic [1:0]             ResultSrcD,
    input logic                   MemWriteD,
    input logic                   JumpD,
    input logic                   BranchD,
    input logic [3:0]             ALUControlD,
    input logic                   ALUSrcD,
    // data signals
    input logic [DATA_WIDTH-1:0]  RD1D,
    input logic [DATA_WIDTH-1:0]  RD2D,
    input logic [DATA_WIDTH-1:0]  PCD,
    input logic [4:0]             Rs1D,
    input logic [4:0]             Rs2D,
    input logic [4:0]             RdD,
    input logic [DATA_WIDTH-1:0]  ExtImmD,
    input logic [DATA_WIDTH-1:0]  PCPlus4D,
    input logic                   JALRInstrD,
    input logic [2:0]             AddressingControlD,

    // control signals
    output logic                  RegWriteE,
    output logic [1:0]            ResultSrcE,
    output logic                  MemWriteE,
    output logic                  JumpE,
    output logic                  BranchE,
    output logic [3:0]            ALUControlE,
    output logic                  ALUSrcE,
    // data signals
    output logic [DATA_WIDTH-1:0] RD1E,
    output logic [DATA_WIDTH-1:0] RD2E,
    output logic [DATA_WIDTH-1:0] PCE,
    output logic [4:0]            Rs1E,
    output logic [4:0]            Rs2E,
    output logic [4:0]            RdE,
    output logic [DATA_WIDTH-1:0] ExtImmE,
    output logic [DATA_WIDTH-1:0] PCPlus4E,
    output logic                  JALRInstrE,
    output logic [2:0]            AddressingControlE
);

always_ff @(posedge clk) begin
    if(flush) begin 
        RegWriteE <= 1'b0;
        ResultSrcE <= 2'b0;
        MemWriteE <= 1'b0;
        JumpE <= 1'b0;
        BranchE <= 1'b0;
        ALUControlE <= 4'b0;
        ALUSrcE <= 1'b0;
        RD1E <= 32'b0;
        RD2E <= 32'b0;
        PCE <= 32'b0;
        Rs1E <= 5'b0;
        Rs2E <= 5'b0;
        RdE <= 5'b0;
        ExtImmE <= 32'b0;
        PCPlus4E <= 32'b0;
        JALRInstrE <= 1'b0;
        AddressingControlE <= 3'b0;
    end
    else begin
        RegWriteE <= RegWriteD;
        ResultSrcE <= ResultSrcD;
        MemWriteE <= MemWriteD;
        JumpE <= JumpD;
        BranchE <= BranchD;
        ALUControlE <= ALUControlD;
        ALUSrcE <= ALUSrcD;
        RD1E <= RD1D;
        RD2E <= RD2D;
        PCE <= PCD;
        Rs1E <= Rs1D;
        Rs2E <= Rs2D;
        RdE <= RdD;
        ExtImmE <= ExtImmD;
        PCPlus4E <= PCPlus4D;
        JALRInstrE <= JALRInstrD;
        AddressingControlE <= AddressingControlD;
    end
end


endmodule
