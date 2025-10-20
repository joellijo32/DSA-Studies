#include <stdio.h>

void Sparse(int a[10][10], int m, int n){
	int i,j,k = 1;
	int s[10][10]; s[0][0] = m; s[0][1] = n;
	printf("\n"); 
	for(i = 0; i< m; i++){
		for(j = 0; j < n;j++){
			if(a[i][j] != 0){
				s[k][0] = i; 
				s[k][1] = j;
				s[k][2] = a[i][j]; 
				k++; 
			}
		}
	printf("\n"); 
	}
	 s[0][2] = k-1; 
	printf("\nSparse Tuple\n");
	for(i = 0;i < s[0][2]+ 1; i++)	{
		for(j = 0; j < 3; j++){
			printf("%d ", s[i][j]); 
		} printf("\n"); 
	}
}


int main(){
	printf("Row: "); int r; scanf("%d", &r); 
	printf("Column: "); int c;scanf("%d", &c); 
	int a[10][10]; 
	printf("Enter Elemetns: \n"); 
	for(int i = 0; i< r; i++){
		for(int j = 0;j < c; j++){
			scanf("%d", &a[i][j]); 
		}
	}
	printf("\nArray Entered: \n");
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			printf("%d ", a[i][j]); 
		} printf("\n"); 
	}
	Sparse(a, r, c); 
}
