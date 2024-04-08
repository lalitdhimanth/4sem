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
typedef struct {
    int queue[10];
    int front ;
    int rear;
}queue;
void enque(queue* q,int a){
    q->queue[++q->rear] = a;

}
int deque(queue* q){
int temp = q->front;
q->front++;
return q->queue[temp];    
}
int isemptyq(queue* q){
    if( q->front >q->rear ){
return 1;    }
return 0;
}
queue * q;
int pushorder[] = {0,0,0,0,0};
int a = 0 ; 
int b = 1 ;
void bfs (int i , int visited[] , int adjmat[][5] ){
        queue * q = (queue*)malloc(sizeof(queue));

    q->front = 0;
    q->rear = -1;
    visited[i] = 1;
    pushorder[a] = i;
    a++;
    enque(q,i);
    while (isemptyq(q) != 1){
        int deq = deque(q);
    for (int j = 0 ; j< 5 ; j++){
        if(adjmat[deq][j] == 1 and visited[j] == 0 ){
            visited[j] = 1;
            enque(q,j);
            pushorder[a] = j ;
            a++;

        }

    }}


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
    
bfs(0 , visited ,adjmat);
for (int i = 0 ; i< 5 ; i++){
        printf("%d\t" , pushorder[i]);
    }

}