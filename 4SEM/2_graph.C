#include <stdio.h>
#include <stdlib.h>

void printadjlist(int adjmat[][5])
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", i);
        for(int j = 0 ; j<5 ; j++){
            if(adjmat[i][j] != 0 ){
                printf("-> %d " , j);
            }
        }
        printf("\n");
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
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d\t", adjmat[i][j]);
        }
        printf("\n");
    }
    printadjlist(adjmat);
}