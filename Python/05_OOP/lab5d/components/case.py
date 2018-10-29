class Case:
    """The case is the protective layer to all the components
    and offers a cosmetic feel to house the computer. 
    """
    def __init__(self, material="Plastic", leds=False, glassWall=False, size="5x5",
                ioPorts={"HDMI":2, "VGA":0, "DP":1, "DVI":0, "AudioIn":1, 
                "AudioOut":2, "USB":6}, powerButtonLocation="Top"):
        self.material=material
        self.leds=leds
        self.glassWall=glassWall
        self.size=size
        self.ioPorts=ioPorts
        self.powerButtonLocation=powerButtonLocation

    def setMaterial(self, materialType):
        self.material=materialType

    def setleds(self, ledsBool):
        self.leds=ledsBool

    def setGlassWall(self, glassWallBool):
        self.glassWall=glassWallBool

    def setSize(self, sizeString):
        self.size=sizeString

    def setIOPortsHDMI(self, numHDMI):
        self.ioPorts["HDMI"]=numHDMI
    
    def setIOPortsVGA(self, numVGA):
        self.ioPorts["VGA"]=numVGA

    def setIOPortsDP(self, numDP):
        self.ioPorts["DP"]=numDP

    def setIOPortsDVI(self, numDVI):
        self.ioPorts["DVI"]=numDVI

    def setIOPortsAudioIn(self, numAudioIn):
        self.ioPorts["AudioIn"]=numAudioIn

    def setIOPortsAudioOut(self, numAudioOut):
        self.ioPorts["AudioOut"]=numAudioOut

    def setIOPortsUSB(self, numUSB):
        self.ioPorts["USB"]=numUSB

    def setPowerButtonLocation(self, powerButtonLocationString):
        self.powerButtonLocation=powerButtonLocationString

    def getMaterial(self):
        return self.material

    def getleds(self):
        return self.leds

    def getGlassWall(self):
        return self.glassWall

    def getSize(self):
        return self.size

    def getIOPortsHDMI(self):
        return self.ioPorts["HDMI"]
    
    def getIOPortsVGA(self):
        return self.ioPorts["VGA"]

    def getIOPortsDP(self):
        return self.ioPorts["DP"]

    def getIOPortsDVI(self):
        return self.ioPorts["DVI"]

    def getIOPortsAudioIn(self):
        return self.ioPorts["AudioIn"]

    def getIOPortsAudioOut(self):
        return self.ioPorts["AudioOut"]

    def getIOPortsUSB(self):
        return self.ioPorts["USB"]

    def getPowerButtonLocation(self):
        return self.powerButtonLocation
    