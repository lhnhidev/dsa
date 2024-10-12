#include <stdio.h>

#define mx 100

typedef int ElementType;

typedef struct Node {
	ElementType Element;
	struct Node* Next;
} Node;

typedef Node* Position;
typedef Position List;

//List readSet() {
//	int n; scanf("%d", &n);
//	List list;
//	makenullList(&list); 
//	for (int i = 0; i < n; i++) {
//		int x; scanf("%d", &x);
//		if (!member(x, list)) {
//			addFirst(x, &list);
//		}
//	}
//	return list;
//}

//float getAvg(List list) {
//	float res = 0;
//	int cnt = 0;
//	Position currentNode = list;
//	while (currentNode->Next != NULL) {
//		res += currentNode->Next->Element; 
//		cnt++;
//		currentNode = currentNode->Next;
//	}
//	if (res == 0) return -10000.0f;
//	return res / cnt;
//}

//void copyEvenNumbers(List l1, List *l2) {
//	makenullList(l2);
//	Position currentNode = l1;
//	while (currentNode->Next != NULL) {
//		if (currentNode->Next->Element % 2 == 0) {
//			append(currentNode->Next->Element, l2);
//		}
//		currentNode = currentNode->Next;
//	}
//}

//void sort(List *list) {
//	Position iNode = *list;
//	while (iNode->Next != NULL) {
//		Position jNode = iNode->Next;
//		while (jNode->Next != NULL) {
//			if (iNode->Next->Element > jNode->Next->Element) {
//				int tmp = iNode->Next->Element;
//				iNode->Next->Element = jNode->Next->Element;
//				jNode->Next->Element = tmp;
//			}
//			jNode = jNode->Next;
//		}
//		iNode = iNode->Next;
//	}
//}

//Position makeNewNode(int x) {
//	Position newNode = (Position)malloc(sizeof(struct Node));
//	newNode->Next = NULL;
//	newNode->Element = x;
//	return newNode;
//}
//
//void append(int x, List *list) {
//	Position newNode = makeNewNode(x);
//	Position currentNode = *list;
//	while (currentNode->Next != NULL) {
//		currentNode = currentNode->Next;
//	}
//	currentNode->Next = newNode;
//}
//
//void readList(List *list) {
//	makenullList(list);
//	int n; scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		int x; scanf("%d", &x);
//		append(x, list);
//	}
//}

//void printOddNumbers(List list) {
//	Position p = list;
//	while (p->Next != NULL) {
//		if (p->Next->Element % 2 != 0) {
//			printf("%d ", p->Next->Element);
//		}
//		p = p->Next;
//	}
//}
#include <malloc.h>

void makenullList(List *list) {
	*list = (List)malloc(sizeof(struct Node));
	(*list)->Next = NULL;
}

int main() {
    return 0;
}
