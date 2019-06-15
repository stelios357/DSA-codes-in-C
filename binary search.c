#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(){
	int size  , e;
	printf("Enter the size\n");
	fflush(stdin);
	scanf("%d\n",&size);
	int arr[size];
	int i =0;
	printf("Enter the elements of array.\n");
	fflush(stdin);
	for( i = 0 ; i < size ; i++){
		scanf("%d",&arr[i]);
	}
	int k = 0 , l =0;
	for(k =0 ; k < size-1 ; k++){
		for(l =0 ; l < size-k-1 ; l++){
			if(arr[l]>arr[l+1]){
				int temp = arr[l];
				arr[l] = arr[l+1];
				arr[l+1] = temp;
			}
		}
	}
	printf("plese enter the element you want to search?\n");
	fflush(stdin);
	scanf("%d",&e);
	int start = 0;
	int end = size-1 ;
	int mid;
	while(1 ){
		if((start + end)%2 ==0){
			mid = (start + end)/2;
		}
		else{
			mid = ((start + end)/2)+1;
		}
	
	if(start<=end){
		if(arr[mid] == e){
			printf("the element is at %d\n", mid+1);
			break;
		}
		else if(arr[mid] > e){
			end = mid-1;
		}	
		
		else if(arr[mid] < e){
			start = mid+1;
		}
		
			
	}
	else{
		printf("NOT HERE YOU FOOL\n");
		break;
	
	}
}
		
	
}
