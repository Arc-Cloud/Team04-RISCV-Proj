`include "../rtl/control.sv"
`include "../rtl/sextend.sv"
`include "../rtl/instmem.sv"

module green #(parameter DATA_WIDTH = 32)(
    input logic [DATA_WIDTH-1:0] A,
    input logic Zero,
    output logic MemWrite,
    output logic RegWrite,
    output logic [3:0] ALUControl,
    output logic ALUSrc,
    output logic [1:0] PCSrc,
    output logic [1:0] ResultSrc,
    output logic [DATA_WIDTH-1:0] ImmExt,
    output logic [DATA_WIDTH-1:0] Instr
);

logic [2:0] ImmSrc;

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
    .ResultSrc(ResultSrc),
    .ImmSrc(ImmSrc)  
);

instmem memory(
    .A(A),
    .RD(Instr)
);
 
sextend sign_extend(
    .Immediate(Instr[31:7]),
    .ImmSrc(ImmSrc),
    .ImmExt(ImmExt)
);

endmodule
