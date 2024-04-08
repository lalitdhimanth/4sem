#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char data[100];
    struct Node *next;
};
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
void insert(struct Node* arr[] , int n , char string[]){
int len = findhas(string) % n ;
struct Node* newNode = (struct Node* )malloc(sizeof(struct Node));
newNode->next = NULL;
strcpy(newNode->data , string);
if(arr[len]==NULL){
    arr[len] = newNode;
}
else{
    struct Node* temp = arr[len];
    while (temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;

}

}
void print(struct Node* arr[], int n){
    for(int i = 0 ;i<n ; i++){
        printf("%d->", i);
        struct Node* temp = arr[i];
        if(temp == NULL){
            
            printf("\n");}
        else{
            while(temp!=NULL){
                printf("%s->", temp->data);
                temp = temp->next;
            }
            printf("\n");
        }
        
    }

}


int main()
{
    printf("enter table size");
    int n;
    scanf("%d", &n);
    struct Node *arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = NULL;
    }
    char str[100];
    while(1){
        printf("enter string to insert");
        scanf("%s",str);
        if(strcmp(str,"0") == 0){break;}
        insert(arr,n,str);

    }
    print(arr,n);
}