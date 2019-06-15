#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct node{
	char name[20];
	int data;
	struct node * next;
};

struct node * head = 0;

push(char name[20] , int data){
	struct node * temp = (struct node *)(malloc(sizeof(struct node)));
	strcpy(temp->name , name);
	temp->data = data;
	temp->next = head ;
	head = temp;
	return;
}

int pop(){
	struct node * temp = (struct node *)(malloc(sizeof(struct node)));
	temp = head;
	if(temp != 0){
		int data = temp->data;
		head = head->next;
		free(temp);
		return data;
	}
	else
	return ;
}

printn(int n){
	struct node * temp = head;
	struct node * temp2;
	int i = 0;
	for(i = 0 ; i < n-2 ;i++){
		temp = temp->next;
	}
	temp2 = temp->next;
	printf("your data is %s %d\n",temp->name ,temp2->data);
	temp->next = temp2->next;
	free(temp2);
	return;
}

print(){
	struct node * temp = head;
	printf("Your list is\n");
	while(temp != 0){
		printf("---->>%s %d\n",temp->name , temp->data);
		temp = temp->next;
	}
	return;
}

int main(){
	int a , b, c, d, e = 0, f;
	char name[20];
	while(1){
		printf("Do you want to engter data ?\n");
		fflush(stdin);
		scanf("%d",&a);
		if(a){
			printf("enter data:\n");
			scanf("%d",&b);
			printf("enter name:\n");
			scanf("%s",name);
			push(name , b);
			e++;
		}
		else
		break;
	}
	printf("Enter number \n");
	scanf("%d",&d);
	f = e-d;
	printn(f);
	print();
	return;
}
