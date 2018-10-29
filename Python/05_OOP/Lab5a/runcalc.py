"""
Author: ELF
Course: Python
version: Python 3.X
FileName: runcalc.py
Lab 5Aa: Calculator
Recommended Version: Python 3.X
IMPORTANT: You must double click the application in windows or
download the Tkinter package in linux. The package is not
installed by default in linux but is in Windows!
Instructions:
    Using your calculator you created from Lab4A, split up the functionality into modules and utilize packaging.
    Some things you could split up:

    The user menu into it's own module on a higher level package
    Opeations into one module, lower level
    Algorithms into one module, lower level
etc
"""
from myCalc import myCalculator
from Tkinter import *


root = Tk()
obj2 = myCalculator(root)
root.mainloop()