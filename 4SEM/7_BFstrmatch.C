#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int bfstr(char Mstring[], char substr[])
{
    int l1 = strlen(Mstring);
    int le = strlen(substr);
    int flag;
    for (int i = 0 ; i<(l1-le) ; i++){
        flag = 0;
        for (int j = 0 ; j< le ; j++){
            if(substr[j] != Mstring[i+j]){
                flag = 1 ; 
                break;
            }
        }
        if(flag == 0 ){
            return i ;
        }
}

}

int main()
{
    printf("enter main string");
    char mstr[20];
    char sstr[20];
    scanf("%s", mstr);
    printf("enter substr");
    scanf("%s", sstr);

    printf("found at index %d", bfstr(mstr, sstr));
}