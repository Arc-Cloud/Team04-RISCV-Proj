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
    addi s2, zero, 100 # s2 = 100 (0b01100100) (0x64)
    xori s3, s2, 0b10101010 # s3 = 0b11001110 (0xce)
    srli s4, s2, 2 # s4 = 25 (0b00011001) (0x19)
    addi s5, zero, -1 # s5 = -1 (0b11111111) (0xff)
    srai s6, s5, 4 # s6 = -1 (0b11111111) (0xff)
    ori s7, s2, 0b10101010 # s7 = 0b11101110 (0xee)
    andi s8, s2, 0b10101010 # s8 = 0b00100000 (0x20)
 