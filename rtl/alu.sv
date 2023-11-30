module alu #(
    parameter DATA_WIDTH = 32
)(  
    input logic [DATA_WIDTH-1:0] SrcA,
    input logic [DATA_WIDTH-1:0] SrcB,
    input logic [3:0] ALUControl,
    output logic Zero,
    output logic [DATA_WIDTH-1:0] ALUResult
);
    logic [DATA_WIDTH-1:0] u_SrcA;
    logic [DATA_WIDTH-1:0] u_SrcB;
    
    always_comb begin
        case (ALUControl)
            4'b0000 : ALUResult = SrcA + SrcB; 
            4'b0001 : ALUResult = SrcA - SrcB; 
            4'b0010 : ALUResult = SrcA & SrcB; 
            4'b0011 : ALUResult = SrcA | SrcB;     
            4'b0100 : ALUResult = SrcA ^ SrcB;   
            4'b0101 : ALUResult = (SrcA < SrcB) ? 32'b1 : 32'b0; 
            4'b0110 : begin 
                u_SrcA = unsigned'(SrcA);
                u_SrcB = unsigned'(SrcB);
                ALUResult = (u_SrcA < u_SrcB) ? 32'b1 : 32'b0;;
            end
            4'b0111 : ALUResult = SrcA << SrcB; //sll
            4'b1000 : ALUResult = SrcA >> SrcB; //srl
            4'b1001 : ALUResult = (SrcA >= SrcB) ? 32'b1 : 32'b0;
            4'b1010 : begin 
                u_SrcA = unsigned'(SrcA);
                u_SrcB = unsigned'(SrcB);
                ALUResult = (u_SrcA >= u_SrcB) ? 32'b1 : 32'b0;
            end
            4'b1011 : ALUResult = SrcA >>> SrcB; // sra

            4'b1100 : ALUResult = SrcA >>> SrcB[4:0]; //srai
            4'b1101 : ALUResult = SrcA << SrcB[4:0];  // slli
            4'b1110 : ALUResult = SrcA >> SrcB[4:0];  // srli
            default: ALUResult = 32'd0;
        endcase

        Zero = (ALUResult == 32'd0);
        // $display("rs1: %h, rs2: %h, ctrl : %b", SrcA, SrcB, ALUControl);
    end

endmodule
