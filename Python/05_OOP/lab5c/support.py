"""
Author: ELF
Course: Python
version: Python 2.7
FileName: support.py
Lab 5c: Update Hero Class
Recommended Version: Python 2.7
Instructions: 
Instructions
    Update your hero class lab with the following additions:
    Create a generic Person class
    Create a Hero class that inherits from Person
    Refactor code where needed
    Utilize proper Encapsulation
    Include user input
    Use getters and setters
Requirments
    Adhere to PEP8 and utilize proper and efficient code
    Input validation
    Utilize a __init__()
    Ensure variables are correct type (class vs instance variables)
    Utilize methods for getters and setters
    Create an few instances of your class. Populate it with data utilzing a init and/or getters and setters
    Split your classes into seperate files and import them properly
Additional:
    Expand this program into a game or larger program. Some possible ideas:
    Hero vs Villan
    Battle Royal
    Guess that Hero
etc
"""

def getInt(msg = "Enter a menu choice: "):
    """ Returns an integer that the user has inputed."""
    while True:  
        try:
            res = int(raw_input(msg))
            break
        except (ValueError, NameError):
            print "Item not an Int"
    return res

def getString(msg = ': '):
    """Returns a string that the user has inputted."""
    invalidInput = set("01234567890-=!@#$%^&*()_+`~\'\";:.>,</?[]\{\}")
    while True:
        res = raw_input(msg)
        if any((c in invalidInput) for c in res):
           print "Invalid input, only accepts letters"
        else:
            return res