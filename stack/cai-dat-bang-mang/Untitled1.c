#include <stdio.h>
#include <stdlib.h>

#define mx 100

typedef int itemType;

typedef struct Stack {
	itemType item[mx];
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

void pushStack(itemType x, Stack *st) {
	if (fullStack(*st)) return;
	st->top--;
	st->item[st->top] = x;	
}

void popStack(Stack *st) {
	if (emptyStack(*st)) return;
	st->top++;
}

itemType topStack(Stack st) {
//	if (emptyStack(st)) return;
	return st.item[st.top];
}

int main() {
	
	Stack st;
	makeNullStack(&st);
		
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		pushStack(x, &st);
	}
	
	printf("Top cua Stack hien tai = %d\n", topStack(st));
	
	for (int i = 0; i < n; i++) {
		printf("%d ", topStack(st));
		popStack(&st);
	}
	
	return 0;
}









