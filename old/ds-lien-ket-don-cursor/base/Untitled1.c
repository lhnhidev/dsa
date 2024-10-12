#include <stdio.h>
#include <malloc.h>

typedef int itemType;
typedef int posType;

typedef struct Node {
	itemType data;
	struct Node *next;
} Node;

// Tao danh sach rong 
void makeNullList(Node **header) {
	*header = (Node *)malloc(sizeof(Node));
	(*header)->next = NULL;
}

// Tao node moi voi gia tri la x
Node *makeNode(itemType x) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = x;
	return newNode;
}

// In ra node bat ky
void printNode(Node *node) {
	printf("%d %d\n", node->data, node->next);
}

// lay ra node dau tien
Node *firstNode(Node *header) {
	return header->next;
}

// lay ra node cuoi cung
Node *lastNode(Node *header) {
	Node *currentNode = header;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
	}
	return currentNode;
}

// chen vao cuoi list 1 gia tri
void appendList(itemType x, Node **header) {
	Node *tmp = *header;
	Node *newNode = makeNode(x);
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = newNode;
}

// chen vao dau list 1 gia tri
void prependList(itemType x, Node **header) {
	Node *newNode = makeNode(x);
	newNode->next = (*header)->next;
	(*header)->next = newNode;
}

// chen gia tri vao bat ky vi tri nao cua danh sach
void insertList(itemType x, posType p, Node **header) {
	Node *newNode = makeNode(x);
	
	Node *currentNode = *header;
	for (posType i = 0; i < p-1; i++) {
		currentNode = currentNode->next;
	}
	if (currentNode == NULL) {
		printf("Vi tri khong ton tai!\n");
		return;
	}
	
	newNode->next = currentNode->next;
	currentNode->next = newNode;
}

// xoa di mot node bang vi tri
void deleteListPosition(posType p, Node **header) {
	Node *current = *header;
	for (int i = 0; i < p-1; i++) {
		current = current->next;
	}
	Node *needDeleteNode = current->next->next;
	current->next = needDeleteNode;
}

// lay ra mot node dua vao gia tri x
Node *locateList(itemType x, Node *header) {
	Node *current = header->next;
	while (current != NULL) {
		if (current->data == x) return current;
		current = current->next;
	}
	return makeNode(0);
}

// lay ra gia tri x dua vao vi tri
itemType retrieveList(posType p, Node *header) {
	Node *current = header->next;
	for (int i = 1; i <= p; i++) {
		current = current->next;
	}
	if (current != NULL) {
		return current->data;
	}
	return 0;
}

int main() {
	Node *header;
	makeNullList(&header);
	
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		appendList(x, &header);
	}
	

	Node *index = header->next;
	while (index != NULL) {
		printf("%d ", index->data);
		index = index->next;
	}
	printf("\n");
	
	Node *myNode = locateList(6, header);
	printNode(myNode);
	
	return 0;
}




