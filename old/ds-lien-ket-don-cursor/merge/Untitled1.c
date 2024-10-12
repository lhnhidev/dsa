#include <stdio.h>
#include <malloc.h>

typedef int itemType;

typedef struct Node {
	itemType data;
	struct Node *next;
} Node;

typedef Node* posType;

void makeNullList(Node **header) {
	(*header) = (Node *)malloc(sizeof(Node));
	(*header)->next = NULL;
}

Node *makeNode(itemType x) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = x;
	return newNode;
}

void insertList(itemType x, int p, Node **header) {
	Node *current = *header;
	Node *newNode = makeNode(x);
	for (int i = 0; i < p-1; i++) {
		current = current->next;
	}
	newNode->next = current->next;
	current->next = newNode;
}

void appendList(itemType x, Node **header) {
	Node *current = (*header)->next;
	Node *newNode = makeNode(x);
	
	if (current == NULL) {
		(*header)->next = newNode;
		return;
	}
	
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = newNode;
}

void readList(Node **header) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		itemType x; scanf("%d", &x);
		insertList(x, i+1, header);
	}
}

void printList(Node *header) {
	Node *current = header->next;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
}

Node *mergeList(Node *header1, Node *header2) {
	Node *current1 = header1->next;
	Node *current2 = header2->next;
	Node *newHeader;
	makeNullList(&newHeader);
	
	while (current1 != NULL && current2 != NULL) {
		if (current1->data < current2->data) {
			appendList(current1->data, &newHeader);
			current1 = current1->next;
		}
		else {
			appendList(current2->data, &newHeader);
			current2 = current2->next;
		}
	}
	
	while (current1 != NULL) {
		appendList(current1->data, &newHeader);
		current1 = current1->next;
	}
	while (current2 != NULL) {
		appendList(current2->data, &newHeader);
		current2 = current2->next;
	}
	
	return newHeader;
}

int main() {
	Node *header1, *header2, *header;
	makeNullList(&header1); makeNullList(&header2); makeNullList(&header);
	readList(&header1); readList(&header2);

	header = mergeList(header1, header2);
	printList(header);
	return 0;
}
