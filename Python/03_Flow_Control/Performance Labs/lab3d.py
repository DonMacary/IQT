"""
Author: ELF
Course: Python
version: Python 2.7
FileName: lab3d.py
Lab 3d: Factorial
Recommended Version: Python 2.7
Instructions: 
    Write a program that prompts a user to input an integer and calculates the factorial of that number using a while loop.
Requirments
    Adhere to PEP8 (Comments, formatting, style, etc)
    Utilize userinput
    Utilize input validation
    Utilize proper formatting
    Utilize proper and clean loops and conditionals
    Follow instructions above
"""

def getInt(msg = 'Input an integer: '):
    """ Returns an integer that the user has inputed."""
    while True:  
        try:
            res = int(raw_input(msg))
            break
        except (ValueError, NameError):
            print "Invalid input! Try Again."
    return res

#Get user input.
while True:
    userInt = getInt()
    if userInt < 0:
        print "Cannot find factorial of a negative number!"
    else:
        break
#Initialize the factorial result int.
fact = 1
print "{}!".format(userInt)
#Loop until the userInt is 1 (could also use a for loop here).
while userInt > 0:
    #Calculate factorial
    fact = userInt*fact
    #If else here is just for print formatting so we don't have an extra 'x' on the end of the print. 
    if userInt == 1:
        print userInt,
    else:
        print "{} x".format(userInt),
    #Don't forget to decrement the number!
    userInt = userInt - 1
#Print the result.
print "=",fact