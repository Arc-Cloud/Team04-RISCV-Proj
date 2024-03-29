module data_mem #(
	parameter DATA_WIDTH = 32,
	parameter STORAGE_WIDTH = 8
)(
// interface signals
	input logic [DATA_WIDTH-1:0] A,
	input logic clk,
    input logic WE,
	input logic [2:0] AddressingControl,
	input logic [DATA_WIDTH-1:0] WD,
	output logic [DATA_WIDTH-1:0] RD
);

logic [1:0] addressing_mode = AddressingControl[1:0];
logic zero_extend = AddressingControl[2];

// mem map says data mem runs from 00000 -> 1FFFF = 131071 Aesses = 2**17
logic [STORAGE_WIDTH-1:0] ram_array [2**17-1:0];

logic [16:0] addr = A[16:0];  // get least 17 bits of address

initial begin
	string path;
    int file;
    file = $fopen("../../rtl_pipelined/datamem_path.txt", "r"); // this true as the working directory is the one containing the testbench
    if (file) $display("Data file opened successfully");
    else $display("File could not be opened, %0d", file);
    $fgets(path, file);
    $fclose(file);

	$display("Loading data memory...");
    $readmemh(path, ram_array, 20'h10000);
    $display("Data memory loaded....");
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
			default : ram_array[addr] <= 0;
		endcase
		// $display("Data : %h, add: %h", {ram_array[3], ram_array[2], ram_array[1], ram_array[0]}, A);
	end

end

// reading from memory (load instructions)
always_comb begin
	case(addressing_mode) 
		2'b00 : // byte addressing
			if(zero_extend) // lbu
				RD = {24'b0, ram_array[addr]};
			else // lb
				RD = {{24{ram_array[addr][7]}}, ram_array[addr]};

		2'b01 : // half addressing
			if(zero_extend) // lhu
				RD = {16'b0, ram_array[addr+1] ,ram_array[addr]};
			else  // lh
				RD = {{16{ram_array[addr+1][7]}}, ram_array[addr+1], ram_array[addr]};
		
		2'b10 :  // word addressing
			// sign extend bit is don't care
			RD = {ram_array[addr+3], ram_array[addr+2], ram_array[addr+1], ram_array[addr]};
		default : RD = 0;
	endcase
	//$display("RD: %h", RD);
end

endmodule
