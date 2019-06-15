/* C Program to Implement Queue  using Linked List */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct node
{
    int vertex;
    struct node *next;
};
 
// Function to create a new node

struct node * createnode(int v)
{
  
    struct node *temp = (struct node*) malloc(sizeof(struct node));
             temp->v = v;
             temp->next = NULL;
    return temp;
}

// Function to insert in a queue

struct node * insertqueue(struct node *rear, int v)
{
    struct node *temp = createnode(data);
     if (rear == NULL)
        rear = temp;
     else
      {
       
        rear->next = temp;
        rear = temp;
       }
 
  return rear;  
}
 
// Function to delete from a queue

// please note we have taken front poniter as double pointer because
// when we delete element the front will move to next node and 
//the change should be reflected to calling program also 

char * deletequeue(struct node **front)
{
    struct node *temp ;
    int val;   

     if (*front == NULL)
       {
            printf("Queue is empty in operation delete...");
            exit(0);
        }
     else
      {
        val= (*front)->str);
        //printf("%s", val);
        temp = *front;       
        *front = (*front)->next; 
         free(temp);
        return val;
       }

}

/* Display if queue is empty or not */
int  emptyqueue(struct node *front, struct node *rear)
{
     if ((front == NULL) && (rear == NULL))
        return 1;
    else
       return 0;
}

Note: the rear and front pointers should be created in main program

