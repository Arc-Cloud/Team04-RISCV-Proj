module hazard_unit #(
    parameter REG_FILE_ADDRESS_WIDTH = 5
)(
    input logic [REG_FILE_ADDRESS_WIDTH-1:0] Rs1E,
    input logic [REG_FILE_ADDRESS_WIDTH-1:0] Rs2E,
    input logic [REG_FILE_ADDRESS_WIDTH-1:0] Rs1D,
    input logic [REG_FILE_ADDRESS_WIDTH-1:0] Rs2D,
    input logic [REG_FILE_ADDRESS_WIDTH-1:0] RdM,
    input logic [REG_FILE_ADDRESS_WIDTH-1:0] RdW,
    input logic [REG_FILE_ADDRESS_WIDTH-1:0] RdE,
    input logic RegWriteM,
    input logic RegWriteW,
    input logic [1:0] ResultSrcE,
    input logic PCSrcE,

    output logic [1:0] ForwardAE,
    output logic [1:0] ForwardBE,
    output logic StallDecode,
    output logic StallFetch,
    output logic FlushExecute,
    output logic FlushDecode
);
    logic loadInstrStall;

    always_comb begin
        // dealing with RAW hazards with forwarding

        if((Rs1E == RdM) && RegWriteM && Rs1E != 0) ForwardAE = 2'b10;
        else if ((Rs1E == RdW) && RegWriteW && Rs1E != 0) ForwardAE = 2'b01;
        else ForwardAE = 2'b00;

        if((Rs2E == RdM) && RegWriteM && Rs2E != 0) ForwardBE = 2'b10;
        else if ((Rs2E == RdW) && RegWriteW && Rs2E != 0) ForwardBE = 2'b01;
        else ForwardBE = 2'b00;
        
        // dealing with load type instructions
        // we stall the pipeline by a cycle if we have an lw instrucion in its execute stage and has 
        // a destination register thats the same as the source register of an instruction in decode stage

        loadInstrStall = (ResultSrcE == 2'b01 && (RdE == Rs1D || RdE == Rs2D));
        StallDecode = loadInstrStall;
        StallFetch = loadInstrStall;

        FlushExecute = StallDecode | PCSrcE;

        // dealing with control hazard
        // PCSrcE is known at the execute stage. So if its high, we should've taken a jump. We need to flush the next two
        // instructions (flush execute and decode stages)
        FlushDecode = PCSrcE;
    end

endmodule
