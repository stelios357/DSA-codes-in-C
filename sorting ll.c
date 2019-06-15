#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct node{
	int data ;
	struct node * next ;
};

struct node * head = 0;

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

sort(){
	struct node * temp = head;
	
}


int main(){
	int a  , ele;
	while(1){
		printf("do you want to enter more elements ?\n");
		fflush(stdin);
		scanf("%d", &a);
		if(a){
			printf("Please enter your element:\n");
			scanf("%d", &ele);
			push(ele);
		}
		else{
			break;
		}
		printf("Now sorting your array:\n.\n.\n.\n.\n.\n.\n.\n.\n");
		sort();
		return 0;
	}	
}
