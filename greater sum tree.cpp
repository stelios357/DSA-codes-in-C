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

void print(struct node * root){
	if( root == NULL) return;
	else{
		print(root->left);
		printf("Data--->%d\n " , root->data);
		print(root->right);
	}
}

void fix(struct node * root , int * sum){
	if(root == NULL) return ;
	fix(root->right , sum);
	*sum = *sum + root->data;
	root->data = *sum - root->data;
	fix(root->left , sum);
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
	fix(root , &sum);
	print(root);
}
