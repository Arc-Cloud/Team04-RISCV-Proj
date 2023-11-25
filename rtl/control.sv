module control #(
    parameter DATA_WIDTH = 32
) (
    input logic zero,   // input one when Branch is equal
    input logic [6:0] op,     // opcode from instruction
    input logic [3:0] funct3, // funct3 from instruction
    input logic [1:0] funct7, //funct7 from instruction
    output logic RegWrite,  // enable when we want to store in register
    output logic [3:0] ALUControl, // control operation in ALU
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
        Resultsrc = 2'b00;
        PCSrc = 1'b0;
        
        //sub & add instruction
        if (func7 == 7'b0100000) ALUControl = 4'b0001; //sub
        else begin
            case(funct3)
                3'b000: ALUControl = 4'b0000; //add
                3'b100: ALUControl = 4'b0100; //xor
                3'b110: ALUControl = 4'b0011; // or
                3'b111: ALUControl = 4'b0010; //and
            endcase
        end
    end

    // b-type instruction implementation
    7'b1100011: begin
        RegWrite = 1'b0;
        ImmSrc = 3'b010;
        ALUSrc = 1'b0;
        ALUControl = 4'b0001;
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
        RegWrite = 1'b1;
        ImmSrc = 3'b000;
        MemWrite = 1'b0;
        LUSrc = 1'b1;
        CSrc = 1'b0;
        Resultsrc = 2'b00;
        case(funct3)
        3'b000: ALUControl = 4'b0000; //addi
        3'b100: ALUControl = 4'b0100; //xor
        3'b110: ALUControl = 4'b0011; // or
        3'b111: ALUControl = 4'b0010; //and
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

    //implementation of lw
    7'b0000011: begin
        MemWrite = 1'b0;
        RegWrite = 1'b1;
        ImmSrc = 3'b000;
        ALUSrc = 1'b1;
        ALUcontrol = 4'b0000;
        Resultsrc = 2'b01;
        PCSrc = 1'b0;
    end

    //implementation of sw
    7'b0100011: begin
        MemWrite = 1'b1;
        RegWrite = 1'b0;
        ImmSrc = 3'b000;
        ALUSrc = 1'b1;
        ALUControl = 4'b0000;
        PCSrc = 1'b0;
    end

    //JALR
    //sb
    //lui
    //lbu
    //shift??

   
    endcase
end
    
endmodule
