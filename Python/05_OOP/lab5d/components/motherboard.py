class Motherboard:
    """The motherboard class is the root of the PC.
    Everything in the PC is connected to the MOBO so it
    is the core of the system. This class presents
    what is available on the motherboard but functionally
    does nothing for this program.
    """
    def __init__(self, name="", brand="", ioPorts=4, bios="", cpuSocket="", memSlots=4,
                 expansionSlots={"isa":2, "pci":3, "pcie":2, "agp":1},
                 storageDevices=2, powerConnectors="", ideConnectors=True,
                 sata=4, coProcessor=True, cabinetConnectors=8):
        self.name=name
        self.brand=brand
        self.ioPorts=ioPorts
        self.bios=bios
        self.cpuSocket=cpuSocket
        self.memSlots=memSlots
        self.expansionSlots=expansionSlots
        self.storageDevices=storageDevices
        self.powerConnectors=powerConnectors
        self.ideConnectors=ideConnectors
        self.sata=sata
        self.coProcessor=coProcessor
        self.cabinetConnectors=cabinetConnectors

def setName(self,nameStr):
    self.name=nameStr

def setBrand(self,brandStr):
    self.brand=brandStr

def setioPorts(self,numPorts):
    self.ioPorts=numPorts

def setBIOS(self,biosName):
    self.bios=biosName

def setCPUSocket(self, cpuSocketName):
    self.cpuSocket=cpuSocketName

def setMemSlots(self, numMemSlots):
    self.memSlots=numMemSlots

def setExpansioSlotsISA(self, numISA):
    self.expansionSlots["isa"]=numISA

def setExpansioSlotsPCI(self, numPCI):
    self.expansionSlots["pci"]=numPCI

def setExpansioSlotsPCIE(self, numPCIE):
    self.expansionSlots["pcie"]=numPCIE

def setExpansioSlotsAGP(self, numAGP):
    self.expansionSlots["agp"]=numAGP

def setStorageDevices(self, numStorageDevices):
    self.storageDevices=numStorageDevices

def setPowerConnectors(self, powerConnectorName):
    self.powerConnectors=powerConnectorName

def setIDEConnectors(self, ideConnector):
    self.ideConnectors=ideConnector

def setSATA(self, numSATA):
    self.sata=numSATA

def setCoProcessor(self, coProcessorTrue):
    self.coProcessor=coProcessorTrue

def setCabinetConnectors(self, numCabinetConnectors):
    self.cabinetConnectors=numCabinetConnectors

def getName(self):
    return self.name

def getBrand(self):
    return self.brand

def getioPorts(self):
    return self.ioPorts

def getBIOS(self):
    return self.bios

def getCPUSocket(self):
    return self.cpuSocketketName

def getMemSlots(self):
    return self.memSlots

def getExpansioSlotsISA(self):
    return self.expansionSlots["isa"]

def getExpansioSlotsPCI(self):
    return self.expansionSlots["pci"]

def getExpansioSlotsPCIE(self):
    return self.expansionSlots["pcie"]

def getExpansioSlotsAGP(self):
    return self.expansionSlots["agp"]

def getStorageDevices(self):
    return self.storageDevices

def getPowerConnectors(self):
    return self.powerConnectors

def getIDEConnectors(self):
    return self.ideConnectors

def getSATA(self):
    return self.sata

def getCoProcessor(self):
    return self.coProcessor

def getCabinetConnectors(self):
    return self.cabinetConnectors
