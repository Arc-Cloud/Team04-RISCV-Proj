module fetch #(
    parameter DATA_WIDTH = 32
)(
    input logic clk,
    input logic reset,
    input logic enable,
    input logic  PCSrcE,
    input logic JALRinstrE,
    input logic [DATA_WIDTH-1:0]ALUResultE,
    input logic [DATA_WIDTH-1:0] PCTargetE,
    output logic [DATA_WIDTH-1:0] instrF,
    output logic [DATA_WIDTH-1:0] PCPlus4F,
    output logic [DATA_WIDTH-1:0] PCF
);



PC counter(
    .clk(clk),
    .reset(reset),
    .enable(enable),
    .ALUResultE(ALUResultE),
    .PCTargetE(PCTargetE),
    .PCSrcE(PCSrcE),
    .JALRinstr(JALRinstrE),
    .PCPlus4F(PCPlus4F),
    .PCF(PCF)
);

logic [DATA_WIDTH-1:0] memInstr;

instmem memory(
    .A(PCF),
    .RD(memInstr)
);

logic hit;
logic [DATA_WIDTH-1:0] cacheInstr;

direct_mapped cache (
    .clk(clk),
    .addresss(PCF),
    .datain(memInstr),
    .WE(~hit),

    .hit(hit),
    .dataout(cacheInstr)
);

assign instrF = hit ? cacheInstr : memInstr;

endmodule
