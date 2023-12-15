### 4 tests

- The tests were designed to fully test our instruction set during in a simple environment
- They were seperated into:
	- [R-test](/testing/Type%20R%20test/r_test.s)
	- [I-test](/testing/Type%20I%20test/i_test.s)
	- [I-S test](/testing/Type%20I-S%20test/is_test.s) testing load and store
	- [B-J test](/testing/Type%20B-J%20test/b_test.s)

For example, the results waveform for the I test
![I test](Testing_imgs/Single%20cycle/I%20test%20waveform.png)
Which passed all tests 

We quite quickly reached a state where all tests were complete and we started work on the F1 and PDF programs
  
### F1 Program test

Program initialises correct values into the 4 s registers with no issues
![F1 init](Testing_imgs/Single%20cycle/F1%20init.png)
The main loop begins and we start incrementing the s2 register, which functions as intended
![F1 loop.png](Testing_imgs/Single%20cycle/F1%20loop.png)
The loop behaves consistently at every iteration and successfully resets its value once it is complete.
![F1 complete.png](Testing_imgs/Single%20cycle/F1%20complete.png) 

### Reference program test

- There are 3 main subroutines to test: init, build and display, each with their own loop behaviour
- The following tests are done using the sine wave to calculate the pdf from
- Assembly file is contained here: 

#### Init
-  Immediately the PC jumps to address 16 to enter init, storing 4 into ra ready for RET.
- There isn't any way to see the values being written into memory but the loop is executing 3 instructions every loop and is decrementing a1 each time, which follows the program
![Reference Init SCS.png](Testing_imgs/Single%20cycle/Reference%20Init%20SCS.png)
![Reference Init SCS.png](Testing_imgs/Single%20cycle/Reference%20Init%20SCS.png)
- Once a0 reaches 0, we return out of init and PC is restored to 4
- 8 is then loaded to ra as we enter the build subroutine
- a1, a2, a3 and a4 are all initialised with the correct values and we begin loop2

![Init build subroutine.png](Testing_imgs/Single%20cycle/Init%20build%20subroutine.png)

- The correct values from data memory are loaded into to from sine.mem
- We count EF once using t1 as it only appears once
- We when reach EE, t1 is incremented all the way to 5 and then we go to the next value
![t1 increments.png](/testing/Test%20results/Testing_imgs/Pipelined/t1%20increments.png)

![Continued build init.png](Testing_imgs/Single%20cycle/Continued%20build%20init.png)
![Continued build init.png](Testing_imgs/Single%20cycle/Continued%20build%20init.png)
- The loop continues until we reach the max count and we enter the display subroutine at address 88
- We start with displaying values B4, 48 and 24

![Display initial.png](Testing_imgs/Single%20cycle/Display%20initial.png)
- a2 is incrementing correctly to index through the result
- In the middle we seem to oscillate between 0 and 24

![Mid way display oscillation.png](Testing_imgs/Single%20cycle/Mid%20way%20display%20oscillation.png)
- At the end we go back up to 48 and finally C8 then goes to 0

![Display ending.png](Testing_imgs/Single%20cycle/Display%20ending.png)
Then the display loops again once we have reached 255 in a1.


This loosely follows the desired result 
![Sine PDF example.png](Testing_imgs/Single%20cycle/Sine%20PDF%20example.png)
