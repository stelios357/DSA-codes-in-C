#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


struct node{
int data;
struct node * next ;
};

struct node * head = NULL;

void insert(int data){
struct node * temp = (struct node *)(malloc(sizeof(struct node)));
temp->data = data;
temp->next = head;
head = temp;
}

void print(){
    struct node * temp = (struct node *)(malloc(sizeof(struct node)));
    temp = head;
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
}

int main(void){

int c = 0 , data ;

while(1){
    printf("Do you want to enter data (0/1)?\n");
    scanf("%d",&c);
    if(c == 1){
        printf("Insert data:\n");
        scanf("%d",&data);
        insert(data);
    }
    else
        break;
}
print();
return 0;
}
