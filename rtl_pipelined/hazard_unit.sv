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
    
    always_comb begin
        // dealing with RAW hazards with forwarding

        if((Rs1E == RdM) && RegWriteM) ForwardAE = 2'b10;
        else if ((Rs1E == RdW) && RegWriteW) ForwardAE = 2'b01;
        else ForwardAE = 2'b00;

        if((Rs2E == RdM) && RegWriteM) ForwardBE = 2'b10;
        else if ((Rs2E == RdW) && RegWriteW) ForwardBE = 2'b01;
        else ForwardBE = 2'b00;
        
        //$display("ForwardFromMemStage: %b", ForwardFromMemStage);
        //$display("ForwardFromWBStage: %b", ForwardFromWBStage);


        // dealing with load type instructions
        // we stall the pipeline by a cycle if we have an lw instrucion in its execute stage and has 
        // a destination register thats the same as the source register of an instruction in decode stage

        StallDecode = (ResultSrcE == 2'b01 && (RdE == Rs1D || RdE == Rs2D));
        StallFetch = StallDecode;
        FlushExecute = StallDecode;

        // dealing with control hazard
        // PCSrcE is known at the execute stage. So if its high, we should've taken a jump. We need to flush the next two
        // instructions (flush execute and decode stages)
        if(PCSrcE) begin
            FlushExecute = 1'b1;
            FlushDecode = 1'b1;
        end
        else
            FlushDecode = 1'b0;
    end

endmodule
