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
from superHero import superHero
from support import *

class Avengers:
    def __init__(self):
        self.heroList = []

    def deleteHero(self, superHero):
        self.heroList.remove(superHero)

    def DisplayAvengers(self):
        """Prints a list containing superHeros"""
        print "THE AVENGERS"
        for k in xrange(len(self.heroList)): self.heroList[k].displayHero()

    def FindHero(self, msg = "Enter the hero you would like to find: " ):
        """Returns a superHero object if it is contained in the list"""
        print msg
        heroStr = getString()
        for k in xrange(len(self.heroList)): 
            if self.heroList[k].getSuperName() == heroStr:
                return self.heroList[k]
        return "NULL"

    def DisplayFound(self):
        """Prints a superHero if it is found in the list"""
        hero = self.FindHero()
        if hero != "NULL":
            hero.displayHero()
        else:
            print "Hero Not Found"

    def AddHero(self, newHero=None):
        if newHero==None:
            newHero = superHero("",0,"","","","","")
            newHero.setName(getString("Enter Heros real name: "))
            newHero.setAge(getInt("Enter Hero's age: "))
            newHero.setGender(getString("Enter Hero's Gender: "))
            newHero.setSuperName(getString("Enter Hero's super name: "))
            newHero.setSuperPower(getString("Enter Hero's super power: "))
            newHero.setWeakness(getString("Enter Hero's weakness: "))
            newHero.setColorScheme(getString("Enter Hero's Color: "))
            self.heroList.append(newHero)
        else:
            self.heroList.append(newHero)

    def DeleteHero(self):
        hero = self.FindHero("Which Hero would you like to delete? ")
        if hero != "NULL":
            self.heroList.remove(hero)
        else:
            print "Hero Not Found"
    
    def ChangeHero(self):    
        hero=self.FindHero("Which Hero would you like to change?: ")
        if hero!="NULL":
            response =0
            while response!=9:
                print "Which Attribute would you like to change?"
                print ("1:Real Name\n2:Age\n3:Gender\n4:SuperName\n"
                    +"5:Super Power\n6:Weakness\n7:Color\n8:Display hero"
                    +"\n9:Finished\n")
                response = getInt(":")
                options = {
                    1:lambda: hero.setName(getString("Enter Heros real name: ")),
                    2:lambda: hero.setAge(getInt("Enter Hero's age: ")),
                    3:lambda: hero.setGender(getString("Enter Hero's Gender: ")),
                    4:lambda: hero.setSuperName(getString("Enter Hero's super name: ")),
                    5:lambda: hero.setSuperPower(getString("Enter Hero's super power: ")),
                    6:lambda: hero.setWeakness(getString("Enter Hero's weakness: ")),
                    7:lambda: hero.setColorScheme(getString("Enter Hero's Color: ")),
                    8:lambda: hero.displayHero(),
                    9:lambda: "No more changes will be made!"
                }
                choice = options.get(response, lambda: "Invalid Choice, Please Try again\n\n")
                choice()
        