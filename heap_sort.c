#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
	int* arr;
	int size;int capacity;
} Heap;

void heapify(Heap* a){
	int max;
	int par = (a->size-2)/2;int lc = (2*par)+1, rc = (2*par)+2;
	printf("\nLast parent: %d at %d\n",a->arr[par], par);
	while(par >= 0){
		if(rc < a->size){
			if(a->arr[lc] > a->arr[rc]) max = lc;
			else max = rc;
		}else max = lc;
		if(a->arr[par] < a->arr[max]){
			int temp = a->arr[par];
			a->arr[par] = a->arr[max];
			a->arr[max] = temp;
		}
		par--;
		lc = (2*par)+1, rc = (2*par)+2;
	}
	printf("\n");
}

void display(Heap* a){
	printf("\n");
	for(int i = 0;i < a->size;i++){
		printf("%d ", a->arr[i]);
	}printf("\n");
}


int main(){
	Heap* a = malloc(sizeof(Heap));
	printf("\nSize: ");int l;scanf("%d", &l);
	a->size = l;a->capacity = 100;
	a->arr = NULL;
	printf("\nEnter elements: \n");
	for(int i = 0; i < l;i++){
		a->arr  = realloc(a->arr, (i+1)*sizeof(int));
		scanf("%d", &a->arr[i]);
	}
	printf("\nEntered Array:\n");
	display(a);
	heapify(a);
	printf("\nHeapified max: \n"); display(a);
}
