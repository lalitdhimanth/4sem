class graph:
    def __init__(self,graph1):
        self.graph=graph1
        self.visited=[]
        self.pushorder=[]
        self.cost = 0
        self.flag=0
    def ucs(self,start,goal):
        self.pushorder.append(start)
        self.visited.append(start)
        print(self.flag)

        if start in goal:
            self.flag=1
            return 
        minnode=start
        minvalue = 100

        for i in self.graph[start]:
            if i not in self.visited:
                if self.graph[start][i] < minvalue :
                    minvalue = self.graph[start][i]
                    minnode = i 
        self.cost+= minvalue
        self.ucs(minnode,goal)
        if self.flag==1:
            return
        self.pushorder.pop()
        self.cost-=minvalue
        print("yo")    
    def printcals(self):
        print(self.pushorder)
        print(self.cost)

graph1 = {
    'S':{'A':5 ,'B':9 ,'C':6, 'D':6},
    'A':{'G1':9 , 'B':3}
    ,'B':{'A':2 , 'C':1}
    ,'C':{'G2':5 , 'F':7}
    ,'D':{'E':2}
    ,'E':{'G3':7}
    ,'F':{'D':2,'G3':8}
}
g=graph(graph1)
g.ucs('S' , ['G1','G2','G3'])
g.printcals()