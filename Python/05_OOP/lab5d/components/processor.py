class Processor:
    def __init__(self, brand="Intel", productLine="I5", cores=4, 
                hyperThreading=True, clockSpeed="3GHz", socket=2011):
        self.brand=brand
        self.productLine=productLine
        self.cores=cores
        self.hyperThreading=hyperThreading
        self.clockSpeed=clockSpeed
        self.socket=socket

    def setBrand(self, brand):
        self.brand=brand

    def setProductLine(self,productLine): 
        self.productLine=productLine

    def setCores(self, cores):    
        self.cores=cores

    def setHyperThreading(self, hyperThreading):
        self.hyperThreading=hyperThreading

    def setClockSpeed(self, clockSpeed):
        self.clockSpeed=clockSpeed

    def setSocket(self,socket):
        self.socket=socket

    def getBrand(self):
        return self.brand

    def getProductLine(self): 
        return self.productLine

    def getCores(self):    
        return self.cores

    def getHyperThreading(self):
        return self.hyperThreading

    def getClockSpeed(self):
        return self.clockSpeed

    def getSocket(self):
        return self.socket
    

    
