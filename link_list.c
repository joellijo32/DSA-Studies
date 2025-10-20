#include <stdio.h>
#include <stdlib.h>

struct node {
	int data; 
	struct node *link; 
}; 

int main(){
	struct node *head = (struct node *)malloc(sizeof(struct node));
	head->data = 45; 
	head->link = NULL; 
	printf("%d\n", head->data); 
	struct node *current = (struct node *)malloc(sizeof(struct node)); 
	head->link = current; 
	current->data = 23; 
	current->link = NULL; 
	printf("Second: %d\n", current->data); 


	return 0;
}
