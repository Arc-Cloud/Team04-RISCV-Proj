module execute_pipeline #(
    parameter DATA_WIDTH = 32
)(
    input logic                 clk,
    input logic                 en,
    input logic                 flush,
    // control signals
    input logic                 RegWriteD,
    input logic [1:0]           ResultSrcD,
    input logic                 MemWriteD,
    input logic                 JumpD,
    input logic                 BranchD,
    input logic [3:0]           ALUControlD,
    input logic                 ALUSrcD,
    // data signals
    input logic [DATA_WIDTH-1]  RD1,
    input logic [DATA_WIDTH-1]  RD2,
    input logic [DATA_WIDTH-1]  PCD,
    input logic [4:0]           Rs1D,
    input logic [4:0]           Rs2D,
    input logic [4:0]           RdD,
    input logic [DATA_WIDTH-1]  ExtImmD,
    input logic [DATA_WIDTH-1]  PCPlus4D,
    input logic                 JALRInstrD
    input logic [2:0]           AddressingControlD

    // control signals
    output logic                RegWriteE,
    output logic [1:0]          ResultSrcE,
    output logic                MemWriteE,
    output logic                JumpE,
    output logic                BranchE,
    output logic [3:0]          ALUControlE,
    output logic                ALUSrcE,
    // data signals
    output logic [DATA_WIDTH-1] RD1E,
    output logic [DATA_WIDTH-1] RD2E,
    output logic [DATA_WIDTH-1] PCE,
    output logic [4:0]          Rs1E,
    output logic [4:0]          Rs2E,
    output logic [4:0]          RdE,
    output logic [DATA_WIDTH-1] ExtImmE,
    output logic [DATA_WIDTH-1] PCPlus4E,
    output logic                JALRInstrE
    output logic [2:0]          AddressingControlE
);



always_ff @(posedge clk) begin
    if(flush) begin 
        RegWriteE <= 32'b0;
        ResultSrcE <= 32'b0;
        MemWriteE <= 32'b0;
        JumpE <= 32'b0;
        BranchE <= 32'b0;
        ALUControlE <= 32'b0;
        ALUSrcE <= 32'b0;
        RD1E <= 32'b0;
        RD2E <= 32'b0;
        PCE <= 32'b0;
        Rs1E <= 32'b0;
        Rs2E <= 32'b0;
        RdE <= 32'b0;
        ExtImmE <= 32'b0;
        PCPlus4E <= 32'b0;
        JALRInstrE <= 32'b0;
        AddressingControlE <= 32'b0;
    end
    else if (en) begin
        RegWriteE <= RegWriteD;
        ResultSrcE <= ResultSrcD;
        MemWriteE <= MemWriteD;
        JumpE <= JumpD;
        BranchE <= BranchD;
        ALUControlE <= ALUControlD;
        ALUSrcE <= ALUSrcD;
        RD1E <= RD1;
        RD2E <= RD2;
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
