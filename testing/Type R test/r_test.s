.text
.globl main

# Test assembly program for R type instructions.

# add
# sub
# xor
# or
# and
# srl - shift right logical
# sra - shift right arithmetic

main:
    addi s1, zero, 1 # intialise s1 to 1 (00000001)
    add s2, s1, s1 # add s1 and s1 and store in s2 (00000002)
    sub s3, s2, s1 #  subtract s1 from s2 and store in s3 (00000001)
    addi s4, zero, 100 #  initialise s4 to 100 (00000064)
    addi s5, zero, 170 #  initialise s5 to 50 (000000aa)
    xor s6, s4, s5 # xor s4 and s5 and store in s6 (11001110) (206) (0xCE)
    or s7, s4, s5 # or s4 and s5 and store in s7 (11101110) (238) (0xEE)
    and s8, s4, s5 # and s4 and s5 and store in s8 (00100000) (32)(0x20)
    addi t1, zero, 2
    addi t2, zero, -1
    srl s9, s4, t1 # shift s4 right by 2 and store in s9 (00011001) (25) (0x19)
    sra s10, t2, t1 # shift s4 right by 2 and store in s10 (11111111) (-13) (0xFFFFFFF)

# passed testing
