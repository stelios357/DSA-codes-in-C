
#include <stdio.h>
void heapsort(int x[], int n);
void createheap(int x[], int n);
void adjustheap(int x[], int n);
void display(int x[], int n);
int main()
{
     int arr[10] = {25,57,48,37,12, 92,86,33,5,40};
     printf("List Before sorting:");
     display(arr, 10);
     heapsort(arr,10);
     printf("\nList After Sorting");
     display(arr,10);
}

void heapsort(int x[], int n)
{
     createheap(x,n);
     adjustheap(x,n);
}
void createheap(int x[], int n)
{
     int i, y, s, f;
     for(i = 1; i<n ; i++)
       {
           y = x[i];
           s = i;
           f = (s-1)/2;
           while(s>= 0 && x[f] < y) // for creating max heap
           {
              x[s] = x[f];
              s = f;
              f = (s-1)/2;
           }
           x[s] = y;
       } // end of for
} // end of creating heap

void adjustheap(int x[], int n)
{
     int i,s,f,y;
     for(i=n-1;i>0;i--)
       {
          y =  x[i]; // preserve the last element
          x[i] = x[0];
          f = 0;
          // now decide s 
          if(i==1) // reached to  the boundary           
            s = -1;
          else
            s = 1;
          if(i>2 && x[2] < x[1])
            s =2;
            
          // adjust heap to maintain the heap property
          while(s >= 0 && y < x[s])
           {
              x[f] = x[s];
              f = s;
              s = 2*f+1; // S may go beyond the boundary
              if( s+1 <= i-1 && x[s] < x[s+1])
                  s = s+1;
              if( s > i-1)
                s = -1;  // reach to the boundary so
                         // further adjusting not required 
           } 
           
           x[f] = y;
        } // end of for
} // end of adjustheap()                   
                  
void display(int x[], int n)
{
     for(int i= 0;i<n ;i++)
      printf("%4d", x[i]);
}                                      
