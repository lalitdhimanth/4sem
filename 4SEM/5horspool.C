#include<stdio.h>
#include<string.h>
void getShiftTable(int shifttable[] , char str[]){
    for ( int i = 0 ; i< strlen(str) - 1 ; i++){
        shifttable[(int)str[i]] = strlen(str) -1 -i ;
    }
}

int horsepool(char str1[] , char str2[]){
    int shifttable[127];
    for (int i = 0 ; i< 127 ; i++){
        shifttable[i] = strlen(str2);
    }
    getShiftTable(shifttable , str2);
    int i = strlen(str2) - 1;
    int l1 = strlen(str1)-1;
    int l2 = strlen(str2)-1;
    while ( i < l1){
        int j = 0;
        while (j<=l2 && str2[l2 - j] == str1[i-j]){
                        printf("%d\t",j);

            j++;
        }
        if(j== l2+1){return (i-l2);}
        else { i = i + shifttable[(int)str1[i]];}

    }
    return -1;
}

int main(){


    printf("Enter main string");
    char str[100];
    scanf("%s",str);
    printf("Enter substr");
    char str2[100];
    scanf("%s",str2);
    int res = horsepool(str,str2);
    printf("\n\n%d",res);
}