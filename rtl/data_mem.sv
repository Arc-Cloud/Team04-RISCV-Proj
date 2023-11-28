module data_mem #(
	parameter DATA_WIDTH = 32,
	parameter STORAGE_WIDTH = 8
)(
// interface signals
	input logic [DATA_WIDTH-1:0] A,
	input logic clk,
    input logic WE,
	input logic [1:0] addressing_mode,
	input logic sign_extend,
	input logic [DATA_WIDTH-1:0] WD,
	output logic [DATA_WIDTH-1:0] RD
);

// mem map says data mem runs from 00000 -> 1FFFF = 131071 Aesses = 2**17
logic [STORAGE_WIDTH-1:0] ram_array [2**17-1:0];

logic [16:0] addr = A[16:0];  // get least 17 bits of address

initial begin
	$display("Loading data memory..");
	$readmemh("../rtl/test_data.mem", ram_array);
    $display("Data memory loaded");
end

// writing to memory (store instructions)
always_ff @(posedge clk) begin
	if (WE) begin
		case(addressing_mode)
			2'b00 : // byte addressing
				ram_array[addr] <= WD[7:0];
			2'b01 : // half addressing
				begin
					ram_array[addr] <= WD[7:0];
					ram_array[addr+1] <= WD[15:8];
				end
			2'b10:  // word addressing
				begin
					ram_array[addr] <= WD[7:0];
					ram_array[addr+1] <= WD[15:8];
					ram_array[addr+2] <= WD[23:16];
					ram_array[addr+3] <= WD[31:24];
				end
		endcase
	end

end

// reading from memory (load instructions)
always_comb begin
	case(addressing_mode) 
		2'b00 : // byte addressing
			if(sign_extend) // lb
				RD = {{24{ram_array[addr][7]}}, ram_array[addr]};
			else // lbu
				RD = {24'b0, ram_array[addr]};

		2'b01 : // half addressing
			if(sign_extend) // lh
				RD = {{16{ram_array[addr+1][7]}}, ram_array[addr+1], ram_array[addr]};
			else  // lhu 
				RD = {16'b0, ram_array[addr+1] ,ram_array[addr]};
		
		2'b10 :  // word addressing
			// sign extend bit is don't care
			RD = {ram_array[addr+3], ram_array[addr+2], ram_array[addr+1], ram_array[addr]};
	endcase
	//$display("RD: %h", RD);
end

endmodule
