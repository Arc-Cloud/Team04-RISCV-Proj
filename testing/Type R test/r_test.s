.text
.global main

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
    add s2, s1, s1 # add s1 and s1 and store in s2 (00000010)
    sub s3, s2, s1 #  subtract s1 from s2 and store in s3 (00000001)
    addi s4, zero, 100 #  initialise s4 to 100 (01100100)
    addi s5, zero, 170 #  initialise s5 to 50 (10101010)
    xor s6, s4, s5 # xor s4 and s5 and store in s6 (11001110) (206)
    or s7, s4, s5 # or s4 and s5 and store in s7 (11101110) (238)
    and s8, s4, s5 # and s4 and s5 and store in s8 (00100000) (32)
    srl s9, s4, 2 # shift s4 right by 2 and store in s9 (00011001) (25)
    sra s10, s4, 2 # shift s4 right by 2 and store in s10 (11110011) (-13)




