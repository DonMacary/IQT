"""
Author: ELF
Course: Python
version: Python 2.7
FileName: lab5b.py
Lab 5b: Superhero
Recommended Version: Python 2.7
Instructions
    Create a very simple super hero class. Some attributes you will need:
    Hero Name
    Real Name
    Power(s)
    Colors
    etc
Requirments
    Adhere to PEP8 and utilize proper and efficient code
    Utilize a __init__()
    Ensure variables are correct type (class vs instance variables)
    Utilize methods:
        Start to format your class using getters and setters
        Create an instance of your class. Populate it with data utilzing a init and/or getters and setters
Additional:
    Begin using encapsulation techniques
"""

class superHero:
    def __init__(self,superName, superPower, weakeness, alias, colorScheme):
        self.superName = superName
        self.superPower = superPower
        self.weakeness = weakeness
        self.alias = alias
        self.colorScheme = colorScheme

    def displayHero(self):
        print "Name: {}".format(self.superName)
        print "Super Power: {}".format(self.superPower)
        print "Weakeness: {}".format(self.weakeness)
        print "Alias: {}".format(self.alias)
        print "Color Scheme: {}\n".format(self.colorScheme)


captainAmerica = superHero("Captain America", "Murica", "Honor", "Steve Rodgers", ["Red", "White", "Blue"])
hulk = superHero("The Hulk", "Big Smash", "No Control", "Bruce Banner", "Green")
ironMan = superHero("Ironman", "Douchebag", "Arrogance", "Tony Stark", ["Red", "Gold"])
thor = superHero("Thor", "God of Thunder", "Big Dummy", "Dr. Donald Blake", "Red Cape?")
blackPanther = superHero("Black Panther", "Super Everything", "Daddy Issues", "Prince T'Challa", "Black")
blackWidow = superHero("Black Widow", "Super Sexy", "No real super powers", "Natasha Romanoff", "Black")
hawkeye = superHero("Hawkeye", "Future Legolas", "Everything", "Blint Barton", "N/A")
antMan = superHero("Ant Man", "teeeny tinnnyy then REALLLLYY BIG", "Getting Stepped on", "Hank Pym", "Ant Colors")
spiderMan = superHero("Spider Man", "Creeps everyone out", "Nobody likes spiders", "Peter Parker", ["Red", "Blue"])
doctorStrange = superHero("Doctor Strange", "Time Control", "Already knows the ending", "Vincent Strange", ["Red", "Blue"] )

Avengers = [ironMan, captainAmerica, hulk, thor, blackPanther, blackWidow, hawkeye, antMan, spiderMan, doctorStrange]
print "THE AVENGERS"
for k in xrange(len(Avengers)): Avengers[k].displayHero()
