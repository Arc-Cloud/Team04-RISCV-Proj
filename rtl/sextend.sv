module sextend #(
    parameters DATA_WIDTH = 32
) (
    input logic [31:7] Immediate,//immediate from the instr
    input logic [1:0] ImmSrc, // choose which format the imm is in
    output logic [31:0] ImmExt // the extended output of the imm
);


always_comb begin
    case(ImmSrc)
    2'b00: ImmExt = {{20{Immediate[31]}}, Immediate[31:20]}; // type I
    2'b01: ImmExt = {{20{Immediate[31]}}, Immediate[31:25], Immediate[11:7]}; // type store
    2'b10: ImmExt = {{20{Immediate[31]}}, Immediate[7], Immediate[30:25], Immediate[11:8], 1'b0};// type branch
    2'b11: ImmExt = {{12{Immediate[31]}},  Immediate[19:12], Immediate[20], Immediate[30:21], 1'b0} //type jump
    endcase 
end
    
endmodule
