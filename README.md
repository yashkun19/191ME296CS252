# CS252 Assignment

## Description
This assignment consisits of two questions related to multithreading

### Problem 1
Write a multithreaded program that calculates various statistical values
for a list of numbers. This program will be passed a series of numbers
on the command line and will then create three separate worker threads.
One thread will determine the average of the numbers, the second will
determine the maximum value, and the third will determine the minimum value

#### Basic idea
Firstly global variables for array,maximum,minimum,average are declared.  
Input is taken through from command line from the user.  
Functions for finding maximum,minimum and average are declared.  
Seperate threads are created for respective operations.  
These thread access the global variables and update their values.  
Finally all threads are joined together and output is printed on the screen.  

### Problem 2
Write a multithreaded program that outputs prime numbers. This program should work as follows: The user will run the program and will
enter a number on the command line. The program will then create a
separate thread that outputs all the prime numbers less than or equal to
the number entered by the user.

#### Basic idea
The appraoch that we use to find prime number upto n is sieve of Eratosthenes.  
Take the input number n from user.  
Declare a function SieveofEratosthenes.  
Create a bool array of length n and initialize all elements to true.
'''
bool prime[*n + 1];
    memset(prime, true, sizeof(prime));
    '''
