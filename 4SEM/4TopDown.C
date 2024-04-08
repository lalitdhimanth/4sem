#include <stdio.h>
#include <stdlib.h>
void heapify(int arr[], int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        int k = i;
        int v = arr[i];
        bool heap = false;
        while (!heap && 2 * k < n - 1)
        {
            int j = 2 * k + 1;
            if (j < n - 1)
            {
                if (arr[j + 1] > arr[j])
                {
                    j++;
                }
            }
            if (v > arr[j])
            {
                heap = true;
            }
            else
            {
                arr[k] = arr[j];
                k = j;
            }
        }
        arr[k] = v;
    }
}

int main()
{
    int n = 1;
    int *arr = (int *)malloc(n * sizeof(int));
    int val;
    while (1)
    {
        arr = (int *)realloc(arr, n * sizeof(int));
        printf("Enter Element to Insert");
        scanf("%d", &val);
        if (val == -1)
        {
            break;
        }

        *(arr + n - 1) = val;
        heapify(arr, n);
        n++;
    }
    n--;
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}