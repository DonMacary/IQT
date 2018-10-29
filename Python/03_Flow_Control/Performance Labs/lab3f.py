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
    for i in xrange(1, 101):
        if i % 5 == 0 and i % 3 == 0:
            print "{}: FizzBuzz".format(i)
        elif i % 5 == 0:
            print "{}: Buzz".format(i)
        elif i % 3 == 0:
            print "{}: Fizz".format(i)
        else:
            print i

def fizzbuzz_elegant():
    """Prints out Fizz on multiples of 3, Buzz on multiples of 5 and 15 
    on multiples of 3 and 5. Uses 2 if statements within a for loop
    """
    #Improved solution, uses a variable to track the string.
    #Removes the need for a third if statement and no elses!
    for i in xrange(1,101):
        text = "{}: ".format(i)
        if i % 3 == 0:
            text += "Fizz"
        if i % 5 == 0:
            text += "Buzz"
        print text

def fizzbuzz_condensed():
    """Prints out Fizz on multiples of 3, Buzz on multiples of 5 and 15
    on multiples of 3 and 5. Condensed as much as possible!
    """
    #This eliminates the use of conditional logic completely!
    #note:This loop starts at 0 and prints based of index number not
    #the actual element.
    for x in range(101):print x%3/2*'Fizz'+x%5/4*'Buzz' or x+1

def fizzbuzz_condensed2():
    """Prints out Fizz on multiples of 3, Buzz on multiples of 5 and 15 
    on multiples of 3 and 5 Condensed to one line!
    """
    #This uses conditional logic in line, allowing us to measure by
    #index and element number!
    for x in xrange(1,101):print('{}:'.format(x)+'Fizz'*(x%3==0)
                                +'Buzz'*(x%5==0))
        
def fizzbuzz_condensed3():
    """Prints out Fizz on multiples of 3, Buzz on multiples of 5 and 15 on 
    multiples of 3 and 5. Condensed to 3 lines!
    """
    #Essentially Condensed 2 but pulled the print out to be more
    #understandable.
    for x in xrange(1,101): 
        out = "{}: ".format(x) + "Fizz"*(x%3 ==0)+"Buzz"*(x%5 == 0)
        print out
    

#fizzbuzz_simple()
#fizzbuzz_elegant()
#fizzbuzz_condensed()
fizzbuzz_condensed2()
#fizzbuzz_condensed3()