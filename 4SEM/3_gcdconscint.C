#include <stdio.h>
#include <stdlib.h>

int consecint(int a, int b)
{
    int t;
    if (a > b)
    {
        t = a;
    }
    else
        t = b;
    while ( t!= a || t!= b){
        if(a % t == 0 && b %t == 0 ){
            return t;
        }
        t--;
    }
    return 1;
}

int main()
{
    printf("gcd of ");
    int a = 100;
    int b = 41;
    printf("%d", consecint(a, b));
}