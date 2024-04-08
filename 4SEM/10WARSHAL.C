#include <stdio.h>

int main()
{
    int adjmat[4][4] = {{0, 1, 0, 0},
                        {0, 0, 0, 1},
                        {0, 0, 0, 0},
                        {1, 0, 1, 0}};

    for(int k = 0 ; k<4 ; k++){
    for(int i = 0 ;i<4 ; i++){
        for(int j = 0 ;j<4; j++){
            adjmat[i][j] = adjmat[i][j] || (adjmat[i][k] && adjmat[k][j]);
        }


       }   }
        printf("Adjacency Matrix:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", adjmat[i][j]);
        }
        printf("\n");
    }
}