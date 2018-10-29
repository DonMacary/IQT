"""
Author: ELF
Course: Python
version: Python 2.7
FileName: computer.py
Lab 5d: Programming Classes with Composition
Recommended Version: Python 2.7
Instructions: (SUBBBING OUT CAR FOR COMPUTER!)
    Compose a computer class composed of many different component classes:
        Motherboard
        Processor
        Memory(RAM)
        Case
        Power Supply
        Graphics Card
        IO Devices
            Keyboard
            Mouse
            Monitor
            Ausio Device
    Create instances of different types of Computers
    Do these steps last (may take a long time):
        Allow users to create the computer, selecting from a menu of selections to narrow down what type of class to make.
        Save the user computer into a file and allow the users to view, delete, add or modify them
Requirments
    Adhere to PEP8 and utilize proper and efficient code
    Input Validation
    Comments
    File usage
    Packages/user modules
    Proper User Class OOP Principles
"""
from components import *

class Computer:
    """Computer class which will start witih a Motherboard
    and will add components that are compatible with that MOBO
    """
    def __init__(self, Motherboard=None, Processor=None, Memory=None,
                Case=None, PowerSupply=None, GraphicsCard=None,
                InputOutputDevices=None):
        self.Motherboard=Motherboard
        self.Processor=Processor
        self.Memory=[Memory]
        self.Case=Case
        self.PowerSupply=PowerSupply
        self.GraphicsCard=GraphicsCard
        self.InputOutputDevices=InputOutputDevices

    def addProcessor(self, Processor):
        if self.Motherboard.cpuSocket == Processor.socket:
            self.Processor=Processor
        else:
            return "Processor not compatible with MotherBoard"

    def addMemory(self, Memory):
        if self.Motherboard.memSlots > 0:
            if self.Memory==None:
                self.Memory=[Memory]
            else:
                if self.Memory[0].type == Memory.type:
                    self.Memory.append(Memory)
                else:
                    return "Memory is not compatible with other Memory"
        else:
            return "No more Memory Slots"

    def addCase(self, case):
        self.Case=Case





