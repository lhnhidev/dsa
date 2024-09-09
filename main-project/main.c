#include <stdio.h>
#include <stdlib.h>

#define mx 1000

typedef int ItemStackType;

typedef struct Stack {
	ItemStackType item[mx]; // MY NOTE WHICH NEED CHANGE!
	int top;
} Stack;

void makeNullStack(Stack *st) {
	st->top = mx;
}

int emptyStack(Stack st) {
	return st.top == mx;
}

int fullStack(Stack st) {
	return st.top == 0;
}

void pushStack(ItemStackType x, Stack *st) {
	if (fullStack(*st)) {
		printf("Ngan xep day!");
		return;
	}
	st->top--;
	st->item[st->top] = x;
}

ItemStackType topStack(Stack st) {
	if (emptyStack(st)) {
		printf("Ngan xep rong!");
		return -1;
	}
	return st.item[st.top];
}

void popStack(Stack *st) {
	if (emptyStack(*st)) {
		printf("Ngan xep rong!");
		return;
	}
	st->top++;
}

void readStack(Stack *st) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ItemStackType x; scanf("%d", &x);
		pushStack(x, st);
	}
}

void printStack(Stack st) {
	if (emptyStack(st)) {
		printf("Ngan xep rong!");
		return;
	}
	int i = st.top;
	while (i != mx) {
		printf("%d ", st.item[i]);
		i++;
	}
}

int main() {
	Stack st;
	makeNullStack(&st);
	readStack(&st);
	printStack(st);
	return 0;
}




