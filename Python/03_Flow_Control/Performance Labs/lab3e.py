"""
Author: ELF
Course: Python
version: Python 2.7
FileName: lab3d.py
Lab 3d: Factorial
Recommended Version: Python 2.7
Instructions: 
    Write a file that prints out the first 100 numbers in the Fibonacci sequence iteratively
    Revist this lab and create a Fibonacci recursive function
Requirments:
    Adhere to PEP8 (Comments, formatting, style, etc)
    Utilize proper formatting
    Utilize proper and clean loops and conditionals
    Follow instructions above
Additional:
    Some additional things you can do are:
        Utilize functions
            Create the recursive solution before going over ch04
        Utilize some Python modules or built in functionality
        Ask user for range of numbers to calculate
"""
import time

def fibIt(n):
    """Prints out the numbers in the fibonacci sequence up to n times using an iterative solution"""
    print "Fibonnacci Sequence using an Iterative Solution for {} iterations".format(n)
    start = time.time()
    if n == 0:
        print 0
    elif n ==1:
        print 1
    else:
        currentFib = 1
        lastFib = 0
        print lastFib,
        for i in xrange(n):
            print " {}".format(currentFib),
            temp = currentFib + lastFib
            lastFib = currentFib
            currentFib = temp
    print ("")
    print "This solution took {} seconds\n".format(time.time() - start)

def fibRec(n):
    """Recursive function which returns a digit of the fibonnacci sequence. Base cases are 0 and 1"""
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibRec(n-1) + fibRec(n-2)

def fibRecRun(n):
    """Prints each level of the fibonnacci sequences using a recursive function and the time it takes to do that"""
    print "Fibonnacci Sequence using an Iterative Solution for {} iterations".format(n)
    start = time.time()
    for i in xrange(n):
        print " {}".format(fibRec(i)),
    print ""
    print "This solution took {} seconds\n".format(time.time() - start)

#Main program which runs each of the solutions.

fibIt(50)

print "RECURSIVE"

fibRecRun(50)

            