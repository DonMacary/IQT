""" Author: ELF
    Course: Python
    FileName: lab2c.py
    Instructions: Write a program that calculates the total of an item, with taxes.
        Bonus: Add additional functionality
        Keep in mind that you have not learned Python formatting for print or user input.
        Simple/ugly printing is allowed here.
        Hard code the user input
"""


""" def getFloat(msg)

This function prompts the user to enter a float. It accepts a string using raw_input and attempts to convert it to a float.
If it doesn't work then it will return an error and reprompt the user until proper input is entered.

The function will return the value for the item

"""
def getFloat(msg = 'Enter a value for an item: '):
    while True:  
        try:
            res = float(raw_input(msg))
            break
        except (ValueError, NameError):
            print "Item not a float"
    return res

# Hard code in user input for now
item1 = 15.25
item2 = 62.14
item3 = getFloat("Enter a value for item 3: $")
#convert item3 to a float - if it doesnt work then we print an error


#print the two item's values before calculating their taxes
print("Item 1 costs ${0:.2f} before taxes, item 2 costs ${1:.2f} before taxes and item 3 costs ${2:.2f} before taxes".format(item1, item2, item3))

#calculate the total of each item including a 20% tax....
item1 = item1 + (item1 * .2)
item2 = item2 + (item2 * .2)
item3 = item3 + (item3 * .2)




print("Item 1 costs ${0:.2f} after taxes, item 2 costs ${1:.2f} after taxes and item 3 costs ${2:.2f} after taxes".format(item1, item2, item3))
