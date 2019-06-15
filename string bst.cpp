#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct player
{
 char name[20];
 int age;
 int nomatchplayed;
 float avg;
};
struct node
{
 struct player p;
 struct node *left;
 struct node * right;
};

struct node * create(struct node * root , char data[20]){
	struct node * temp = (struct node *)(malloc(sizeof(struct node)));
	strcpy(temp->p.name , data);
	temp->left = temp->right = NULL;
	return temp;
}

struct node * insert(struct node * root , char data[20]){
	if(root == NULL) root = create(root , data) ;
	else{
		int n;
		n = strcmp(root->p.name , data);
		printf("The n is %d" , n);
		if(n>=0) root->left = insert(root->left , data);
		else root->right = insert(root->right , data);
		}
	return root;
}

void print(struct node * root){
	if( root == NULL) return;
	else{
		print(root->left);
		printf("Data--->%s\n " , root->p.name );
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
			char data[20];
			scanf("%s" , data);
			root = insert(root , data);	
		}
		else{
			break;
		}
	}
	printf("Your inorder data is :\n");
	print(root);
}
