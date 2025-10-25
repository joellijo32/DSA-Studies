#include <stdio.h>

int main(){
	printf("Size: "); int s; scanf("%d", &s); 
	int a[s]; printf("Enter Ele:\n"); 
	for(int i = 0; i < s;i++) scanf("%d", &a[i]); 
	printf("\nArray ent: \n"); 
	for(int i = 0; i < s;i++) printf("%d ", a[i]); 
	printf("\n"); int temp ; 
	for(int i = 0 ; i < s-1; i++){
		for(int j = 0; j < s-i; j++){
			if(a[j] > a[j+1]){
				temp = a[j]; 
				a[j] = a[j+1]; 
				a[j+1] = temp; 
			}
		}
	}

	printf("Sorted Ar:\n"); 
	for(int i  = 0; i <s;i++) printf("%d ", a[i]); 
	printf("\n");
	return 0;
}
