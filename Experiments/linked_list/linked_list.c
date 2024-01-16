#include <stdio.h>
#include <stdlib.h>

struct Node {
	int num;
	struct Node* next;
};

void push(struct Node** head, int num);
void printall(struct Node** head);

int
main()
{
	struct Node stack, *head;

	stack.num = 1000;
	stack.next = NULL;

	head = &stack;

	for (int i = 0; i < 4; i++) push(&head, i * 100);

	printall(&head);

	return 0;
}

void
push(struct Node** head, int num)
{
	struct Node* nw_node;

	nw_node = (struct Node*)malloc(sizeof(struct Node));

	nw_node->num = num;

	nw_node->next = *head;

	*head = nw_node;
}

void
printall(struct Node** head)
{
	struct Node* h = *head;
	while (h != NULL) {
		printf("%d\n", h->num);
		h = h->next;
	}
}
