#include <stdio.h>
#include <stdlib.h>

typedef struct Heap{
	int* arr;
	int capacity;
	int size;
} Heap;


void display(Heap* a){
	printf("\n") ;
	int s = a->size;
	for(int i = 0; i< s; i++){
		printf("%d ", a->arr[i]);
	}printf("\n");
}

void insertion(Heap* a,int l, int value){
	l++;
	a->arr = realloc(a->arr, l*sizeof(int));
	a->arr[l-1] = value;int temp;
	int i = l-1;int parent;
	a->size = l;
	while(i > 0){
		parent = (i-1)/2;
		if(a->arr[parent] < a->arr[i]){
			temp = a->arr[i];
			a->arr[i] = a->arr[parent];
			a->arr[parent] = temp;

		}else return;
		i = parent;
	}
}

void deletion(Heap* a){
	int l = a->size;
	int i = 0;
	int temp = a->arr[l-1];
	a->arr[l-1] = a->arr[i];
	a->arr[i] = temp; a->size = (a->size)-1; l--;int lc = 1, rc = 2;
	while(lc <= l-1 || rc <= l-1 ){
		int max;
		if(a->arr[lc] > a->arr[rc]) max = lc;
		else max = rc;

		if(a->arr[i] < a->arr[max]){
			temp = a->arr[max];
			a->arr[max]= a->arr[i];
			a->arr[i] = temp;
			i = max;
		}else return;
		lc = (2*i)+1 , rc = lc+1;
	}
}

int main(){
	printf("Size: ");Heap* a = malloc(sizeof(Heap));
	scanf("%d", &(a->size));a->capacity = 100;
	printf("Elements (in descending order - max heap): \n");
	a->arr = malloc(sizeof(int)*a->size);
	for(int i = 0 ; i < a->size; i++){
		scanf("%d", &(a->arr[i]));
	}
	while(1){
		printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nChoice: ");
		int choice; scanf("%d", &choice);
		switch(choice){
			case 1: printf("\nTo insert: ");int val;scanf("%d", &val);
				insertion(a,a->size,val); printf("\nInserted: %d\n", val); 
				break;
			case 2: deletion(a);printf("\nDeleted Root: %d\n", a->arr[a->size]); 
				break;
			case 3: printf("\nMax Heap:\n");display(a);break;
			default: return 0;
		}
	}
}
