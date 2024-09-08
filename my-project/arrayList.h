#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#define mx 1000

typedef int itemType;
typedef int posType;

typedef struct List {
	itemType item[mx];
	posType last;
} List;

//make null
void makeNull(List *list) {
	list->last = 0;
}

//emptyList
int emptyList(List list) {
	return list.last == 0;
}

//first list
int firstList(List list) {
	return 1;
}

//end list
int endList(List list) {
	return list.last + 1;
}

//next list
int nextList(int p, List list) {
	if (p >= 1 && p <= list.last) {
		return p + 1;
	}
	else {
		return -1;
	}
}

//previous list 
int previousList(int p, List list) {
	if (p > 1 && p <= list.last) {
		return p - 1;
	}
	else {
		return -1;
	}
}

//insert list
void insertList(int x, int p, List *list) {
	if (list->last == mx) {
		printf("Your list was full!\n");
		return;
	} 
	if (p < 1 || p > list->last + 1) {
		printf("Not Found your position\n");
		return;
	}
	
	for (int i = list->last; i > p-1; i--) {
		list->item[i] = list->item[i-1];
	}
	list->item[p-1] = x;
	list->last++;
}

//delete list
void deleteList(int p, List *list) {
	if (p < 1 || p > list->last) {
		printf("Not found your position\n");
		return;
	}
	
	for (int i = p-1; i < list->last - 1; i++) {
		list->item[i] = list->item[i+1];
	}
	list->last--;
}

//retrieve list
int retrieveList(int p, List list) {
	return list.item[p-1];
}

//locate list
int locateList(int x, List list) {
	for (int i = 1; i <= list.last; i++) {
		if (list.item[i-1] == x) return i;
	}
	return endList(list);
}

//read list
void readList(List *list) {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		printf("Value of element %d is: ", i);
		int x; scanf("%d", &x);
		insertList(x, i, list);
	}
}

//print list
void printList(List list) {
	for (int i = 1; i <= list.last; i++) {
		int x = retrieveList(i, list);
		printf("%d ", x);
	}
}

//swap list
void swapList(int p1, int p2, List *list) {
	int tmp = list->item[p1-1];
	list->item[p1-1] = list->item[p2-1];
	list->item[p2-1] = tmp;
}

//sort list
void sortList(List *list) {
	for (int i = 0; i < list->last; i++) {
		for (int j = i + 1; j < list->last; j++) {
			if (list->item[i] > list->item[j]) {
				swapList(i + 1, j + 1, list);
			}
		}
	}
}

