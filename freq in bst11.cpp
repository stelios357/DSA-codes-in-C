#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct number{
	int value;
	int freq;
};
struct node{
	struct number n;
	struct node *left;
	struct node * right;
};

struct node * create(struct node * root , int data){
	struct node * temp = (struct node *)(malloc(sizeof(struct node)));
	temp->n.value = data ;
	temp->left = temp->right = NULL;
	return temp;
}

struct node * insert(struct node * root , int data){
	if(root == NULL) root = create(root , data) ;
	else{
		if(data = root->n.value) root->n.freq ++;
		else if(data < root->n.value) root->left =	insert(root->left , data);
		else root->right = insert(root->right , data);
		}
	return root;
}

void print(struct node * root){
	if( root == NULL) return;
	else{
		print(root->left);
		printf("Data--->%d Freq---->%d\n" , root->n.value , root->n.freq);
		print(root->right);
	}
}

int main(){
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
