#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
	int* arr;
	int size;int capacity;
} Heap;

void heapify(Heap* a){
	printf("\nSize: ");int l;scanf("%d", &l);
	a->size = l;a->capacity = 100;
	a->arr = NULL;
	for(int i = 0; i < l;i++){
		a->arr  = realloc(a->arr, (i+1)*sizeof(int));
		scanf("%d", &a->arr[i]);
	}
	printf("\nEntered Array:\n");
	for(int i = 0; i< l;i++) printf("%d ", a->arr[i]);
	printf("\n");
}

int main(){
	Heap* a = malloc(sizeof(Heap));
	heapify(a);
}
