""" Author: ELF
    Course: Python
    FileName: lab2d.py
    Instructions: 
        Write a program that reverses a user inputted string then outputs the new string, in all uppercase letters.
        Bonus: Add additional functionality, experiment with other string methods.
"""

#Accept user input
userString = raw_input("Enter a string: ")

#Create a reverse of the user input
reverseString = userString[::-1]

#print the reversed string in all uppsercase
print(reverseString.upper())


