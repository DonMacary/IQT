"""
    Author: ELF
    Course: Python
    version: Python 2.7
    FileName: lab2h.py
    Lab 2h: Dictionaries
    Recommended Version: Python 2.7

    Instructions:
        Create a program that takes input of a group of students' names and grades...
        then sorts them based on highest to lowest grade. Then calculate and print the sorted list and the average for the class. (Hint: Use Dictionaries!)
"""
#open a file with students grades
gradesFile = open("studentGrades.txt", "r")
#creates a list of each line of the file ended with a null terminator
lines = gradesFile.readlines()
#create a dictionary to store the student grades
studentGrades = {}
classAverage = 0.0
#loop through the list of lines
for i in range(len(lines)):
    #split the names from the grades
    temp = lines[i].split("|")
    #store the name as the key in the dictionary and then the grades as a list for the value of that dictionary also make all the grades ints
    tempGrades = map(int,temp[1:-1])
    #calculate the student's average
    average = float( sum(tempGrades ) / len(tempGrades ) )
    #create a tuple for the list of students grades and their average
    value = (average, sorted(tempGrades, reverse=True))
    #assign the dictionary value as the tuple
    studentGrades[temp[0]] = value
    #add the student's average to the class average
    classAverage = classAverage + average

#finish calculating the class average
classAverage = classAverage / len(lines)
#print the students grades and the class average
print studentGrades
print "The Class Average is {}".format(classAverage)

gradesFile.close()
