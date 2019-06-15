#include<stdio.h>
#include<stdlib.h>

struct graph{
	int v;
	int e;
	struct list * adj;
};

struct list{
	int data;
	struct list * next;
};

struct graph * create(struct graph * g){
	int i , j , u ,v;
	printf("Enter v n e : \n");
	scanf("%d%d" , &g->v , &g->e);
	g->adj = (struct list *)(malloc(sizeof(struct list *)*g->v));
	for(i = 0 ; i < g->v ; i++){
		(g->adj+i)->data = i;
		(g->adj+i)->next = g->adj+i;
	}
	for(i = 0 ; i < g->v ; i++){
		printf("Enter source and destination :\n");
		scanf("%d%d" , &u , &v);
		struct list * temp = (struct list *)(malloc(sizeof(struct list )));
		temp->data = v;
		temp->next = g->adj+u;
		struct list * t  = g->adj+u;
		while(t->next != g->adj+u){
			t = t->next;
		}
		t = temp;
	}
}

print(struct graph * g){
	int i;
	for(i = 0 ; i < g->v ; i++){
		struct graph * temp = g;
		int j=0;
		while((temp->adj+j)->next != temp->adj+j){
			printf("--->%d is connected to : %d" , i, (temp->adj+j)->data );
			j++;
		}
	}
}

int main(){
	struct graph * g = (struct graph *)(malloc(sizeof(struct graph)));
	create(g);
	print(g);
}
