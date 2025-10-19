#include <stdio.h>

int a[100], f = -1, r = -1; 

void enqueue(int item){
	if(((r+1)%100) == f){
		printf("Queue Overflow"); 
		return; 
	}
	if(r == -1){
		f = 0 ,r = 0; 
		a[0] = item; return; 
	}
	r = (r+1)%100; 
	a[r] = item; 
}

int dequeue(){
	if(f == -1){
		printf("Queue Underflow."); 
		return -99; 
	}
	int val = a[f]; 
	if(f == r){
		f = -1, r = -1; 
		return val; 
	}
	f = (f+1)%100; return val ;
}

void display(){
	printf("\n"); 
	if(f == -1){
		printf("Queue Empty\n"); return; 
	}
	if(f < r){
		for(int i = f; i <= r; i++){
			printf("%d ", a[i]); 
		}
	} else if(f > r){
		for(int i = f; i < 100; i++){
			printf("%d ", a[i]); 
		}
		for(int i = 0; i <= r; i++){
			printf("%d ", a[i]); 
		}
	} else {
		printf("%d", a[f]); 
	}
	printf("\n"); 
}

int main(){
	int val; 
	while(1){
		printf("1. enqueue\n2. dequeue\n3. display\n4. exit\nchoice: "); 
		int choice ; scanf("%d", &choice); 
		switch(choice){
			case 1: printf("Value: "); scanf("%d", &val); 
				enqueue(val); break;
			case 2: val = dequeue(); 
				if(val != -99){
					printf("Popped: %d", val); 
				} break;
			case 3: display(); break;
			case 4: return 1; 
		}
	}
}


