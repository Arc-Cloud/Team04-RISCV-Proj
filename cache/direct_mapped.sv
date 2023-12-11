module cache #(
    parameter DATA_WIDTH = 32,
    parameter CACHE_LENGTH = 8,
    parameter TAG_WIDTH = 27,
    parameter SET_WIDTH = 3
)(
    input logic [DATA_WIDTH-1:0] address,
    input logic clk,
    input logic [DATA_WIDTH-1:0] datain,
    input logic WE,
    output logic hit,
    output logic [DATA_WIDTH-1:0] dataout
);

// // if it is a read cycle then a hit then a read from cache is initiated
// //  If it is a miss, then the hardware must go and fetch the data from the next level of the memory hierarchy and fill the
// cache with it.
// y, if the operation is a write, it must write to the cache
// AND to the next level of memory hierarch (i.e. in this case, the main
// memory).


logic valids [CACHE_LENGTH-1:0];
logic [TAG_WIDTH-1:0] tags [CACHE_LENGTH-1:0];
logic [DATA_WIDTH-1:0] data [CACHE_LENGTH-1:0];

logic currentSet [SET_WIDTH-1:0];
logic currentTag [TAG_WIDTH-1:0];

always_comb begin
    currentSet = address[SET_WIDTH+1:2];
    currentTag = address[DATA_WIDTH-1:DATA_WIDTH-TAG_WIDTH];
    hit = (valids[currentSet] && currentTag == tags[currentSet]);

    if(hit) dataout = data[currentSet];
end

// writing to cache
always_ff @(posedge clk) begin
    if(WE)begin 
        data[currentSet] <= datain;
        valids[currentSet] <= 1;
        tags[currentSet] <= currentTag;
    end
end


// V bit + tag + 32 bits data
endmodule
