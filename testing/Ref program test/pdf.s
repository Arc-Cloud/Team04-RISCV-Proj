.text
.equ base_pdf, 0x100
.equ base_data, 0x10000
.equ max_count, 200

main:
    JAL ra, init # Jump to inti, save return address in ra
    JAL ra, build # Jump to build, save return address in ra
forever:
    JAL ra, display
    J  forever

init: # function to intialise PDF buffer memory
    LI a1, 0x100 # loop_count a1 = 0d256
_loop1: # while a1 != 0
    ADDI a1, a1, -1 # a1 = a1 - 1
    SB zero, base_pdf(a1) # store 0 in pdf buffer mem[base_pdf + a1] = 0
    BNE a1, zero, _loop1 # if a1 != 0, jump to _loop1 
    RET # return to main

build: # function to build PDF buffer memory
    LI a1, base_data # a = base address of data array = 0x10000
    LI a2, 0 # a2 = offset into of data array
    L1 a3, base_pdf # a3 = base address of pdf buffer = 0x100
    LI a4, max_count # a4 = max_count to iterate to = 200
_loop2:
    add a5, a1, a2 # a5 = a1 + a2 = base_data + offset
    LBU t0, 0(a5) # t0 = mem[a5+0] = data[offset] = data value
    ADD a6, t0, a3 # a6 = index of pdf buffer = data value + base_pdf
    LBU t1, 0(a6) # t1 = mem[a6+0] = pdf buffer value
    ADDI t1, t1, 1 # t1 = t1 + 1 = pdf buffer value + 1, incrementing count
    SB t1, 0(a6) # mem[a6+0] = t1 = pdf buffer value + 1, update bin count
    ADDI a2, a2, 1 # a2 = a2 + 1 = offset + 1, increment offset, point to next data in array
    BNE t1, a4, _loop2 # if t1 != a4, jump to _loop2, until bin count reaches max
    RET

display: # function to display PDF buffer memory by sending to a0
    LI a1, 0 # a1 = offset into pdf buffer
    LI a2, 255 # a2 = max index of pdf array
_loop3
    LBU a0, base_pdf(a1) # a0 = mem[base_pdf + a1] = pdf buffer value
    ADDI a1, a1, 1 # a1 = a1 + 1 = offset + 1, increment offset, point to next pdf buffer value
    BNE a1, a2, _loop3 # if a1 != a2, jump to _loop3, until offset reaches max
    RET

