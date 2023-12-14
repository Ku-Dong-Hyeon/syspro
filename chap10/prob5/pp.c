#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void addq(struct node **head, struct node **tail, int data) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	
	newNode->data = data;
	newNode->next = NULL;

	if(*tail == NULL){
		*head = *tail = newNode;
	}
	else {
		(*tail)->next = newNode;
		*tail = newNode;
	}
}

int delete(struct node **head, struct node **tail) {
	if (*head == NULL) {
		printf("Queue is empty\n");
		exit(0);
	}

	struct node *temp = *head;
	int deletedData = temp->data;

	if (*head == *tail) {
		*head = *tail = NULL;
	}
	else {
		*head = temp->next;
	}

	free(temp);

	return deletedData;
}

void printQueue(struct node *head) {
	if (head == NULL) {
		printf("Queue is empty\n");
		return;
	}

	printf("Print queue\n");
	while(head != NULL) {
		printf("%d\n",head->data);
		head = head->next;
	}
}

int main() {
	struct node *head = NULL;
	struct node *tail = NULL;
	int input;

	while(scanf("%d",&input)==1){
		addq(&head, &tail, input);
	}

	printQueue(head);

	while(head!=NULL){
		int deletedElement = delete(&head, &tail);
	}
	return 0;
}
