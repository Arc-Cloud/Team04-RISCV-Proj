module fetch #(
    parameter DATA_WIDTH = 32;
)(
    input logic clk,
    input logic rst,
    input logic  PCSrcE,
    input logic JALRinstrE,
    input logic [DATA_WIDTH-1:0]ALUResultE,
    input logic [DATA_WIDTH-1:0] PCtargetE,
    output logic [DATA_WIDTH-1:0] instrF,
    output logic [DATA_WIDTH-1:0] PCPlus4F,
    output logic [DATA_WIDTH-1:0] PCF
);



PC counter(
    .clk(clk),
    .reset(rst),
    .ALUResult(ALUResultE),
    .PCtargetE(PCtargetE),
    .PCSrcE(PCSrcE),
    .JALRinstr(JALRinstrE),
    .PCPlus4F(PCPlus4F),
    .PCF(PCF)
);

instmem memory(
    .A(PCF),
    .RD(instrF)
);

endmodule
