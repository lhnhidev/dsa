#include <stdio.h>
#include <malloc.h>

typedef int ElementType;

typedef struct Node {
	ElementType data;
	struct Node* next;
	struct Node *previous;
} Node;

typedef Node* Position;
typedef Position dbList;

void makeNullList(dbList *list) {
	list = NULL;
}

int emptyDbList(dbList list) {
	return list == NULL;
}

void insertDbList(int x, Position p, dbList *list) {
	if (*list == NULL) {
		(*list) = (dbList)malloc(sizeof(Node));
		(*list)->data = x;
		(*list)->previous = NULL;
		(*list)->next = NULL;
	}
	else {
		Position newNode = (Position)malloc(sizeof(Node));
		newNode->data = x;
		newNode->next = p;
		newNode->previous = p->previous;
		
		if (p->previous != NULL) {
			p->previous->next = newNode;
		}
		p->previous = newNode;
	}
}

void deleteDbList(Position p, dbList *list) {
	if (*list == NULL) return;
	if (p == *list) {
		if (p->next != NULL) {
			p = p->next;
		}
		else {
			p = NULL;
		}
	}
	if (p->previous != NULL) p->previous->next = p->next;
	if (p->next != NULL) p->next->previous = p->previous;
}

int main() {
	dbList list;
	makeNullList(&list);
	return 0;
}




