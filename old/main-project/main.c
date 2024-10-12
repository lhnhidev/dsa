#include <stdio.h>

#define mx 100

typedef struct List {
	int item[mx];
	int last;
} List;

void makeNullList(List *list) {
	list->last = 0;
}

// day 1 phan tu vao cuoi danh sach
void appendList(int x, List *list) {
	if (list->last > mx) return; // tai vi day
	list->last++;
	list->item[list->last - 1] = x;
}

// doc vao danh sach
void readList(List *list) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		appendList(x, list);
	}
}

// in danh sach
void printList(List list) {
	for (int i = 0; i < list.last; i++) {
		printf("%d ", list.item[i]);
	}
}

// locate
int locate(int x, List list) {
	for (int i = 0; i < list.last; i++) {
		if (x == list.item[i]) {
			return i + 1;
		}
	}
	return -1;
}

// member
int member(int x, List list) {
	if (locate(x, list) != -1) return 1;
	return 0;
}

//delete
void deleteList(int p, List *list) {
	for (int i = p-1; i < list->last; i++) {
		list->item[i] = list->item[i+1];
	}
	list->last--;
}
	
int main() {
	
	List list;
	makeNullList(&list);
	
	readList(&list);
	
	deleteList(2, &list);
	printList(list);
	
	return 0;
}







