module writeback_pipeline#(
    parameter DATA_WIDTH = 32,
    parameter REG_FILE_ADDRESS_WIDTH = 5
)(
    input logic clk,
    input logic RegWriteM,
    input logic [1:0] ResultSrcM,
    input logic [DATA_WIDTH-1:0] ALUResultM,
    input logic [DATA_WIDTH-1:0] ReadDataM,
    input logic [REG_FILE_ADDRESS_WIDTH-1:0] RdM,
    input logic [DATA_WIDTH-1:0] PCPlus4M,

    output logic RegWriteW,
    output logic [1:0] ResultSrcW,
    output logic [DATA_WIDTH-1:0] ALUResultW,
    output logic [DATA_WIDTH-1:0] ReadDataW,
    output logic [REG_FILE_ADDRESS_WIDTH-1:0] RdW,
    output logic [DATA_WIDTH-1:0] PCPlus4W
);

    always_ff @(posedge clk)begin
        ALUResultW <= ALUResultM;
        ReadDataW <= ReadDataM;
        RdW <= RdM;
        PCPlus4W <= PCPlus4M;
        RegWriteW <= RegWriteM;
        ResultSrcW <= ResultSrcM;
    end

endmodule
