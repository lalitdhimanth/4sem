#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int findhas(char string[])
{
    int sum = 0;

    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i]>='a' && string[i]<='z')
        {
            sum+= string[i] - 'a' +1;
        }
        else{sum+= string[i] - 'A' +1;
        }
    }
    return sum;
}
int main(){
    int n;
    printf("Enter size of hash table");
        scanf("%d",&n);
    
    int k;
    printf("Enter num of ele to be inserted");
    scanf("%d",&k);
    if(k>n){printf("NOT POSSIBLE");
    exit(0);}
    char arrstring[13][100];
    char str[100];
    for(int i = 0 ;i<n;i++){
        strcpy(arrstring[i],"0");
    }

    for(int i = 0 ; i< k ; i++){
        printf("Enter string");
        scanf("%s",str);
        int fh = findhas(str) % n;
        if(strcmp(arrstring[fh] , "0") == 0 ){
        strcpy(arrstring[fh] , str);
        }
        
        else{
            int j = fh ;
            while(1){
                j=(j+1)%n;
                if(strcmp(arrstring[j] , "0") == 0){strcpy(arrstring[j] , str);
                break;}
            }
        }

    }
    for(int i = 0 ;i<n;i++){
        printf("%s\t",arrstring[i]);
    }

}