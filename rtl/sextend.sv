module sextend #(
    parameters DATA_WIDTH = 32
) (
    input logic [31:7] Immediate,
    input logic [1:0] ImmSrc,
    output logic [31:0] ImmExt
);


always_comb begin
    case(ImmSrc)
    2'b00: ImmExt = {{20{Immediate[31]}}, Immediate[31:20]};
    2'b01: ImmExt = {{20{Immediate[31]}}, Immediate[31:25], Immediate[11:7]};
    2'b10: ImmExt = {{19{Immediate[31]}}, Immediate[7], Immediate[30:25], Immediate[11:8], 1'b0};
    endcase 
end
    
endmodule