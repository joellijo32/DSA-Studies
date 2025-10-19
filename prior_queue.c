#include <stdio.h>

int f = -1, r = -1; 
struct element {
	int item; 
	int priority; 
}a[10] ; 

void enqueue(int value, int prior){
	if(r == -1){
		a[++r].item = value; 
		a[r].priority = prior; f = 0; 
	} else if(f == 0 && r == 9){
		printf("Queue Overflow"); 
	} else {
		int loc; 
		if(r == 9){
			for(int i = f; i <= r; i++){
				a[i-1] = a[i]; 
			}f--; r--; 
		}
		for(int i = f; i <= r; i++){
			if(a[i].priority < prior){
				loc = i+1; break;
			}
		}
		for(int i = r; i >= f; i--){
			a[i+1] = a[i]; 
		}
		a[loc].item = value; 
		a[loc].priority = prior; r++; 
	}
}


int dequeue(){
	if(f == -1){
		printf("Queue empty"); 
		return -99; 
	} else if(f==r){
		int val = a[f].item; 
		f = -1, r = -1; return val; 
	} else {
		int val; int p = a[f].priority; int loc ; 
		for(int i = f; i <= r; i++){
			if(a[i].priority > p){
				p = a[i].priority; val = a[i].item;loc = i; 
			}
		}
		for(int i = loc; i<= r; i++){
			a[i] = a[i+1]; 
		}r--;
		return val; 
	}
}


void display(){
	printf("\n");
	if(f == -1){
		printf("Queue Empty"); 
	} 
	for(int i = f; i <= r; i++){
		printf("%d ", a[i].item); 
	}
	printf("\n"); 
}

int main(){
	int val, p; 
	while(1){
		printf("\n1. enqueue\n2. dequeue\n3. display\n4. exit\nChoice: ");
		scanf("%d", &val);  
		switch(val){
			case 1: printf("value: "); scanf("%d", &val); 
				printf("prior: "); scanf("%d",&p); 
				enqueue(val,p); break;
			case 2: val = dequeue(); 
				if(val != -99){
					printf("Dequeued: %d", val); 
				}break;
			case 3: display(); break; 
			case 4: return 0; 
			default: printf("Invalid choice"); 
		}
	}
}

