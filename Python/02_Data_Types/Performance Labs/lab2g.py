"""
    Author: ELF
    Course: Python
    version: Python 2.7
    FileName: lab2f.py
    Lab 2G: Planets Exercise
    Recommended Version: Python 2.7

    Instructions:
        Execute the commands described by the print statements
"""


planet_string = "Mercury|Venus|Earth|Mars|Jupiter|Saturn|Uranus|Neptune"
#Convert the string to a list
planet_list = planet_string.split("|")

"""
def log_planets()

    this function prints out each element in a list on a new line 

"""
def log_planets():
    print "Here is a list of the planets:"
    for planet in planet_list:
        print planet
    print "----------------\n\n"
#show the original list
log_planets()

#add the sun to the beginning of the list and print
print 'Adding "The Sun" to the beginning of the planets list.'
planet_list.insert(0, "The Sun")
log_planets()

#add pluto to the end of the list and print
print 'Adding "Pluto" to the end of the planets list.'
planet_list.append("Pluto")
log_planets()

#remove "The Sun" from the list
print 'Removing "The Sun" from the beginning of the planets list.'
planet_list.remove("The Sun")
log_planets()

#remove pluto from the end of the list
print 'Removing "Pluto" from the end of the planets list.'
planet_list.remove("Pluto")
log_planets()

#find Earth and store its index
print 'Finding and logging the index of "Earth" in the planets list.'
earth = planet_list.index("Earth")
print("Earth is index: {}".format(earth))
log_planets()

#Remove the planet that occurs after Earth
print 'Removing the planet after "Earth".'
planetAfterEarth = planet_list.pop(earth+1)
log_planets()

#Adding back the planet we just removed and putting it where it was
print 'Addding back in the planet removed after "Earth".'
planet_list.insert(earth+1, planetAfterEarth)
log_planets()

#print the list in reverse order
print 'Reversing the order of the planets list.'
planet_list.reverse()
log_planets()

#Sort the planets alphabetically
print 'Sorting the planets list'
planet_list.sort()
log_planets()