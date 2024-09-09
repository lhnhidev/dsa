#include <stdio.h>

#define mx 100

typedef int itemType;
typedef int posType;

typedef struct List {
	itemType item[mx];
	posType last;
} List;

// Khoi tao ds rong
void makeNullList(List *list) {
	list->last = 0;
}

// Kiem tra ds rong
int emptyList(List list) {
	return list.last == 0;
}

// Kiem tra ds day
int fullList(List list) {
	return list.last == mx;
}

// Lay vi tri dau tien
int firstList(List list) {
	if (emptyList(list)) {
		return -1;
	}
	return 1;
}

// Lay vi tri cuoi cung
int endList(List list) {
	if (emptyList(list)) {
		return -1;
	}
	return list.last;
}

// Lay vi tri tiep theo
int nextList(posType p, List list) {
	if (p < 1 || p >= list.last) {
		return -1;
	}
	return p + 1;
}

// Lay vi tri truoc do
int previousList(posType p, List list) {
	if (p <= 1 || p > list.last) {
		return -1;
	}
	return p - 1;
}

// Chen gia tri vao ds
void insertList(itemType x, posType p, List *list) {
	if (fullList(*list)) {
		printf("Danh sach day!");
		return;
	}
	if (p < 1 || p > list->last + 1) {
		printf("Vi tri khong hop le!");
		return;
	}
	for (int i = list->last; i > p - 1; i--) {
		list->item[i] = list->item[i-1];
	}
	list->item[p-1] = x;
	list->last++;
}

// Chen vao cuoi
void appendList(itemType x, List *list) {
	// C1: 
//	insertList(x, list->last + 1, list);
	
	// C2:
	if (fullList(*list)) {
		printf("Danh sach day!");
		return;
	}
	list->item[list->last] = x;
	list->last++;
}

// chen vao dau
void prependList(itemType x, List *list) {
	// C1:
//	insertList(x, 1, list);
	
	// C2:
	if (fullList(*list)) {
		printf("Danh sach day!");
		return;
	}
	for (int i = list->last; i > 0; i--) {
		list->item[i] = list->item[i-1];
	}
	list->item[0] = x;
	list->last++;
}

// Xoa phan tu tai vi tri p trong ds
void delListByPos(posType p, List *list) {
	if (p < 1 || p > list->last) {
		printf("Vi tri khong hop le!");
		return;
	}
	for (int i = p-1; i < list->last; i++) {
		list->item[i] = list->item[i+1];
	}
	list->last--;
}

// Xoa phan tu gia tri x trong ds
void delListByValue(itemType x, List *list) {
	for (int i = 0; i < list->last; i++) {
		if (x == list->item[i]) {
			for (int j = i; j < list->last; j++) {
				list->item[j] = list->item[j+1];
			}
			list->last--;
			return;
		}
	}
	printf("Khong co gia tri %d trong danh sach!", x);
}

// Lay gia tri tai vi tri p
itemType retrieveList(posType p, List list) {
	if (p < 1 || p > list.last) {
		return -1;
	}
	return list.item[p - 1];
}

// Tim vi tri dau tien bang x
posType locateList(itemType x, List list) {
	for (int i = 0; i < list.last; i++) {
		if (x == list.item[i]) {
			return i + 1;
		}
	}
	return -1;
}

// Doc ds
void readList(List *list) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		appendList(x, list);
	}
}

// In ds
void printList(List list) {
	if (emptyList(list)) {
		printf("Danh sach rong!");
		return;
	}
	for (int i = 1; i <= list.last; i++) {
		printf("%d ", list.item[i-1]);
	}
}

// Swap 2 vi tri trong ds
void swapList(posType x, posType y, List *list) {
	int tmp = list->item[x - 1];
	list->item[x - 1] = list->item[y - 1];
	list->item[y - 1] = tmp;
}

// Sort ds
void sortList(List *list) {
	for (int i = 0; i < list->last; i++) {
		for (int j = i + 1; j < list->last; j++) {
			if (list->item[i] > list->item[j]) {
				swapList(i + 1, j + 1, list);
			}
		}
	}
}

int main() {
	List list;
	makeNullList(&list);
	
	readList(&list);
	printList(list);
	
	sortList(&list);
	printf("\n");
	printList(list);
	return 0;
}







