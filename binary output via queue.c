#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node * next;
};

struct node * head;

void insert(int data){
	struct node * temp = (struct node *)(malloc(sizeof(struct node )));
	temp->data = data;
	temp->next = head;
	head = temp;
}

void print(){
	struct node * temp = head;
	printf("the unsorted array is :");
	while(temp != NULL){
		printf("\n------>data:%d",temp->data);
		temp = temp->next;
	}
}

void sort(){
	struct node * i , * j;
	i = head;
	int temp;
	for(i;i->next != NULL ; i=i->next){
		for(j=i->next;j != NULL; j=j->next){
			if(i->data > j->data){
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
}

void prints(){
struct node * temp = head;
	printf("\nthe sorted array is :");
	while(temp != NULL){
		printf("\n------>data:%d",temp->data);
		temp = temp->next;
}
}

int main(void){
	head = NULL;
	int a , b;
	while(1){
		printf("\ndo you want to enter data ?\n");
		scanf("%d",&a);
		if(a){
			printf("\ndata:");
			scanf("\n%d",&b);
			insert(b);
		}
		else
		break;
	}
}
