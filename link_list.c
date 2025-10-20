#include <stdio.h>
#include <stdlib.h>

struct node {
	int data; 
	struct node *link;
}; 

int main(){
	struct node *head = NULL, *temp = NULL, *newNode = NULL; 
	int n, value; 
	printf("Size: ");scanf("%d", &n); 
	for(int i = 0; i < n;i++){
		newNode = (struct node *)malloc(sizeof(struct node)); 
		printf("Value %d: ", i+1); scanf("%d", &value); 
		newNode->data = value; 
		newNode->link = NULL;

		if(head == NULL){
			head = newNode; 
			temp = head;
		} else {
			temp->link = newNode; 
			temp = newNode; 
		}
	}
	printf("\nLinked List: \n"); 
	temp = head; 
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("NULL\n"); 
	return 0; 
}
