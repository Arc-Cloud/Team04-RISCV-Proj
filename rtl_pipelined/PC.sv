module PC #(
    parameter DATA_WIDTH = 32;
)(
    input logic clk,
    input logic reset,
    input logic [DATA_WIDTH-1:0] PCtargetE,
    input logic [1:0] PCSrcE,
    input logic [DATA_WIDTH-1:0] ALUResult,
    output logic [DATA_WIDTH-1:0] PCPlus4F,
    output logic [DATA_WIDTH-1:0] PCF
);


logic [DATA_WIDTH-1:0] PCPlus4F;
logic [DATA_WIDTH-1:0] PCnext = 32'hbfc00000;

always_comb begin
    PCPlus4F = PCF + 4;
    case(PCSrcE)
        2'b00: PCNext = PCPlus4F;
        2'b01: PCNext = PCtargetE;
        2'b10: {ALUResult[32:2], 2'b00};
    endcase
end

always_ff @(posedge clk or posedge rst)begin
    if (rst) PCF <= 32'hbfc00000;
    else PCF <= PCNext;
end


endmodule
