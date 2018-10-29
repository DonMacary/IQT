"""
Checks a certain range of numbers to see if they can divide into a user specified num
"""
# Program main, runs at start of program
def launch():
    num = raw_input('What number would you like to check?')
    amount = raw_input('How many numbers do you want to check?')

    if isInt(num) == False or isInt(amount) == False:
        print "You must enter an integer"
        launch() 
    elif int(amount) < 0 or int(num) < 0:
        print "You must enter a number greater than 0"
        launch() 
    else:
        divisable_by(int(num), int(amount))

# Checks num divisable numbers up to amount or itself
def divisable_by(num, amount):
    i = 1.0
    while (num / i >= 1 and amount > 0):
        if num % i == 0:
            print '{} is divsable by {}'.format(int(num), int(i))
            amount -= 1
        i += 1

# EXCEPTION HANDLING
def isInt(x):
    try:
        int(x) ###
        return True
    except ValueError:
        return False

launch()