#include <stdio.h>

int s[10][10]; int t[10][10];
void sparse(int a[10][10], int m, int n){
	int i,j,k = 1; 
	s[0][0] = m; s[0][1] = n; 
	for(i = 0; i < m;i++){
		for( j = 0; j < n;j++){
			if(a[i][j] != 0){
				s[k][0] = i; 
				s[k][1] = j;
				s[k][2] = a[i][j]; 
				k++; 
			}
		}
	}
	s[0][2] = k-1; 
	printf("\nSparse Tuple: \n"); 
	for(i = 0; i <= s[0][2];i++ ){
		for(int j = 0; j < 3; j++){
			printf("%d ", s[i][j]);
		}printf("\n"); 
	}

}

void transpose(){
	 t[0][1] = s[0][0]; t[0][0] = s[0][1]; t[0][2] = s[0][2]; 
	 int i, j, k = 1; 
	i = s[0][1]
