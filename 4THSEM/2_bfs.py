class graph:
    def __init__(self):
        self.dict1 = {}
        self.queue=[]
        self.visited=[]
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
    def bfstraversal(self,from_node):
        self.queue.append(from_node)
        self.visited.append(from_node)
        while len(self.queue)>0:
            a = self.queue.pop(0)
            if a in self.dict1:
                for i in self.dict1[a]:
                    for j in i:
                        if j not in self.visited:
                            self.queue.append(j)
                            self.visited.append(j)
    def printm(self):
        print(self.visited)
                    
        
        
g = graph()
g.addedge('A', 'B', 5)
g.addedge('A', 'C', 10)
g.addedge('B', 'D', 7)
g.addedge('C', 'E', 3)
g.printdict()
g.bfstraversal('A')
g.printm()