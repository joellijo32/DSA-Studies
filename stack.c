#include <stdio.h>

	int a[100]; int top; 
	
	void push(int item){
		if(top == 100){
			printf("Stack Overflow. Push failed."); 
		} else {
			a[++top] = item; 
		}
	}

	int pop(){
		if(top == -1){
			printf("Stack Underflow.Pop failed."); 
			return -99; 
		} else {
			return a[top--]; 
		}
	}

	void display(){
		if(top == -1){
			printf("Stack Empty."); 
		} else {
			for(int i = top; i > -1; i--){
				printf("%d\n", a[i]); 
			}
		}
	}

	int peek(){
		if(top == -1){
			printf("Stack Empty. Peek failed.");
			return -99 ;  
		} else return a[top]; 
	}


	int main(){
		printf("Stack Simuli\n"); 
		while(1){
			printf("1. push\n2. pop\n3. peek\n4. display\nChoice: "); 
			int choice; scanf("%d", &choice);
			int val;  
			switch(choice){
				case 1: printf("Value: "); scanf("%d", &val); 
					push(val); printf("Pushed %d Successfully", val); 
					break; 
				case 2: val = pop(); 
					if(val != -99){
						printf("Popped value: %d", val); 
					} break; 
				case 3: val = peek(); 
					if(val != -99) printf("Peeked value: %d", val); 
					break; 
				case 4: printf("\n"); 
					display(); 
					break; 
				default: printf("Invalid Choice."); 
			}
		}
	}
		
		
