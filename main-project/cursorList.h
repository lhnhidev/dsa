#include <stdio.h>
#include <stdlib.h>
//#include "arrayList.h"

typedef int ItemCurType;

typedef struct Node {
	ItemCurType data;
	struct Node *next;
} Node;

typedef Node* PosCurType;
typedef PosCurType CurList;

// Tao mot Node moi
Node *makeNode(ItemCurType x) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

// Tao ds rong
void makeNullCurList(CurList *header) {
	(*header) = (CurList)malloc(sizeof(Node));
	(*header)->next = NULL;
}

// Kiem tra ds rong
int emptyCurList(CurList header) {
	return header->next == NULL;
}

// Xu ly khi danh sach rong
void solveEmptyCurList(CurList header) {
	if (emptyCurList(header)) {
		printf("Danh sach rong!");
		exit(0);
	}
}

// Lay vi tri dau tien
PosCurType firstCurList(CurList header) {
	solveEmptyCurList(header);
	
	return header->next;
}

// Lay vi tri cuoi cung
PosCurType endCurList(CurList header) {
	solveEmptyCurList(header);
	
	PosCurType currentNode = header;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
	}
	return currentNode;
}

// Lay vi tri dung truoc vi tri p
PosCurType nextCurList(PosCurType p, CurList header) {
	solveEmptyCurList(header);
	PosCurType currentNode = header->next;
	
	while (currentNode != NULL) {
		if (currentNode == p) {
			if (emptyCurList(p)) {
				printf("Vi tri khong hop le!");
				return NULL;
			}
			return p->next;
		}
		currentNode = currentNode->next;
	}
	printf("Vi tri khong hop le!");
	return NULL;
}

// Lay vi tri dung sau vi tri p
PosCurType previousCurList(PosCurType p, CurList header) {
	solveEmptyCurList(header);
	
	PosCurType currentNode = header->next;
	while (currentNode->next != NULL) {
		if (currentNode->next == p) {
			return currentNode;
		}
		currentNode = currentNode->next;
	}
	/* printf("Vi tri khong hop le!"); */
	return NULL;
}

// Chen mot Node vao vi tri p
void insertCurList(ItemCurType x, PosCurType p, CurList *header) {
	Node *insertNode = makeNode(x);
	
	insertNode->next = p->next;
	p->next = insertNode;
}

// Chen vao cuoi danh sach
void appendCurList(ItemCurType x, CurList *header) {
	PosCurType currentNode = *header;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
	}
	
	// Cach 1:
	// insertCurList(x, currentNode, header);
	
	// Cach 2:
	Node *insertNode = makeNode(x);
	currentNode->next = insertNode;
}

// Chen vao dau danh sach
void prependCurList(ItemCurType x, CurList *header) {
	// Cach 1:
	// insertCurList(x, *header, header);
	
	// Cach 2:
	Node *insertNode = makeNode(x);
	insertNode->next = (*header)->next;
	(*header)->next = insertNode;
}

// Xoa Node co data la x
void delCurListByValue(ItemCurType x, CurList *header) {
	solveEmptyCurList(*header);
	
	PosCurType currentNode = *header;
	while (currentNode->next != NULL) {
		if (currentNode->next->data == x) {
			currentNode->next = currentNode->next->next;
			return;
		}
		currentNode = currentNode->next;
	}
}

// Xoa Node tai vi tri p
void delCurListByPos(PosCurType p, CurList *header) {
	solveEmptyCurList(*header);
	
	p->next = p->next->next; // xoa thang dung sau vi tri p
}

// Lay ra Node thu n
Node *retrieveCurList(int n, CurList header) {
	if (n < 1) {
		printf("Vi tri khong hop le!");
		return NULL;
	}
	
	Node *currentNode = header->next;
	int i = 1;
	while (currentNode != NULL && i < n) {
		currentNode = currentNode->next;
		i++;
	}
	
	if (currentNode == NULL) {
		printf("Vi tri khong hop le!");
	}
	return currentNode;
}

// Lay ra Node co data la x
Node *locateCurList(ItemCurType x, CurList header) {
	solveEmptyCurList(header);
	
	PosCurType currentNode = header->next;
	while (currentNode != NULL) {
		if (currentNode->data == x) {
			return currentNode;
		}
		currentNode = currentNode->next;
	}
	printf("Khong ton tai %d trong danh sach!", x);
	return NULL;
}

// Doc danh sach
void readCurList(CurList *header) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		appendCurList(x, header);
	}
}

// In danh sach
void printCurList(CurList header) {
	solveEmptyCurList(header);
	
	PosCurType currentNode = header->next;
	while (currentNode != NULL) {
		printf("%d ", currentNode->data);
		currentNode = currentNode->next;
	}
}

// Doi vi tri 2 Node trong danh sach
void swapCurList(PosCurType x, PosCurType y, CurList *header) {
	ItemCurType tmp = x->data;
	x->data = y->data;
	y->data = tmp;
}

// Sap xep danh sach
void sortCurList(CurList *header) {
	PosCurType i = (*header)->next;
	while (i != NULL) {
		PosCurType j = i->next;
		while (j != NULL) {
			if (i->data > j->data) {
				swapCurList(i, j, header);
			}
				j = j->next;
		}
		i = i->next;
	}
}
