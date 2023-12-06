/*
 ____  __  ____  ____  __    __  __ _  ____  ____       
(  _ \(  )(  _ \(  __)(  )  (  )(  ( \(  __)(    \      
 ) __/ )(  ) __/ ) _) / (_/\ )( /    / ) _)  ) D (      
(__)  (__)(__)  (____)\____/(__)\_)__)(____)(____/      
  ___  ____  _  _                                       
 / __)(  _ \/ )( \                                      
( (__  ) __/) \/ (                                      
 \___)(__)  \____/                                                                                                      
*/

module pipelined_cpu#(
    parameter  DATA_WIDTH = 32
)(
    input logic clk,
    input logic rst
);

//////////////////////////////////////////////////
//                    Fetch                     //
//////////////////////////////////////////////////


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


//////////////////////////////////////////////////
//             Pipeline to Decode               //
//////////////////////////////////////////////////


logic [DATA_WIDTH-1] instrD;
logic [DATA_WIDTH-1] PCD;
logic [DATA_WIDTH-1] PCPlus4D;

decode_pipeline decode_pipeline(
    // Inputs
    .clk(clk),
    .enable(~StallDecode),
    .flush(FlushDecode),
    .instrF(instrF),
    .PCF(PCF),
    .PCPlus4F(PCPlus4F),

    // Outputs
    .instrD(instrD),
    .PCD(PCD),
    .PCPlus4D(PCPlus4D)
);



//////////////////////////////////////////////////
//                  Decode                      //
//////////////////////////////////////////////////


logic [4:0]          RdW;
logic                RegWriteW;
logic                RegWriteD;
logic [1:0]          ResultSrcD;
logic                MemWriteD;
logic                JumpD;
logic                BranchD;
logic [3:0]          ALUControlD;
logic                ALUSrcD;
logic [DATA_WIDTH-1] RD1;
logic [DATA_WIDTH-1] RD2;
logic [4:0]          Rs1D;
logic [4:0]          Rs2D;
logic [4:0]          RdD;
logic [DATA_WIDTH-1] ExtImmD;
logic                JALRInstrD;
logic [2:0]          AddressingControlD;
 
decode decode(
    // Inputs
    .instrD(instrD),
    .ResultW(ResultW),
    .RdW(RdW),
    .RegWriteW(RegWriteW),
    
    // Outputs
    .RegWriteD(RegWriteD),
    .ResultSrcD(ResultSrcD),
    .MemWriteD(MemWriteD),
    .JumpD(JumpD),
    .BranchD(BranchD),
    .ALUControlD(ALUControlD),
    .ALUSrcD(ALUSrcD),
    .JALRInstrD(JALRInstrD),
    .AddressingControlD(AddressingControlD),

    .RD1(RD1),
    .RD2(RD2),

    .ExtImmD(ExtImmD),

    .PCD(PCD),
    .PCPlus4D(PCPlus4D),

    .Rs1D(Rs1D),
    .Rs2D(Rs2D),
    .RdD(RdD)
);


//////////////////////////////////////////////////
//            Pipeline to Execute               //
//////////////////////////////////////////////////

logic                  RegWriteE;
logic [1:0]            ResultSrcE;
logic                  MemWriteE;
logic                  JumpE;
logic                  BranchE;
logic [3:0]            ALUControlE;
logic                  ALUSrcE;
logic [DATA_WIDTH-1:0] RD1E;
logic [DATA_WIDTH-1:0] RD2E;
logic [DATA_WIDTH-1:0] PCE;
logic [4:0]            Rs1E;
logic [4:0]            Rs2E;
logic [4:0]            RdE;
logic [DATA_WIDTH-1]   ExtImmE;
logic [DATA_WIDTH-1]   PCPlus4E;
logic                  JALRInstrE;
logic [2:0]            AddressingControlE;


execute_pipeline execute_pipeline(
    // Inputs
    .clk(clk),
    .en(~StallExecute),
    .flush(FlushExecute),
    .PCD(PCD),
    .PCPlus4D(PCPlus4D),
    .RegWriteD(RegWriteD),
    .ResultSrcD(ResultSrcD),
    .MemWriteD(MemWriteD),
    .JumpD(JumpD),
    .BranchD(BranchD),
    .ALUControlD(ALUControlD),
    .ALUSrcD(ALUSrcD),
    .RD1(RD1),
    .RD2(RD2),
    .Rs1D(Rs1D),
    .Rs2D(Rs2D),
    .RdD(RdD),
    .ExtImmD(ExtImmD),
    .JALRInstrD(JALRInstrD),
    .AddressingControlD(AddressingControlD),

    // Outputs
    .RegWriteE(RegWriteE),
    .ResultSrcE(ResultSrcE),
    .MemWriteE(MemWriteE),
    .JumpE(JumpE),
    .BranchE(BranchE),
    .ALUControlE(ALUControlE),
    .ALUSrcE(ALUSrcE),
    .RD1E(RD1E),
    .RD2E(RD2E),
    .PCE(PCE),
    .Rs1E(Rs1E),
    .Rs2E(Rs2E),
    .RdE(RdE),
    .ExtImmE(ExtImmE),
    .PCPlus4E(PCPlus4E),
    .JALRInstrE(JALRInstrE),
    .AddressingControlE(AddressingControlE)
);


