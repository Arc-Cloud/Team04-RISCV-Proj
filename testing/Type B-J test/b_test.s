.text
.global main

main:
    # Initialize registers
    addi s0, zero, 5   # Set s0 to 5
    addi s1, zero, 5   # Set s1 to 5

    # Test beq
    beq s0, s1, beq_label  # Branch to beq_label if s0 is equal to s1
    addi s2, zero, 1        # Increment s2 to 1 if s0 is not equal to s1
    j continue_tests       # Jump to continue_tests

beq_label:
    addi s2, zero, 2        # Increment s2 to 2 if s0 is equal to s1

continue_tests:
    # Test bne
    addi s3, zero, 10  # Set s3 to 10
    addi s4, zero, 5   # Set s4 to 5
    bne s3, s4, bne_label  # Branch to bne_label if s3 is not equal to s4
    addi s5, zero, 1        # Increment s5 if s3 is equal to s4
    j continue_jal_tests   # Jump to continue_jal_tests

bne_label:
    addi s5, zero, 2        # Increment s5 if s3 is not equal to s4

continue_jal_tests:
    # Test jal
    jal a0, jal_target  # Jump to jal_target and save return address in x0

    addi s8, zero, 1        # Increment s8 by 1 if jal_target is executed
    j end_of_program       # Unconditional jump to end_of_program

jal_target:
    addi s8, zero, 42       # Set s8 to 42
    ret                     # Return from subroutine

end_of_program:
    # Program ends
