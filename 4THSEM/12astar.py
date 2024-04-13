class Puzzle:
    def __init__(self,puzzle):
        self.puzzle=puzzle
        self.nodestraversed=0
    def misplacedtiles(self,finalstate):
        i = 0 
        j = 0
        count=0
        for j in range(3):
            for i in range(3):
                if self.puzzle[i][j]!=finalstate[i][j]:
                    count = count+1
        return count
    def upmove(self):
        a = b = 0
        for i in range(3):
            for j in range(3):
                if self.puzzle[i][j] == 0:
                    a, b = i, j
        newpuz = self.puzzle.copy()
        print(self.puzzle)

        if a > 0:  # Check if moving up is possible
            newpuz[a][b], newpuz[a - 1][b] = newpuz[a - 1][b], newpuz[a][b]
        return newpuz
    def downmove(self):
        a=b=0
        for j in range(3):
            for i in range(3):
                if self.puzzle[i][j] == 0 :
                    a,b = i,j
        newpuz = self.puzzle.copy()
        if a <=1 :
            newpuz[a+1][b] , newpuz[a][b] = newpuz[a][b] , newpuz[a+1][b]
        
        return newpuz
    def rightmove(self):
        a=b=0
        for j in range(3):
            for i in range(3):
                if self.puzzle[i][j] == 0 :
                    a,b = i,j
        newpuz = self.puzzle.copy()
        if b<=1:
            newpuz[a][b+1],newpuz[a][b] = newpuz[a][b], newpuz[a][b+1]
        return newpuz
    def leftmove(self):
        a=b=0
        for j in range(3):
            for i in range(3):
                if self.puzzle[i][j] == 0 :
                    a,b = i,j
        newpuz = self.puzzle.copy()
        if b>=1:
            newpuz[a][b-1],newpuz[a][b] = newpuz[a][b], newpuz[a][b-1]
        return newpuz
        
        
            


puzzle=[[1,2,3],
        [8,0,4],
        [7,6,5]]
finals=[[2,8,1],
        [0,4,3],
        [7,6,5]]

P = Puzzle(puzzle)
print(P.downmove())
P.upmove()
print(P.leftmove())
print(P.rightmove())
# print(P.misplacedtiles(finals))
