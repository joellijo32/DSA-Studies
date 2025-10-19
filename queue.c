#include <stdio.h>

int a[100], f = -1 , r = -1; 

void enqueue(int item){
	if(r == 100){
		printf("\nQueue Overflow.\n"); 
		return; 
	} else if(r == -1){
		f = 0;
	} 
	a[++r] = item; 
}

int dequeue(){
	if(f == -1){
		printf("\nQueue Overflow\n"); 
		return -99; 
	} else{
		int item = a[f] ;
		 if(f == r){
			f = -1; r = -1; 
			return item; 
		}
		f++; 
		return item; 
	}
}

int peek(){
	if(f == -1){
		printf("\nQueue Empty\n"); 
		return -99; 
	}
	return a[f]; 
}

void display(){
	if(f == -1){
		printf("\nQueue empty\n"); 
	} else{
		for(int i = f; i <= r; i++){
			printf("%d ", a[i]);
		}
	}
}

int main(){
	printf("\nQueue:\n"); 
	while(1){
		printf("\n1. push\n2. pop\n3. peek\n4. display\n5. exit\nchoice: "); 
		int choice ; scanf("%d", &choice);
		int val;  
		switch(choice){
			case 1: printf("Item: "); scanf("%d", &val); 
				enqueue(val); 
				break; 
			case 2: val = dequeue(); 
				if(val != -99){
					printf("Popped : %d", val); 
				}
				break; 
			case 3: val = peek(); 
				if(val != -99){
					printf("Peeked: %d", val); 
				} break; 
			case 4: printf("\n") ; display(); printf("\n"); break;  
			case 5: return 1; 
			default: printf("Invalid Input");  
		}
	}
}
	
