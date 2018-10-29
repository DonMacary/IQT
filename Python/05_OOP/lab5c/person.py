"""
Author: ELF
Course: Python
version: Python 2.7
FileName: person.py
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

class Person(object):
    def __init__(self, name, age, gender):
        self.name = name
        self.age = age
        self.gender = gender
       
    def setName(self, name):
        self.name = name
        
    def setAge(self, age):
        self.age = age

    def setGender(self, gender):
        self.gender = gender

    def getName(self):
        return self.name

    def getAge(self):
        return self.age

    def getGender(self):
        return self.gender

    def displayPerson(self):
        print "Name: {}".format(self.getName())
        print "Age: {}".format(self.getAge())
        print "Gender: {}".format(self.getGender())

