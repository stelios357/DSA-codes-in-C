#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define size 100

int arr[size];
int tops = -1;
int tope = size;

pushs(int data){
	if(tope>= tops+1){
		tops++;
		arr[tops] = data;
		return;
	}
	else{
		printf("Stack 1 ooverflow.\n");
		return;
	}
}

pushe(int data){
	if(tope<= tops+1){
		printf("Stack 2 ooverflow.\n");
		return;
	}
	else{
		tops++;
		arr[tops] = data;
		return;
	}
}

pops(){
	if(tops == -1){
		printf("stack 1 underflow.\n");
		return;
	}
	else{
		tops--;
		return;
	}
}

pope(){
	if(tope == size){
		printf("stack 2 underflow.\n");
		return;
	}
	else
	tope++;
	return;
}

prints(){
	int i = tops;
	for( i ; i >= 0 ; i--){
		printf("---->%d\n" ,arr[i]);
	}
	return;
}
printe(){
	int i = tope;
	printf("Your array from end is:");
	for( i ; i < 100 ; i++){
		printf("---->%d\n" ,arr[i]);
	}
	return;
}

int main(){
	int a , b , c ,d, e;
	while(1){
		printf("Do you want to enter data ?\n");
		fflush(stdin);
		scanf("%d",&a);
		if(a){
			printf("In which array you want to put ?\n");
			scanf("%d",&b);
			if(b == 1){
				printf("Please enter data :\n");
				scanf("%d",&c);
				pushs(c);
			}
			else if( b == 2){
				printf("Please enter data :\n");
				scanf("%d",&d);
				pushs(d);
			}
		}
		else
		break;
	}
	prints();
	printe();

}
