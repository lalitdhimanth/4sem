class jugs:
    def __init__(self , jug1, jug2 , target):
        self.jug1 = jug1
        self.jug2 = jug2
        self.target = target
        self.visited = []
        self.pushorder = []
        self.flag = 0
    def dfs(self,jug1state,jug2state):
        
        if (jug1state,jug2state) in self.visited:
            return
        else: 
            self.visited.append((jug1state,jug2state))
            self.pushorder.append((jug1state,jug2state))
        if self.flag ==1:
            return
        if jug1state == target or jug2state == target:
            if jug1state == target :
                jug2state = 0
                self.pushorder.append((jug1state,0))
                print(self.pushorder)
                print(self.visited)
                self.flag = 1
                return
            else:
                jug1state=0
                self.pushorder.append((0,jug2state))
                print(self.pushorder)
                print(self.visited)
                self.flag = 1
        self.dfs(self.jug1,jug2state)
        if self.flag==1:
            return
        self.dfs(jug1state,self.jug2)
        if self.flag==1:
            return
        #water from jug1 to jug2
        for i in range (max(jug1state,jug2state)+1):
            j1 = jug1state - i
            j2 = jug2state+i
            if (j1==0 and j2<=self.jug2) or (j1>0 and j2 == self.jug2):

                self.dfs(j1,j2)
            j1 = jug1state + i 
            j2 = jug2state - i 
            if( j2 == 0 and j1 <= self.jug1) or ( j2 > 0 and j1 == self.jug1 ):

                self.dfs(j1,j2)

            
        
        
        
        
        



jug1,jug2,target = 4, 3 , 2
J = jugs(jug1,jug2,target)
J.dfs(0,0)