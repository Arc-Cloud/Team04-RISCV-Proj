module orange #(
    parameter DATA_WIDTH = 32
) (
    input logic [4:0] rs1,
    input logic [4:0] rs2,
    input logic [4:0] rd,
    input logic [DATA_WIDTH-1:0] ImmExt,
    input logic [DATA_WIDTH-1:0] PCPlus4,
    input logic clk,
    input logic AluSrc,
    input logic [3:0] ALUControl,
    input logic WE,
    input logic WE3,
    input logic [1:0] ResultSrc,
    input logic [4:0] testRegAddress,
    input logic [2:0] AddressingControl,
    output logic Zero,
    output logic [DATA_WIDTH-1:0] Result,
    output logic [DATA_WIDTH-1:0] ALUResult
);

    logic [DATA_WIDTH-1:0] ReadData;
    logic [DATA_WIDTH-1:0] RD2;
    logic [DATA_WIDTH-1:0] SrcA;
    logic [DATA_WIDTH-1:0] Reg_DATA_IN;

    always_comb begin
        case(ResultSrc)
            2'b00: Reg_DATA_IN = ALUResult;
            2'b01: Reg_DATA_IN = ReadData;
            2'b10: Reg_DATA_IN = PCPlus4;   // need to have option of adding pc + 4 to ra
        endcase
    end

    reg_file RegFile(
        // inputs
        .clk(clk),
        .AD1(rs1),
        .AD2(rs2),
        .AD3(rd),
        .WD3(Reg_DATA_IN),
        .WE3(WE3),
        .testRegAddress(testRegAddress),

        // outputs
        .RD1(SrcA),
        .RD2(RD2),
        .testRegData(Result)
    );

    alu ALU(
        // inputs
        .ALUControl(ALUControl),
        .SrcA(SrcA),
        .SrcB(AluSrc ? ImmExt : RD2),

        // outputs
        .Zero(Zero),
        .ALUResult(ALUResult)
    );

    data_mem DATA_MEMORY(
        // inputs
        .A(ALUResult),
        .clk(clk),
        .WE(WE),
        .WD(RD2),
        .AddressingControl(AddressingControl),

        // outputs
        .RD(ReadData)
    );
    
endmodule
