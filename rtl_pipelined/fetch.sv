module fetch #(
    parameter DATA_WIDTH = 32;
)(
    input logic clk,
    input logic rst,
    input logic [2:0] PCSrcE,
    input logic [DATA_WIDTH-1:0]ALUResult,
    input logic [DATA_WIDTH-1:0] PCtargetE,
    output logic [DATA_WIDTH-1:0] instrD,
    output logic [DATA_WIDTH-1:0]PCPlus4D,
    output logic [DATA_WIDTH-1:0] PCD
);

logic [DATA_WIDTH-1:0] PCPlus4F;
logic [DATA_WIDTH-1:0] PCF;
logic [DATA_WIDTH-1:0] address;

PC counter(
    .clk(clk),
    .reset(rst),
    .ALUResult(ALUResult),
    .PCtargetE(PCtargetE),
    .PCSrcE(PCSrcE),
    .PCPlus4F(PCPlus4F),
    .PCF(PCF)
);

instmem memory(
    .A(PCF),
    .RD(address)
);

always_ff @(posedge clk)begin
    instrD <= address;
    PCD <= PCF;
    PCPlus4D <= PCPlus4F;

end

endmodule
