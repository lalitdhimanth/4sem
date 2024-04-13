import random

class HCS:
    def __init__(self, LOWERL, UPPERL):
        self.lowerlimit = LOWERL
        self.upperlimit = UPPERL
        self.changex = 0.01
        self.maxfound = -100000
        self.iterations = 0

    def funcx(self, x):
        return x * x  - 8 * x

    def start(self):
        i = 0
        while i < 20:
            a = random.uniform(self.lowerlimit, self.upperlimit)
            self.hcsm(a)
            i += 1

    def hcsm(self, a):
        while True:
            curr = self.funcx(a)
            temp1 = max(min(a+self.changex , 10),-10)
            temp2 = max(min(a-self.changex ,10),-10)
            curraddx = self.funcx(temp1)
            currsubx=self.funcx(temp2)
            arr = [curraddx, currsubx]
            
            # Calculate the threshold as a percentage of the current maximum value found

            
            self.iterations += 1
            if self.iterations > 1000:
                break
            
            if max(arr) > a:
                self.maxfound = max(arr)
                if curraddx > currsubx:
                    a = a + self.changex
                else:
                    a = a - self.changex
            else:
                break

    def printmax(self):
        print(self.maxfound)

hillcs = HCS(-10, 10)
hillcs.start()
print("hello")
hillcs.printmax()
