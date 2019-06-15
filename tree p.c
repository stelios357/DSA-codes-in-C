#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node * left ;
	struct node * right ;
};

struct node * createnode(int data){
	struct node * temp = (struct node * )(malloc(sizeof(struct node))) ;
	temp->data = data;
	temp->left = 0;
	temp->right = 0;
	return temp;
}

struct node * insert( struct node * root , data){
	if(root == 0){
		root = createnode();
		return root;
	}
	
	else if( data <= root->data){
		root->left = insert(root->left , data);
		return root;
	}
	else{
		root->right = insert(root->right , data);
		return root;
	}
	
}

int main(){
	struct node * root = 0;
	root = insert( root , 15);
	root = insert( root , 10);
	root = insert( root , 25);
	 root = insert( root , 14);
}
