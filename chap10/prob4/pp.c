#include <stdio.h>   
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};
void push(struct node **top, int data) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = *top;
	*top = newNode;
}

int pop(struct node **top) {
	if (!*top) {
		printf("Stack is empty\n");
		exit(0);
	}

	struct node *temp = *top;
	int poppedData = temp->data;
	*top = temp->next;

	free(temp);
	return poppedData;
}

void printStack(struct node *top) {
	if (!top) {
		printf("Stack is empty\n");
return;
	}
	printf("Print stack\n");
	while (top != NULL) {
		printf("%d\n",top->data);
		top = top->next;
	}
}

int main() {
	struct node *stackTop = NULL;
	int input;
	while (scanf("%d",&input)==1){
		push(&stackTop, input);
	}
	printStack(stackTop);
	return 0;
}
