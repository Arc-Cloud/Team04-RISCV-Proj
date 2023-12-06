
Take screenshots of cycle diagram
Short explanation of results and why it is working
Expansion where necessary


### Branch and Jump tests




### Store and loads test

  

### I-type test

  
  
  
  

### F1 Program test

Written program is linked here:




  

### Reference program test

- There are 3 main subroutines to test: init, build and display, each with their own loop behaviour
- The following tests are done using the sine wave to calculate the pdf from
- Assembly file is contained here: 

#### Init

![img1](../../imgs/Pasted%20image%2020231206025344.png)

-  Immediately the PC jumps to address 16 to enter init, storing 4 into ra ready for RET.
- There isn't any way to see the values being written into memory but the loop is executing 3 instructions every loop and is decrementing a1 each time, which follows the program
- 
![img2](../../imgs/Pasted%20image%2020231206030114.png)
- Once a0 reaches 0, we return out of init and PC is restored to 4
- 8 is then loaded to ra as we enter the build subroutine
- a1, a2, a3 and a4 are all initialised with the correct values and we begin loop2
![img3](../../imgs/Pasted%20image%2020231206033910.png)
- The correct values from data memory are loaded into to from sine.mem
- We count EF once using t1 as it only appears once
- We when reach EE, t1 is incremented all the way to 5 and then we go to the next value
![img4](../../imgs/Pasted%20image%2020231206043634.png)
- The loop continues until we reach the max count and we enter the display subroutine at address 88
- We start with displaying values B4, 48 and 24
![img5](../../imgs/Pasted%20image%2020231206044133.png)
- a2 is incrementing correctly to index through the result
- In the middle we seem to oscillate between 0 and 24
 ![[Pasted image 20231206044421.png]]
 ![img6](../../imgs/Pasted%20image%2020231206044421.png)
 - At the end we go back up to 48 and finally C8 then goes to 0
  ![[Pasted image 20231206044514.png]]
  Then the display loops again once we have reached 255 in a1.

This somewhat follow the desired result
