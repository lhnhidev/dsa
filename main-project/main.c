#include <stdio.h>
#include <stdlib.h>
//#include "arrayList.h"
#include "cursorList.h"

int main() {
	CurList header;
	makeNullCurList(&header);

	readCurList(&header);
	
	sortCurList(&header);
	
	printCurList(header);
	
	return 0;
}
