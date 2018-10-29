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
from avengers import Avengers
from support import *

AvengersList = Avengers()
#Setting up a bunch entries in a list to play with
AvengersList.AddHero(superHero("Steve Rodgers", 31, "Male", "Captain America", "Murica", "Honor", ["Red", "White", "Blue"]))
AvengersList.AddHero(superHero("Bruce Banner", 40, "Male", "The Hulk", "Big Smash", "No Control", "Green"))
AvengersList.AddHero(superHero("Tony Stark", 48, "Male", "Ironman", "Douchebag", "Arrogance", ["Red", "Gold"]))
AvengersList.AddHero(superHero("Dr. Donald Blake", 43, "Male", "Thor", "God of Thunder", "Big Dummy", "Red Cape?"))
AvengersList.AddHero(superHero("Prince T'Challa", 33, "Male", "Black Panther", "Super Everything", "Daddy Issues", "Black"))
AvengersList.AddHero(superHero("Natasha Romanoff", 29, "Female", "Black Widow", "Super Sexy", "No real super powers", "Black"))
AvengersList.AddHero(superHero("Blint Barton", 37, "Male", "Hawkeye", "Future Legolas", "Everything", "N/A"))
AvengersList.AddHero(superHero("Hank Pym", 32, "Male", "Ant Man", "teeeny tinnnyy then REALLLLYY BIG", "Getting Stepped on", "Ant Colors"))
AvengersList.AddHero(superHero("Peter Parker", 21, "Male", "Spider Man", "Creeps everyone out", "Nobody likes spiders", ["Red", "Blue"]))
AvengersList.AddHero(superHero( "Vincent Strange", 50, "Male", "Doctor Strange", "Time Control", "Already knows the ending", ["Red", "Blue"]))

def printMenu():
    """Prints the main menu."""
    print ("\tMENU\n1:Display Avengers\n2:Find Hero\n3:Add Hero\n" 
    + "4:Delete Hero\n5:Change Hero Details\n6:Exit\n")

def Exit():
    print "Thank you have a nice day!"

response = 0
while response != 6:
    printMenu()
    response = getInt()
    menuOptions = {
        1: AvengersList.DisplayAvengers,
        2: AvengersList.DisplayFound,
        3: AvengersList.AddHero,
        4: AvengersList.DeleteHero,
        5: AvengersList.ChangeHero,
        6: Exit
    }
    choice = menuOptions.get(response, lambda: "Invalid Choice, Please Try again\n\n")
    choice()
