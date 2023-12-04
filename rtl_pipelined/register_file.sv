module register_file(
    parameter DATA_WIDTH = 32,
    parameter ADDRESS_WIDTH = 5
)(
    input  logic [ADDRESS_WIDTH-1] A1,
    input  logic [ADDRESS_WIDTH-1] A2,
    input  logic [ADDRESS_WIDTH-1] A3,
    input  logic [ADDRESS_WIDTH-1] WD3,
    input  logic                   WE3, 
    output logic [DATA_WIDTH-1]    RD1,
    output logic [DATA_WIDTH-1]    RD2
);

logic [DATA_WIDTH-1:0] reg_file [2**ADDRESS_WIDTH-1:0];  

always_ff @(negedge clk) begin
    if(WE3) 
        reg_file[A3] <= (A3 == 5'd0) ? 32'd0 : WD3;
end 

always_comb begin
    RD1 = reg_file[A1];
    RD2 = reg_file[A2];
end

endmodule