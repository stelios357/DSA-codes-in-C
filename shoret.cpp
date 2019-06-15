#include<stdio.h>
#include<stdlib.h>

int INF = 9999;

struct graph{
	int v;
	int e;
	int * adj;
};

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

print(struct graph * g){
	int i , j ;
	for(i = 0 ; i < g->v ; i++){
		for(j = 0 ; j < g->v ; j++){
				printf("%7d", *(g->adj+i * g->v + j));
		}
		printf("\n");
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
}
