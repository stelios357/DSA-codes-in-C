#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char data[50];
	struct node * next;
};

struct node * head = 0;

push(char data [50]){
	struct node * temp = (struct node *)(malloc(sizeof(struct node )));
	strcpy(temp->data , data);
	temp->next = head;
	head = temp;
	return;
}

char * pop(){
	struct node * temp = head;
	char data[50];
	if(temp == 0)
		printf("STACK UNDERFLOW\n");
	else{
		strcpy(data , temp->data);
	}
	return data;
}

print(){
	struct node * temp = head;
	while(temp != 0){
		printf("%s",temp->data);
		temp= temp->next;
	}
}

int empty(){
	if(head == 0)
		return 1;
	else 
		return 0;
}



int main(void){
	int a , b , c;
	char ror[50];
	char k;
	while(1){
		printf("What do you want to do ?\n push(a) \n pop(b) \n print(c) \n exit(d)\n");
		fflush(stdin);\
		scanf("%c",&k);
		if( k == 'a' || k == 'b' ||k == 'c' ){
			switch(k){
				case 'a':
					printf("Plese enter your name:\n");
					scanf("%s\n",ror);
					push(ror);
					break;
				case 'b':
					printf("Your name:  ");
					char op[50];
					strcpy(op,pop());
					printf("%s\n",op);
					break;
				case 'c':
					print();
					break;
			}
		}
		else
		break;
	}
}
