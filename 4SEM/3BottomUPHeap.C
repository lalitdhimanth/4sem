#include <stdio.h>

void heapify(int arr[], int n)
{

    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        int k = i;
        int v = arr[i];
        bool heap = false;
        while (!heap && 2 * k+1  < n)
        {
            int j = 2 * k + 1;
            if (j < n-1)
            { // i has 2 subtree
                if (arr[j] < arr[j + 1])
                {
                    j++;
                }
            }
            if (v < arr[j])
            {
                arr[k] = arr[j];
                k = j;
            }
            else
            {
                heap = true;
            }
        }
        arr[k] = v;
    }
}

void heapsort(int arr[] , int n){
    for (int i = n ; i>0 ;i--){
        int temp = arr[0];
        arr[0] = arr[i-1];
        arr[i-1] = temp;
        heapify(arr,i-1);
    }
}

int main()
{
    int arr[] = {2, 9, 7, 6, 5, 8};
    heapify(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\nheapsort\n");
    heapsort(arr,6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d\t", arr[i]);
    }
}