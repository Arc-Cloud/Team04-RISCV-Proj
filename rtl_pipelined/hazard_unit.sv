module hazard_unit #(
    parameter DATA_WIDTH = 32,
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
    input logic ResultSrcE,
    input logic PCSrcE,

    output logic ForwardAE,
    output logic ForwardBE,
    output logic StallDecode,
    output logic StallFetch,
    output logic FlushExecute,
    output logic FlushDecode
);
    logic ForwardFromMemStage = (Rs1E == RdM || Rs2E == RdM);
    logic ForwardFromWBStage = (Rs1E == RdW || Rs2E == RdW);

    always_comb begin
        // dealing with RAW hazards with forwarding
        if(ForwardFromMemStage && RegWriteM) begin
            ForwardAE = (Rs1E == RdM) ? 2'b10 : 2'b00;
            ForwardBE = (Rs2E == RdM) ? 2'b10 : 2'b00;
        end else if (ForwardFromWBStage && RegWriteW) begin
            ForwardAE = (Rs1E == RdW) ? 2'b01 : 2'b00;
            ForwardBE = (Rs2E == RdW) ? 2'b01 : 2'b00;
        end else begin 
            ForwardAE = 2'b00;
            ForwardBE = 2'b00;
        end

        // dealing with lw
        // we stall the pipeline by a cycle if we have an lw instrucion in its execute stage and has 
        // a destination register thats the same as the source register of an instruction in decode stage

        StallDecode = (ResultSrcE == 2'b01 && (RdE == Rs1D || RdE == Rs2D));
        StallFetch = StallDecode;
        FlushExecute = StallDecode;

        // dealing with control hazard
        // PCSrcE is known at the execute stage. So if its high, we should've taken a jump. We need to flush the next two
        // instructions (flush execute and decode stages)
        if(PCSrcE)
            FlushExecute = 1'b1;
            FlushDecode = 1'b1;
        else
            FlushDecode = 1'b0;
    end

endmodule