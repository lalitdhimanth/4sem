class graph:
    def __init__(self):
        self.dict1 = {}
        self.pushorder=[]
        self.poporder=[]

        ###{a : { 'B' : 5 , 'C' : 10}}
    def addedge(self , fromm, to , weight):
        if fromm in self.dict1:
            self.dict2 = self.dict1[fromm]
            self.dict2[to] = weight 
            self.dict1[fromm] = self.dict2
        else:
            self.dict2 = {}
            self.dict2[to] = weight
            self.dict1[fromm] = self.dict2
    def printdict(self):
        print(self.dict1)
    def dfstraversal(self,fromm):
        if fromm not in self.pushorder:
            self.pushorder.append(fromm)
        else:
            return
        if fromm in self.dict1:
            for newdict in self.dict1[fromm]:
                for i in newdict:
                    if i not in self.pushorder :
                        self.dfstraversal(i)
        self.poporder.append(fromm)
    def printa(self):
        print(self.pushorder)
        print(self.poporder)
                    
g = graph()
g.addedge('A', 'B', 5)
g.addedge('A', 'C', 10)
g.addedge('B', 'D', 7)
g.addedge('C', 'E', 3)
g.printdict()
# Perform DFS traversal from node 'A'
g.dfstraversal('A')

# Print the push and pop order
g.printa()