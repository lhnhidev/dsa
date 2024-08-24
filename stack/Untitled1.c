#include <stdio.h>
#include <stdlib.h>

#define mx 100

typedef int itemType;

typedef struct Stack {
	itemType item[mx];
	int topStack;
} Stack;

void makeNullStack(Stack *stack) {
	stack->topStack = mx;
}

int emptyStack(Stack stack) {
	return stack.topStack == mx;
}

int fullStack(Stack stack) {
	return stack.topStack == 0;
}

void pushStack(itemType x, Stack *stack) {
	if (fullStack(*stack)) return;
	stack->topStack--;
	stack->item[stack->topStack] = x;
}

void popStack(Stack *stack) {
	if (emptyStack(*stack)) return;
	stack->topStack++;
}

itemType topStack(Stack stack) {
	if (emptyStack(stack)) {
		printf("Stack rong!\n");
		return 0;
	}
	return stack.item[stack.topStack];
}

int main() {
	
	Stack stack;
	makeNullStack(&stack);

	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		itemType x; scanf("%d", &x);
		pushStack(x, &stack);
	}
	
	while (!emptyStack(stack)) {
		itemType tmp = topStack(stack);
		printf("%d ", tmp);
		popStack(&stack);
	}
	
	return 0;
}



