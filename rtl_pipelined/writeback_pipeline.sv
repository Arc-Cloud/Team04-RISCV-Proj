module writeback_pipeline#(
    parameter DATA_WIDTH = 32
)(
    input logic clk,
    input logic RegWriteM,
    input logic [1:0] ResultSrcM,
    input logic [DATA_WIDTH-1:0] ALUResultM,
    input logic [DATA_WIDTH-1:0] ReadDataM,
    input logic RdM,
    input logic [DATA_WIDTH-1:0] PCPlus4M,

    output logic RegWriteW,
    output logic [1:0] ResultSrcW,
    output logic [DATA_WIDTH-1:0] ALUResultW,
    output logic [DATA_WIDTH-1:0] ReadDataW,
    output logic RdW,
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
