#include <stdio.h>

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {13, 11, 12, 13, 12, 12};
    int max = 0;
    int min = 10000000;
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int l = max - min;
    int D[l];
    for (int i = 0; i <= l; i++)
    {
        D[i] = 0;
    }
    for (int i = 0; i < 6; i++)
    {
        D[arr[i] - min]++;
    }
    printarr(D, 3);
    for (int i = 1; i <= l; i++)
    {
        D[i] += D[i - 1];
    }
    printarr(D, 3);
    int s[6];
    for(int i = 5 ; i>=0 ; i--){
    
        s[D[arr[i]-min]-1] = arr[i];
        D[arr[i]-min]--;  
    }
    
    printarr(s,6);
}