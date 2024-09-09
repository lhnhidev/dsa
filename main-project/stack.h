#include <stdio.h>
#include <stdlib.h>

#define mxStack 160524

typedef int ItemStackType;

typedef struct Stack {
	ItemStackType item[mxStack];
	int top;
} Stack;

// Khoi tao Stack rong
void makeNullStack(Stack *st) {
	st->top = mxStack;
}

// Kiem tra Stack rong
int emptyStack(Stack st) {
	return st.top == mxStack;
}

// Kiem tra Stack day
int fullStack(Stack st) {
	return st.top == 0;
}

// Them mot phan tu cho Stack
void pushStack(ItemStackType x, Stack *st) {
	if (fullStack(*st)) {
		printf("Ngan xep day!");
		return;
	}
	st->top--;
	st->item[st->top] = x;
}

// Lay phan tu dau cua Stack
ItemStackType topStack(Stack st) {
	if (emptyStack(st)) {
		printf("Ngan xep rong!");
		return -1;
	}
	return st.item[st.top];
}

// Xoa phan tu dau cua Stack
void popStack(Stack *st) {
	if (emptyStack(*st)) {
		printf("Ngan xep rong!");
		return;
	}
	st->top++;
}

// Doc Stack
void readStack(Stack *st) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ItemStackType x; scanf("%d", &x);
		pushStack(x, st);
	}
}

// In Stack
void printStack(Stack st) {
	if (emptyStack(st)) {
		printf("Ngan xep rong!");
		return;
	}
	int i = st.top;
	while (i != mxStack) {
		printf("%d ", st.item[i]);
		i++;
	}
}
