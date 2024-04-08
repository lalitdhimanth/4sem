#include <stdio.h>
#include <stdlib.h>

void printadjlist(int adjmat[][5])
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t ", i);
        for(int j = 0 ; j<5 ; j++){
            if(adjmat[i][j] != 0 ){
                printf("-> %d " , j);
            }
        }
        printf("\n");
    }
}
int pushorder[] = {0,0,0,0,0};
int poporder[] = {0,0,0,0,0};
int a = 0 ; 
int b = 0;


void dfs (int adjmat[][5] , int i ,int visited[]){
pushorder[a] = i;
a++;
// int pushorder[5];
    // int poporder[5];
visited[i] = 1;
for (int j = 0 ; j< 5 ; j++){
    if (visited[j] == 0 && adjmat[i][j] ==1){
        dfs(adjmat , j , visited);
        poporder[b] = j ;
        b++;
    }
}
}
int main()
{   
       
    printf("printing graph\n ");
    int adjmat[5][5] = {
        {0, 1, 0, 1, 0}, // Node 0
        {1, 0, 1, 1, 1}, // Node 1
        {0, 1, 0, 0, 1}, // Node 2
        {1, 1, 0, 0, 1}, // Node 3
        {0, 1, 1, 1, 0}  // Node 4
    };
  
    int visited[] = {0,0,0,0,0};
    dfs(adjmat , 0 ,visited);
    for (int i = 0 ; i< 5 ; i++){
        printf("%d\t" , pushorder[i]);
    }
    printf("\n");
    for (int i = 0 ; i< 5 ; i++){
        printf("%d\t" , poporder[i]);
    }
}