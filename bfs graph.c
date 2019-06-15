#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node * next;
};

struct node * front = 0;
struct node * back = 0;

void push(int data){
	struct node * temp = (struct node *)(malloc(sizeof(struct node )));
	temp->data = data;
	
	if(front == 0 && back == 0){
		front = back = temp;
		return;	
	}
	else{
		back->next = temp;
		back = temp;
		back->next = 0;
		return;
	}
}

int pop(){
	if(front == 0){
		printf("Queue underflow\n");
		return 0;
	}
	else{
		struct node * temp;
		temp = front;
		int data = temp->data;
		front = temp->next;
		free(temp);
		return data;
	}
}

int empty(){
	if(front == 0)
	return 1;
	
	else
	return 0;
}

int INF = 9999;

struct graph{
	int v;
	int e;
	int * adj;
};

print(struct graph * g){
	int i , j ;
	for(i = 0 ; i < g->v ; i++){
		for(j = 0 ; j < g->v ; j++){
				printf("%7d", *(g->adj+i * g->v + j));
		}
		printf("\n");
	}
}

void bfs( struct graph * g){
	int arr[4] = {0};
	push(0);
	arr[0] = 1;
	while(1){
		int n = pop();
		int i;
		printf("---->%d" , n);
		for(i = 0 ; i <= 4 ; i++ ){
			if( *(g->adj+n*g->v+i) == 1 && arr[i] == 0){
				printf("Enters if!\n");
				push(i);
				arr[i] = 1;
			}
		}
		if(empty()) break;
	}
}
int main(){
	int i , j;
	int matrix[4][4] = {{1 , 1 , INF , 1},
					    {INF , 1, 1 , INF},
						{INF , INF , 1 ,1}, 
						{INF , INF , INF ,1}};
	struct graph * g =(struct graph *)(malloc(sizeof(struct graph )));
	g->v = 4;
	g->e = 8;
	g->adj = (int*)malloc(sizeof(int)*g->v*g->v); 
	for(i = 0 ; i < g->v ; i++){
		for(j = 0 ; j < g->v ; j++){
			*(g->adj+i * g->v + j) = matrix[i][j];
		}
	}
	print(g);
	printf("\n\n");
	bfs(g);			
}
