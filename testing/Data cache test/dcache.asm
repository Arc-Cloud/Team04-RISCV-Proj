addi s0, zero, 5
addi s1, zero, 0
LOOP: beq s0, zero, DONE
lw s2, 4(s1)
lw s3, 12(s1)
lw s4, 8(s1)
addi s0, s0, -1
j LOOP
DONE: