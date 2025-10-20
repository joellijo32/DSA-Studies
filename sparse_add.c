#include <stdio.h>

void sparse(int a[10][10], int m, int n, int s[10][3]){
	int i , j , k = 1;
	s[0][0] = m; s[0][1] = n;
	for(i = 0;i < m;i++){
		for(j = 0; j < n;j++){
			if(a[i][j] != 0){
				s[k][0] = i; 
				s[k][1] = j;
				s[k][2] = a[i][j]; 
				k++; 
			}
		}
	}
	s[0][2] = k-1; 
	printf("\nSparse Tuple: "); 
	for(i = 0; i < s[0][2]+1; i++){
		for(j = 0; j < 3;j++){
			printf("%d ", s[i][j]); 
		}printf("\n"); 
	}

	printf("\n"); 
}

void add(int a[10][3], int b[10][3]){
	int i ,j,k= 1; 
	int t[10][3]; 
	int r1 = a[0][0], c1 = a[0][1], r2 = b[0][0], c2 = b[0][1]; 
	if(r1 != r2 || c1 != c2){
		printf("Incompactible arrays to add"); 	
		return; 
	}
	int m=1, n=1;t[0][0] = a[0][0], t[0][1] = a[0][1]; 
	for(i = 0; i < r1; i++){
		for(j = 0; j < c1;j++){
			if(a[m][0] == i && a[m][1] == j && b[n][0] == i && b[m][1] == j){
				t[k][0] = a[m][0]; 
				t[k][1] = b[n][1]; 
				t[k][2] = a[m][2] + b[n][2]; 
				k++; 
				m++, n++; 
			} else if(a[m][0] == i && a[m][1] == j){
				t[k][0] = a[m][0], t[k][1] = a[m][1], t[k][2] = a[m][2]; 
				k++, m++; 
			} else if(b[n][0] == i && b[n][1] == j){
				t[k][0] = b[n][0] , t[k][1] = b[n][1], t[k][2] = b[n][2]; 
				k++, n++; 
			}
		}
	}
	t[0][2] = k-1; 
	printf("\n"); 
	for(i = 0; i < t[0][2]+1 ; i++){
		for(j = 0; j < 3; j++){
			printf("%d ", t[i][j]); 
		}printf("\n"); 
	}
	printf("\n"); 
}

int main(){
	int a[10][10], b[10][10];
	int m , n; printf("First Array: \n");
	printf("Row = "); scanf("%d", &m);
	printf("colum = "); scanf("%d", &n);
	printf("Array: \n");
	for(int i = 0; i < m;i++){
		for(int j = 0; j < n;j++){
			scanf("%d", &a[i][j]);
		}
	}
	int s1[10][3];
	printf("\n"); sparse(a, m, n, s1);
	printf("Second Array: \n");
	printf("Row = "); scanf("%d", &m);
	printf("colum = "); scanf("%d", &n);
	printf("Array: \n");
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n;j++){
			scanf("%d", &b[i][j]);
		}
	}
	int s2[10][3];
	printf("\n"); sparse(b,m,n,s2);
        add(s1,s2);

}
