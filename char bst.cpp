#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person{
 	char name[20];
 	int age;
};
struct node{
 	struct person p;
 	struct node *left;
 	struct node * right;
 	int height ;
 	int balance;
};

int max(int a , int b){
	if(a>b) return a;
	else return b;
}

int height (struct node * root ){
	if(root == NULL) return 0;
	else return root->height;
}

int balance(struct node * root ){
	if(root == NULL) return 0;
	else{ return height(root->left ) - height(root->right);}
}

struct node * create(struct node * root , char data[20]){
	struct node * temp = (struct node *)(malloc(sizeof(struct node)));
	strcpy(temp->p.name , data);
	temp->left = temp->right = NULL;
	temp->height = 1;
	temp->balance = balance(temp);
	return temp;
}

struct node * insert(struct node * root , char data[20]){
	if(root == NULL){
		root = create(root , data);
	}
	else{
		printf("Entered else\n ");
		int n = strcmp(data , root->p.name);
		printf("The value of n is %d\n" , n);
		if(n > 1){
			printf("Entered condition for data > root->data\n");
			root->right = insert(root->right , data);
	}
		else{
			root->left = insert(root->left , data);
			printf("Entered condition for data < root->data\n");
			
		}
		root->height = max(height(root->left) , height(root->right))+1;
		root->balance = balance(root); 
	}
	return root;
}

void print(struct node * root){
	if(root == NULL) return;
	else{
		print(root->left);
		printf("The data is ---> %s The balance factor is --->%d The height is---> %d \n" , root->p.name , root->balance , root->height);
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
			char data[20];
			scanf("%s" , &data);
			root = insert(root , data);	
		}
		else{
			break;
		}
	}
	printf("Your inorder data is :\n");
	print(root);
}
