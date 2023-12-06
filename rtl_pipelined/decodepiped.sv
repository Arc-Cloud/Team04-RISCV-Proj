module decodepiped #(
    parameter DATA_WIDTH = 32
)(
    input logic clk,
    input logic en,
    input logic flush,
    input logic [DATA_WIDTH-1:0] isntrF,
    input logic [DATA_WIDTH-1:0] PCF,
    input logic [DATA_WIDTH-1:0] PCPlus4F,
    output logic [DATA_WIDTH-1:0] instrD,
    output logic [DATA_WIDTH-1:0] PCD,
    output logic [DATA_WIDTH-1:0] PCPlus4D
);

always_ff @(posedge clk)begin
    if (flush) begin 
        instrD <= 32'b0;
        PCD <= 32'b0;
        PCPlus4D <= 32'b0;
    end
    else if (en) begin
        instrD <= instrF;
        PCD <= PCF;
        PCPlus4D <= PCPlus4F;
    end

end


endmodule
