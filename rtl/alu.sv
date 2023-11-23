module alu #(
    parameter DATA_WIDTH = 32
)(  
    input logic [DATA_WIDTH-1:0] SRCA,
    input logic [DATA_WIDTH-1:0] SRCB,
    input logic [2:0] ALUcontrol,
    output logic zero,
    output logic [DATA_WIDTH-1:0] ALUresult
);

    logic [DATA_WIDTH-1:0] result;

    always_comb begin
        case (ALUcontrol)
            3'b000 : result = SRCA + SRCB;
            3'b001 : result = SRCA - SRCB;
            3'b010 : result = SRCA & SRCB;
            3'b011 : result = SRCA | SRCB;
            3'b101 : result = SRCA < SRCB;
            default: result = 32'd0;
        endcase

        zero = result == 0 

    end

endmodule
