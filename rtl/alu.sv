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
    
    always_comb begin
        case (ALUcontrol)
            4'b0000 : ALUresult = SRCA + SRCB;
            4'b0001 : ALUresult = SRCA - SRCB;
            4'b0010 : ALUresult = SRCA & SRCB;
            4'b0011 : ALUresult = SRCA | SRCB;              
            4'b0101 : ALUresult = SRCA < SRCB;
            4'b0110 : begin 
                u_SRCA = unsigned'(SRCA);
                u_SRCB = unsigned'(SRCB);
                ALUresult = u_SRCA < u_SRCB;
            end
            4'b0100 : ALUresult = SRCA ^ SRCB;
            4'b0111 : ALUresult = SRCA << SRCB;
            4'b1000 : ALUresult = (shift_right_type) ? SRCA >> SRCB : SRCA >>> SRCB;
            4'b1001 : ALUresult = SRCA >= SRCB;
            4'b1010 : begin 
                u_SRCA = unsigned'(SRCA);
                u_SRCB = unsigned'(SRCB);
                ALUresult = u_SRCA >= u_SRCB;
            end

            default: ALUresult = 32'd0;
        endcase

        zero = (ALUresult == 32'd0);
        //$display("rs1: %h, rs2: %h, ctrl : %b", SRCA, SRCB, ALUcontrol);

    end

endmodule
