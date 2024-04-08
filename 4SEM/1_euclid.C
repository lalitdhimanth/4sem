#include<stdio.h>
#include<stdlib.h>
int opcount = 0 ;
int euclidgcd(int a , int b){
if(b==0){
    return a ;
}

opcount++;

return euclidgcd(b , a%b);


}

int main(){
printf("gcd of input nums");
int a = 100;
int b = 24;
printf("%d",euclidgcd(a,b));
printf("opcount %d",opcount);



}