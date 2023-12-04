.text
.equ base_pdf, 0x100
.equ base_data, 0x10000
.equ max_count, 200

main:
    JAL ra, init         # Jump to init, save return address in ra
    JAL ra, build        # Jump to build, save return address in ra

forever:
    JAL ra, display
    J forever

init:                    # Function to initialize PDF buffer memory
    LI a1, 0x100         # Loop count, a1 = 256
_loop1:
    ADDI a1, a1, -1      # a1 = a1 - 1
    SB zero, base_pdf(a1)  # mem[base_pdf + a1] = 0
    BNE a1, zero, _loop1  # If a1 != 0, jump to _loop1
    RET                   # Return to main

build:                   # Function to build PDF buffer memory
    LI a1, base_data      # a1 = base address of data array = 0x10000
    LI a2, 0              # a2 = offset into data array
    LI a3, base_pdf       # a3 = base address of PDF buffer = 0x100
    LI a4, max_count      # a4 = max_count to iterate to = 200

_loop2:
    ADD a5, a1, a2        # a5 = base_data + offset
    LBU t0, 0(a5)         # t0 = data[offset]
    ADD a6, t0, a3        # a6 = index of PDF buffer = data value + base_pdf
    LBU t1, 0(a6)         # t1 = PDF buffer value
    ADDI t1, t1, 1        # Increment bin count
    SB t1, 0(a6)          # Update bin count in PDF buffer
    ADDI a2, a2, 1        # Increment offset, point to next data in array
    BNE t1, a4, _loop2    # If bin count != max_count, jump to _loop2

    RET                   # Return to main

display:                # Function to display PDF buffer memory by sending to a0
    LI a1, 0             # Offset into PDF buffer
    LI a2, 255           # Max index of PDF array

_loop3:
    LBU a0, base_pdf(a1)  # a0 = mem[base_pdf + a1]
    ADDI a1, a1, 1        # Increment offset, point to next PDF buffer value
    BNE a1, a2, _loop3    # If offset != max, jump to _loop3

    RET                   # Return to main
