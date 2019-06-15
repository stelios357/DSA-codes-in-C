#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
};

struct node * headfv = NULL;
struct node * headfe[10] = {0};

void vertex(int data){
	struct node * temp = (struct node *)(malloc(sizeof(struct node )));
	temp->data = data;
	temp->next = headfv;
	headfv = temp;
}



int main(){
	while(1){
		printf("Do you want to enter a vertice ?\n");
		int choicev;
		fflush(stdin);
		scanf("%d" , &choicev);
		if(choice){
			printf("Enter yoiur vertex :\n");
			int v;
			scanf("%d" , &v);
			vertex(v);
			while(1){
				printf("Do you want to enter an edge ?\n");
				int choicee;
				fflush(stdin);
				scanf("%d" , &choicee);
				if(choicee){
					printf("Enter yoiur edge :\n");
					int e;
					scanf("%d" , &e);
					edge(e);
				}
				else break;
			}
		}
		else break;
	}
}
