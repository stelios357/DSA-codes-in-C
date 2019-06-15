#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next ;
};

struct node * chain[10];

void ini(){
	int i = 0;
	for ( i ; i < 10 ; i++){
		chain[i] = 0 ;
	}
}

int hashcode(int data){
	int hashindex;
	hashindex = data %10;
	return hashindex;
}

void insert( int data){
	struct node * temp = (struct node *)(malloc(sizeof(struct node )));
	temp->data = data;
	temp->next = NULL;
	int hashindex = hashcode(data);
	if(chain[hashindex] == NULL){
		chain[hashindex] = temp;
	}
	else{
		struct node * tempp = chain[hashindex];
		while(tempp->next){
			tempp = tempp->next;
		}
		tempp->next = temp;
	}
}


void print(){
	int i ;
	for(i = 0 ; i < 10 ; i++){
		printf("Chain[%d]" , i);
		struct node * temp = chain[i];
		while(temp){
			printf("--->%d" , temp->data);
			temp = temp->next;
		}
		printf("--->NULL\n");
	}
}

void search(int data){
	int hashindex = hashcode(data);
	struct node * temp = chain[hashindex];
	while(temp){
			if(temp->data == data){
				printf("The entity found.\n");
				return;
			}
			printf("Not found!\n");
			return;
		}
}

int main(){
	while(1){
		printf("Do you want to enter data ?\n");
		int choice;
		scanf("%d" , &choice);
		if(choice){
			printf("Enter your data :\n");
			int data;
			scanf("%d" , &data);
			insert(data);
		}
		else{
			break;
		}
	}
	print();
		while(1){
			printf("Do you want to search data ?\n");
			int choice;
			scanf("%d" , &choice);
			if(choice){
				printf("Enter your data :\n");
				int data;
				scanf("%d" , &data);
				search(data);
			}
			else{
				break;
			}
		}
}
