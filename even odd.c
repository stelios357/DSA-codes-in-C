#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct node{
	int data ;
	struct node * next ;
};

struct node * head = 0;
struct node * heade = 0;
struct node * heado = 0;

push(int data){
	struct node * temp = (struct node *)(malloc(sizeof(struct node )));
	temp->data = data;
	temp->next = head;
	head = temp ;
	return;
}

int pop(){
	struct node * temp = head;
	int data = temp->data;
	head = temp->next;
	free(temp);
	return data;
}

pushe(int data){
	struct node * temp = (struct node *)(malloc(sizeof(struct node )));
	temp->data = data;
	temp->next = heade;
	heade = temp ;
	return;
}

pusho(int data){
	struct node * temp = (struct node *)(malloc(sizeof(struct node )));
	temp->data = data;
	temp->next = heado;
	heado = temp ;
	return;
}

printe(){
	struct node * temp = heade;
	printf("your even int are:\n");
	while(temp != 0){
		printf("%d", temp->data);
		temp = temp->next;
	}
	return;
}

printo(){
	struct node * temp = heado;
	printf("your even int are:\n");
	while(temp != 0){
		printf("%d", temp->data);
		temp = temp->next;
	}
	return;
}

int main(){
	int a , b , c, d, e=0 ;
	while(1){
		printf("do you want to enter more elements ?\n");
		fflush(stdin);
		scanf("%d", &a);
		if(a){
			scanf("%d",&b);
			push(b);
			e++;
		}
		else{
			break;
		}
	}
	while(e){
		e--;
		c = pop();
		if(c%2==0){
			pushe(c);
		}
		else
		pusho(c);	
	}
	printe();
	printo();
	return;
	
}
