module writeback #(
    parameter DATA_WIDTH = 32,
    parameter NUM_INPUTS = 4
) (
    input logic [1:0] ResultSrcW,
    input logic [DATA_WIDTH-1:0] ALUResultW,
    input logic [DATA_WIDTH-1:0] ReadDataW,
    input logic [DATA_WIDTH-1:0] PCPlus4W,

    output logic [DATA_WIDTH-1:0]  ResultW 
);
    logic [DATA_WIDTH-1:0] MUXW_inputs [0:NUM_INPUTS-1];

    always_comb begin
        MUXW_inputs = {ALUResultW, ReadDataW, PCPlus4W, {DATA_WIDTH{1'b0}}};
    end
    
    mux MUXW(
        .inputs(MUXW_inputs),
        .select(ResultSrcW),
        .outputs(ResultW)
    );

endmodule
