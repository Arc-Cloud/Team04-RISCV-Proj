module alu #(
    parameter DATA_WIDTH = 32
)(  
    input logic [DATA_WIDTH-1:0] SRCA,
    input logic [DATA_WIDTH-1:0] SRCB,
    input logic [3:0] ALUcontrol,
    input logic shift_right_type,
    output logic zero,
    output logic [DATA_WIDTH-1:0] ALUresult
);
    logic [DATA_WIDTH-1:0] u_SRCA;
    logic [DATA_WIDTH-1:0] u_SRCB;
    
    logic [DATA_WIDTH-1:0] result;

    always_comb begin
        case (ALUcontrol)
            4'b0000 : result = SRCA + SRCB;
            4'b0001 : result = SRCA - SRCB;
            4'b0010 : result = SRCA & SRCB;
            4'b0011 : result = SRCA | SRCB;              
            4'b0101 : result = SRCA < SRCB;
            4'b0110 : begin 
                u_SRCA = unsigned'(SRCA);
                u_SRCB = unsigned'(SRCB);
                result = u_SRCA < u_SRCB;
            end
            4'b0100 : result = SRCA ^ SRCB;
            4'b0111 : result = SRCA << SRCB;
            4'b1000 : result = (shift_right_type) ? SRCA >> SRCB : SRCA >>> SRCB;
            4'b1001 : SRCA >= SRCB;
            4'b1010 : begin 
                u_SRCA = unsigned'(SRCA);
                u_SRCB = unsigned'(SRCB);
                result = u_SRCA >= u_SRCB;
            end

            default: result = 32'd0;
        endcase

        zero = result == 0 

    end

endmodule
