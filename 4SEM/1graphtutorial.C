#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("enter Number of elements");
    scanf("%d", &n);
    char arr[n];
    printf("ENTER CHARACTERS");

    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &arr[i]);
    }
    int adjmat[n][n];

    int val = 0;
    int flag = 0;
    for (int from = 0; from < n; from++)
    {
        for (int to = 0; to < n; to++)
        {
            printf("DOES %c goes to %c", arr[from], arr[to]);
            scanf("%d", &flag);
            val = 0;
            if (flag == 1)
            {
                printf("ENTER WEIGHT FROM  %c  to %c", arr[from], arr[to]);
                scanf("%d", &val);
            }
            adjmat[from][to] = val;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", adjmat[i][j]);
        }
        printf("\n");
    }
    printf("AJACENCY LIST");
    for (int i = 0; i < n; i++)
    {
        printf("%c ", arr[i]);
        for (int j = 0; j < n; j++)
        {
            if (adjmat[i][j] != 0)
            {
                printf("---> %c.%d", arr[j], adjmat[i][j]);
            }
        }
        printf("\n");
    }
}