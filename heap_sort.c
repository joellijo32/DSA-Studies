#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
	int* arr;
	int size;int capacity;
} Heap;

void display(Heap* a){
	printf("\n");
	for(int i = 0;i < a->capacity;i++){
		printf("%d ", a->arr[i]);
	}printf("\n");
}


void heapify(Heap* a,int i){
	int largest = i;int lc = (2*i)+1, rc= (2*i)+2;
	if(lc <= a->size && a->arr[largest] < a->arr[lc]){
		largest = lc;
	}
	if(rc <= a->size && a->arr[largest] < a->arr[rc]){
		largest = rc;
	}
	if(largest != i){
		int temp = a->arr[i];
		a->arr[i] = a->arr[largest];
		a->arr[largest] = temp;
		heapify(a,largest);
	}
}

int main(){
	Heap* a = malloc(sizeof(Heap));
	printf("\nSize: ");int l;scanf("%d", &l);
	a->size = l;a->capacity = l;
	a->arr = NULL;
	printf("\nEnter elements: \n");
	for(int i = 0; i < l;i++){
		a->arr  = realloc(a->arr, (i+1)*sizeof(int));
		scanf("%d", &a->arr[i]);
	}
	printf("\nEntered Array:\n");
	display(a);
	int par = (a->size-2)/2;
	while(par >= 0){
		heapify(a,par);par--;
	}
	printf("\nHeapified max heap: \n"); display(a);
/*	printf("\nHeap sorted Array: \n"); heapSort(a);
	display(a);*/
}
