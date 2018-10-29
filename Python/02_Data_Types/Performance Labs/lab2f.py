""" Author: ELF
    Course: Python
    version: Python 2.7
    FileName: lab2f.py
    Instructions: 
        Write a program that will be able to check if two words (strings) are anagrams.
        An anagram is a word or phrase formed by rearranging the letters of a different word or phrase
        The program should include:
        All proper comments
        Needed docstrings
        User input (only expecting one user input due to not having gone over loops yet)
"""
from collections import Counter

# prompt user
print("Enter two strings to check is they are anagrams of each other!")

# Get user input strings
string1 = raw_input("Please enter your first string: ").lower()
string2 = raw_input("Please enter your second string: ").lower()

#create counters for each string
string1Counter = Counter(string1)
string2Counter = Counter(string2)

#compare the two counters
if string1Counter == string2Counter:
    print("The two strings are anagrams of each other!")
else:
    print("The two strings are not anagrams of each other!")
    
