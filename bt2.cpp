#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
	int data ;
	struct node * left;
	struct node * right;
};

struct node * root = NULL;

struct node* createnode(int data){
	struct node * lnew = (struct node*)(malloc(sizeof(struct node)));
	lnew->data = data;
	lnew->left = lnew->right = NULL;
	return lnew;
}

struct node * insert(struct node * root , int data){
	if(root == NULL){ //empty tree
		root = createnode(data);
	}
	else if(data >= root->data){
		root->right = insert(root->right , data);
	}
	else{
		root->right = insert(root->right , data);
	}
	printf("Inserted %d\n" , data);
	return root;
}

int search(struct node * s ,int  data){
	if(s == NULL){
		printf("entered the condition for null\n");
		return 0;
	}
	if( s->data == data){
		printf("entered the condition for found\n");
		return 1;
	}
	else if( data <= s->data){
		printf("entered the left node\n");
		return search(root->left , data);
	}
	else{
		printf("entered the right node\n");
		return search(s->right , data);
	}
}

int main(){
	root = insert(root , 10);
	root = insert(root , 101);
	root = insert(root , 17);
	root = insert(root , 16);
	root = insert(root , 14);
	root = insert(root , 102);
	printf("enter the element you want to search?\n");
	int a;
	scanf("%d" , &a);
	int k =search(root , a);
	if(k){
		printf("Found.\n");}
	else
		printf("Not found.\n");
	}

