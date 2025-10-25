#include <stdio.h>

void selection_sort(int a[], int l){
	int temp = 0;
	for(int i = 0; i < l-1 ;i++){
		int small = a[i]; int pos = i;
		for(int j = i+1; j < l; j++){
			if(a[j] < small){
				small = a[j]; pos =j;continue;
			}
		}
		temp = a[pos]; 
		a[pos] = a[i]; 
		a[i] = small; 
	}
}

void display(int a[], int l){
	printf("\n"); 
	for(int i = 0; i < l; i++) printf("%d ", a[i]); 
	printf("\n"); 
}

int main(){
	printf("Size: "); int s;scanf("%d" , &s); 
	int ar[s]; 
	printf("Enter elemt: \n"); for(int i = 0; i < s;i++) scanf("%d", &ar[i]); 
	printf("\nArray ent: "); display(ar, s); 
	selection_sort(ar, s); 
	printf("\nSorted Array: "); display(ar, s); 
}

