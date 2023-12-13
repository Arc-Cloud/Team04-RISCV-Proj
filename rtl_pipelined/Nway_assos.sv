module Nway_assos #(  
    parameter DATA_WIDTH = 32,
    parameter NUM_OF_BLOCKS = 8,
    parameter BLOCKS_PER_SET = 2,
    parameter NUM_OF_SETS = NUM_OF_BLOCKS / BLOCKS_PER_SET,
    parameter SET_WIDTH = $clog2(NUM_OF_SETS),
    parameter TAG_WIDTH = DATA_WIDTH - SET_WIDTH
)(
    input logic [DATA_WIDTH-1:0] address,
    input logic clk,
    input logic [DATA_WIDTH-1:0] datain,
    input logic WE,

    output logic hit,
    output logic [DATA_WIDTH-1:0] dataout
);

    logic valids [NUM_OF_SETS-1:0][BLOCKS_PER_SET-1:0];
    logic [TAG_WIDTH-1:0] tags [NUM_OF_SETS-1:0][BLOCKS_PER_SET-1:0];
    logic [DATA_WIDTH-1:0] data [NUM_OF_SETS-1:0][BLOCKS_PER_SET-1:0];
    
    logic used [SET_WIDTH-1:0];

    logic [SET_WIDTH-1:0] currentSet;
    logic [TAG_WIDTH-1:0] currentTag;

    logic hit1;
    logic hit0;

    logic wayin;

    always_comb begin
        currentSet = address[SET_WIDTH+1:2];
        currentTag = address[DATA_WIDTH-1:DATA_WIDTH-TAG_WIDTH];

        hit1 = (valids[currentSet][1] && tags[currentSet][1] == currentTag);
        hit0 = (valids[currentSet][0] && tags[currentSet][0] == currentTag);

        hit = hit1 || hit0;
        
        used[currentSet] = hit1;

        if(hit) dataout = hit1 ? data[currentSet][1] : data[currentSet][0];
        
        if(valids[currentSet][1] == 0) wayin = 1;
        else if (valids[currentSet][0] == 0) wayin = 0;
        else wayin = ~used[currentSet];
    end

    // writing to cache
    always_ff @(posedge clk) begin
        if(WE)begin 

            data[currentSet][wayin] <= datain;
            valids[currentSet][wayin] <= 1;
            tags[currentSet][wayin] <= currentTag;
        end
    end

endmodule
