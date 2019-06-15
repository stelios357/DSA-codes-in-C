#include <stdio.h>
#include <stdlib.h>


struct node{
	int vertex;
    struct node *next;
};

struct node * createnode(int v){
   struct node * newnode = (struct node*)malloc(sizeof(struct node));
   newnode->vertex = v;
   newnode->next = NULL;
   return newnode;
}

void creategraph_adjlist (struct node *adj_list[10], int n ){
    int i, j;
    char choice;
    struct node *newnode, *cur;
    for ( i = 1 ; i <= n ; i++ ){
        for ( j = 1 ; j <= n ; j++ )
        {
            if ( i == j )
                continue;
            printf("\n Vertices %d & %d are Adjacent ? (Y/N) :", i, j);
            getchar(); // to eat unwanted '\n' int the buffer
            scanf("%c", &choice);
            if ( choice == 'y' || choice == 'Y' )
            {
                newnode =createnode(j);
                if ( adj_list[i] == NULL )
                    adj_list[i] = newnode;
                else
                {
                    cur = adj_list[i];
                    while(cur->next!= NULL)
                        cur = cur->next;
                    cur->next = newnode; // add vertex to end of list
		} 
             }
        } // end of for j 
    } // end of for i
} // end of creategraph_list

int creategraph_adjmat(int adj_mat[][10], int n )
{
    int i, j;
    char choice;
    for (i = 1 ; i <= n ; i++ )
    {
        for ( j = 1 ; j <= n ; j++ )
        {
            if ( i == j )
            {
                adj_mat[i][j] = 0;
		continue;
            } 
           printf("\n Vertices %d & %d are Adjacent ? (Y/N) :",i,j);
           getchar(); // to eat unwanted '\n' from buffer
            scanf("%c", &choice);
            if ( choice == 'y' || choice == 'Y' )
                adj_mat[i][j] = 1;
            else
                adj_mat[i][j] = 0;
	} // end of for j
    } //end of for i
} // end of create graph using adjmatrix

void bfs(int adjmat[][10], int n, int svertex)
{
     // assuming queue is already implemented
    int i, v;
    int *visited = (int *)calloc(n+1,sizeof(int));
    insertqueue(&q,svertex);
    visited[svertex]= 1;
    printf("\nBFS sequence:");
    while(!emptyqueue(q))
     {
        v = deletequeue(&q);
        printf("v%d ", v);
        for(i=1; i<=n;i++)
         {
            if(visited[i]==0 && adjmat[v][i] == 1)
             { 
                insertqueue(&q,i);
                visited[i] = 1;
             }
         }
     } // end of while
} // end of iterative BFS   

void dfs(int adjmat[][10], int n, int svertex)
{
    struct stack s; // assuming stack is already implemented
    int i, v;
    int *visited = (int *)calloc(n+1,sizeof(int));
    push(&s,svertex);
    visited[svertex]= 1;
    printf("\nDFS sequence:");
    while(!emptystack(s))
     {
        v = pop(&s);
        printf("v%d ", v);
        for(i=1; i<=n;i++)
         {
            if(visited[i]==0 && adjmat[v][i] == 1)
             { 
                push(&s,i);
                visited[i] = 1;
             }
         }
     } // end of while
} // end of iterative DFS   
  
mygraph.c
Displaying mygraph.c.
