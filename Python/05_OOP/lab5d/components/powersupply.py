class PowerSupply:
    def __init__(self, powerType="ATX12V", maxPower="350W", 
                supportedConnectors={"4Pin":True, "6Pin":True, "8Pin":True, 
                "24pin":True}):
        self.powerType=powerType
        self.maxPower=maxPower
        self.supportedConnectors=supportedConnectors

    def setPowerType(self,powerType):
        self.powerType=powerType

    def setMaxPower(self,maxPower):
        self.maxPower=maxPower

    def setSupportConnectors4Pin(self,fourPin):
        self.supportedConnectors["4Pin"]=fourPin

    def setSupportConnectors6Pin(self,sixPin):
        self.supportedConnectors["6Pin"]=sixPin

    def setSupportConnectors8Pin(self,eightPin):
        self.supportedConnectors["8Pin"]=eightPin
    
    def setSupportConnectors24Pin(self,twentyFourPin):
        self.supportedConnectors["24Pin"]=twentyFourPin

    def getPowerType(self):
        return self.powerType

    def getMaxPower(self):
        return self.maxPower

    def getSupportConnectors4Pin(self):
        return self.supportedConnectors["4Pin"]

    def getSupportConnectors6Pin(self):
        return self.supportedConnectors["6Pin"]

    def getSupportConnectors8Pin(self):
        return self.supportedConnectors["8Pin"]
    
    def getSupportConnectors24Pin(self):
        return self.supportedConnectors["24Pin"]