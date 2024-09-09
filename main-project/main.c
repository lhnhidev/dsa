#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
	Stack st;
	makeNullStack(&st);
	readStack(&st);
	printStack(st);
	return 0;
}




