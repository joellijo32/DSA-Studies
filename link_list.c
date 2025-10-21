#include <stdio.h>
#include <stdlib.h>

struct node {
	int data; 
	struct node *link;
}; 

int main(){
	printf("Enter till -99\n"); 
	struct node *head, *newNode, *temp; int n;
	while(1){
		scanf("%d", &n); 
		if(n == -99) break;
		newNode = (struct node *)malloc(sizeof(struct node)); 
		newNode->data = n;
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
	printf("\n"); 

	printf("New element: "); scanf("%d", &n); 
	newNode = (struct node *)malloc(sizeof(struct node)); 
	newNode->data = n;
	newNode->link = head; 
	head = newNode; 
	printf("\nCurrent: \n"); 
	temp = head; 
	while(temp != NULL){
		printf("%d ", temp->data); 
		temp = temp->link; 
	}
	printf("\n"); 
}



