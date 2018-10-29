"""
Author: ELF
Course: Python
version: Python 2.7
FileName: lab3f.py
Lab 3f: FizzBuzz
Recommended Version: Python 2.7
Instructions: 
    Iterate through a loop 100 times, print Fizz if the number 
    is divisble by 3,print Buzz if it is divisible by 5.
    Print FizzBuzz if its divisible by both.
Requirments:
    Adhere to PEP8 (Comments, formatting, style, etc)
    Utilize proper formatting
    Utilize proper and clean loops and conditionals
    Follow instructions above
Additional:
    Create two versions:
        One version which is as short as possible
        Another version which is as drawn out and creative as possible
"""
def fizzbuzz_simple():
    """Prints out Fizz on multiples of 3, Buzz on multiples of 5 and 15
    on multiples of 3 and 5. Uses multiple if else statements within a 
    for loop.
    """
    #Simplest solution using nothing to attempt to condense the function.
    # For loop all the numbers and check if the divisors.
    print "Fizz Buzz in for Loop But longer!"
    for i in xrange(1, 101):
        if i % 5 == 0 and i % 3 == 0:
            print "{}: FizzBuzz".format(i)
        elif i % 5 == 0:
            print "{}: Buzz".format(i)
        elif i % 3 == 0:
            print "{}: Fizz".format(i)
        else:
            print i
