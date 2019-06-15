#include<stdio.h>
#include<stdlib.h>

struct node{
	char data;
	struct node * left;
	struct node * right;
};

struct node * root = 0;

struct node * createnode( struct node * root , char data  ){
	struct node * temp = (struct node *)(malloc(sizeof(struct node)));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

struct node * insert(struct node * root ,char data){
	if(root == 0){
		root = createnode(root , data);
	}
	else if(data <= root->data){
			root->left = insert(root->left , data);
		}
	else{
			root->right = insert(root->right , data);
		}
	return root;
}

void preorder(struct node * root){
	struct node * temp = root ;
	if(temp == 0){
		return;
	}
	else{
		printf("--------->%c\n" , temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}

void inorder(struct node * root){
	
	struct node * temp = root ;
	if(temp == 0){
		return;
	}
	else{
		inorder(temp->left);
		printf("--------->%c\n" , temp->data);
		inorder(temp->right);
	}
}

void postorder(struct node * root){
	
	struct node * temp = root ;
	if(temp == 0){
		return;
	}
	else{
		postorder(temp->left);
		postorder(temp->right);
		printf("--------->%c\n" , temp->data);
		
	}
}

int main(){
	while(1){
		printf("do you want to enter data ?\n");
		int c ;
		scanf("%d" , &c);
		if(c){
			printf("Please enter ypur data:\n");
			fflush(stdin);
			char data;
			scanf("%c" , &data);
			root = insert(root , data);
		}
		else
			break;
	}
	printf("\n\n\n preorder\n");
	preorder(root);
	printf("\n\n\n Inorder\n");
	inorder(root);
	printf("\n\n\n postorder\n");
	postorder(root);
	
}
