"""
Author: ELF
Course: Python
version: Python 2.7
FileName: lab3c.py
Lab 3c: Fun House
Recommended Version: Python 2.7
Instructions: 
    Create a text-based game where the user is navigating through a "Fun" House. Prompt the user to make a decision and using if/elif/else statements, give them different outcomes based on their answers. 
    Begin with an introduction to your fun house and prompt the user to choose between at least three different options. You can use nested if/elif/else statements to make the game more complex.

Requirments
    Adhere to PEP8 (Comments, formatting, style, etc)
    Utilize userinput
    Utilize proper formatting
    Utilize proper and clean if/elif/else statements
    Follow instructions above
Additional
    Take this a step further. Use some previous concepts. Here are some things you can do:
        Create a file that holds all of your prompts
        Store file prompts into a list, dict, etc
        Use if/elif/else statements to validate user input
        Use formatting to create UI elements and/or fancy prompts
        Use operators and user input to perform calculations based on prompts
        etc
"""
import random

def getInt(msg = 'Which door would you like to enter?: '):
    """ Returns an integer that the user has inputed."""
    while True:  
        try:
            res = int(raw_input(msg))
            break
        except (ValueError, NameError):
            print "CHOOSE A DOOR NUMBER"
    return res

def funGame():
    """Fun games prompts the user for a number 1-10, if the user guesses correctly then 'alive' is returned. Otherwise 'dead' is returned"""
    print "Pick a number between 1 and 10... NO DECIMALS! If you pick the same number as me then I'll let you live!"
    randomNum = random.randint(1,10)
    print randomNum
    while True:
        choice = getInt("Enter a number!!: ")
        if choice > 10 or choice < 1:
            print "You must only pick a number between 1 and 10!"
        else:
            if choice == randomNum:
                print "Lucky you, looks like this time you get away with your life!"
                print "JUST KIDDING YOU GET TO PICK ANOTHER DOOR! HAHAHAHAHA"
                return "alive"
            else:
                print "Ooh I'm sorry, you lose! TIME TO DIE!!!"
                print "YOU ARE NOW DEAD"
                return "dead"

def jokesGame():
    """jokesGame prompts the user to choose responses to respond to a joke, 'dead' is always returned"""
    print "Welcome to the jokes room! Which joke would you like to hear!?"
    print "1) Knock Knock Joke"
    print "2) Animal Joke"
    print "3) Boring Joke"
    while True:
        choice = getInt("Which Joke do you want to hear?: ")
        if choice == 1:
            print "Knock Knock?"
            print "You: Who's there?"
            print "Dead!"
            print "You: Dead who?"
            print "YOU ARE NOW DEAD"
            return 'dead'
        elif choice == 2:
            print "There was once a very very hungry and scary animal"
            print "And he's right over there..."
            print "YOU HAVE BEEN EATEN BY A STRANGE ANIMAL! YOU ARE NOW DEAD!"
            return 'dead'
        elif choice == 3:
            print "Wow you are NO FUN, I'll just kill you now! BYE BYE"
            print "YOU ARE NOW DEAD!"
            return 'dead'
        else:
            print "You must choose one of the joke options...."

print "Do you want to play a game?!"
print "TOO BAD! YOU HAVE NO CHOICE (except if you hit ctrl c but don't do that..... OR ELSE)"
print "Here's how you play: There are 3 doors in front of you, 1 of them will let you escape to your freedom, but the other two.... well those are a little more FUN >:)"
print "Pick your door wisely! MWAHAHHAHHAHAHHAH\n"


while True:
    print "Door 1: Happy Fun times"
    print "Door 2: Jokes Room"
    print "Door 3: Not this way!"
    response = getInt()
    if response == 1:
        print "Welcome to the Happy Fun times room.... Let's play!\n"
        status = funGame()
        if status == "dead":
            break
    elif response == 2: 
        print "Welcome to the Jokes Gallery! Why don't I tell you a joke....."
        status = jokesGame()
        if status == "dead":
            break
    elif response == 3:
        print "I told you not to go this way! There's no fun over here!!! now you must DIE"
        print "YOU ARE NOW DEAD!"
        break
    else:
        print "You must choose a door!"
    