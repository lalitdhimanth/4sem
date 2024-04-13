class graph:
    def __init__(self,graph,n):
        self.graph = graph
        self.pushorder=[]
        self.poporder=[]
        self.maze=[]
    def dfs(self,start,dest):
        self.maze.append(start)
        self.pushorder.append(start)
        for i in self.graph[start]:
            if i not in self.pushorder:
                self.dfs(i,dest)
                
                if i == dest:
                    self.maze.append(i)
                    print(self.maze)
                    return
        if self.maze:        
            self.maze.pop(-1)
        self.poporder.append(start)    
    def printpushpop(self):
        print(self.pushorder)
        print(self.poporder)

Maze={
	1:[2,6],
	2:[1,3],
	3:[2,8],
	4:[5],
	5:[4,10],
	6:[1,11],
	7:[8],
	8:[3,7],
	9:[10,14],
	10:[5,9,15],
	11:[6,12],
	12:[11,17],
	13:[14],
	14:[13,9,19],
	15:[10,20],
	16:[17],
	17:[12,16,18],
	18:[17,19],
	19:[14,18],
	20:[15],
	0:[2,5]
}

n = 6
G = graph(Maze,6)
G.dfs(2,20)
