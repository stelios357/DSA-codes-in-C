#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node * next ;
};

struct node * head = NULL;

void push(int data){
	struct node * temp = (struct node *)(malloc(sizeof(struct node)));
	temp->data = data;
	temp->next = head;
	head = temp;
	return;
}

int pop(){
	if(head != NULL){
	int cob;
	struct node * temp = head;
	cob = head->data;
	head = temp->next;
	free(temp);
	return cob;
}
else
printf("\nThe stack is full.\n");
return ;
}

print(){
	struct node * temp;
	temp = head;
	printf("\nYour list is:\n");
	while(temp!=NULL){
		printf("----->%d\n",temp->data);
		temp = temp->next;
	}
}

int main(void){
	int n;
	char c , exp[100];
	while(1){
		printf("Please enter the exp:\n");
		scanf("%s",exp);
		n = strlen(exp);
		int i=0;
		for ( i = 0 ; i < n ; i++){
			if(isoperator(exp[i])){
				printf("%c",)
			}
		}
	}
}
