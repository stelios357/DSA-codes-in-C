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
		printf("created a node %d\n" , data);
		root = createnode(data);
	}
	else if(data <= root->data){
		printf("Inserted left %d\n" , data);
		root->left = insert(root->left , data);
	}
	else{
		printf("Inserted right %d\n" , data);
		root->right = insert(root->right , data);
	}
	
	return root;
}

int max (int a , int b){
	if( a > b){
		return a;
	}
	else return b;
}

int height(struct node * root){
	if( root == NULL){
		printf("entered NULL\n");
		return -1;
	}
	else {
		return max(height(root->left) , height(root->right)) +1 ;
	}
}

int maxi(struct node * root){
	struct node * temp = root;
	if(root == NULL)
	printf("Empty fucker.!\n");
	else{
		while(temp->right != NULL){
			temp = temp->right;
		}
		return temp->data;
	}
}

int main(){
	while(1){
		printf("Do you want to enter data ?\n");
		int choice;
		scanf("%d",&choice);
		if(choice){
			printf("Enter data :\n");
			int data ;
			scanf("%d", &data);
			root = insert(root , data);
		}
		else
			break;
	}
	printf("Do you want to find the height of the tree ?\n");
	int k = height(root);
	printf("The height is %d" , k);
	int g = maxi(root);
	printf("The max  is %d" , g);
}

