#include <stdio.h>
#include <stdlib.h>

struct node {
	int data; 
	struct node *link;
}; 


void add(struct node *head, int val){ 
	struct node *newNode = (struct node *)malloc(sizeof(struct node)); 
	newNode->data = val; 
	newNode->link = NULL;
	struct node *temp = head; 
	while(temp->link != NULL){
		temp = temp->link;
	}
	temp->link = newNode; 
	printf("\nAdded Successfully\n"); 
}

int main(){
	struct node *newNode, *head, *temp; 
	printf("Enter till -99\n"); int val; 
	while(1){
		scanf("%d", &val); 
		if(val == -99) break;
		newNode = (struct node *)malloc(sizeof(struct node)); 
		newNode->data = val; 
		newNode->link = NULL; 

		if(head == NULL){
			head = newNode;
			temp = head; 
		} else {
			temp->link = newNode; 
			temp = newNode; 
		}
	}
	printf("\nEntered: \n"); 
	temp = head; 
	while(temp != NULL){
		printf("%d ", temp->data); 
		temp = temp->link;
	}
	printf("\nto Add: "); int n;scanf("%d", &n); 
	add(head, n);

	printf("\nArray now: "); 
	temp = head; 
	while(temp != NULL){
		printf("%d ", temp->data); 	
		temp = temp->link;
	} 
	printf("\n");
	return 0; 
}
