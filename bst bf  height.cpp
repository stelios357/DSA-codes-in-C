#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node *left;
	struct node * right;
	int height;
	int bf;
};

int max( int a , int b){
	if(a > b) return a;
	else return b;
}

int height(struct node * root ){
	if (root==NULL) return 0;
	else{
		int h = root->height;
		return h;
	}
}

int bal(struct node * root){
	if(root == NULL) return 0;
	else{
		int b = height(root->left) - height(root->right);
		return b;
	}
}

struct node * create(struct node * root , int data){
	struct node * temp = (struct node *)(malloc(sizeof(struct node)));
	temp->data = data ;
	temp->left = temp->right = NULL;
	temp->height = 1;
	temp->bf = bal(temp);
	return temp;
}

struct node * insert(struct node * root , int data){
	if(root == NULL) root = create(root , data) ;
	else{
		if(data <= root->data) root->left = insert(root->left , data);
		else root->right = insert(root->right , data);
		}
	root->height = max( height( root->left) , height( root->right)) + 1;
	root->bf = bal( root);
	return root;
}

void print(struct node * root){
	if( root == NULL) return;
	else{
		print(root->left);
		printf("Data--->%d , bf---->%d , height--->%d\n " , root->data , root->bf , root->height);
		print(root->right);
	}
}


int main(){
	int sum = 0;
	struct node * root = NULL ;
	while(1){
		printf("Do you want to enter data ?(0/1)\n");
		int choice;
		fflush(stdin);
		scanf("%d" , &choice);
		if(choice){
			printf("Please enter your data :\n");
			int data;
			scanf("%d" , &data);
			root = insert(root , data);	
		}
		else{
			break;
		}
	}
	printf("Your inorder data is :\n");
	print(root);
}
