#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node * next;
};

struct node * front = 0;
struct node * back = 0;

void push(int data){
	struct node * temp = (struct node *)(malloc(sizeof(struct node )));
	temp->data = data;
	
	if(front == 0 && back == 0){
		printf("Seal broken\n");
		front = back = temp;
		return;	
	}
	else{
		back->next = temp;
		back = temp;
		back->next = 0;
		return;
	}
}

int pop(){
	if(front == 0){
		printf("Queue underflow\n");
		return 0;
	}
	else{
		struct node * temp;
		temp = front;
		int data = temp->data;
		front = temp->next;
		free(temp);
		return data;
	}
}

print(){
	struct node * temp = front;
	while(temp != 0){
		printf("%d",temp->data);
		temp=temp->next;
	}
	return;
}

int main (void){
	int a , b ,c ;
	char k;
	while(1){
		printf("Do you want to: \n enqueue(a)\n dequeue(b)\n print your queue(c)\n exit(d)\n");
		fflush(stdin);
		scanf("%c",&k);
		if( k == 'a'||  k == 'b'|| k == 'c'){
			switch(k){
				case 'a':
					printf("Enter your data:\n");
					scanf("%d" , &a);
					push(a);
					break;
				case 'b':
					printf("Your data was:");
					b = pop();
					printf("%d",b);
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
