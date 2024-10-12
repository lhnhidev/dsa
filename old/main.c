#include <stdio.h>

typedef int itemType;
typedef int position;

typedef struct List {
	itemType item[100];
	position last;
} List;

void makeNullList(List *list) {
	list->last = 0;
}

void appendList(int x, List *list) {
	list->item[list->last] = x;
	list->last++;
}

void readList(List *list) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		appendList(x, list);
	}
}

void printList(List list) {
	for (int i = 0; i < list.last; i++) {
		printf("%d ", list.item[i]);
	}
}

void deleteList(int p, List *list) {
	for (int i = p-1; i < list->last; i++) {
		list->item[i] = list->item[i + 1];
	}
	list->last--;
}

int locateList(int x, List list) {
	for (int i = 0; i < list.last; i++) {
		if (x == list.item[i]) return i + 1;
	}
	return list.last;
}

int endList(List L){
    return L.last;
}
void removeAll(int x, List *pL) {
    int p = locateList(x, *pL);
    while (p != endList(*pL)) {
        deleteList(p, pL);
        p = locateList(x, *pL);
    }
}

int main() {
	List L;
	int i;
	L.last=0;
	for(i=0;i<5;i++)
	  {  L.item[i] = 2*i;}
	L.last=5;
	removeAll(0,&L);
	for(i=0;i<L.last;i++)
	{    printf("%d ",L.item[i]);}
	return 0;
}
