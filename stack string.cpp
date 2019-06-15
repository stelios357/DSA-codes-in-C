#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
	char data[20];
	struct node * next;
};

struct node * head = 0;

push( char data [20]){
	struct node * temp = (struct node *)(malloc(sizeof(struct node)));
	strcpy(temp->data , data );
	temp->next = head;
	head = temp;
}

char * pop(){
	struct node * temp = head;
	if( temp != 0) {
		head = head->next;
		return temp->data;
	}
}

int empty(){
	if(head == 0){
		return 1;
	}
	else
	return 0;
}

char * top(){
	if(head == 0)
	return 0;
	else
	return head->data;
}

int main(){
	int  d = 0;
	while(1){
		printf("do you want to enter data ? \n");
		int a , b , c =0 ;
		char data[20] , y[20] , z[20];
		fflush(stdin);
		scanf("%d",&a);
		if(a){
			printf("Enter your string:\n");
			scanf("%s",data);
			if(d == 0){
				push(data);
				d++;
			}
			else{
				printf("d=!0\n");
				if(!(strcmp(data,top()))){
					printf("equal\n");
					pop();
					d--;
				}
				else{
					printf("not equal\n");
					push(data);
					d++;
				}
			}
		}
		else
		break;
	}
	printf("The final ans is %d\n",d);		
}
