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
		printf("Seal broken\n");
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

void shortestpath(struct graph * g){
	int i , j , k;
	int wnew[4][4];
	for(i = 0 ; i < g->v ; i++){
		for(j = 0 ; j < g->v ; j++){
				wnew[i][j] = *(g->adj+i * g->v + j);
		}
	}
	for(i = 0 ; i < g->v ; i++){
		for(j = 0 ; j < g->v ; j++){
			for(k = 0 ; k < g->v ; k++){
				if((wnew[i][k] + wnew[k][j])<wnew[i][j]){
					wnew[i][j] = wnew[i][k] + wnew[k][j];
				}
			}
		}
	}
	for(i = 0 ; i < g->v ; i++){
		for(j = 0 ; j < g->v ; j++){
				*(g->adj+i * g->v + j) = wnew[i][j];
		}
	}
}

void bfs( struct graph * g ){
	printf("ENTER\n");
	int arr[4] = {0};
	printf("arr[0]%d\n", arr[0]);
	arr[0] =1;
	printf("arr[0]%d\n", arr[0]);
	int x = 0;
	printf("The 1st element is %d\n" , x);
	int y = 0;
	printf("check matrix %d\n" , *(g->adj+x * g->v + y));
	while(1){
		for(y = 0 ; y < g->v ; y++){
			if((*(g->adj+x * g->v + y)== 1) && arr[y] == 0){
				printf("ENTER for loop\n");
				push(y);
				printf("pushed %d\n" , y);
				arr[y]=1;
			}
			break;
		if(!empty()){
			printf("ENTER break\n");
			break;
		} 
		else{
			printf("ENTER else for pop\n");
			int v = pop();
			printf("%d\n" , v);
		}
		}	
	}
}

int main(){
	int i , j;
	int matrix[4][4] = {{0 , 5 , INF , 10},
					    {INF , 0 , 3 , INF},
						{INF , INF , 0 ,1}, 
						{INF , INF , INF ,0}};
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
	shortestpath(g);
	printf("\n\n");
	print(g);
	printf("\n\n");
	bfs(g);			
}
