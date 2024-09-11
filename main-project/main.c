#include <stdio.h>
#include <stdlib.h>

/* - - - - - - - - - - - - - - NOTE - - - - - - - - - - - - - - 
*	
*	1. Poly: viet tat cua Polynomial co nghia la da thuc
*	
*	2. Mono: don thuc cua Monomial co nghia la don thuc
*
*	3. Coe: viet tat cua Coefficient co nghia la he so
*
*	4. Exp: viet tat cua Exponent co nghia la so mu
*
*  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/ 

typedef struct ElementType {
	int Heso;
	int Somu;
} ElementType;

typedef struct Node {
	ElementType Element;
	struct Node* Next;
} Node;

typedef Node* Position;
typedef Position List;
#define GetCoe Next->Element.Heso	// Dinh nghia GetCoe -> lay ra he so cua Node hien tai
#define GetExp Next->Element.Somu	// Dinh nghia GetExp -> lay ra so mu cua Node hien tai

// Tao mot da thuc rong
void makeNullPoly(List *header) {
	(*header) = (Node *)malloc(sizeof(Node));
	(*header)->Next = NULL;
}

// Tao mot Node moi
Node *makeNode(ElementType x) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->Element = x;
	newNode->Next = NULL;
}

// Chen Don thuc vao vi tri p cua Da thuc
void insertPoly(ElementType x, Position p, List *header) {
	Node *newNode = makeNode(x);
	newNode->Next = p->Next;
	p->Next = newNode;
}

// Them mot Don thuc vao dau Da thuc
void prependPoly(ElementType x, List *header) {
	Node *newNode = makeNode(x);
	newNode->Next = (*header)->Next;
	(*header)->Next = newNode;
}

// Them mot Don thuc vao cuoi Da thuc
void appendPoly(ElementType x, List *header) {
	Position currentNode = *header;
	while (currentNode->Next != NULL) {
		currentNode = currentNode->Next;
	}
	Node *newNode = makeNode(x);
	currentNode->Next = newNode;
}

// Tim vi tri dau tien cua Don Thuc co He so la c
Position locatePolyByCoe(int c, List header) {
	Position currentNode = header;
	while (currentNode->Next != NULL) {
		if (currentNode->GetCoe == c) {
			return currentNode;
		}
		currentNode = currentNode->Next;
	}
	return NULL;
}

// Tim vi tri dau tien cua Don thuc co So mu la e
Position locatePolyByExp(int e, List header) {
	Position currentNode = header;
	while (currentNode->Next != NULL) {
		if (currentNode->GetExp == e) {
			return currentNode;
		}
		currentNode = currentNode->Next;
	}
	return NULL;
}

// Xoa Don thuc co he so c xuat hien dau tien trong Da thuc
void deletePolyByCoe(int c, List *header) {
	Node *deleteNode = locatePolyByCoe(c, *header);
	if (deleteNode) {	// Neu Node can xoa co ton tai trong Da Thuc thi moi xoa!
		Node *freeNode = deleteNode->Next;
		deleteNode->Next = deleteNode->Next->Next;
		free(freeNode);	
	}
}

// Xoa Don thuc co so mu e xuat hien dau tien trong Da thuc
void deletePolyByExp(int e, List *header) {
	Node *deleteNode = locatePolyByExp(e, *header);
	if (deleteNode) {	// Neu Node can xoa co ton tai trong Da Thuc thi moi xoa!
		Node *freeNode = deleteNode->Next;
		deleteNode->Next = deleteNode->Next->Next;
		free(freeNode);	
	}
}

// Nhap vao mot da thuc
void readPoly(List *header) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ElementType x; 
		scanf("%d %d", &x.Heso, &x.Somu);
		appendPoly(x, header);
	}
}

// In ra mot da thuc
void printPoly(List header) {
	Position currentNode = header;
	while (currentNode->Next != NULL) {
		if (currentNode->GetCoe < 0) {
			printf("- %d^%d ", -currentNode->GetCoe, currentNode->GetExp);
		}
		else {
			printf("+ %d^%d ", currentNode->GetCoe, currentNode->GetExp);
		}
		currentNode = currentNode->Next;
	}
}

int main() {
	List header;
	makeNullPoly(&header);
	
	readPoly(&header);
	
	deletePolyByExp(-9, &header);
	
	printPoly(header);
	
	return 0;
}




