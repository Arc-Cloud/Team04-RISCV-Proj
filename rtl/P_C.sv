module P_C#(
    parameter WIDTH = 32
)(
    input logic              rst,
    input logic              clk,
    input logic  [1:0]           PCsrc,
    input logic  [WIDTH-1:0] ALUResult,
    input logic  [WIDTH-1:0] ImmEXT,
    output logic [WIDTH-1:0] PC,
    output logic [WIDTH-1:0] PCPlus4
);

logic [WIDTH-1:0] PCNext;
logic [WIDTH-1:0] PCTarget;


// Combinational logic to calculate PCNext
always_comb begin
    PCTarget = PC + ImmEXT;
    PCPlus4 = PC + 4;
    case(PCsrc)
        2'b00: PCNext = PCPlus4;
        2'b01: PCNext = PCTarget;
        2'b10: PCNext = {ALUResult[31:1], 1'b0};  // LSB must always be 0 since instruction mem addresses can't be odd
    endcase 

    //$display("next: %h", PCNext);
end

// Sequential logic to update PC register
always_ff @(posedge clk or posedge rst) begin
    if (rst) 
        PC <= {WIDTH{1'b0}};
    else 
        PC <= PCNext;
end

endmodule
