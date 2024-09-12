#include <stdio.h>
#include <stdlib.h>
#include "polyNomial.h"

int main() {
	List header1, header2;
	
	makeNullPoly(&header1);
	makeNullPoly(&header2);
	
	readPoly(&header1);
	readPoly(&header2);
	
	List myList = subPoly(header1, header2);
	
	printPoly(header1);
	printf("\n");
	printPoly(header2);
	printf("\n\n");
	printPoly(myList);
	
	return 0;
}




