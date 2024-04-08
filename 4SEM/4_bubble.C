#include<stdio.h>
#include<stdlib.h>
int opcount = 0;
void bubblesort(int a[]){
    int temp;
for (int i = 0 ; i< 4 ; i++){
    for (int j = 0 ; j< 4-i ; j++){
        opcount++;
        if(a[j] > a[j+1]){
            opcount++;
            temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
        }
    
    }
}


}

int main(){
int a[] = {5,4,3,2,1};
bubblesort(a);
for (int i = 0 ; i< 5 ; i++){
    printf("%d\t",a[i]);
}
printf("opcount : %d",opcount);

}