#include <stdio.h>

void insertion_sort(int a[], int l){
	int temp = 0; int pos = l;
	for(int i = 1; i < l; i++){
		temp = a[i]; 
		int j = i-1; 
		while(j >= 0 && a[j] > temp){
			a[j+1] = a[j]; 
			j--; 
		} a[j+1] = temp; 
	}
}

int main(){
	printf("Size: "); int n;scanf("%d", &n); 
	int ar[n]; printf("enter:\n");
	for(int i = 0; i < n;i++){
		scanf("%d", &ar[i]); 
	}printf("\nArray enter: \n") ; 
	for(int i = 0; i < n;i++) printf("%d ", ar[i]); insertion_sort(ar, n);
	printf("\nsoerte: \n"); 
	for(int i = 0; i < n;i++) printf("%d ", ar[i]); printf("\n"); 
	return 0; 
}
