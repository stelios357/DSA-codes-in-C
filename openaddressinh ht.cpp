#include<stdio.h>
#include<stdlib.h>

int arr[10] = {};
int count = 0;

int hcode(int data){
	int i = data % 10;
	return i;
}

void insert(int data){
	if(count == 10){
		printf("The hashtable is full!\n");
		exit(EXIT_FAILURE);
	}
	else{
		int code = hcode(data);
		while(arr[code] != NULL && arr[code] != -1 ){
			code = ( code + 1)% 10;
		}
		arr[code] = data;
		count++;
	}
}

int search(int data){
	if(count == 0){
		printf("No element exists!\n");
	}
	else{
		int code = hcode(data);
		while(arr[code] != NULL && arr[code] != -1 ){
			if(arr[code] == data){
				printf("Found !!!\n");
				return 1;
			}
			code = ( code + 1)% 10;
		}
		printf("Not found!!!\n");
		return 0;
	}
}

int Delete(int data){
	if(count == 0){
		printf("No element exists!\n");
	}
	else{
		int code = hcode(data);
		while(arr[code] != NULL && arr[code] != -1 ){
			if(arr[code] == data){
				arr[code] = -1;
				count--;
				return 1;
			}
			code = ( code + 1)% 10;
		}
		printf("Not found!!!\n");
		return 0;
	}
}

void print(){
	if(count == 0){
		printf("No element exists!\n");
	}
	else{
		int i;
		for( i = 0 ; i < 10 ; i++){
			printf("---->%d\n" , arr[i]);
		}
	}
}

int main()
{
    int ch,item;
    printf("Enter Elements to insert in hash table :");
    printf("\nTo STOP, enter 0\n\n");
    do{
        scanf("%d",&item);
        insert(item);
    }while(item!=0);

    print();

    printf("\nEnter the elements you want to delete :");
    printf("\nTo STOP, enter 0\n\n");
    do
    {
        scanf("%d",&item);
        if(item)
            Delete(item);
    }while(item);

    print();

    printf("\nEnter the elements you want to search :");
    printf("\nTo STOP, enter 0\n\n");
    do
    {
        scanf("%d",&item);
        if(item){
            int loc;
            loc=search((item));
            if(loc!=-1)
                printf("\nElement %d Found at location %d",item,loc);
        }
    }while(item);

    printf("\nEnter Elements to insert in hash table :");
    printf("\nTo STOP, enter 0\n\n");
    do{
        scanf("%d",&item);
        insert(item);
    }while(item!=0);

    print();
    return 0;
}
