#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node * next;
};

struct node * head = 0;

void push (int data){
	struct node * temp = (struct node *)(malloc(sizeof(struct node )));
	temp->data = data;
	temp->next = head;
	head = temp;
	return;
}

int pop(){
	struct node * temp = head;
	if(temp != 0){
		int data = temp->data;
		head = temp->next;
		free(temp);
		return data ;
	}
	else
	return -1;
}

int top(){
	struct node * temp = head;
	if(temp != 0){
		int data = temp->data;
		return data ;
	}
	else
	return -1;
}

print(){
	struct node * temp = head;
	while(temp != 0){
		printf("------->%d\n",temp->data);
		temp = temp->next;
	}
}

int main(){
	push(1);
	push(44);
	push(14);
	push(17);
	push(7714);
	push(169);
	push(89);
	push(90);
	push(70);
	push(42);
	push(35);
	push(29);
	push(101);
	push(34);
	push(67);
	push(56);
	push(32);
	printf("Your array is:\n");
	print();
	printf("Enter no of moves:\n");
	int a;
	int moves = 0;
	fflush(stdin);
	scanf("%d",&a);
	int arr[a];
	int i = 0 , j =0 ;
	for( i = 0 ; i <a-1 ; i++){
		arr[i] = pop();
		moves++;
	}
	
	for( i = 0 ; i <a-2 ; i++){
		for( j = 0 ; j < a-2-i ; j++){
			if(arr[j] < arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	if( arr[0] < top()){
		int t = pop();
		printf("The largest element at the top %d\n", t);
		moves++;
	}
	else{
		int t = arr[0];
		push(t);
		printf("The largest element at the array %d\n", t);
		moves++;
	}
	printf("total moves %d\n",moves);
}
