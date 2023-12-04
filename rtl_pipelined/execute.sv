`include "../rtl_pipelined/execute_data_file.sv"
`include "../rtl_pipelined/alu.sv"
`include "../rtl_pipelined/mux.sv"

module execute #(
    parameter DATA_WIDTH = 32,
    parameter REG_FILE_ADDRESS_WIDTH = 5
)(
    input logic clk,
    input logic RegWriteE,
    input logic [1:0] ResultSrcE,
    input logic MemWriteE,
    input logic JumpE,
    input logic BranchE,
    input logic [3:0] ALUControlE,
    input logic AluSrcE,
    input logic [REG_FILE_ADDRESS_WIDTH-1:0] RD1E,
    input logic [REG_FILE_ADDRESS_WIDTH-1:0] RD2E,
    input logic [DATA_WIDTH-1:0] PCE,
    input logic [REG_FILE_ADDRESS_WIDTH-1:0] RdE,
    input logic [DATA_WIDTH-1:0] ExtImmE,
    input logic [DATA_WIDTH-1:0] PCPlus4E,
    input logic [1:0] ForwardAE,
    input logic [1:0] ForwardBE, 
    input logic [DATA_WIDTH-1:0] ResultW,

    output logic PCSrcE,
    output logic [DATA_WIDTH-1:0] PCTargetE,

    output logic [DATA_WIDTH-1:0] RegWriteM,
    output logic [1:0] ResultSrcM,
    output logic MemWriteM,
    output logic [DATA_WIDTH-1:0] ALUResultM,
    output logic [DATA_WIDTH-1:0] WriteDataM,
    output logic [REG_FILE_ADDRESS_WIDTH-1:0] RdM,
    output logic [DATA_WIDTH-1:0] PCPlus4M
);

    logic [DATA_WIDTH-1:0] SrcAE;
    logic [DATA_WIDTH-1:0] SrcBE;
    logic [DATA_WIDTH-1:0] WriteDataE;
    logic [DATA_WIDTH-1:0] ALUA_forward_inputs;
    logic [DATA_WIDTH-1:0] ALUB_forward_inputs;
    logic [DATA_WIDTH-1:0] ALUResultE;
    logic ZeroE;

    always_comb begin
        ALUA_forward_inputs = {RD1E, ResultW, ALUResultM, {DATA_WIDTH{1'b0}}};
        ALUB_forward_inputs = {RD2E, ResultW, ALUResultM, {DATA_WIDTH{1'b0}}};
        SrcBE = (AluSrcE) ? ExtImmE : WriteDataE; 
        PCSrcE = (BranchE & ZeroE) | JumpE;
        PCTargetE = PCE + ExtImmE;
    end

    mux MUXA(
        .inputs(ALUA_forward_inputs),
        .select(ForwardAE),

        .outputs(SrcAE)
    );

    mux MUXB(
        .inputs(ALUB_forward_inputs),
        .select(ForwardBE),

        .outputs(WriteDataE)
    );


    alu ALU(
        .SrcA(SrcAE),
        .SrcB(SrcBE),
        .ALUControl(ALUControlE),
        
        .Zero(ZeroE),
        .ALUResult(ALUResultE)
    );

    execute_reg_file ERF(
        .clk(clk),
        .RegWriteE(RegWriteE),
        .ResultSrcE(ResultSrcE),
        .MemWriteE(MemWriteE),
        .ALUResultE(ALUResultE),
        .WriteDataE(WriteDataE),
        .RdE(RdE),
        .PCPlus4E(PCPlus4E),

        .RegWriteM(RegWriteM),
        .ResultSrcM(ResultSrcM),
        .MemWriteM(MemWriteM),
        .ALUResultM(ALUResultM),
        .WriteDataM(WriteDataM),
        .RdM(RdM),
        .PCPlus4M(PCPlus4M)
    );

endmodule
