class Graph:
    def __init__(self,graph , hurestic):
        self.graph=graph
        self.heuristic=hurestic
        self.costtill=0
        self.pushorder=[]
        self.visited=[]
        self.flag=0
    def Astar(self, start , goal):
        self.pushorder.append(start)
        self.visited.append(start)
        arr = []
        if self.flag==1:
            return
        if start == goal:
            self.flag=1
            return
        for i in self.graph[start]:
            if i not in self.visited:
                tup = (i , self.graph[start][i])
                arr.append(tup)
        newmincost = 100000
        newminpath=start
        for i,j in arr:
            heurval = self.heuristic[i]
            if j+heurval< newmincost :
                newmincost = j +heurval
                newminpath = i
        self.costtill+= newmincost - self.heuristic[newminpath] 
        print(self.costtill,newmincost,newminpath)
        self.Astar(newminpath, goal)
    def printpathandcost(self):
        print(self.pushorder)
        print(self.costtill)
graph_data = {
    'A': {'B': 6, 'F': 3},
    'B': {'A': 6, 'C': 3, 'D': 2},
    'C': {'B': 3, 'D': 1, 'E': 5},
    'D': {'B': 2, 'C': 1, 'E': 8},
    'E': {'C': 1, 'D': 8, 'I': 5, 'J': 5},
    'F': {'A': 3, 'G': 1, 'H': 7},
    'G': {'F': 1, 'I': 3},
    'H': {'F': 7, 'I': 2},
    'I': {'E': 5, 'G': 3, 'H': 2, 'J': 3},
    'J': {'E': 5, 'I': 3}
}

hurestic = {
            'A': 10,
            'B': 8,
            'C': 5,
            'D': 7,
            'E': 3,
            'F': 6,
            'G': 5,
            'H': 3,
            'I': 1,
            'J': 0
        }
g = Graph(graph_data ,hurestic)
g.Astar('A' , 'J')
g.printpathandcost()