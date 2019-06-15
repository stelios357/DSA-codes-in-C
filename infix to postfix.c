#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char data;
	struct node * next ;
};

struct node * head = NULL ;

void push(char data){
	struct node * temp = (struct node *)(malloc(sizeof(struct node )));
	temp->data = data;
	temp->next = head;
	head = temp;
	return;
}

int pop(){
	if(head= NULL)
		return 0;
	
	else{
		int data;
		struct node * temp = head;
		data = temp->data;
		head = head->next;
		free(temp);
		return data;
	}
}

int empty(){
	if(head = NULL)
		return 1;
	else
		return 0;
}

int isoperand(char t){
	if( t <= '0' && t <= '9'||'a' <= t && t <= 'z' ||'A' <= t && t <= 'Z' )
		return 1;
	else
		return 0;

}

int isbracket(char t){
if(  t == '(' || t == ')' || t == '{' || t == '}' || t == '[' || t == ']' )
	return 1;
else
	return 0;

}

int isopening(char t){
	if(t == '{' || t == '[' || t == '(')
	return 1;
else
	return 0;
}

int isclosing(char t){
	if(t == '}' || t == ']' || t == ')')
		return 1;
	else
		return 0;
}

int isoperator(char r){
	if( r == '+' ||r == '-' ||r == '/' ||r == '*' ||r == '^')
	return 1;
	else
	return 0;
}

char top(){
	char data = head->data;
	return data;
}

int value(char v){
	int value = 0;
	switch(v){
		case'^':
		value = 4;
		break;
		
		case'/':
		value = 3;
		break;
		
		case'+':
		value = 2;
		break;
		
		case'-':
		value = 2;
		break;
		
		case'*':
		value = 3;
		break;
	}
}
int higher(char o , char c){
	if (value(o) >value (c))
		return 1;
	else
		return 0;
}
int main(){
	getchar();
	printf("\nEnter your infix operation:\n");
	char ex[100];
	char final[100];
	int h = 0;
	scanf("%s\n",ex);
	printf("\n check for infix %s\n",ex);
	int l = strlen(ex);
	int i = 0;
	printf("\n check for length %d\n",l);
	for(i=0;i<l;i++){
		if(isoperand(ex[i])){
			printf("\n check for operand");
			final[h]=ex[i];
			h++;
		}
		if(isoperator(ex[i])){
			printf("\n check for operator");
			while(!empty && higher(top() , ex[i]) && !opening(top())){
				printf("\n check for pop");
				char k = pop();
				final[h]= k;
				h++;
			}
			push(ex[i]);
			printf("\n check for push");
		}
		if(isopening(ex[i])){
			printf("\n check for opening operator");
			push(ex[i]);
		}
		if(isclosing(ex[i])){
			printf("\n check for closing operator");
			while(!empty && !isopening(top())){
				char r = pop();
				printf("\n check for pop");
				final[h]= r;
				h++;
			}
			pop();
		}
		while(!empty){
			char t = pop();
			final[h]=t;
			h++;
		}
	}
	printf("%s",final);
}
