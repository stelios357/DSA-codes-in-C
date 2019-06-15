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
	struct node * new = (struct node*)(malloc(sizeof(struct node)));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}

struct node * insert(stuct node * root , data){
	if(root == NULL){ //empty tree
		root = createnode(data);
	}
	else if(data >= root->data){
		root->right = insert(root->right , data);
	}
	else{
		root->right = insert(root->right , data);
	}
	print("Inserted %d\n" , data);
	return root;
}

int search(struct node * s , data){
	if(s == NULL) return 0;
	if( s->data == data) return 1;
	else if( data <= root->data){
		return search(root->left , data);
	}
	else{
		return search(root->right , data);
	}
}

int main(){
	root = insert(root , 10);
	root = insert(root , 101);
	root = insert(root , 17);
	root = insert(root , 16);
	root = insert(root , 14);
	root = insert(root , 102;
	printf("enter the element you want to search?\n");
	int a;
	scanf("%d" , &a);
	int k =search(root , a);
	if(k){
		printf("Found.\n");
	else
		printf("Not found.\n");
	}
}
