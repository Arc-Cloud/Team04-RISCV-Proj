module sextend #(
    parameters DATA_WIDTH = 32
) (
    input logic [31:7] Immediate,//immediate from the instr
    input logic [2:0] ImmSrc, // choose which format the imm is in
    output logic [31:0] ImmExt // the extended output of the imm
);


always_comb begin
    case(ImmSrc)
    3'b000: ImmExt = {{20{Immediate[31]}}, Immediate[31:20]}; // type I
    3'b001: ImmExt = {{20{Immediate[31]}}, Immediate[31:25], Immediate[11:7]}; // type store
    3'b010: ImmExt = {{20{Immediate[31]}}, Immediate[7], Immediate[30:25], Immediate[11:8], 1'b0};// type branch
    3'b011: ImmExt = {{12{Immediate[31]}},  Immediate[19:12], Immediate[20], Immediate[30:21], 1'b0}; //type jump
    3'b100: ImmExt = {Immediate[31:12], 12'b0}; // U isntruction
    endcase 
end
    
endmodule
