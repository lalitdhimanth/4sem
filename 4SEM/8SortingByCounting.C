#include<stdio.h>



int main(){
    int arr[] = {6,3,8,9,1,4};
    int S[6];
    int mat[6];
    for(int i = 0 ;i < 6 ; i++){
        mat[i] = 0;
    }
    for(int i = 0 ; i<6 ; i++){
        for(int j = i+1 ; j<6 ; j++){
            if(arr[i] > arr[j]){mat[i]++;}
            else {mat[j]++ ;}
        }
    }
    for(int i = 0 ; i< 6 ;i++){
        printf("%d\t",mat[i]);
    }
    for(int i = 0 ;i<6 ;i++){
        S[mat[i]] =arr[i];
    }
    printf("\n");
    for(int i = 0 ; i< 6 ;i++){
        printf("%d\t",S[i]);
    }
}