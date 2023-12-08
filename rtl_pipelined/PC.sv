module PC #(
    parameter DATA_WIDTH = 32
)(
    input logic clk,
    input logic reset,
    input logic enable,
    input logic [DATA_WIDTH-1:0] PCTargetE,
    input logic  PCSrcE,
    input logic JALRinstr,
    input logic [DATA_WIDTH-1:0] ALUResultE,
    output logic [DATA_WIDTH-1:0] PCPlus4F,
    output logic [DATA_WIDTH-1:0] PCF
);

logic [DATA_WIDTH-1:0] PCNext = 32'hbfc00000;

always_comb begin
    PCPlus4F = PCF + 4;
    case(PCSrcE)
        1'b0: PCNext = JALRinstr ? {ALUResultE[31:2], 2'b00}: PCPlus4F;
        1'b1: PCNext = JALRinstr ? {ALUResultE[31:2], 2'b00}: PCTargetE;
    endcase
end

always_ff @(posedge clk)begin
    if (reset) PCF <= 32'hbfc00000;
    else if (enable) PCF <= PCNext;
end


endmodule
