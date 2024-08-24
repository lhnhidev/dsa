#include <stdio.h>
#include <stdlib.h>

typedef int itemType;

typedef struct Node {
	itemType data;
	struct Node *next;
} Node;

typedef Node* posType;

//Make Node
Node* makeNode(itemType x) {
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}

//Make Null List
void makeNullList(Node **header) {
	*header = (Node *)malloc(sizeof(Node));
	(*header)->next = NULL;
}

//Push Front List
void pushFront(itemType x, Node **header) {
	Node *newNode = makeNode(x);
	newNode->next = (*header)->next;
	(*header)->next = newNode;
}

//Pust Back List
void pushBack(itemType x, Node **header) {
	Node *newNode = makeNode(x);
	Node *tmp = *header;
	if (*header == NULL) { //bo dong nay cung duoc, nhung se rac roi!
		*header = newNode;
		return;
	}
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = newNode;
}

int main() {
	Node *header;
	makeNullList(&header);
	while (1) {
		int order; scanf("%d", &order);
		if (order == 1) {
			int x; scanf("%d", &x);
			pushFront(x, &header);
		}
		else if (order == 2) {
			int x; scanf("%d", &x);
			pushBack(x, &header);
		}
		else {
			//Print List
			Node *tmp = header->next; //neu xoa dong 34 se sua chu yeu o day!
//			tmp = tmp->next;    //day nua
			while (tmp != NULL) {
				printf("%d ", tmp->data);
				tmp = tmp->next;
			}
		}
	}
	return 0;
}
