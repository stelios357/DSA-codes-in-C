#include<stdio.h>
#include<stdlib.h>

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
	int adj[4][4];
};

struct graph * create(struct graph * g){
		printf("Please enter no of Vertices and Edges!\n");
		int v , e , u , i;
		scanf("%d %d", &g->v , &g->e);
		for( u = 0 ; u < g->v ; u++){
			for( v = 0 ; v < 4; v++){
				g->adj[u][v] = 0;
			}
		}
		printf("Please enter the combis:\n");
		
		for( u = 0 ; u < g->e ; u++){
			scanf("%d %d" , &e , &i);
			g->adj[e][i]= 1;
			g->adj[i][e]= 1;
		}
		return(g);
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
			if( g->adj[n][y] == 1 && arr[y] == 0){
				push(y);
				arr[y]=1;
			}
		}
		if(isempty()) break;
	}
}

int main(){
	struct graph * g = (struct graph *)(malloc(sizeof(struct graph)));
	create(g);
	dfs(g);
}
