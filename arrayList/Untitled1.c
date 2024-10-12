#include <stdio.h>

typedef int ElementType;
typedef int Position;

#define mx 100

typedef struct List {
	ElementType Element[mx];
	Position Last;
} List;

void makeNullList(List *list) {
	list->Last = 0;
}

int emptyList(List list) {
	return list.Last == 0;
}

int fullList(List list) {
	return list.Last == mx;
}

int firstList(List list) {
	return 1;
}

int endList(List list) {
	return list.Last + 1;
}

void appendList(int x, List *list) {
	if (list->Last == mx) return;
	list->Element[list->Last] = x;
	list->Last++;	
}

void prependList(int x, List *list) {
	if (list->Last == mx) return;
	for (int i = list->Last; i >= 0; i--) {
		list->Element[i] = list->Element[i - 1];
	}
	list->Element[0] = x;
	list->Last++;
}

void insertList(int x, int p, List *list) {
	if (list->Last == mx) return;
	for (int i = list->Last; i > p - 1; i--) {
		list->Element[i] = list->Element[i - 1];
	}
	list->Element[p - 1] = x;
	list->Last++;
}

void deleteList(int p, List *list) {
	for (int i = p-1; i < list->Last; i++) {
		list->Element[i] = list->Element[i + 1];
	}
	list->Last--;
}

void readList(List *list) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		appendList(x, list);
	}
}

void printList(List list) {
	for (int i = 0; i < list.Last; i++) {
		printf("%d ", list.Element[i]);
	} 
}

int locateList(int x, List list) {
	for (int i = 0; i < list.Last; i++) {
		if (x == list.Element[i]) return i + 1;
	}
	return list.Last + 1;
}

int retrieveList(int p, List list) {
	return list.Element[p - 1];
}

int nextList(int p, List list) {
	return p + 1;
}

void sortList(List *list) {
	for (int i = 0; i < list->Last; i++) {
		for (int j = i + 1; j < list->Last; j++) {
			if (list->Element[i] > list->Element[j]) {
				int tmp = list->Element[i];
				list->Element[i] = list->Element[j];
				list->Element[j] = tmp;
			}
		}
	}
}

void swapList(int p1, int p2, List *list) {
	int tmp = list->Element[p1 - 1];
	list->Element[p1 - 1] = list->Element[p2 - 1];
	list->Element[p2 - 1] = tmp;
}

int main() {
	List list;
	makeNullList(&list);
	
	readList(&list);
	swapList(2, 6, &list);
	printList(list);
	
	return 0;
}




