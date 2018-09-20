Problem Description  
Find the sum of two non-negative integers that do not exceed 200 bits.  
  
Input data
There are two lines, each line is a non-negative integer of no more than 200 bits, and there is no extra leading 0.
Output requirements
One line, the result of the addition. There can be no extra leading 0 in the result, ie if the result is 342, then it can't
The output is 0342.  
  
Input sample  
22222222222222222222  
33333333333333333333  
  
Sample output:  
55555555555555555555  
Problem solving  
The first thing to solve is the problem of storing 200-bit integers. Obviously, any C/C++ intrinsic type of variable cannot save it. The most intuitive idea is that you can save it with a string. A string is essentially an array of characters, so for programming convenience, we can also use the array unsigned an[200] to store a 200-bit integer, let an[0] store a single digit, and an[1] store the ten digits. Number, an[2] stores hundreds of digits... So how do you add two large integers? The method is very simple, that is, the simulation of the primary school students in the vertical form of addition, starting from the individual position, bit by bit, exceeding or reaching 10 carry. In other words, save the first number with unsigned an1[201],
Unsigned an2[200] represents the second number and then adds them bit by bit. The result of the addition is stored directly in an1. Pay attention to handling the carry. In addition, the length of the an1 array is set to 201 because the two 200-bit integers are added together and the result may be 201 bits. In actual programming, you don't have to bother to set the size of the array just right. It doesn't matter if you open the big one a bit, so that you don't accidentally calculate the value of "just right", which causes the array to be small, resulting in an out-of-bounds error.  
  
Implementation skills  
1. Re-emphasize: In actual programming, you don't have to bother to set the size of the array just right, a little bigger.
It doesn't matter, so that you don't accidentally calculate the value of "just right", which causes the array to be small, resulting in an out-of-bounds error.  
2. Statement 25 is to convert a character-type number to an unsigned type. For example, to convert the character '8' to an unsigned type of 8. A variable of type char is essentially an int type, and the value is the Ascii code of the character. Since the Ascii code of the character '0' to the character '9' is continuously incremented, the value of '8' - '0' is 8.
