class Graph:
    def __init__(self, graph):
        self.graph = graph

    def is_bipartite_util(self, u, color, visited):
        visited[u] = True
        for v in self.graph[u]:
            if visited[v] and color[v] == color[u]:
                return False
            if not visited[v]:
                color[v] = 1 - color[u]
                if not self.is_bipartite_util(v, color, visited):
                    return False
        return True

    def is_bipartite(self):
        color = {}
        visited = {}
        for u in self.graph.keys():  # Iterating over keys of self.graph
            color[u] = -1
            visited[u] = False
        for u in self.graph.keys():  # Iterating over keys of self.graph
            if not visited[u]:
                color[u] = 1
                if not self.is_bipartite_util(u, color, visited):
                    return False
        return True

# Initialize graph
graph2 = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B', 'G'],
    'E': ['B', 'F'],
    'F': ['C', 'E'],
    'G': ['D']
}

# Create Graph object
g = Graph(graph2)

# Check if graph is bipartite
if g.is_bipartite():
    print("Graph is Bipartite")
else:
    print("Graph is not Bipartite")
