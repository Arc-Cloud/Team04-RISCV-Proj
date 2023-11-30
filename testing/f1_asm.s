.text
.globl main

main:
    JAL ra, init
    JAL ra, wait

init:
    ADDI s2, zero, 0x0   
    ADDI s3, zero, 0xff  # load s3 with 0x11111111
    addi s4, zero, 0xff  # mask reg
    addi s6, zero, 0x0   # result reg init at 0
    ADDI s5, zero, 0x8   

loopi:
    slli s2, s2, 1    # shift left by 1
    addi s2, s2, 1    # add 1
    and  s6, s4, s2
    bne  s6, s3, loopi
    RET

wait:
    addi s5, s5, -1
    BNE s5, zero, wait
    ADDI s6, zero, 0
