#include <stdio.h>
#include <malloc.h>

typedef int ElementType;

typedef struct Node {
	ElementType data;
	struct Node* next;
} Node;

typedef Node* Position;
typedef Position List;

void makeNullList(List *header) {
	*header = (List)malloc(sizeof(struct Node));
	(*header)->next = NULL;
}

int emptyList(List header) {
	return header->next == NULL;
}

Node* makeNode(int x) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void appendList(int x, List *header) {
	Node* newNode = makeNode(x);
	Position iNode = *header;
	while (iNode->next != NULL) {
		iNode = iNode->next;
	}
	iNode->next = newNode;
}

void prependList(int x, List *header) {
	Node *newNode = makeNode(x);
	newNode->next = (*header)->next;
	(*header)->next = newNode;
}

void insertList(int x, Position p, List *header) {
	Node *newNode = makeNode(x);
	newNode->next = p->next;
	p->next = newNode;
}

void deleteList(Position p, List *header) {
	if (p->next != NULL) {
		p->next = p->next->next;
	}
}

void readList(List *header) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		appendList(x, header);
	}
}

void printList(List header) {
	Position iNode = header;
	while (iNode->next != NULL) {
		printf("%d ", iNode->next->data);
		iNode = iNode->next;
	}
}

Position locateList(int x, List header) {
	Position iNode = header;
	while (iNode->next != NULL) {
		if (iNode->next->data == x) return iNode;
		iNode = iNode->next;
	}
	return NULL;
}

int main() {
	List header;
	makeNullList(&header);
	
	readList(&header);
	printList(header);
	return 0;
}




