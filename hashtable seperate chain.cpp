#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
	int data ;
	struct node * next;
};

struct node * chain[10];

initialize(){
	int i = 0;
	for( i = 0 ; i < 10 ; i++){
		chain[i] = NULL;
	}
}

int hashcode(int data ){
	int hashindex;
	hashindex = data%10;
	return hashindex;
}

struct node * insert(int data){
	int hashindex = hashcode(data);
	struct node * temp = (struct node *)(malloc(sizeof(struct node)));
	temp->data = data ;
	temp->next = NULL;
	
	if(chain[hashindex] == NULL){
		chain[hashindex] = temp;
	}
	else{
		struct node * temp1 = chain[hashindex];
		while(temp1->next){
			temp1=temp1->next;
		}
		temp1->next = temp;
	}
}

void print(){
	int i ;
	for( i = 0 ; i < 10 ; i++){
		printf("Chain[%d]" , i);
		struct node * temp = chain[i];
		while(temp){
			printf("--->%d" , temp->data);
			temp = temp->next;
		}
		printf("--->NULL\n");
	}
}

int main()
{
    //init array of list to NULL
    initialize();

    insert(7);
    insert(0);
    insert(3);
    insert(10);
    insert(4);
    insert(5);

    print();

    return 0;
}
