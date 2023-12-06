module PC #(
    parameter DATA_WIDTH = 32;
)(
    input logic clk,
    input logic reset,
    input logic enable,
    input logic [DATA_WIDTH-1:0] PCtargetE,
    input logic  PCSrcE,
    input logic JALRinstr,
    input logic [DATA_WIDTH-1:0] ALUResultE,
    output logic [DATA_WIDTH-1:0] PCPlus4F,
    output logic [DATA_WIDTH-1:0] PCF
);


logic [DATA_WIDTH-1:0] PCPlus4F;
logic [DATA_WIDTH-1:0] PCnext = 32'hbfc00000;

always_comb begin
    PCPlus4F = PCF + 4;
    case(PCSrcE)
        1'b0: PCNext = JALRinstr ? {ALUResultE[32:2], 2'b00}: PCPlus4F;
        1'b1: PCNext = JALRinstr ? {ALUResultE[32:2], 2'b00}: PCtargetE;
    endcase
end

always_ff @(posedge clk)begin
    if (reset) PCF <= 32'hbfc00000;
    else if (enable) PCF <= PCNext;
end


endmodule
