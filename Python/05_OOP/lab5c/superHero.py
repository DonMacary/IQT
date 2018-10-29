"""
Author: ELF
Course: Python
version: Python 2.7
FileName: hero.py
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
from person import Person

class superHero(Person):
    def __init__(self, name, age, gender, superName, superPower, weakness, colorScheme):
        Person.__init__(self, name, age, gender)
        self.superName = superName
        self.superPower = superPower
        self.weakness = weakness
        self.colorScheme = colorScheme

    def setSuperName(self, superName):
        self.superName = superName
    
    def setSuperPower(self, superPower):
        self.superPower = superPower

    def setWeakness(self, weakness):
        self.weakness = weakness

    def setColorScheme(self, colorScheme):
        self.colorScheme = colorScheme

    def getSuperName(self):
        return self.superName
    
    def getSuperPower(self):
        return self.superPower

    def getWeakness(self):
        return self.weakness

    def getColorScheme(self):
        return self.colorScheme

    def displayHero(self):
        self.displayPerson()
        print "SuperName: {}".format(self.getSuperName())
        print "Super Power: {}".format(self.getSuperPower())
        print "Weakeness: {}".format(self.getWeakness())
        print "Color Scheme: {}\n".format(self.getColorScheme())
