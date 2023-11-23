module P_C#(
    parameter WIDTH = 32
)(
    input logic              rst,
    input logic              clk,
    input logic              PCsrc,
    input logic  [WIDTH-1:0] ImmEXT,
    output logic [WIDTH-1:0] PC
);

logic [WIDTH-1:0] PCNext;
logic [WIDTH-1:0] PCTarget;
logic [WIDTH-1:0] PCPlus4;


// Combinational logic to calculate PCNext
always_comb begin
    PCTarget = PC + ImmEXT;
    PCPlus4 = PC + 4;
    PCNext = PCsrc ? PCTarget : PCPlus4;
end

// Sequential logic to update PC register
always_ff @(posedge clk or posedge rst) begin
    if (rst) 
        PC <= {WIDTH{1'b0}};
    else 
        PC <= PCNext;
end

endmodule
