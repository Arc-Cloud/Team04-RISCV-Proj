module control #(
    parameter DATA_WIDTH = 32
) (
    input logic zero,   // input one when Branch is equal
    input logic [6:0] op,     // opcode from instruction
    input logic [3:0] funct3, // funct3 from instruction
    input logic [1:0] funct7, //funct7 from instruction
    output logic RegWrite,  // enable when we want to store in register
    output logic [2:0] ALUControl, // control operation in ALU
    output logic ALUSrc, // choose immediate (1) or register (0) operand
    output logic MemWrite, // enable write into the data memory
    output logic PCSrc, // choose counter increments (imm or +4)
    output logic [1:0] Resultsrc, // choose which data to store to register: Register(0) memory (1) PC (2)
    output logic [2:0] ImmSrc // choose which sign extend is performed on sextend module
);


 // note: I've  only included instructions that are in reference 
always_comb begin
    case(op)

    // implemets R type instructions
    7'b0110011: begin
        RegWrite = 1'b1;
        ALUSrc = 1'b0;
        MemWrite = 1'b0;
        Resultsrc = 1'b0;
        PCSrc = 1'b0;
        
        //sub & add instruction
        if (func7 == 7'b0100000) ALUControl = 3'b001; //sub
        else ALUControl = 3'b000; // add
    end

    // b-type instruction implementation
    7'b1100011: begin
        RegWrite = 1'b0;
        ImmSrc = 3'b010;
        ALUSrc = 1'b0;
        ALUControl = 3'b001;
        MemWrite = 1'b0;
        case(funct3)
        //implementation of beq
        3'b000: begin
            PCSrc = zero;
        end
        // implementation of bne
        3'b001: begin
            PCSrc = !zero;
        end
        endcase
    end

    // implementation of I-type instruction
    7'b0010011: begin
        case(funct3)
        //implementation of addi
        3'b000: begin
            RegWrite = 1'b1;
            ImmSrc = 3'b000;
            MemWrite = 1'b0;
            ALUSrc = 1'b1;
            PCSrc = 1'b0;
            Resultsrc = 1'b0;
            ALUControl = 3'b000;
        end
        endcase
    end

    // implementation of JAL
    7'b1101111: begin
        RegWrite = 1'b1;
        ImmSrc = 2'b011;
        MemWrite = 1'b0;
        Resultsrc = 2'b10;
        PCSrc = 1'b1;
    end

    //lw
    //JALR
    //sb
    //lui
    //lbu
    //shift??

   
    endcase
end
    
endmodule
