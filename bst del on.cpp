#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node * left;
	struct node * right;
};



struct node * createnode(struct node * root , int data){
	struct node * temp =(struct node *)(malloc(sizeof(struct node )));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

struct node * insert(struct node * root ,int data){
	if(root == NULL){
		root = createnode(root , data);
	}
	else{
		if(data <= root->data){
			root->left = insert(root->left , data);
		}
		else{
			root->right = insert (root->right , data);
		}
	}
	return root;
}

void print(struct node * root){
	if(root == NULL){
		return;
	}
	else{
		print(root->left);
		printf("--------->%d\n" , root->data);
		print(root->right);
	}
}

struct node * fmin(struct node * root){
	struct node * temp = root;
	while(temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

struct node * delete1 (struct node * root , int data){
	if(root == NULL) 
		return root;
	else if(data < root->data) root->left = delete1(root->left , data);
	else if(data > root->data) root->right = delete1(root->right , data);
	else{
		if(root->left == NULL && root->right == NULL){
			free(root);
			root = NULL;
		}
		else if(root->left == NULL){
			struct node * temp = root;
			root = root->right ;
			free(temp);
		}
		else if(root->right == NULL){
			struct node * temp = root;
			root = root->left ;
			free(temp);
		}
		else{
			struct node * temp = fmin(root->right);
			root->data = temp->data;
			root->right = delete1(root->right , temp->data);
		}
		return root;
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
	while(1){
		printf("Do you want to delete data ?(0/1)\n");
		int choice;
		scanf("%d" , &choice);
		if(choice){
			printf("Enter the no you want to delete:\n");
			int deletex;
			scanf("%d" ,&deletex);
			if(root == NULL){
				printf("The tree is empty.\n");
			}
			else{
				delete1(root , deletex);
				printf("the number %d has been deleted!\n" , deletex);
				print(root
				);
			}
		}
		else{
			break;
		}
	}
}





















