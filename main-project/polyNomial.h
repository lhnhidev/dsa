#include <stdio.h>
#include <stdlib.h>


/* - - - - - - - - - - - - - - NOTE - - - - - - - - - - - - - - 
*	
*	1. Poly: viet tat cua Polynomial co nghia la Da thuc
*	
*	2. Mono: viet tat cua Monomial co nghia la Don thuc
*
*	3. Coe: viet tat cua Coefficient co nghia la He so
*
*	4. Exp: viet tat cua Exponent co nghia la So mu
*
*	5. Co the hieu Node la mot Don thuc va nguoc lai
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
		if (x.Heso != 0) appendPoly(x, header);
	}
}

// In ra mot da thuc
void printPoly(List header) {
	Position currentNode = header;
	
	// Neu Da thuc rong thi khong lam gi ca
	if (currentNode->Next == NULL) return;
	
	// Kiem tra neu phan tu dau duong thi khong can in ra dau +
	if (currentNode->GetCoe > 0) {
		if (currentNode->GetCoe == 1) {
			printf("x^%d ", currentNode->GetExp);
		}
		else {
			printf("%dx^%d ", currentNode->GetCoe, currentNode->GetExp);
		}
		currentNode = currentNode->Next;
	}
	while (currentNode->Next != NULL) {
		if (currentNode->GetCoe < 0) {
			printf("- %dx^%d ", -currentNode->GetCoe, currentNode->GetExp);
		}
		else if (currentNode->GetCoe == 1) {
			printf("+ x^%d ", currentNode->GetExp);
		}
		else if (currentNode->GetCoe != 0) {
			printf("+ %dx^%d ", currentNode->GetCoe, currentNode->GetExp);
		}
		currentNode = currentNode->Next;
	}
}

// Lay Don thu o vi tri order
Position locatePolyByOrder(int order, List header) {
	if (order < 1) return NULL;
	Position currentNode = header;
	int i = 1;
	while (i < order) {
		currentNode = currentNode->Next;
		if (currentNode == NULL) {
			return NULL;
		}
		i++;
	}
	return currentNode;
}

// Doi cho 2 Don thuc trong Da thuc
void swapPoly(Position nodeI, Position nodeJ) {
	int tmp = nodeI->GetCoe;
	nodeI->GetCoe = nodeJ->GetCoe;
	nodeJ->GetCoe = tmp;
	tmp = nodeI->GetExp;
	nodeI->GetExp = nodeJ->GetExp;
	nodeJ->GetExp = tmp;
}

// Sap xep theo he so
void sortPolyByCoe(int option, List *header) {
	// option == 1 -> Sap xep tang dan
	// option == -1 -> Sap xep giam dan
	if (option != 1 && option != -1) return;
	Position nodeI = *header;
	while (nodeI->Next != NULL) {
		Position nodeJ = nodeI->Next;
		while (nodeJ->Next != NULL) {
			if (option * (nodeI->GetCoe - nodeJ->GetCoe) > 0) {
				swapPoly(nodeI, nodeJ);
			}
			nodeJ = nodeJ->Next;
		}
		nodeI = nodeI->Next;
	}
}

// Sap xep theo so mu
void sortPolyByExp(int option, List *header) {
	// option == 1 -> Sap xep tang dan
	// option == -1 -> Sap xep giam dan
	if (option != 1 && option != -1) return;
	Position nodeI = *header;
	while (nodeI->Next != NULL) {
		Position nodeJ = nodeI->Next;
		while (nodeJ->Next != NULL) {
			if (option * (nodeI->GetExp - nodeJ->GetExp) > 0) {
				swapPoly(nodeI, nodeJ);
			}
			nodeJ = nodeJ->Next;
		}
		nodeI = nodeI->Next;
	}
}

// Tron 2 Da thuc lai voi nhau
List mergePoly(List header1, List header2) {
	List resList;
	makeNullPoly(&resList);
	Position nodeI = header1;
	Position nodeJ = header2;
	while (nodeI->Next != NULL) {
		appendPoly(nodeI->Next->Element, &resList);
		nodeI = nodeI->Next;
	}
	while (nodeJ->Next != NULL) {
		appendPoly(nodeJ->Next->Element, &resList);
		nodeJ = nodeJ->Next;
	}
	return resList;
}

// Rut gon Da thuc
void normalizePoly(List *header) {
	Position nodeI = *header;
	while (nodeI->Next != NULL) {
		Position nodeJ = nodeI->Next;
		while (nodeJ->Next != NULL) {
			if (nodeJ->GetExp == nodeI->GetExp) {
				nodeI->GetCoe += nodeJ->GetCoe;
				nodeJ->Next = nodeJ->Next->Next; // Xoa di nodeJ sau khi da cong don vao nodeI
			}
			else {
				nodeJ = nodeJ->Next;
			}
		}
		
		nodeI= nodeI->Next;
	}
}

// Cong 2 Da Thuc voi nhau
List addPoly(List header1, List header2) {
	List resList = mergePoly(header1, header2);
	normalizePoly(&resList);
	return resList;
}

// Tru Da thuc trai cho Da thuc phai
List subPoly(List header1, List header2) {
	List oppositeList;
	makeNullPoly(&oppositeList);
	
	Position currentNode = header2;
	while (currentNode->Next != NULL) {
		ElementType x = {currentNode->GetCoe * -1, currentNode->GetExp};
		appendPoly(x, &oppositeList);
		currentNode = currentNode->Next;
	}
	
	return addPoly(header1, oppositeList);
}

// Nhan 2 Da Thuc voi nhau
List mulPoly(List header1, List header2) {
	List resList;
	makeNullPoly(&resList);
	
	Position nodeI = header1;
	while (nodeI->Next != NULL) {
		Position nodeJ = header2;
		while (nodeJ->Next != NULL) {
			int c = nodeJ->GetCoe * nodeI->GetCoe,
				e = nodeJ->GetExp + nodeI->GetExp;
			ElementType x = {c, e};
			appendPoly(x, &resList);
			nodeJ = nodeJ->Next;
		}
		nodeI = nodeI->Next;
	}
	
	normalizePoly(&resList);
	return resList;
}

// Copy Da thuc y cho Da thuc x
List copyPoly(List header) {
	List resList;
	makeNullPoly(&resList);
	
	Position currentNode = header;
	while (currentNode->Next != NULL) {
		appendPoly(currentNode->Next->Element, &resList);
		currentNode = currentNode->Next;
	}
	
	return resList;
}

// Lay luy thua p cua mot da thuc
void powPoly(List *header, int p) {
	if (p < 0) {
		printf("Khong nhan so mu am");
		return;	
	}
	else if (p == 0) {
		(*header)->GetCoe = 1;
		(*header)->GetExp = 0;
		(*header)->Next = NULL;
		return;
	}
	
	List beMultyPoly = copyPoly(*header); // Tao ra Da thuc bi nhan
	for (int i = 1; i < p; i++) {
		*header = mulPoly(*header, beMultyPoly);
	}
}

// Copy Da thuc dua vao he so
List copyPolyByCoe(int order, List header) {
	// order == 1 -> copy chan
	// order == -1 -> copy le
	
	List resList;
	makeNullPoly(&resList);
	
	if (order != 1 && order != -1) return resList;
	
	Position currentNode = header;
	while (currentNode->Next != NULL) {
		if (order == 1) {
			if (currentNode->GetCoe % 2 == 0) {
				appendPoly(currentNode->Next->Element, &resList);
			}
		}
		else if (order == -1) {
			if (currentNode->GetCoe % 2 != 0) {
				appendPoly(currentNode->Next->Element, &resList);
			}
		}
		currentNode = currentNode->Next;
	}
	return resList;
}

// Copy Da thuc dua vao so mu
List copyPolyByExp(int order, List header) {
	// order == 1 -> copy chan
	// order == -1 -> copy le
	
	List resList;
	makeNullPoly(&resList);
	
	if (order != 1 && order != -1) return resList;
	
	Position currentNode = header;
	while (currentNode->Next != NULL) {
		if (order == 1) {
			if (currentNode->GetExp % 2 == 0) {
				appendPoly(currentNode->Next->Element, &resList);
			}
		}
		else if (order == -1) {
			if (currentNode->GetExp % 2 != 0) {
				appendPoly(currentNode->Next->Element, &resList);
			}
		}
		currentNode = currentNode->Next;
	}
	return resList;
}

// Tim nhan tu chung
ElementType gcdPoly(List header) {
	#include <math.h> // Nap chong thu vien
	int gcd(int a, int b) { // Nap chong ham
	    while (b != 0) {
	        int tmp = b;
	        b = a % b;
	        a = tmp;
	    }
    	return a;
	}
	
	Position currentNode = header;
	int c = header->GetCoe;
	int e = header->GetExp;
	while (currentNode->Next != NULL) {
		c = gcd(currentNode->GetCoe, c);
		e = (int)fmin(e, currentNode->GetExp);
		if (c == 1) break;
		currentNode = currentNode->Next;
	}
	ElementType x = {c, e};
	return x;
}

