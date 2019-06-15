/* Implementation of integer stack using arrays */

#include <stdio.h>
#include<stdlib.h>
#define SIZE  100       

struct intstack 
{
   int arr[SIZE];
   int top;
};

// To check whether stack is empty or not
int isempty(struct intstack s) 
{

   if(s.top == -1)
      return 1;
   else
      return 0;
}

// To check whether stack is full or not   

int isfull(struct intstack s) 
{

   if(s.top == SIZE)
      return 1;
   else
      return 0;
}

// To push an element on the stack 

void push(struct intstack *s, int val) 
{
     if(s->top>=SIZE) 
       {
            printf("Stack overflow...");
            exit(0);
        }
   
      s->top++;
      s->arr[s->top] = val;
}

// To pop the element of stack 

int pop(struct intstack *s) 
{
     if(s->top== -1) 
       {
            printf("Stack underflow...");
            exit(0);
        }
   
   return s->arr[s->top--];
}

// To read top of the stack without delete 

int top(struct intstack s) 
{
     if(s.top==-1) 
       {
            printf("Stack underflow...");
            exit(0);
        }
   
   return s.arr[s.top];
}
