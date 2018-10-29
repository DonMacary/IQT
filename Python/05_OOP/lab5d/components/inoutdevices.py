class InputOutputDevices:
    """Contains a list of Input Output Devices"""
    def __init__(self):
        self.ioDevices=[]

    def addIODevice(self, device, inOrOut, connector):
        self.ioDevices.append([device,inOrOut,connector])

    def removeIODevice(self, device):
        self.ioDevices.remove(device)

    def displayIODevices(self):
        print "IO Devices"
        for k in xrange(len(self.ioDevices)): 
            print("{}:\tName - {}\n\tInput\Output: {}\n \
            \tConnector - {}".format(k, self.ioDevices[k][0],
            self.ioDevices[k][1], self.ioDevices[k][2]))

    