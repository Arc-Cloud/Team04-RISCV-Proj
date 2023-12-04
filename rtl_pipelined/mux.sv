module mux #(
    parameter WIDTH = 32,
    parameter NUM_INPUTS = 4
)
(
    input logic [WIDTH-1:0] inputs [0:NUM_INPUTS-1],
    input logic [$clog2(NUM_INPUTS)-1:0] select,
    output logic [WIDTH-1:0] outputs
);

    always @(posedge select)
        outputs <= inputs[select];

endmodule
