#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node *left;
	struct node * right;
};

struct node * create(struct node * root , int data){
	struct node * temp = (struct node *)(malloc(sizeof(struct node)));
	temp->data = data ;
	temp->left = temp->right = NULL;
	return temp;
}

struct node * insert(struct node * root , int data){
	if(root == NULL) root = create(root , data) ;
	else{
		if(data <= root->data) root->left = insert(root->left , data);
		else root->right = insert(root->right , data);
		}
	return root;
}

void printino(struct node * root){
	if( root == NULL) return;
	else{
		printino(root->left);
		printf("Data--->%d\n " , root->data);
		printino(root->right);
	}
}

void printpreo(struct node * root){
	if( root == NULL) return;
	else{
		printf("Data--->%d\n " , root->data);
		printpreo(root->left);
		
		printpreo(root->right);
	}
}

void printposo(struct node * root){
	if( root == NULL) return;
	else{
		printposo(root->left);
		printposo(root->right);
		printf("Data--->%d\n " , root->data);
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
	printf("Your preorder data is :\n");
	printpreo(root);
	printf("Your inorder data is :\n");
	printino(root);
	printf("Your postorder data is :\n");
	printposo(root);
}
