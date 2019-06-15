#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
	int data ;
	struct node * left;
	struct node * right;
};

struct node * root = NULL;

struct q{
	struct node * data;
	struct q * next;
};

struct q * head = NULL;
struct q * tail = NULL;

enqueue( struct node * data){
	printf("enqueued 1st element %d\n" , data);
	struct q * temp = (struct q * )(malloc(sizeof(struct q)));
	temp->data = data;
	printf("the data entered in q is %d\n" , temp->data);
	if(head == NULL){
		printf("head tail set for 1\n");
		head = tail = temp;	
	} 
	else{
		printf("tail set\n");
		tail = temp;
	}
}

struct node * top(){
	return head->data;
}

void pop(){
	if(head == NULL) return;
	struct q * temp = head;
	head = temp->next;
	free(temp);
}

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
int empty(){
	if(head == NULL) return 1;
	else return 0;
}

levelordert(struct node * root){
	printf("entered\n");
	if (root == NULL){
		printf("no element.\n");
	}
	else{
		printf("the tree isnt empty.\n");
		enqueue(root);
		while( 1){
			printf("the top is %d" , top());
			struct node * temp = top();
			
			pop();
			printf("%d" , temp->data);
			if(temp->left != NULL){
				enqueue(temp->left);
			}
			if(temp->left != NULL){
				enqueue(temp->left);
			}
			break;
		}
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
	printf("The height is %d\n" , k);
	int g = maxi(root);
	printf("The max  is %d\n" , g);
	printf("the level order traversal is :\n");
	levelordert(root);
}

