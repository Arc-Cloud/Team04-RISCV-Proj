module inst_mem #(
    parameter DATA_WIDTH = 32,
    parameter STORAGE_WIDTH = 8
) (
    input logic [31:0] A,
    output logic [31:0] RD
);

logic [11:0] addr;

logic [STORAGE_WIDTH-1:0] rom_array [32'hbfc00fff:32'hbfc00000];

initial begin
    string path;
    int file;
    file = $fopen("../../rtl/instmem_path.txt", "r"); // this true as the working directory is the one containig the testbench
    if (file) $display("Instr file opened successfully");
    else $display("File could not be opened, %0d", file);
    $fgets(path, file);
    $fclose(file);

    $display("Loading instruction memory...");
    $readmemh(path, rom_array);
    $display("Instruction memory loaded....");// instr.mem to be preloaded depending on the program to be executed
end

always_comb begin
    addr = A[11:0];
    RD = {rom_array[addr], rom_array[addr+1], rom_array[addr+2], rom_array[addr+3]};
    //$display("current instr: %h, addr: %h", RD, addr);
end
    
endmodule
