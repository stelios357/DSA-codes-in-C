#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	printf("Enter the size of both arrays.\n");
	int a , b;
	int i = 0 ; 
	int j = 0;
	fflush(stdin);
	scanf("%d\n%d\n",&a,&b);
	int arr1[a] , arr2[b] ;
	printf("Enter the elements of 1st array \n");
	fflush(stdin);
	for( i=0 ; i <= a ; i++){
		scanf("%d", &arr1[i]);
	}
	printf("Enter the elements of 2nd array \n");
	fflush(stdin);
	for( j=0 ; j <= b ; j++){
		scanf("%d", &arr2[j]);
	}
	fflush(stdin);
	printf("Your sorted array is:\n");
	int k =0 , l =0 , m =0;
	fflush(stdin);
	while(l<a){
		printf("Testing array 1 %d" , arr1[l]);
		l++;
	}
	printf("\n");
	fflush(stdin);
	while(m<b){
		printf("testing array 2%d" , arr2[m]);
		m++;
	}
	fflush(stdin);
	printf("\n");
	l =0 ; m =0;
	while(l<a && m<b){
		if(arr1[l] < arr2[m]){
			printf("%d" , arr1[l]);
			l++;
		}
		else if(arr1[l] > arr2[m]){
			printf("%d" , arr2[m]);
			m++;
		}
		else if(arr1[l] = arr2[m]){
			printf("%d" , arr1[l]);
			l++;
			m++;
		}
	}
	while(l<a){
		printf("%d" , arr1[l]);
		l++;
	}
	while(m<b){
		printf("%d" , arr2[m]);
		m++;
	}
}

