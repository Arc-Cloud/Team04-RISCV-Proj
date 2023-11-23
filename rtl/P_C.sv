module P_C#(
    parameter WIDTH = 32
)(
    input logic              rst,
    input logic              clk,
    input logic              PCsrc,
    input logic  [WIDTH-1:0] ImmOP,
    output logic [WIDTH-1:0] PC
);

logic [WIDTH-1:0] next_PC;
logic [WIDTH-1:0] branch_PC;
logic [WIDTH-1:0] inc_PC;


// Combinational logic to calculate next_PC
always_comb begin
    branch_PC = PC + ImmOP;
    inc_PC = PC + 4;
    next_PC = PCsrc ? branch_PC : inc_PC;
end

// Sequential logic to update PC register
always_ff @(posedge clk or posedge rst) begin
    if (rst) 
        PC <= {WIDTH{1'b0}};
    else 
        PC <= next_PC;
end

endmodule
