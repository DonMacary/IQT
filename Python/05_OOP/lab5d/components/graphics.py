class GraphicsCard:
    def __init__(self, name="", brand="", memSpeed="5GB/s", memConfig="3GBDDR5", 
                monitorSupport={"HDMI":True, "DVI":True, "VGA":False, "DP":True}, 
                multiMonitor=4):
        self.name=name
        self.brand=brand
        self.memSpeed=memSpeed
        self.memConfig=memConfig
        self.monitorSupport=monitorSupport
        self.multiMonitor=multiMonitor

    def setName(self, name):
        self.name=name

    def getName(self):
        return self.name

    def setBrand(self, brand):
        self.brand=brand

    def getBrand(self):
        return self.brand

    def setMemSpeed(self, memSpeed):
        self.memSpeed=memSpeed

    def getMemSpeed(self):
        return self.memSpeed

    def setMemConfig(self, memConfig):
        self.memConfig=memConfig

    def getMemConfig(self):
        return self.memConfig

    def setMonitorSupportHDMI(self, hdmiTF):
        self.monitorSupport["HDMI"]=hdmiTF

    def getMonitorSupportHDMI(self):
        return self.monitorSupport["HDMI"]

    def setMonitorSupportDVI(self, dviTF):
        self.monitorSupport["DVI"]=dviTF

    def getMonitorSupportDVI(self):
        return self.monitorSupport["DVI"]

    def setMonitorSupportVGA(self, vgaTF):
        self.monitorSupport["VGA"]=vgaTF

    def getMonitorSupportVGA(self):
        return self.monitorSupport["VGA"]

    def setMonitorSupportDP(self, dpTF):
        self.monitorSupport["DP"]=dpTF

    def getMonitorSupportDP(self):
        return self.monitorSupport["DP"]

    def setMultiMonitor(self, numMonitors):
        self.multiMonitor=numMonitors

    def getMultiMonitor(self):
        return self.multiMonitor

    