### 4 basic tests

These tests were written to test the operation of all included instructions while also testing the hazard unit for RAW and branch/jump hazards during general operation. They are the same assembly programs used for the single cycle CPU.

These immediately helped us debug and fix initial bugs in our hazard unit in a clean environment, e.g. we had a bug in our memory forwarding in the hazard unit for RAW hazards in the i_type test (path here), which resulted in us changing the code from this:
![Broken forwarding.png](/testing/Test%20results/Testing_imgs/Pipelined/Broken%20forwarding.png)
to this:
![Fixed forwarding.png](/testing/Test%20results/Testing_imgs/Pipelined/Fixed%20forwarding.png)

Once all tests passed we moved on to the F1 and PDF programs

### F1 program

The F1 program remains unchanged, just requires verification of functionality

We start well with flushing the execute stage to prepare for the jump to init and initialisation begins.
![F1 init](Testing_imgs/Pipelined/F1%20init.png)

Initialisation of the registers completes successfully. To then prepare for the RAW hazard in loopi we set forwarding AE and BE to 10, then we flush the execute 3 cycles later to account for the first branch hazard. We then flush again due to the second bne and then one more time for the ending of the loop when we use RET and call JALR.
![F1 hazards](Testing_imgs/Pipelined/F1%20hazards.png)
All the while s2 is successfully incrementing to simulate the f1 lights. Program is also shown working in the video





### PDF program

Simulation was ran with the Gaussian waveform
- Instantiation worked well and we enter into loop 1 with 256 being written into a1 and the decrement starting
- Can't see values written to memory but CPU behaviour remains consistent
- Hazard unit correctly flushes the execute stage once the BNE instruction reaches decode to avoid branch hazard
![CPU initialisation](Testing_imgs/Pipelined/CPU%20initialisation%20pipe.png)
- Once we are finished with loop 1 we flush twice since we have jumped back to main, then we prepare to jump to build which occurs successfully and initialisation is successful 
 ![End of init.png](Testing_imgs/Pipelined/End%20of%20init.png)


- Loop 2 has been entered, a5 is incrementing successfully, and the correct values from data mem are written into t0.
- We successfully flush the execute stage to account for jump and branch hazards when repeating the loop once we have verified branch direction
- The pipeline is also successfully stalled at fetch and decode to avoid RAW hazards during LBU as shown by the **enable** waveforms
- Initially we faced problems with not flushing the execute stage during JALR instructions, which was fixed when we saw 0x10000 being written to a1 several cycles early
- One gigantic issue we faced was datamem values not being written to t0, which we though was because of JALR. When we fixed JALR and this still happened we were stuck for a day.
- All the fix required was that we hadn't applied the offset of 0x10000 when initialising in system verilog, denoted by commit 80cc125
- Post fixes, the loop behaves as expected

![Initialisation build.png](Testing_imgs/Pipelined/Initialisation%20build.png)
- We successfully return and jump to the display stage (300000 cycles later!)
- The output signal on a0 shows a clear correlation to a gaussian distribution, peaking at the value C8 at index 108 and appears to work in the video shown in the readme.
