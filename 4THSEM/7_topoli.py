class graph:
    def __init__(self,graph,n):
        self.graph = graph
        self.visited=set()
        self.topo1=[]
        self.indegree=[0,0,0,0,0,0]
    def indeg(self):
        for i in self.graph.keys():
            for val in self.graph[i] :
                if val not in self.visited:
                    self.indegree[ord(val)-ord('A')] = self.indegree[ord(val)-ord('A')]+1
                else:
                    self.indegree[ord(val)-ord('A')] = 100000
            
    def topo(self):
        self.indeg()
        a = min(self.indegree)
        if a == 100000:
            return
        a = chr(self.indegree.index(a) + ord('A'))
        self.topo1.append(a)
        self.visited.add(a)
        self.topo()
        
    def printtop(self):
        print(self.topo1)
                                
graph1 = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}
n=6
g=graph(graph1,6)
g.topo()
g.printtop()