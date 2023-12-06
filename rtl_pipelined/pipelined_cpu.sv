module pipelined_cpu#(
    parameter  DATA_WIDTH = 32
)(
    input logic clk,
    input logic rst
);
    

/////////////////////////////////////////
//////////////////Fetch//////////////////
/////////////////////////////////////////

logic                StallFetch;
logic                PCSrcE;
logic                JALRinstrE;
logic [DATA_WIDTH-1] ALUResultE;
logic [DATA_WIDTH-1] instrF;
logic [DATA_WIDTH-1] PCPlus4F;
logic [DATA_WIDTH-1] PCF;

fetch fetch(
    // Inputs
    .clk(clk),
    .enable(~StallFetch),
    .reset(rst),
    .PCSrcE(PCSrcE),
    .JALRinstrE(JALRinstrE),
    .ALUResultE(ALUResultE),

    // Outputs
    .instrF(instrF),
    .PCPlus4F(PCPlus4F),
    .PCF(PCF)
);


/////////////////////////////////////////
//////////////////Decode/////////////////
/////////////////////////////////////////






endmodule