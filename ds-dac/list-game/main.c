#include <stdio.h>
#include <stdlib.h>

#define mx 100

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
		
	}
}

//previous list 
int previousList(int p, List list) {
	if (p > 1 && p <= list.last) {
		return p - 1;
	}
	else {
		
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
	int tmp = list->item[p1];
	list->item[p1] = list->item[p2];
	list->item[p2] = tmp;
}

//sort list
void sortList(List *list) {
	for (int i = 0; i < list->last; i++) {
		for (int j = i + 1; j < list->last; j++) {
			if (list->item[i] > list->item[j]) {
				swapList(i, j, list);
			}
		}
	}
}

int main() {
	int options; 
	Menu:
		printf("/-------------------------------------------------/\n");
		printf("/                Chose your options!              /\n");
		printf("\n");
		printf("/ - Click 1: Start                                /\n");
		printf("/ - Click 2: End                                  /\n");
	
	scanf("%d", &options);
	if (options == 2) return 0;
	if (options != 1) {
		system("cls");
		goto Menu;
	}
	else {
		List list;
		makeNull(&list);
		printf("\nWe created your list! Now it is NULL!\n");
		printf("Initial your list!\n");
		printf("Amount of list (Maximum is 100): ");
		readList(&list);
		
		printf("\nYour list is: ");
		printList(list); printf("\n\n");
		
		printf("/-------------------------------------------------/\n");
			printf("/                Chose your order!                /\n");
			printf("\n");
			printf("/ - Click 0: Exit!                                /\n");
			printf("/ - Click 1: Insert value                         /\n");
			printf("/ - Click 2: Delete value                         /\n");
			printf("/ - Click 3: Get value by position                /\n");
			printf("/ - Click 4: Get position by value                /\n");
			printf("/ - Click 5: Get first position                   /\n");
			printf("/ - Click 6: Get last position                    /\n");
			printf("/ - Click 7: Find next position                   /\n");
			printf("/ - Click 8: Find previous position               /\n");
		while (1) {
			int order;
			printf("\nYour order is: ");
			scanf("%d", &order);
			while (order < 0 || order > 8) {
				printf("Not found order! Please try again!\n");
				printf("\nYour order is: ");
				scanf("%d", &order);
			}
			printf("\n");
			int x, p;
			switch (order) {
				case 0: 
					return 0;
					break;
				case 1: 
					printf("Your position where you want to insert: ");
					scanf("%d", &p);
					printf("Your value which you want to insert: ");
					scanf("%d", &x);
					insertList(x, p, &list);
					printf("New list is: ");
					printList(list);
					printf("\n");
					break;
				case 2: 
					printf("Your position where you want to delete: ");
					scanf("%d", &p);
					deleteList(p, &list);
					printf("New list is: ");
					printList(list);
					printf("\n");
					break;
				case 3: 
					printf("Your position where you want to get value: ");
					scanf("%d", &p);
					printf("Your value is: %d", retrieveList(p, list));
					printf("\n");
					break;
				case 4: 
					printf("Your value which you want to get position: ");
					scanf("%d", &x);
					printf("Your position is: %d", locateList(x, list));
					printf("\n");
					break;
				case 5:
					printf("The first position in your list is: %d\n", firstList(list));
					break;
				case 6:
					printf("The last position in your list is: %d\n", endList(list));
					break;
				case 7:
					printf("Your position which you want to get next position: ");
					scanf("%d", &p);
					printf("The next position is: %d", nextList(p, list));
					printf("\n");
					break;
				case 8:
					printf("Your position which you want to get previous position: ");
					scanf("%d", &p);
					printf("The previous position is: %d", previousList(p, list));
					printf("\n");
					break;
			}
		}
		
	}
	return 0;
}
