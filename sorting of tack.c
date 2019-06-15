#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node * next ;
};

struct node * head = NULL;
struct node * head1 = NULL;

void push(int data){
	struct node * temp = (struct node *)(malloc(sizeof(struct node)));
	temp->data = data;
	temp->next = head;
	head = temp;
	return;
}

int pop(){
	if(head != NULL){
		char cob;
		struct node * temp = head;
		cob = head->data;
		head = temp->next;
		free(temp);
		return cob;
		}
	else{
		return 0;
	}
}


int empty(){
	if(head = NULL){
		return 0;
	}
	else
		return 1;
}



void insertat(int data ,int n){
	
	if(n == 1){
		struct node * temp = (struct node *)(malloc(sizeof(struct node)));
		temp->data = data;
		temp->next = head1;
		head1 = temp;
		return;
	}
	else{
		struct node * temp = (struct node *)(malloc(sizeof(struct node)));
		temp->data = data;
		int i;
		struct node * temp1 = head1;
		for( i = 0 ; i < n-2 ; i++){
			temp1 = temp1->next;
		}
		temp->next = temp1->next;
		temp1->next = temp;
		return;
	}
}

int compare(int data){
	int c = 1;
	struct node * temp = head1;
	if(temp == NULL){
		return 1;
	}
	else{
		while(temp->next != 0){
			if(data > temp->data){
				temp=temp->next;
				printf("to check temp %d\n" ,temp);
				c++;
			}
		}
		printf("to check posintion in compare outside loop %d\n",c);
		return c ; 
	}
}

void print(){
	printf("your sorted is :\n");
	struct node * temp = head1;
	while(temp != NULL){
		printf("---------->%d\n",temp->data);
		temp=temp->next;
		
	}
}
void print1(){
	printf("your unsorted is :\n");
	struct node * temp = head;
	while(temp != NULL){
		printf("---------->%d\n",temp->data);
		temp=temp->next;
		
	}
}
int main(void){
	int i ;
	push(100);
	push(89);
	push(69);
	print1();
	for(i = 0 ; i < 7 ; i++){
		int t;
		t = pop();
		if(t){
			printf("to check the poped element %d\n" , t);
			int n;
			n = compare(t);
			printf("to check position %d\n" , n);
			insertat(t,n);
		}
		printf("to check the poped element %d\n" , t);
		int n;
		n = compare(t);
		printf("to check position %d\n" , n);
		insertat(t,n);
	}
	print();
}
