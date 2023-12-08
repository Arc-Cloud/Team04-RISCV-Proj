//`define ABSOLUTE_PATH `("../realpath -e ../testing/Type I test/i_test.mem")

module instmem #(
    parameter STORAGE_WIDTH = 8
) (
    input logic [31:0] A,
    output logic [31:0] RD
);

logic [11:0] addr;

logic [STORAGE_WIDTH-1:0] rom_array [32'hbfc00fff:32'hbfc00000];

initial begin    
    $display("Loading instruction memory...");
    $readmemh("/home/ilan/Desktop/Year2/Team04-RISCV-Proj/testing/Type B-J test/b_test.mem", rom_array);
    $display("Instruction memory loaded....");// instr.mem to be preloaded depending on the program to be executed
end

always_comb begin
    addr = A[11:0];
    RD = {rom_array[addr], rom_array[addr+1], rom_array[addr+2], rom_array[addr+3]};
    $display("current instr: %h, addr: %h", RD, addr);
end
    
endmodule

