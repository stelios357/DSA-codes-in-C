#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node * next;
};

struct node * head = NULL;

void insert(int data){
	struct node * new = (struct node*)(malloc(sizeof(struct node)));
	new->data = data;
	new->next= head;
}	head = new;



void print(){
	struct node * temp = head;
	while(temp!= NULL){
		printf("%d <--->  ",temp->data);
		temp = temp->next;
	}
}


int main()
{
	printf("\n");
	int n=1 , d;
	while(n){
		printf("do you want to enter data ?\n");
		scanf("%d",&n);
		if(n){
			printf("data:\n");
			scanf("%d",&d);
			insert(d);
		}
		else
		break;
	}
	print();
    return 0;
}

