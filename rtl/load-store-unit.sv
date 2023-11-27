module load_store #(
    parameter DATA_WIDTH = 32
)
(
    input  logic [2:0]            LoadStoreControl,
    input  logic [DATA_WIDTH-1:0] SrcA
    input  logic [DATA_WIDTH-1:0] SrcB
    output logic [DATA_WIDTH-1:0] LoadStoreResult
);

logic [DATA_WIDTH-1:0] u_SrcA;
logic [DATA_WIDTH-1:0] u_SrcB;

// to implement

always_comb begin
    case (LoadStoreControl)
        4'b0000 : begin
            Address = SrcA + SrcB;
            LoadStoreResult       
        end //lb
        4'b0001 : begin
            Address = SrcA + SrcB;
            LoadStoreResult       
        end      //lh
v       4'b0010 :  begin
            Address = SrcA + SrcB;
            LoadStoreResult       
        end        //lw
        4'b0011 : begin
            u_SrcA = unsigned'(SrcA);
            u_SrcB = unsigned'(SrcB);
            Address = u_SrcA + u_SrcB;
            LoadStoreResult =     //lbu
        end
        4'b0100 : begin
            u_SrcA = unsigned'(SrcA);
            u_SrcB = unsigned'(SrcB);
            Address = u_SrcA + u_SrcB;
            LoadStoreResult =     //lhu
        end
        4'b0101 : begin
            Address = SrcA + SrcB;
            LoadStoreResult       
        end       //sb
        4'b0110 : begin
            Address = SrcA + SrcB;
            LoadStoreResult       
        end       //sh
        4'b0111 :  begin
            Address = SrcA + SrcB;
            LoadStoreResult       
        end        //sw
                   
        default: LoadStoreResult = 32'd0;

    endcase

end


endmodule
/*
**Inputs to the Load-Store Unit:**
1. **LoadStoreControl**: Tells the load-store unit what operation to perform (e.g., load or store, byte/half-word/word).
2. **Source Register Value (`SrcA`)**: The base address for the memory access.
3. **Immediate Value**: An offset added to the base address.
4. **Data to Store**: In the case of store operations, this is the data to be written to memory.
5. **Control Signals**: These may include signals to enable the unit, to indicate the size of the access, and whether to sign-extend or zero-extend the data.

**Outputs from the Load-Store Unit:**
1. **Memory Address**: The calculated address where data should be loaded from or stored to.
2. **Data Loaded**: The data retrieved from memory during load operations.
3. **Memory Write Data**: The actual data to be written to memory, which might include masking for partial writes.
4. **Control Signals to Memory**: These signals control read and write operations, including enabling the memory, write-enable signals, and the like.

The load-store unit works in conjunction with the control unit to synchronize the execution of memory operations with the rest of the CPU pipeline.
It may also output status signals indicating the success or failure of an operation (e.g., for alignment exceptions).
*/

