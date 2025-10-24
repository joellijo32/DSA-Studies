#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	struct node *prev; 
	char page[100]; 
	struct node *next; 
} Node ;

Node* createNode(char a[100]){
	Node *newNode = (Node *)malloc(sizeof(Node)); 
	strcpy(newNode->page, a) ; 
	newNode->prev = NULL, newNode->next = NULL ;
	return newNode; 
}

void back(Node* current){
	if(current->prev == NULL){
		printf("\nNo Back\n"); 
		return; 
	}
	current = current->prev; 
	printf("\nNow at: %s\n", current->page); 
}

void forward(Node* current){
	if(current->next == NULL){
		printf("\nTo go to: "); char* s = malloc(100); 
		scanf("%s", s); 
		 
		Node* newNode = createNode(s); 
		current->next = newNode; newNode->prev = current; 
		current = newNode;   
	}else {
		current = current->next; 
	}
	printf("\nNow at: %s\n", current->page); 
}


void display(Node* temp, Node* curr){
	printf("\n");
	if(temp == NULL) printf("\nError Displaying\n"); 
	while(temp != NULL){
		printf("%s", temp->page); 
		if(temp == curr){
			printf(" <- Current page");
		}
		temp = temp->next;printf("\n");  
	}
	printf("\n"); 
}

int main(){
	char second[100] = "google.com";   
	Node* head = createNode(second); int val ; Node* temp = head;
	printf("\nInitially at %s\n", head->page); 
	while(1){
		printf("\n1. forward\n2. backward\n3. display\n4. exit\nchoice: "); 
		scanf("%d", &val); 
		switch(val){
			case 1: forward(temp); 
				temp=temp->next; break;
			case 2: back(temp); 
				if(temp->prev != NULL) temp= temp->prev;  
				break;
			case 3: display(head, temp); break;
			case 4: return 0; 
			default: printf("Invalid choice"); 
		}
	}
	free(head); free(temp); 
}
			




