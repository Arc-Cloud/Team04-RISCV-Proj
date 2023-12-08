module control_unit #(
    parameter DATA_WIDTH = 32
)(
    input  logic [6:0]      op,
    input  logic [2:0]      funct3,
    input  logic            funct7,
    output logic            RegWriteD,
    output logic [1:0]      ResultSrcD,
    output logic            MemWriteD,
    output logic            JumpD,
    output logic            BranchD,
    output logic [3:0]      ALUControlD,
    output logic            ALUSrcD,
    output logic [2:0]      ImmSrcD,
    output logic            JALRInstrD,
    output logic [2:0]      AddressingControlD
);

always_comb begin
    case(op)            

        // implemets R type instructions
        7'b0110011: begin
            RegWriteD = 1'b1;
            ResultSrcD = 2'b00;
            MemWriteD = 1'b0;
            JumpD = 1'b0;
            BranchD = 1'b0;
            ALUSrcD = 1'b0;
            JALRInstrD = 1'b0;
            
            case(funct3)
                3'b000: begin
                    case(funct7)
                        1'b0: ALUControlD = 4'b0000; //add
                        1'b1: ALUControlD = 4'b0001; //sub
                    endcase
                end
                3'b001: ALUControlD = 4'b0111; //sll
                3'b010: ALUControlD = 4'b0101; //slt
                3'b011: ALUControlD = 4'b0110; // sltu
                3'b100: ALUControlD = 4'b0100; //xor
                3'b110: ALUControlD = 4'b0011; // or
                3'b111: ALUControlD = 4'b0010; //and
                3'b101: begin
                    case(funct7)
                        1'b0:  ALUControlD = 4'b1000; //srl
                        1'b1:  ALUControlD = 4'b1011; //sra 
                    endcase
                end
                default: ALUControlD = 4'b0000;
            endcase
        end

        // B-type instruction implementation
        7'b1100011: begin
            RegWriteD = 1'b0;
            MemWriteD = 1'b0;
            JumpD = 1'b0;
            BranchD = 1'b1;
            
            case(funct3) 
                3'b000 : ALUControlD = 4'b0001;   // beq
                3'b001 : ALUControlD = 4'b1100;   // bne
                3'b100 : ALUControlD = 4'b0101;   // blt
                3'b101 : ALUControlD = 4'b1001;   // bge
                3'b110 : ALUControlD = 4'b0110;   // bltu
                3'b111 : ALUControlD = 4'b1010;   // bgeu
            endcase

            ALUSrcD = 1'b0;
            ImmSrcD = 3'b010;
            JALRInstrD = 1'b0;
        end

        // implementation of I-type (19) instructions
        7'b0010011: begin
            RegWriteD = 1'b1;
            ResultSrcD = 2'b00;
            MemWriteD = 1'b0;
            JumpD = 1'b0;
            BranchD = 1'b0;
            ALUSrcD = 1'b1;
            ImmSrcD = 3'b000;
            JALRInstrD = 1'b0;

            case(funct3)
                3'b000: ALUControlD = 4'b0000; //addi
                3'b001: ALUControlD = 4'b0111; // slli
                3'b100: ALUControlD = 4'b0100; //xori
                3'b101: 
                    case(funct7)
                        1'b0: ALUControlD = 4'b1000; //srli
                        1'b1: ALUControlD = 4'b1011; //srai 
                    endcase
                3'b110: ALUControlD = 4'b0011; // ori
                3'b111: ALUControlD = 4'b0010; //andi
                default: ALUControlD = 4'b0000;
            endcase
        end

        // implementation of J-Ttype instructions (111)
        // JAL
        7'b1101111: begin
            RegWriteD = 1'b1;
            ResultSrcD = 2'b10;
            MemWriteD = 1'b0;
            MemWriteD = 1'b0;
            BranchD = 1'b0;
            ImmSrcD = 3'b011;
            JumpD = 1'b1;
            JALRInstrD = 1'b0;
        end

        //implementation of I-type (3) instructions (lb, lh, lw, lbu, lhu)
        7'b0000011: begin
            RegWriteD = 1'b1;
            ResultSrcD = 2'b01;
            MemWriteD = 1'b0;
            JumpD = 1'b0;
            BranchD = 1'b0;
            ALUControlD = 4'b0000;
            ALUSrcD = 1'b1;
            ImmSrcD = 3'b000;   
            JALRInstrD = 1'b0;
            AddressingControlD = funct3;
        end

        //implementation of S-type instructions (35) (sb, sh, sw)
        7'b0100011: begin
            RegWriteD = 1'b0;
            MemWriteD = 1'b1;
            JumpD = 1'b0;
            BranchD = 1'b0;
            ALUControlD = 4'b0000;
            ALUSrcD = 1'b1;
            ImmSrcD = 3'b001;
            JALRInstrD = 1'b0;
            AddressingControlD = funct3;
        end

        //implementation of I-type (103) instructions 
        //JALR
        7'b1100111: begin
            RegWriteD = 1'b1;
            ResultSrcD = 2'b10;
            MemWriteD = 1'b0;
            BranchD = 1'b0;
            ALUControlD = 4'b0000;
            ALUSrcD = 1'b1;
            ImmSrcD = 3'b000;
            JALRInstrD = 1'b1;
        end

        // implementation of U-type instructions (55)
        // LUI
        7'b0110111: begin
            RegWriteD = 1'b1;
            ResultSrcD = 2'b00;
            MemWriteD = 1'b0;
            JumpD = 1'b0;
            BranchD = 1'b0;
            ALUControlD = 4'b1111;
            ALUSrcD = 1'b1;
            ImmSrcD = 3'b100;
            JALRInstrD = 1'b0;
        end    

        default: begin
            RegWriteD = 1'b0;
            ResultSrcD = 2'b00;
            MemWriteD = 1'b0;
            JumpD = 1'b0;
            BranchD = 1'b0;
            ALUControlD = 4'b0000;
            ALUSrcD = 1'b0;
            ImmSrcD = 3'b000;
            JALRInstrD = 1'b0;
        end
    endcase
    //$display("opcode: %b", op);
end

endmodule
