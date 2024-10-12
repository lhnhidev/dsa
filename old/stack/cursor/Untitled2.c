#include <stdio.h>
#include <stdlib.h>

typedef int itemType;

typedef struct Stack {
	itemType data;
	struct Stack *next;
} Stack;

typedef Stack* posType;

void makeNullStack(Stack **st) {
	(*st) = (Stack *)malloc(sizeof(Stack));
	(*st)->next = NULL;
}

int emptyStack(Stack *st) {
	return st->next == NULL;
}

Stack *makeNodeStack(itemType x) {
	Stack *newNode = (Stack *)malloc(sizeof(Stack));
	newNode->next = NULL;
	newNode->data = x;
	return newNode;
}

void pushStack(itemType x, Stack **st) {
	Stack *top = makeNodeStack(x);
	top->next = (*st)->next;
	(*st)->next = top;
}

void popStack(Stack **st) {
	(*st)->next = (*st)->next->next;
}

itemType topStack(Stack *st) {
	return st->next->data;
}

int main() {
	
	Stack *st;
	makeNullStack(&st);
	
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		pushStack(x, &st);
	}
	
	while (!emptyStack(st)) {
		printf("%d ", topStack(st));
		popStack(&st);
	}
	
	return 0;	
}













