#include <stdio.h>

#define mx 100

typedef int ElementType;

typedef struct Stack {
	ElementType Element[mx];
	int Top;
} Stack;

void makeNullStack(Stack *st) {
	st->Top = mx;
}

int fullStack(Stack st) {
	return st.Top == 0;
}

int emptyStack(Stack st) {
	return st.Top == mx;
}

void pushStack(ElementType x, Stack *st) {
	if (fullStack(*st)) return;
	st->Top--;
	st->Element[st->Top] = x;
}

void readStack(Stack *st) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		pushStack(x, st);
	}
}

ElementType topStack(Stack st) {
	return st.Element[st.Top];
}

void popStack(Stack *st) {
	if (emptyStack(*st)) return;
	st->Top++;
}

void printStack(Stack st) {
	for (int i = st.Top; i < mx; i++) {
		printf("%d ", st.Element[i]);
	}
}

int main() {
	Stack st;
	makeNullStack(&st);
	
	readStack(&st);
	printStack(st);
	
	return 0;
}
