#include<stdio.h>
#include<stdlib.h>

struct graph{
	int v;
	int e;
	int *adj; 
	
};

struct graph * create(){
	struct graph * g = (struct graph *)(malloc(sizeof(struct graph)));
		printf("Please enter no of Vertices and Edges!\n");
		int v , e , u , i;
		scanf("%d %d", &g->v , &g->e);
		for( u = 0 ; u < g->v ; u++){
			for( v = 0 ; v < g->v ; v++){
				g->adj[u][v] = 0;
			}
		}
		g->adj = malloc(4*g->v*g->v);
		printf("Please enter the combis:\n");
		
		for( u = 0 ; u < g->v ; u++){
			scanf("%d %d" , &e , &i);
			g->adj[e][i] = 1;
			g->adj[i][e] = 1;
		}
		return(g);
}
