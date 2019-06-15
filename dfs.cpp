#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int * matrix;
int INF = 999;

struct node{
	int data;
	struct node * next ;
};

struct node * head = NULL;

void push(int data){
	struct node * temp = (struct node *)(malloc(sizeof(struct node)));
	temp->data = data;
	temp->next = head;
	head = temp;
	return;
}

int pop(){
	if(head != NULL){
	int cob;
	struct node * temp = head;
	cob = head->data;
	head = temp->next;
	free(temp);
	return cob;
}
else
printf("\nThe stack is full.\n");
return -100;
}

int isempty(){
	if(head == NULL) return 1;
	else return 0;
}

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

dfs(struct graph * g){
	int arr[4] = {0};
	int y;
	push(0);
	arr[0]=1;
	while(1){
		int n = pop();
		printf("---->%d\n" , n);
		for(y = 0 ; y <= 4 ; y++){
			if( *(g->adj+n*g->v+y) == 1 && arr[y] == 0){
				push(y);
				arr[y]=1;
			}
		}
		if(isempty()) break;
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
	dfs(g);			
}
