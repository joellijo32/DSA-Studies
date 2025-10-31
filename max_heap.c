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


int main(){
	printf("Size: ");Heap* a = malloc(sizeof(Heap));
	scanf("%d", &(a->size));a->capacity = 100;
	printf("Elements: \n");
	a->arr = malloc(sizeof(int)*a->size);
	for(int i = 0 ; i < a->size; i++){
		scanf("%d", &(a->arr[i]));
	}
	display(a);
	printf("\nInsert: "); int v;scanf("%d", &v);
	insertion(a,a->size,v);printf("\nInserted %d\n", v);
	display(a);
}
