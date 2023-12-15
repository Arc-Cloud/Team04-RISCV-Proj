# Idrees

My role on the team mostly revolved around a very holistic overlook on the whole project, beginning with building the master TLD file for our Single Cycle CPU. Once the others had finished the first version of the single cycle I was tasked with simulating the CPU and getting it in a running state so that we can debug the control flow and test with written programs. I wrote the bash scripts necessary and the C++ test bench. This also required continuous maintenance of our file structure, file and variable naming.

I wrote 4 assembly programs grouped by instruction type to test our instruction set. An example for testing branch and jump instructions is below. 

```systemverilog
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
    jal ra, jal_target  # Jump to jal_target and save return address in a0

    addi s8, zero, 1        # Increment s8 by 1 if jal_target is executed
    j end_of_program       # Unconditional jump to end_of_program

jal_target:
    addi s8, zero, 42       # Set s8 to 42
    ret                     # Return from subroutine

end_of_program:
    # Program ends
```

They were instrumental for initial debugging of the CPU as they were very basic programs with a very easy to follow control flow. Combined they were efficient in not only testing the instruction set but also contained the hazards necessary to ensure our pipelined CPU would break down the line if our hazard unit was not developed correctly.

With these assembly programs I used gtkWave to analyse the output waveforms in detail. If there was an error in output or the values being written to registers I would see if I could fix it myself and if not, I would talk with the relevant person, tell him what was wrong and we would go through it together. This proved to be very successful and we were able to test and verify the single cycle CPU very quickly. I then wrote up these successful tests in a markdown file for reference and to prove it was working. Fixes I applied myself where usually edits to the control and ALU modules where some control signals were missing or states were incorrectly set at the wrong times, such as in commit 54d3a5d and commit 1c96195.

This work was continuous especially as we moved onto the pipelined CPU.  Distributed development across modules and mismatch between processor branches caused a lot of differences with naming conventions etc producing a large amount of runtime errors. I spent a lot of time getting the whole CPU in a working state, step by step working through compiler warnings and analysing all the code written thus far, e.g. in commit 47ed292. This required knowledge on every single part of the CPU to know exactly what to look for when starting debug to know what exactly is going wrong. The time spent on most bugs did not usually reflect the time required to fix them, such as commit 80cc125, which took us a few hours to realise and was the result of miscommunication and us incorrectly tracking progress between git branches.

To make individual testing for the other users easier I also extended our script to include a menu which automatically configured paths between files and ran the desired program here (include path). I would also spend time ensuring our git branches were healthy and our working directory was always in a clean state, though this was also a collective thing.

Due to the holistic nature of my role I learned a huge amount regarding a RISC V CPU while also strengthening my assembly and bash scripting skills. My git knowledge was also solidified and I enjoyed being able to overseer the overall development of the CPU.

I certainly could have contributed more towards the teamwork aspect as I rarely spent much time with the team as a whole, working in the later hours instead to verify their work done during the day. I also could have contributed more in the beginning, perhaps by working with some of the control logic which would have prevented bugs down the line and saved us some time.

