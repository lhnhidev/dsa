#include <stdio.h>
#include <stdlib.h>
//#include "arrayList.h"
#include "cursorList.h"

int main() {
	List L;
	Position p;
			
	L=(struct Node*)malloc(sizeof(struct Node));	
	L->Next=NULL;
		
	append(1, &L);
	append(1, &L);
	append(1, &L);
	
		
	normalize(&L);
	p=L;
	while(p->Next!=NULL)
	{
			printf("%d ",p->Next->Element);
			p=p->Next;
	}
	return 0;
}
