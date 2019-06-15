#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node * next ;
};

struct node * front = NULL;
struct node * rear = NULL;

void enqueue(int data){
	struct node * temp = (struct node *)(malloc(sizeof(struct node)));
	temp->data = data ;
	if((front = NULL) && (rear = NULL)){
		front = temp;
		rear = temp;
	}
	else{
		front->next = temp;
		front = temp;
	
	}
	return;
}

int dequeue(){
	struct node * temp = rear;
	if(rear = NULL){
		printf("\nNO.\n");
		return 0;
	}
	else{
		printf("\nthe data removed is");
		rear = rear->next;
		int data = temp->data;
		free(temp);
		return data;
	}
}

void print(){
	struct node * temp = rear ;
	printf("\nYour data is : \n");
	while(temp != NULL){
		printf("---------->%d\n",temp->data);
		temp = temp->next;
	}
	return;
}

int main(void){
	int a , b , c ,d;
	char k;
	while(1){
		getchar();
		printf("\ndo you want to :\nenter data ?(a)\ndequeue(b)\nprint(c)\nexit(d)\n");
		scanf("%c",&k);
		switch(k){
			case 'a':
				printf("\nplease enter the data:\n");
				scanf("%d\n",&a);
				enqueue(a);
				break;
			case 'b':
				b = dequeue();
				printf("%d",b);
				break;
			case 'c':
				print();
				break;
			case 'd':
				exit;
				break;
			default :
				exit;
		}
	}
}
