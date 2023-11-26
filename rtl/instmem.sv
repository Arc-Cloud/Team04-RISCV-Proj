module instmem #(
    parameter DATA_WIDTH = 32
) (
    input logic [31:0] A,
    output logic [31:0] RD
);

logic [DATA_WIDTH-1:0] rom [2**12-1:0];

initial begin
    $display("Loading instruction memory...");
    $readmemh("../rtl/instr.mem", rom);
    $display("Instruction memory loaded....");// instr.mem to be preloaded depending on the program to be executed
end

always_comb begin
    RD = rom[A]; // set RD into value at address A.
    // $display("Current instr: %h", RD);
end
    
endmodule
