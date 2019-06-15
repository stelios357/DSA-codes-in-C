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
return -100;
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
	char c;
	while(1){
		getchar();
		printf("\nDo you want to : \npush(p) \npop(o) \nprint(t)  \nexit(x)\n");
		scanf("%c",&c);
		if(c == 'x')
			break;
		else{
		
			switch(c){
			case 'p':
				printf("\nEnter data:");
				int v;
				scanf("\n%d",&v);
				push(v);
				break;
				
			case 'o':
				printf("\nthe data poped is:");
				int w;
				w = pop();
				printf("%d\n",w);
				break;
				
			case 't':
				print();
				break;
		}
	}
}
}
