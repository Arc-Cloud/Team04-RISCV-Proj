module execute #(
    parameter DATA_WIDTH = 32,
    parameter REG_FILE_ADDRESS_WIDTH = 5,
    parameter NUM_INPUTS = 4
)(
    //input logic clk, // not used

    input logic JumpE,
    input logic BranchE,
    input logic [3:0] ALUControlE,
    input logic AluSrcE,
    input logic [REG_FILE_ADDRESS_WIDTH-1:0] RD1E,
    input logic [REG_FILE_ADDRESS_WIDTH-1:0] RD2E,
    input logic [DATA_WIDTH-1:0] PCE,

    input logic [DATA_WIDTH-1:0] ExtImmE,
    input logic [1:0] ForwardAE,
    input logic [1:0] ForwardBE, 
    input logic [DATA_WIDTH-1:0] ResultW,
    input logic [DATA_WIDTH-1:0] ALUResultM,

    output logic PCSrcE,
    output logic [DATA_WIDTH-1:0] PCTargetE,
    output logic [DATA_WIDTH-1:0] ALUResultE,
    output logic [DATA_WIDTH-1:0] WriteDataE
);

    logic [DATA_WIDTH-1:0] SrcAE;
    logic [DATA_WIDTH-1:0] SrcBE;
    logic [DATA_WIDTH-1:0] ALUA_inputs [0:NUM_INPUTS-1];
    logic [DATA_WIDTH-1:0] ALUB_inputs [0:NUM_INPUTS-1];
    logic ZeroE;

    always_comb begin
        ALUA_inputs = {RD1E, ResultW, ALUResultM, {DATA_WIDTH{1'b0}}};
        ALUB_inputs = {RD2E, ResultW, ALUResultM, {DATA_WIDTH{1'b0}}};
        SrcBE = (AluSrcE) ? ExtImmE : WriteDataE; 
        PCSrcE = (BranchE & ZeroE) | JumpE;
        PCTargetE = PCE + ExtImmE;
    end

    mux MUXA(
        .inputs(ALUA_inputs),
        .select(ForwardAE),

        .outputs(SrcAE)
    );

    mux MUXB(
        .inputs(ALUB_inputs),
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

endmodule
