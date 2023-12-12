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
            4'b0001 : begin ALUResult = SrcA - SrcB; Zero = (ALUResult == 32'd0); end  // beq   
            4'b0010 : ALUResult = SrcA & SrcB; 
            4'b0011 : ALUResult = SrcA | SrcB;     
            4'b0100 : ALUResult = SrcA ^ SrcB;   
            4'b0101 : begin ALUResult = (SrcA < SrcB) ? 32'd1 : 32'd0; Zero = (ALUResult == 32'd1); end  // blt
            4'b0110 : begin 
                u_SrcA = $unsigned(SrcA);
                u_SrcB = $unsigned(SrcB);
                ALUResult = (u_SrcA < u_SrcB) ? 32'd1 : 32'd0;
                Zero = (ALUResult == 32'd1);   // bltu
            end
            4'b0111 : ALUResult = SrcA << SrcB[4:0]; //sll, slli
            4'b1000 : ALUResult = SrcA >> SrcB[4:0]; //srl, srli
            4'b1001 : begin ALUResult = (SrcA >= SrcB) ? 32'd1 : 32'd0; Zero = (ALUResult == 32'd1); end  // bge
            4'b1010 : begin 
                u_SrcA = $unsigned(SrcA);
                u_SrcB = $unsigned(SrcB);
                ALUResult = (u_SrcA >= u_SrcB) ? 32'd1 : 32'd0;
                Zero = (ALUResult == 32'd1);   // bgeu
            end
            4'b1011 : ALUResult = $signed(SrcA) >>> SrcB[4:0]; // sra, srai
            4'b1100 : begin ALUResult = SrcA - SrcB; Zero = (ALUResult != 32'd0); end  // bne
            4'b1111 : ALUResult = SrcB;
            default: ALUResult = 32'd0;
        endcase
    end

endmodule
