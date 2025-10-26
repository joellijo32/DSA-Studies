#include <stdio.h>

void merge(int a[], int lb, int mid, int ub){
	int size = ub-lb+1;
	int b[size];
	int i = lb, j = mid+1, k = 0 ;
	while(i <= mid && j <= ub){
		if(a[i] <= a[j]){
			b[k] = a[i]; i++, k++;
		} else{
			b[k] = a[j]; j++, k++;
		}
	}
	while(i <= mid){
		b[k++] = a[i++];
	}
	while(j <= ub){
		b[k++] = a[j++];
	}
	for(i = 0; i < size; i++){
		a[i] = b[i];
	}
}

void mergeSort(int a[], int lb, int ub){
	if(lb < ub){
		int mid = (int)(lb + ub)/2;
		mergeSort(a, lb, mid); mergeSort(a, mid+1, ub);
		merge(a, lb, mid, ub);
	}
}



void display(int a[], int size){
	printf("\n");
	for(int i = 0; i < size; i++){
		printf("%d ", a[i]); 
	}
	printf("\n");
}


int main(){
	printf("Size: "); int l; scanf("%d", &l);
	int ar[l]; printf("Elements: \n");
	for(int i = 0; i <l; i++) scanf("%d", &ar[i]);
	display(ar, l);
	printf("After mergin: \n"); mergeSort(ar, 0, l-1);
	display(ar, l);
}
