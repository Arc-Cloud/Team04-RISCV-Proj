`include "../rtl/reg_file.sv"
`include "../rtl/data_memory.sv"
`include "../rtl/alu.sv"

module orange #(
    parameter DATA_WIDTH = 32
) (
    input logic [4:0] rs1,
    input logic [4:0] rs2,
    input logic [4:0] rd,
    input logic [DATA_WIDTH-1:0] ImmExt,
    input logic clk,
    input logic AluSrc,
    input logic [2:0] ALUControl,
    input logic MemWrite,
    input logic ResultSrc,
    output logic zero,
);

    logic [DATA_WIDTH-1:0] ALUresult;
    logic [DATA_WIDTH-1:0] ReadData;
    logic [DATA_WIDTH-1:0] RD2;
    logic [DATA_WIDTH-1:0] SrcA;

    reg_file RegFile(
        // inputs
        .clk(clk),
        .AD1(rs1),
        .AD2(rs2),
        .AD3(rd),
        .WD3(ResultSrc ? ReadData : ALUresult),

        // outputs
        .RD1(SrcA),
        .RD2(RD2)
    );

    alu ALU(
        // inputs
        .ALUControl(ALUControl),
        .SRCA(SrcA),
        .SRCB(AluSrc ? ImmExt : RD2),

        // outputs
        .zero(zero),
        .ALUresult(ALUresult)
    );

    data_mem DATA_MEMORY(
        // inputs
        .clk(clk),
        .WE(MemWrite),
        .addr(ALUresult),

        // outputs
        .RD(ReadData)
    );
    
endmodule
