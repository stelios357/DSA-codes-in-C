#include<stdio.h>
#include<stdlib.h>

struct e{
	char name[20];
	int age;
	int doj;
};

struct node{
	struct e emp;
	struct node * next;
};

struct node * chain[10];

void ini{
	int i = 0;
	for(i ; i < 10 ; i++){
		chain[i] = NULL;
	}
}

void insert( char name[20] , int age , int doj){
	struct node * temp = (struct node *)(malloc(sizeof(struct node)));
	strcpy( name , temp->emp.name);
	temp->emp.age = age ;
	temp->emp.doj = doj;
	if(chain)
}
