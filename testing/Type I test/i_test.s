.text
.global main

# code to test i-type instructions

# addi
# slli
# xori
# srli
# srai
# ori
# andi

main:
    addi s0, zero, 1 # s0 = 1
    slli s1, s0, 4 # s1 = 16
    addi s2, zero, 100 # s2 = 100 (0b01100100)
    xori s3, s2, 0b10101010 # s3 = 186 (0b10111010)
    srli s4, s2, 2 # s4 = 25 (0b00011001)
    addi s5, zero, -1 # s5 = -1 (0b11111111)
    srai s6, s5, 4 # s6 = -1 (0b11111111)
    ori s7, s2, 0b10101010 # s7 = 250 (0b11111010)
    andi s8, s2, 0b10101010 # s8 = 64 (0b01000000)
 