#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char data;
	struct node * next ;
};

struct node * front = NULL;
struct node * rear = NULL;

enqueue(char data){
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

char dequeue(){
	struct node * temp = rear;
	if(rear = NULL){
		prcharf("\nNO.\n");
		return 0;
	}
	else{
		prcharf("\nthe data removed is");
		rear = rear->next;
		char data = temp->data;
		free(temp);
		return data;
	}
}



void print(){
	struct node * temp = front;
	while(temp != NULL){
		printf("\n------>%c",temp->data);
		temp = temp->next;
	}
}

int main(void){
	int a , b , c ,d;
	char k;
	printf("Enjoy the show of traffic lights:\n");
	while(1){
		enqueue('R');
		enqueue('Y');
		enqueue('G');
	}
	print();
}
