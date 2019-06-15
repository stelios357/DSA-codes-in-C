#include<stdio.h>
#include<stdlib.h>
struct graph{
	int v;
	int e;
	struct list * adj;
};

struct list{
	int vertex ;
	struct list * next;
};

struct graph * create(){
	struct graph * g = (struct graph *)(malloc(sizeof(struct graph)));
	printf("No of vertices and edges !!\n");
	int a , b , c , d;
	scanf("%d %d" , &g->v , &g->e);
	struct list * temp = (struct list *)(malloc(sizeof(struct list)*g->v));
	g->adj = temp;
	for( a = 0 ; a< g->e ; a++){
		g->adj[a].vertex = a;
		g->adj[a].next = g->adj + a;
	}
	for(b = 0 ; b < g->e ; b++){
		printf("Please enter Origin and destination :n");
		scanf("%d %d" , &c , &d);
		struct list * tempp = (struct list *)(malloc(sizeof(struct list)));
		tempp->vertex = d;
		temp->next = g->adj+c;
		struct list * tempx;
		tempx = g->adj+c;
		while(tempx->next !=g->adj+c ){
			tempx = tempx->next;
		}
		tempx->next = temp;
	}
	return(g);
	
}
