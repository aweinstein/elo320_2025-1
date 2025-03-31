#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;	
} Node;

int main(void)
{
	Node *a = malloc(sizeof(Node));
	Node *b = malloc(sizeof(Node));
	Node *c = malloc(sizeof(Node));
	
	a->data = 27;
	b->data = 3;
	c->data = 54;
	
	a->next = b;
	b->next = c;
	c->next = NULL;
	
	// Recorramos la lista
	Node *current = a; //Magicamente se que parte en a
	while(current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL \n");
	
	
	return 0;	
}