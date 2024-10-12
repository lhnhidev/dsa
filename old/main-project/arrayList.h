#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

#define mx 16524

typedef int ItemArrType;
typedef int PosArrType;

typedef struct ArrList {
	ItemArrType item[mx];
	PosArrType last;
} ArrList;

/* - - - - - - - - - - - - - DOCUMENT - - - - - - - - - - - - - 
*
*	1. Khai bao: ArrList
*
*	2. Cach goi ham: functionName + ArrList
*
*	3. Ten kieu du lieu phan tu: ItemArrType
*
*	4. Ten kieu du lieu vi tri: PosArrType
*
*  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
*/

// Khoi tao ds rong
void makeNullArrList(ArrList *list) {
	list->last = 0;
}

// Kiem tra ds rong
int emptyArrList(ArrList list) {
	return list.last == 0;
}

// Kiem tra ds day
int fullArrList(ArrList list) {
	return list.last == mx;
}

// Lay vi tri dau tien
int firstArrList(ArrList list) {
	if (emptyArrList(list)) {
		return -1;
	}
	return 1;
}

// Lay vi tri cuoi cung
int endArrList(ArrList list) {
	if (emptyArrList(list)) {
		return -1;
	}
	return list.last;
}

// Lay vi tri tiep theo
int nextArrList(PosArrType p, ArrList list) {
	if (p < 1 || p >= list.last) {
		return -1;
	}
	return p + 1;
}

// Lay vi tri truoc do
int previousArrList(PosArrType p, ArrList list) {
	if (p <= 1 || p > list.last) {
		return -1;
	}
	return p - 1;
}

// Chen gia tri vao ds
void insertArrList(ItemArrType x, PosArrType p, ArrList *list) {
	if (fullArrList(*list)) {
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
void appendArrList(ItemArrType x, ArrList *list) {
	// C1: 
//	insertArrList(x, list->last + 1, list);
	
	// C2:
	if (fullArrList(*list)) {
		printf("Danh sach day!");
		return;
	}
	list->item[list->last] = x;
	list->last++;
}

// chen vao dau
void prependArrList(ItemArrType x, ArrList *list) {
	// C1:
//	insertArrList(x, 1, list);
	
	// C2:
	if (fullArrList(*list)) {
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
void delArrListByPos(PosArrType p, ArrList *list) {
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
void delArrListByValue(ItemArrType x, ArrList *list) {
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
ItemArrType retrieveArrList(PosArrType p, ArrList list) {
	if (p < 1 || p > list.last) {
		return -1;
	}
	return list.item[p - 1];
}

// Tim vi tri dau tien bang x
PosArrType locateArrList(ItemArrType x, ArrList list) {
	for (int i = 0; i < list.last; i++) {
		if (x == list.item[i]) {
			return i + 1;
		}
	}
	return -1;
}

// Doc ds
void readArrList(ArrList *list) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		appendArrList(x, list);
	}
}

// In ds
void printArrList(ArrList list) {
	if (emptyArrList(list)) {
		printf("Danh sach rong!");
		return;
	}
	for (int i = 1; i <= list.last; i++) {
		printf("%d ", list.item[i-1]);
	}
}

// Swap 2 vi tri trong ds
void swapArrList(PosArrType x, PosArrType y, ArrList *list) {
	int tmp = list->item[x - 1];
	list->item[x - 1] = list->item[y - 1];
	list->item[y - 1] = tmp;
}

// Sort ds
void sortArrList(ArrList *list) {
	for (int i = 0; i < list->last; i++) {
		for (int j = i + 1; j < list->last; j++) {
			if (list->item[i] > list->item[j]) {
				swapArrList(i + 1, j + 1, list);
			}
		}
	}
}
