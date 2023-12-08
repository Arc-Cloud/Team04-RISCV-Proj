module mux #(
    parameter WIDTH = 32,
    parameter NUM_INPUTS = 4,
    parameter SELECT_BITS = 2
)
(
    input logic [WIDTH-1:0] inputs [0:NUM_INPUTS-1],
    input logic [SELECT_BITS-1:0] select,
    output logic [WIDTH-1:0] outputs
);
    always_comb 
        case(select)
            2'b00: outputs = inputs[0];
            2'b01: outputs = inputs[1];
            2'b10: outputs = inputs[2];
            2'b11: outputs = 32'b0;  // shouln't be possible
        endcase

endmodule
