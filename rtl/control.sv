module control #(
    parameter DATA_WIDTH = 32
) (
    input logic zero,   // input one when Branch is equal
    input logic [6:0] op,     // opcode from instruction
    input logic [2:0] funct3, // funct3 from instruction
    input logic [6:0] funct7, //funct7 from instruction
    output logic RegWrite,  // enable when we want to store in register
    output logic [3:0] ALUControl, // control operation in ALU
    output logic ALUSrc, // choose immediate (1) or register (0) operand
    output logic MemWrite, // enable write into the data memory
    output logic [1:0] PCSrc, // choose counter increments (imm or +4)
    output logic [1:0] ResultSrc, // choose which data to store to register: Register(0) memory (1) PC (2)
    output logic [2:0] ImmSrc, // choose which sign extend is performed on sextend module
    output logic [2:0] AddressingControl // choose which type of load/store instruction to perform 
);


 // note: I've  only included instructions that are in reference 
always_comb begin
    case(op)

    // implemets R type instructions
    7'b0110011: begin
        RegWrite = 1'b1;
        ALUSrc = 1'b0;
        MemWrite = 1'b0;
        ResultSrc = 2'b00;
        PCSrc = 2'b00;
        
        //sub & add instruction
        if (funct7 == 7'b0100000) ALUControl = 4'b0001; //sub
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
            3'b000: begin
                PCSrc = zero ? 2'b01 : 2'b00; // beq
            end
            3'b001: begin
                PCSrc = zero ? 2'b00 : 2'b01; // 
                //$display("z: %b, PCsrc: %b", zero, PCSrc);
            end
        endcase
    end

    // implementation of I-type (19) instructions
    7'b0010011: begin
        RegWrite = 1'b1;
        ImmSrc = 3'b000;
        MemWrite = 1'b0;
        ALUSrc = 1'b1;
        PCSrc = 2'b00;
        ResultSrc = 2'b00;
        case(funct3)
        3'b000: ALUControl = 4'b0000; //addi
        3'b100: ALUControl = 4'b0100; //xori
        3'b110: ALUControl = 4'b0011; // ori
        3'b111: ALUControl = 4'b0010; //andi
        endcase
    end

    // implementation of J-Ttype instructions (111)
    // JAL
    7'b1101111: begin
        RegWrite = 1'b1;
        ImmSrc = 3'b011;
        MemWrite = 1'b0;
        ResultSrc = 2'b10;
        PCSrc = 2'b01;
    end

    //implementation of I type (3) instructions (lb, lh, lw, lbu, lhu)
    7'b0000011: begin
        MemWrite = 1'b0;
        RegWrite = 1'b1;
        ImmSrc = 3'b000;
        ALUSrc = 1'b1;
        ALUControl = 4'b0000;   
        ResultSrc = 2'b01;
        PCSrc = 2'b00;
        AddressingControl = funct3;
    end

    //implementation of S-type instructions (35) (sw)
    7'b0100011: begin
        MemWrite = 1'b1;
        RegWrite = 1'b0;
        ImmSrc = 3'b001;
        ALUSrc = 1'b1;
        ALUControl = 4'b0000;
        PCSrc = 2'b00;
        AddressingControl = funct3;
    end

    //implementation of I-type (103) instructions 
    //JALR
    7'b1100111: begin
        RegWrite = 1'b1;
        ImmSrc = 3'b011;
        ResultSrc = 2'b10;
        PCSrc = 2'b10;
        ALUControl = 4'b0000;
    end

    endcase
    //$display("opcode: %b", op);
end
    
endmodule
