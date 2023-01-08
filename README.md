# Embedded-C
The program essentially adds two 16 bit numbers and displays the sum on the seven segment display.
The Timer1 is used in auto reload mode and to set a baud rate of 9600, the value in TH1 is set at 253 (FD). 
The anode of the 4 seven segment displays (multiplexed) are connected to 4 pins of the port P2 while the data lines are connected to port P1. This allows for all the numbers to be displayed on the seven segment display. The anode values are changed in a very short interval of time (to light up respective SSDs) such that the numbers appear stagnant thereby acheiving the goal of displaying the 4 digits of the sum simultaenously.
The code was written on Keil V5. 
