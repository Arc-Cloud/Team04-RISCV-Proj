module memory #(
    parameter DATA_WIDTH = 32
)(
    input logic clk,
    input logic [DATA_WIDTH-1:0] ALUResultM,
    input logic [DATA_WIDTH-1:0] WriteDataM,
    input logic MemWriteM,
    input logic [2:0] AddressingControlM,

    output logic [DATA_WIDTH-1:0] ReadDataM
);

data_mem data_memory(
    .clk(clk),
    .A(ALUResultM),
    .WD(WriteDataM),
    .WE(MemWriteM),
    .AddressingControl(AddressingControlM),

    .RD(ReadDataM)
);

endmodule
