#include <stdio.h>

struct Poly{
	int coeff; 
	int exp ; 
}; 

void readPolynomial(struct Poly p[], int s){
	for(int i = 0; i < s; i++){
		printf("coeff of term %d: ", (i+1)); 
		scanf("%d", &(p[i].coeff)); 
		printf("exp of term %d: ", (i+1)); 
		scanf("%d", &(p[i].exp)); 
	}
}

void displayPoly(struct Poly p[], int s){
	int count = 0; 
	for(int i = 0; i < s; i++){
		if(count == 0){
			printf("%dx^%d", p[i].coeff, p[i].exp);
			count = 1; 
		}else {
			printf(" + %dx^%d", p[i].coeff, p[i].exp); 
		}
	}
	printf("\n");  
}

void addPoly(struct Poly first[], struct Poly second[], int p1, int p2, struct Poly sum[]){
	int i = 0, j = 0, k = 0; 
	while(i < p1 && j < p2){
		if(first[i].exp == second[j].exp){
			sum[k].coeff = first[i].coeff + second[j].coeff; 
			sum[k].exp = first[i].exp; 
			i++; j++; k++; 
		} else if(first[i].exp > second[j].exp){
			sum[k].coeff = first[i].coeff; 
			sum[k].exp = first[i].exp; 
			i++; k++; 
		}else {
			sum[k].coeff = second[j].coeff; 
			sum[k].exp = second[j].exp; 
			k++; j++; 
		}
		
	}
}

int main(){
	printf("Size of Poly 1: "); 
	int p1 ; scanf("%d", &p1); 
	struct Poly first[p1]; 
	readPolynomial(first, p1); 
	printf("Size of Poly 2: "); 
	int p2; scanf("%d", &p2); 
	struct Poly second[p2]; 	
	readPolynomial(second, p2);

	printf("\nPolynomial 1: "); 
	displayPoly(first, p1); 
	printf("\nPolynomial 2: "); 
	displayPoly(second, p2);
	
	struct Poly sum[p1+p2]; 
	addPoly(first, second, p1, p2,sum); 
	printf("\nSum = "); 
	displayPoly(sum,p1+p2); 
	 
	

	 
	
}




