module decode #(
    parameter DATA_WIDTH = 32
)(
    input logic                 clk,
    input logic                 rst,
    input logic                 WE3,
    input logic [DATA_WIDTH-1]  InstrD,
    input logic [DATA_WIDTH-1]  ResultW,
    input logic [DATA_WIDTH-1]  PCD,
    input logic [DATA_WIDTH-1]  PCPlus4D,
    input logic [4:0]           RdW,
    input logic                 RegWriteW,

    output logic                RegWriteE,
    output logic [1:0]          ResultSrcE,
    output logic                MemWriteE,
    output logic                JumpE,
    output logic                BranchE,
    output logic [3:0]          ALUControlE,
    output logic                ALUSrcE,
    output logic [DATA_WIDTH-1] RD1E,
    output logic [DATA_WIDTH-1] RD2E,
    output logic [DATA_WIDTH-1] PCE,
    output logic [4:0]          Rs1E,
    output logic [4:0]          Rs2E,
    output logic [4:0]          RdE,
    output logic [DATA_WIDTH-1] ExtImmE,
    output logic [DATA_WIDTH-1] PCPlus4E,
    output logic                JALRInstrE
    output logic [2:0]          AddressingControlE
 
)

// free logic
logic [2:0] ImmSrcD;
logic [4:0] Rs1D;
logic [4:0] Rs2D;
logic [4:0] RdD;

// control unit
logic RegWriteD;
logic [1:0] ResultSrcD;
logic MemWriteD;
logic JumpD;
logic BranchD;
logic [3:0] ALUControlD;
logic ALUSrcD;
logic [2:0] AddressingControlD;

// register file
logic [DATA_WIDTH-1] RD1;
logic [DATA_WIDTH-1] RD2;

// extend
logic [DATA_WIDTH-1] ExtImmD;

always_comb begin
    Rs1D = InstrD [19:15];
    Rs2D = InstrD [24:20];
    RdD = InstrD[11:7];
end

control_unit control_unit(
    // inputs 
    .op(InstrD[6:0]),
    .funct3(InstrD[14:12]),
    .funct7(InstrD[30]),

    // outputs 
    .RegWriteD(RegWriteD),
    .ResultSrcD(ResultSrcD),
    .MemWriteD(MemWriteD),
    .JumpD(JumpD),
    .BranchD(BranchD),
    .ALUControlD(ALUControlD),
    .ALUSrcD(ALUSrcD),
    .ImmSrcD(ImmSrcD),
    .JALRInstrD(JALRInstrD),
    .AddressingControlD(AddressingControlD)
);

register_file register_file(
    // inputs
    .A1(InstrD[19:15]),
    .A2(InstrD[24:20]),
    .A3(RdW),
    .WD3(ResultW),
    .WE3(RegWriteW),

    // outputs
    .RD1(RD1),
    .RD2(RD2)
);

extend extend(
    // inputs
    .Immediate(InstrD[31:7]),
    .ImmSrcD(ImmSrcD),
    //outputs
    .ExtImmD(ExtImmD)
);


always_ff @(posedge clk) begin
    RegWriteE <= RegWriteD;
    ResultSrcE <= ResultSrcD;
    MemWriteE <= MemWriteD;
    JumpE <= JumpD;
    BranchE <= BranchD;
    ALUControlE <= ALUControlD;
    ALUSrcE <= ALUSrcD;
    JALRInstrE <= JALRInstrD;
    RD1E <= RD1;
    RD2E <= RD2;
    PCE <= PCD;
    Rs1E <= Rs1D;
    Rs2E <= Rs2D;
    RdE <= RdD;
    ExtImmE <= ExtImmD;
    PCPlus4E <= PCPlus4D;
    AddressingControlE <= AddressingControlD;
end


endmodule