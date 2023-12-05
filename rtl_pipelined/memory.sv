module memory #(
    parameter DATA_WIDTH = 32,
    parameter STORAGE_WIDTH = 8,
    parameter REG_FILE_ADDRESS_WIDTH = 5
)(
    input logic clk,
    input logic [DATA_WIDTH-1:0] ALUResultM,
    input logic [DATA_WIDTH-1:0] WriteDataM,
    input logic MemWriteM,
    input logic RegWriteM,
    input logic [2:0] AddressingControlM,
    input logic [1:0] ResultSrcM,
    input logic [REG_FILE_ADDRESS_WIDTH-1:0] RdM,
    input logic [DATA_WIDTH-1:0] PCPlus4M,
    output logic RegWriteW,
    output logic [1:0] ResultSrcW,
    output logic [DATA_WIDTH-1:0]ALUResultW,
    output logic [DATA_WIDTH-1:0] ReadDataW,
    output logic [REG_FILE_ADDRESS_WIDTH-1:0] RdW,
    output logic [DATA_WIDTH-1:0] PCPlus4W
);

logic [DATA_WIDTH-1:0] ReadDataM;

data_mem data(
    .clk(clk),
    .A(ALUResultM),
    .WD(WriteDataM),
    .RD(ReadDataM),
    .WE(MemWriteM),
    .AddressingControl(AddressingControlM)
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
