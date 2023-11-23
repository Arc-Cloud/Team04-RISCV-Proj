.text
.globl main
.org 0xBFC00000

main:
    JAL ra, init
    JAL ra, lfsr_step
    JAL ra, wait

init:
    ADDI s2, zero, 0x0   # load s2 with 0x0
    ADDI s3, zero, 0xff  # load s3 with 0x11111111
    ADDI s4, zero, 0x1   # shift value stored in s4
    ADDI s5, zero, 0x1111

loopi:
    SLL s2, s2, s4    # shift left by 1
    ADD s2, s2, s4    # add 1
    BNE s2, s3, loopi
    RET


# Polynomial: x^4 + x^1 + 1 (0b10011)

lfsr_step:
    # Shift the LFSR value left by one
    slli s5, s5, 1

    # Extract the out bit (bit 3 before the shift, now bit 4)
    # The mask for bit 4 is 0x10 (in binary 00010000)
    andi s6, s5, 0x10

    # If the out bit is set, XOR the LFSR with the polynomial
    # The polynomial is 0b11 (0x03) after ignoring the x^4 term
    # Use branch if not equal to zero to apply the XOR
    bnez s6, apply_xor

    # Skip XOR and go to end
    j end_lfsr_step

apply_xor:
    # Polynomial without the x^4 term is 0x03
    xor s5, s5, 0x03

end_lfsr_step:
    # Mask the LFSR to 4 bits (in case it was more)
    andi s5, s5, 0x0F
    RET

    # s5 now contains the new LFSR value

wait:
    sub s5, s5, s4
    BNE s5, zero, wait
    ADDI s2, s2, zero
