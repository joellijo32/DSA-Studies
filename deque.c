#include <stdio.h>

int a[10], f = -1, r = -1; 
void push(int item){
	if(f == 0 && r == 9){
		printf("Deque Overflow"); 
	} else if(f > 0){
		a[--f] = item; 
	} else if(f == -1){
		a[++f] = item;r++; 
	} else {
		for(int i = r; i >= f; i--){
			a[i+1] = a[i]; 
		}
		r++; 
		a[f] = item; 
	}
}

void inject(int item){
	if(f == 0 && r == 9){
		printf("Deque Overflow"); 
	} else if(r == -1){
		a[++r] = item; 
		f = 0; 
	} else if(f > 0){
		for(int i = f; i <= r; i++){
			a[i-1] = a[i]; 
		}
		f--; 
		a[r] = item;
	} else a[++r] = item;
} 


int pop(){
	if(r == -1){
		printf("Deque Empty"); 
		return -99; 
	} else if(f == r){
		int val = a[r] ;f = -1, r= -1;
		return val;
	}
	return a[r--]; 
}

int deject(){
	if(f == -1){
		printf("Deque Empty");  return -99;
	}else if(f == r){
		int val = a[f]; 
		f = -1, r = -1; 
		return val;
	} return a[f++]; 
}

void display(){
	if(f == -1){
		printf("\nDeque Empty\n");  return;
	}
	printf("\n"); 
	for(int i = 0; i < 10; i++){
		printf("%d ", a[i]); 
	}
	printf("\n"); 
}

int main(){
	int val; 
	while(1){
		printf("\n1. push\n2. inject\n3. pop\n4. deject\n5. display\n6. exit\nchoice: "); 
		int choice; scanf("%d", &choice); 
		switch(choice){
			case 1: printf("Value: "); scanf("%d", &val); 
				push(val); break;
			case 2: printf("Value: "); scanf("%d", &val); 
				push(val); break;
			case 3: val = pop(); 
				if(val != -99){
					printf("\nPopped: %d", val); 
				}break;
			case 4: val = deject(); 
				if(val != -99){
					printf("\nDejected: %d", val); 
				}break;
			case 5: display();break;
			case 6: return 1; 
			default: printf("Invalid choice"); 
		}
	}
	return 0; 
}


