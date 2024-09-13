#include <stdio.h>
#include <stdlib.h>
#include "polyNomial.h"

#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define WHITE "\033[0m"

void renderMenu() {
	printf(WHITE "\n");
	printf(BLUE "\n\t- - - - - - - - - - - - - - - MENU CAC LENH - - - - - - - - - - - - - - -\n\n" WHITE);
	printf("\t999. Thoat chuong trinh!\n");
	printf("\t0. In ra mot da thuc\n");
	printf("\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\t1. Chen mot Don thuc vao vi tri P trong Da thuc\n");
	printf("\t2. Chen mot Don thuc vao dau Da thuc\n");
	printf("\t3. Chen mot Don thuc vao cuoi Da thuc\n");
	printf("\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\t4. Tim vi tri dau tien cua Don Thuc co He so la c\n");
	printf("\t5. Tim vi tri dau tien cua Don thuc co So mu la e\n");
	printf("\t6. Xoa Don thuc co he so c xuat hien dau tien trong Da thuc\n");
	printf("\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\t7. Xoa Don thuc co so mu e xuat hien dau tien trong Da thuc\n");
	printf("\t8. In ra Don thu o vi tri P\n");
	printf("\t9. Doi cho 2 Don thuc trong Da thuc\n");
	printf("\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\t10. Sap xep Da thuc\n");
	printf("\t11. Tron Da thuc\n");
	printf("\t12. Rut gon Da thuc\n");
	printf("\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\t13. Cong da thuc\n");
	printf("\t14. Tru da thuc\n");
	printf("\t15. Nhan da thuc\n");
	printf("\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\t16. Copy Da thuc\n");
	printf("\t17. Luy thua mu P cho Da thuc\n");
	printf("\t18. Copy Da thuc dua vao He so\n");
	printf("\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\t19. Copy Da thuc dua vao So mu\n");
	printf("\t20. In ra nhan tu chung cua Da thuc\n");
}

int main() {
	printf("- - - - - - - - - - - - Polynomial Game - - - - - - - - - - - - \n\n");
	
	printf("Nhap vao Da thuc cua ban!\n");
	
	/*
		Vi du
			Input: 
				3
				2 3
				4 1
				-2 8
			Output:
				2x^3 + 4x - 2x^8
	*/	
	
	List header; makeNullPoly(&header);
	readPoly(&header);
	
	renderMenu();
	
	printf(GREEN "\nDa thuc cua ban:\t" WHITE);
	printPoly(header);
	return 0;
}




