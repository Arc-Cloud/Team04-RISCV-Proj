module reg_file #(
    parameter DATA_WIDTH = 32,
    parameter ADDRESS_WIDTH = 5

)(
    input logic clk,
    input logic [ADDRESS_WIDTH-1:0] AD1,  // source reg1 address
    input logic [ADDRESS_WIDTH-1:0] AD2,  // source reg2 address
    input logic [ADDRESS_WIDTH-1:0] AD3,  // dest reg address
    input logic WE3,            // synchronous write enable  
    input logic [DATA_WIDTH-1:0] WD3,  // data to be written to destination register
    input logic [ADDRESS_WIDTH-1:0] testRegAddress,
    output logic [DATA_WIDTH-1:0] RD1,   // contents of rs1 
    output logic [DATA_WIDTH-1:0] RD2,   // contents of rs2
    output logic [DATA_WIDTH-1:0] testRegData
);

logic [DATA_WIDTH-1:0] register_file [2**ADDRESS_WIDTH-1:0];  

always_ff @(posedge clk) begin
    if(WE3) register_file[AD3] <= WD3;
end 

always_comb begin
    RD1 = register_file[AD1];
    RD2 = register_file[AD2];
    testRegData = register_file[testRegAddress];
    //$display("dest data: %h", register_file[5'd10]);
end

endmodule
