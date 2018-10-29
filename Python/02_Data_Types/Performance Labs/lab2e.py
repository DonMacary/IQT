""" Author: ELF
    Course: Python
    FileName: lab2e.py
    Instructions: 
        Write a program that takes a string as user input then counts the number of words in that sentence.
        Bonus: Add additional functionality, experiment with other string methods.
        ex: Output number of characters, number of uppercase letters, etc...
"""
#accept user input into userString
userString = raw_input("Enter a string: ")

stringList = userString.split(" ")

print("There are {} words in the string you provided".format(len(stringList)))

print("There are {} letters in the string you provided".format(sum(1 for c in userString if c.isupper()) + sum(1 for l in userString if l.islower())))

print("There are {} capital letters in the string you provided".format(sum(1 for c in userString if c.isupper())))

print("There are {} lowercase letters in the string you provided".format(sum(1 for l in userString if l.islower())))
