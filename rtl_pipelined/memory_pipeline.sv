module memory_pipeline #(
    parameter DATA_WIDTH = 32,
    parameter REG_FILE_ADDRESS_WIDTH = 5
)(
    input logic clk,
    input logic RegWriteE,
    input logic [1:0] ResultSrcE,
    input logic MemWriteE,
    input logic [DATA_WIDTH-1:0] ALUResultE,
    input logic [DATA_WIDTH-1:0] WriteDataE,
    input logic [REG_FILE_ADDRESS_WIDTH-1:0] RdE,
    input logic [DATA_WIDTH-1:0] PCPlus4E,
    input logic [2:0]            AddressingControlE,

    input logic [DATA_WIDTH-1:0] cacheDataE,
    input logic cachehitE,


    output logic RegWriteM,
    output logic [1:0] ResultSrcM,
    output logic MemWriteM,
    output logic [DATA_WIDTH-1:0] ALUResultM,
    output logic [DATA_WIDTH-1:0] WriteDataM,
    output logic [REG_FILE_ADDRESS_WIDTH-1:0] RdM,
    output logic [DATA_WIDTH-1:0] PCPlus4M,    
    output logic [2:0]            AddressingControlM,

    output logic [DATA_WIDTH-1:0] cacheDataM,
    output logic cachehitM
);

    always_ff @(posedge clk) begin
        RegWriteM <= RegWriteE;
        ResultSrcM <= ResultSrcE;
        MemWriteM <= MemWriteE;
        ALUResultM <= ALUResultE;
        WriteDataM <= WriteDataE;
        RdM <= RdE;
        PCPlus4M <= PCPlus4E;
        AddressingControlM <= AddressingControlE;

        cacheDataM <= cacheDataE;
        cachehitM <= cachehitE;
    end
        
endmodule
