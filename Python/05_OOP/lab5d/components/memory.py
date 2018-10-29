class Memory:
    """Displays the type of RAM"""
    def __init__(self, type="", size=8):
        self.type=type
        self.size=size

    def setType(self, type):
        self.type=type
    
    def setSize(self, size):
        self.size=size

    def getType(self):
        return self.type

    def getSize(self):
        return self.size
