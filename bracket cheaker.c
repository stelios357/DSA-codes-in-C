#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char data;
	struct node * next ;
};

struct node * head = NULL;

void push(char data){
	struct node * temp = (struct node *)(malloc(sizeof(struct node)));
	temp->data = data;
	temp->next = head;
	head = temp;
	return;
}

char pop(){
	if(head != NULL){
		char cob;
		struct node * temp = head;
		cob = head->data;
		head = temp->next;
		free(temp);
		return cob;
		}
	else{
		return 0;
	}
}

int isoperand(char t){
	if( 'a' <= t && t <= 'z' ||'A' <= t && t <= 'Z' ||t <= '0' && t <= '9' )
		return 1;
	else
		return 0;

}

int isoperator(char t){
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



int equality(char o , char c){
	if( o == '{'){
		if(c == '}'){
			return 1;
	}
	else
		return 0;
		}
	if( o == '['){
		if(c == ']'){
			return 1;
	}
	else
		return 0;
		}

	if( o == '('){
		if(c == ')'){
			return 1;
	}
	else
		return 0;
		}

}

int empty(){
	if(head = NULL){
		return 0;
	}
	else
		return 1;
}

int isclosing(char t){
	if(t == '}' || t == ']' || t == ')')
		return 1;
	else
		return 0;
}

int main(void){
	char exp[20];
	int i=0;
	int flag=0;
	getchar();
	printf("\nPlease enter the expression:\n");
	scanf("%s\n",exp);
	int len = strlen(exp);
	//okay till here.
	for(i = 0;i < len;i++){
		if(isoperator(exp[i])){
			if(isopening(exp[i])){
				push(exp[i]);
			}
		if(isclosing(exp[i])){
				if(!empty()){
					printf("\nNO\n");
					flag = 1;
				}
				else{
					char temp;
					temp = pop();
					if(equality(temp , exp[i])){
						continue;
					}
					else{
						printf("NO.\n");
						flag=1;
					}
				}
		}
		}
	else
		continue;
	}
	if(!empty()){
	
	if(!flag){
		printf("YES.");
	}
	else
	printf("\nno\n");
}
else
printf("\nno\n");
}
