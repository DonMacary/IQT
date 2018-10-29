"""
    Author: ELF
    Course: Python
    version: Python 2.7
    FileName: lab3a.py
    Lab 3a: Mad-Libs
    Recommended Version: Python 2.7
    Instructions: 
        General
            Create your own mad libs game asking the user for input to fill in the blanks. Print out using .format().

            (Humor encouraged)

        Background
            "Mad Libs is a phrasal template word game where one player prompts others for a list of words to substitute for blanks in a story, before reading the often comical or nonsensical story aloud. 
            The game is frequently played as a party game or as a pastime."

        Requirments
            Adhere to PEP8 (Comments, formatting, style, etc)
            Create a handfull of pharses that require different numbers of inputs
            Prompt the user for input(s):
                Inputs can be done a number of ways...
                    (SIMPLE) Ask user for input directly, tell them if the word(s) need to be a verb, noun, etc.
                    (Moderate) Give the user a handful of choices per input to choose from.You will need to create a bank of verbs, nouns, etc for this.
                    (Harder) Give the user cards based off the actual game. Allowing them to draw, etc following the rules. Allow them to only input those cards.
                (opitional) Implement basic user input checking:
                    Check to ensure words are words, numbers are numbers (there are many ways to do this)
                    Ensure symobls aren't used if they are not needed
                    Check length
                    etc
                    Implement re-input if input is incorrect
            Output the user inputs into the given pharse
            Use formatting to not only output the user inputs, but to create a UI within the terminal. Space out certain UI elements such as title of program, choices, menu deceration, etc.
"""

def getInt(msg = 'Enter a menu choice: '):
    """ Returns an integer that the user has inputed."""
    while True:  
        try:
            res = int(raw_input(msg))
            break
        except (ValueError, NameError):
            print "Item not a float"
    return res

def getString(msg = 'Enter a verb: '):
    """Returns a string that the user has inputted."""
    invalidInput = set("01234567890-=!@#$%^&*()_+`~\'\";:.>,</?[]\{\}")
    while True:
        res = raw_input(msg)
        if any((c in invalidInput) for c in res):
           print "Invalid input, only accepts letters"
        else:
            return res
            

def printMenu():
    """ This function prints the menu for the game."""
    print "1) Football game"
    print "2) Video Games game"
    print "3) TV game"
    print "4) Movies game"
    print "5) Exit"

"""The following 4 functions are the different Mad Libs games that are available"""
def football():
    """This mad libs game is all about football, there is no return value, it will only print"""
    print "FOOTBALL GAME:\n"
    print "Football is back baby! Which means we get to watch ___________ (noun) ______________! (verb/phrase)\n"
    noun = getString("Enter a noun: ")
    verb = getString("Enter a verb or phrase: ")
    print "Football is back baby! Which means we get to watch {} {}!\n".format(noun, verb)
    print "My favorite part about football is watching the referee pull out his ______________ (noun) when a player _____________. (verb/phrase)\n"
    noun = getString("Enter a noun: ")
    verb = getString("Enter a verb or phrase: ")
    print "My favorite part about football is watching the referee pull out his {} when a player {}.\n".format(noun, verb)
    print "I can't wait to watch ______________(noun) lose a close game by ________________! (verb/phrase)\n"
    noun = getString("Enter a noun: ")
    verb = getString("Enter a verb or phrase: ")
    print "I can't wait to watch {} lose a close game by {}\n".format(noun, verb)

def videoGames():
    """This mad libs game is all about video games, there is no return value, it will only print"""
    print "VIDEO GAMES!\n\n"
    print "Welcome to the World of ____________ (noun) where you are a ____________ (noun) whose only purpose is to _____________! (verb/phrase) \n"
    noun1 = getString("Enter the first noun: ")
    noun2 = getString("Enter the second noun: ")
    verb = getString("Enter a verb or phrase: ")
    print "Welcome to the World of {} where you are a {} whose only purpose is to {}!\n".format(noun1, noun2, verb)
    print "My favorite weapon is the _________________(noun) because I like to use it to ________________(verb/phrase)\n"
    noun = getString("Enter a noun: ")
    verb = getString("Enter a verb or phrase: ")
    print "My favorite weapon is the {} because I like to use it to {}\n".format(noun, verb)


def television():
    """This mad libs game is all about TV, there is no return value, it will only print"""
    print "TV game\n\n"

def movies():
    """This mad libs game is all about movies, there is no return value, it will only print"""
    print "Movies game\n\n"

def printExit():
    """Prints a message for exiting the game"""
    print "Thank you for playing! See you next time!"

print "Welcome to Bad Libs! The game of Mad libs but a much more bad version!!"
#response is a conditional variable for game loop to work, it will be constantly updated within the game loop.
response = 0
#This is the beginning of the game loop which will print the menu, accept user input, and play the game functions depending on user input.
while response != 5:
    printMenu()
    response = getInt()
    menuOptions = {
        1: football,
        2: videoGames,
        3: television,
        4: movies,
        5: printExit
    }
    choice = menuOptions.get(response, lambda: "Invalid Choice, Please Try again\n\n")
    choice()

