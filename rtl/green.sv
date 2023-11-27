`include "../rtl/control.sv"
`include "../rtl/sextend.sv"
`include "../rtl/instmem.sv"

module green #(parameter DATA_WIDTH = 32, IM_WIDTH = 12, REGISTER = 5)(
    input logic [DATA_WIDTH-1:0] A,
    input logic Zero,
    output logic MemWrite,
    output logic RegWrite,
    output logic ALUControl,
    output logic ALUSrc,
    output logic [1:0] PCSrc,
    output logic ResultSrc,
    output logic [DATA_WIDTH-1:0] ImmExt,
    output logic [DATA_WIDTH-1:0] Instr
);

logic [1:0] Immsrc;

control decode_insr(
    // inputs
    .zero(Zero),
    .op(Instr[6:0]),
    .funct3(Instr[14:12]),
    .funct7(Instr[31:25]),

    // outputs
    .RegWrite(RegWrite),
    .ALUControl(ALUControl),
    .MemWrite(MemWrite),
    .ALUSrc(ALUSrc),
    .PCSrc(PCSrc),
    .Resultsrc(ResultSrc),
    .ImmSrc(Immsrc)  
);

instmem memory(
    .A(A),
    .RD(Instr)
);
 
sextend sign_extend(
    .Immediate(Instr[31:7]),
    .ImmSrc(Immsrc),
    .ImmExt(ImmExt)
);

endmodule
