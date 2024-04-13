class graph:
    def __init__(self, graph, n):
        self.graph = graph
        self.pushorder = []
        self.poporder = []
        self.visited = set()
        self.curr=''
        self.newgraph={}
    def setcurr(self,curr, graph):
        self.curr=curr
        self.visited=set()
        self.pushorder=[]
        self.newgraph = graph
    def dfs(self, start):
        if start not in self.visited:
            self.pushorder.append(start)
            self.visited.add(start)  # Mark the current node as visited
        i=self.graph[start].copy()
        for j in i :
            if j not in self.visited:

                self.graph[start].remove(j)
                self.dfs(j)
                print("kya hua")
            elif j in self.visited and j == self.curr :
                print("Cycle, :" ,end='')
                revarr = self.pushorder[::-1]
                revindex = len(revarr) - 1 - revarr.index(j)
                print(self.pushorder[revindex:] , end ='')
                print(f"\t {j}")

    def findcycle(self, start):
        index = self.pushorder.index(start)
        cycle = self.pushorder[index:]
        print("Cycle:", cycle)

    def printpushpop(self):
        print("Push Order:", self.pushorder)
        print("Pop Order:", self.poporder)


graph1 = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E', 'A']  # Introducing a cycle: 'F' -> 'A'
}

G = graph(graph1, 6)
G.setcurr('A',graph1)
G.dfs('A')
G.printpushpop()