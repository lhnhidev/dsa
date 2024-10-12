#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef int ElementType;

typedef struct Node {
	ElementType Element;
	struct Node *Next;
} Node;

typedef Node* List;
typedef List Position;

void makenullList(Node **header) {
	(*header) = (Node *)malloc(sizeof(Node));
	(*header)->Next = NULL;
}

Node *makeNode(ElementType x) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->Next = NULL;
	newNode->Element = x;
	return newNode;
}

Node *locate(ElementType x, Node *header) {
	Node *p = header;
	while (p->Next != NULL) {
		if (p->Next->Element == x) {
			return p;
		}
		p = p->Next;
	}
	return p;
}

int member(ElementType x, Node *header) {
	Node *p = header;
	while (p->Next != NULL) {
		if (p->Next->Element == x) {
			return 1;
		}
		p = p->Next;
	}
	return 0;
}

void addFirst(ElementType x, Node **header) {
	Node *newNode = makeNode(x);
	newNode->Next = (*header)->Next;
	(*header)->Next = newNode;
}

void append(ElementType x, Node **header) {
	Node *newNode = makeNode(x);
	
	Node *currentNode = *header;
	while (currentNode->Next != NULL) {
		currentNode = currentNode->Next;
	}
	currentNode->Next = newNode;
}

void deleteList(Node *p, Node **header) {
	Node *currentNode;
	if (p->Next != NULL) {
		currentNode = p->Next;
		p->Next = currentNode->Next;
	}
}

void erase(ElementType x, Node **header) {
	Node *needDelete = locate(x, *header);
	deleteList(needDelete, header);
}

void sort(Node **header) {
	Node *iNode = (*header)->Next;
	if (iNode == NULL || iNode->Next == NULL) return;
	
	while (iNode != NULL) {
		Node *jNode = iNode->Next;
		while (jNode != NULL) {
			
			if (iNode->Element > jNode->Element) {
				ElementType tmp = iNode->Element;
				iNode->Element = jNode->Element;
				jNode->Element = tmp;
			}
			
			jNode = jNode->Next;
		}
		iNode = iNode->Next;
	}
}

void readList(Node **header) {
	makenullList(header);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ElementType x; scanf("%d", &x);
		append(x, header);
	}
}

void printList(Node *header) {
	Node *currentNode = header->Next;
	while (currentNode != NULL) {
		printf("%d ", currentNode->Element);
		currentNode = currentNode->Next;
	}
}

void normalize(Node **header) {
	Node *iNode = (*header)->Next;
	while (iNode != NULL) {
		Node *jNode = iNode;
		while (jNode->Next != NULL) { // phai xem thang dung dang sau co ton tai hay khong?
			if (jNode->Next->Element == iNode->Element) {
				deleteList(jNode, header);
			}
			else {
				jNode = jNode->Next;
			}
		}
		iNode = iNode->Next;
	}
}



