#include <stdio.h>

typedef int ElementType;
typedef int Position;

#define mx 100

typedef struct Stack {
	ElementType element[mx];
	Position top;
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

void pushStack(int x, Stack *st) {
	if (st->top == 0) return;
	st->top--;
	st->element[st->top] = x;
}

void popStack(Stack *st) {
	if (st->top == mx) return;
	st->top++;
}

int topStack(Stack st) {
	if (st.top == mx) return -1;
	return st.element[st.top];
}

int main() {
	Stack st;
	makeNullStack(&st);
	return 0;
}



