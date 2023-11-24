module data_mem #(
	parameter DATA_WIDTH = 32
)(
// interface signals
	input logic [DATA_WIDTH-1:0] addr,
	input logic clk,
    input logic WE,
	output logic [DATA_WIDTH-1:0] RD
);

// mem map says data mem runs from 00000 -> 1FFFF = 131071 addresses = 2**17

logic [DATA_WIDTH-1:0] ram_array [2**17-1:0];

always_ff @(posedge clk) begin
	if (WE) RD <= ram_array[addr];
end

endmodule

