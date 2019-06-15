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

binary(int n){
	int i = 1 , j =0 , k =0;
	int l;
	while(i <= n){
		while(n>0){
			j=n%2;
			push(j);
			n /=2;		
			k++;
		}
		for( l = 0 ; l <k ; l++){
			pop();
		}
		print();
		i++;
	}
}

int empty(){
	if(front == 0)
	return 1;
	
	else
	return 0;
}

int main (void){
	int a , b = 0 ,c ;
	char k;
	printf("Please enter your number.\n");
	scanf("%d",&a);
	push(1);
	while(!empty && b < a){
		c = pop();
		printf("%d",c);
		int d ;
		d = c + 0 + 1;
		push(d);
		print();
	}
}
