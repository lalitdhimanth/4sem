#include <stdio.h>
int C[100][100];

int min(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int main()
{for (int i = 0; i < 100; i++)
{
    for (int j = 0; j < 100; j++)
    {
        C[i][j] = 0;
    }
}
    int n = 20;
    int k = 5;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
            {
                C[i][j] = 1;
            }
            else
            {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    printf("%d", C[20][5]);
}