//////////////////////////////////////////////////
//                  Execute                     //
//////////////////////////////////////////////////
logic                  PCSrcE;
logic [DATA_WIDTH-1:0] PCTargetE;
logic [DATA_WIDTH-1:0] ALUResultE;
logic [DATA_WIDTH-1:0] WriteDataE;

execute execute(
    // Inputs
    .clk(clk),

    .JumpE(JumpE),
    .BranchE(BranchE),
    .ALUControlE(ALUControlE),
    .AluSrcE(ALUSrcE),
    .RD1E(RD1E),
    .RD2E(RD2E),
    .PCE(PCE),
    .ExtImmE(ExtImmE),

    .ForwardAE(ForwardAE),
    .ForwardBE(ForwardBE),
    .ResultW(ResultW),
    .ALUResultM(ALUResultM),

    //Outputs
    .PCSrcE(PCSrcE),
    .PCTargetE(PCTargetE),
    .ALUResultE(ALUResultE),
    .WriteDataE(WriteDataE)
);


//////////////////////////////////////////////////
//             Pipeline to Memory               //
//////////////////////////////////////////////////

logic                              RegWriteM;
logic [1:0]                        ResultSrcM;
logic [DATA_WIDTH-1:0]             ALUResultM;
logic [DATA_WIDTH-1:0]             WriteDataM;
logic                              MemWriteM;
logic [REG_FILE_ADDRESS_WIDTH-1:0] RdM;
logic [2:0]                        AddressingControlM;
logic [DATA_WIDTH-1:0]             PCPlus4M;

memory_pipeline memory_pipeline(
    // Inputs
    .clk(clk),
    .RegWriteE(RegWriteE),
    .ResultSrcE(ResultSrcE),
    .MemWriteE(MemWriteE),
    .ALUResultE(ALUResultE),
    .WriteDataE(WriteDataE),
    .RdE(RdE),
    .PCPlus4E(PCPlus4E),
    .AddressingControlE(AddressingControlE),
    
    // Outputs
    .RegWriteM(RegWriteM),
    .ResultSrcM(ResultSrcM),
    .MemWriteM(MemWriteM),
    .ALUResultM(ALUResultM),
    .WriteDataM(WriteDataM),
    .RdM(RdM),
    .PCPlus4M(PCPlus4M)
);



//////////////////////////////////////////////////
//                  Memory                      //
//////////////////////////////////////////////////

logic [DATA_WIDTH-1:0] ReadDataM;

memory memory(
    // Inputs
    .clk(clk),
    .ALUResultM(ALUResultM),
    .WriteDataM(WriteDataM),
    .MemWriteM(MemWriteM),
    .AddressingControlM(AddressingControlM),
    
    // Outputs
    .ReadDataM(ReadDataM)
);



//////////////////////////////////////////////////
//            Pipeline to WriteBack             //
//////////////////////////////////////////////////

logic RegWriteW,
logic [1:0] ResultSrcW,
logic [DATA_WIDTH-1:0] ALUResultW
logic [DATA_WIDTH-1:0] ReadDataW
logic RdW,
logic [DATA_WIDTH-1:0] PCPlus4W

writeback_pipeline writeback_pipeline(
    // Inputs
    .clk(clk),
    .RegWriteM(RegWriteM),
    .ResultSrcM(ResultSrcM).
    .ALUResultM(ResultSrcM),
    .ReadDataM(ReadDataM),
    .RdM(RdM),
    .PCPlus4M(PCPlus4M),

    // Outputs
    .RegWriteW(RegWriteW),
    .ResultSrcW(ResultSrcW),
    .ALUResultW(ALUResultE),
    .ReadDataW(ReadDataW),
    .RdW(RdW),
    .PCPlus4W(PCPlus4W)
);


//////////////////////////////////////////////////
//                  WriteBack                   //
//////////////////////////////////////////////////

logic [DATA_WIDTH-1:0] ResultW;

writeback writeback(
    // Inputs
    .ResultSrcW(ResultSrcW),
    .ALUResultW(ALUResultW),
    .ReadDataW(ReadDataW),
    .PCPlus4W(PCPlus4W),

    // Outputs
    .ResultW(ResultW),    
);


//////////////////////////////////////////////////
//                 Hazard Unit                  //
//////////////////////////////////////////////////

logic [1:0]            ForwardAE;
logic [1:0]            ForwardBE;
logic StallDecode;
logic StallFetch;
logic FlushExecute;
logic FlushDecode;

hazard_unit hazard_unit(
    // Inputs
    .Rs1E(Rs1E),
    .Rs2E(Rs2E),
    .Rs1D(Rs1D),
    .Rs2D(Rs2D),
    .RdM(RdM),
    .RdW(RdW),
    .RdE(RdE),
    .RegWriteM(RegWriteM),
    .RegWriteW(RegWriteW),
    .ResultSrcE(ResultSrcE),
    .PCSrcE(PCSrcE),
    
    // Outputs
    .ForwardAE(ForwardAE),
    .ForwardBE(ForwardBE),
    .StallDecode(StallDecode),
    .StallFetch(StallFetch),
    .FlushExecute(FlushExecute),
    .FlushDecode(FlushDecode)
);

endmodule
