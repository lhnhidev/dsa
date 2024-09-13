#include <stdio.h>
#include <stdlib.h>
#include "polyNomial.h"

#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define WHITE "\033[0m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

void renderMenu() {
	printf(WHITE "\n");
	printf(BLUE "\n\t- - - - - - - - - - - - - - - MENU CAC LENH - - - - - - - - - - - - - - -\n\n" WHITE);
	printf("\t999. Thoat chuong trinh!\n");
	printf("\t0. In ra da thuc\n");
	printf("\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\t1. Chen mot Don thuc vao vi tri P trong Da thuc\n");
	printf("\t2. Chen mot Don thuc vao dau Da thuc\n");
	printf("\t3. Chen mot Don thuc vao cuoi Da thuc\n");
	printf("\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\t4. Tim phan tu dau tien co He so la c\n");
	printf("\t5. Tim phan tu dau tien co So mu la e\n");
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
//	printf("\t16. Copy Da thuc\n");
	printf("\t16. Luy thua mu P cho Da thuc\n");
	printf("\t17. Tao Da thuc moi co he so chan hoac le\n");
	printf("\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\t18. Tao Da thuc moi co so mu chan hoac le\n");
	printf("\t19. In ra nhan tu chung cua Da thuc\n");
}

int main() {
	printf("- - - - - - - - - - - - Polynomial Game - - - - - - - - - - - - \n\n");
	
	printf(RED "Nhap vao Da thuc cua ban!\n" WHITE);
	
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
	
	int n = -1000;
	int c, e, pos, pos1, pos2;
	List header2;
	ElementType x;
	int cnt = 0;
	while (n != 999) {
		if (cnt == 0) {
			printf(RED "\n\nNhap lenh cua ban: " WHITE); scanf("%d", &n);
		}
		else {
			printf(RED "\n\nXong\n");
			printf("Nhap lenh tiep theo: " WHITE); scanf("%d", &n);
		}
		cnt++;
		switch (n) {
			case 0:
				printf(GREEN "\tDa Thuc cua ban:\t" WHITE); printPoly(header);
				break;
			case 1:
				printf(GREEN "\tHe so phan tu: " WHITE); scanf("%d", &c);
				printf(GREEN "\tSo mu phan tu: " WHITE); scanf("%d", &e);
				printf(GREEN "\tThu tu vi tri can chen: " WHITE); scanf("%d", &pos);
				x.Heso = c; x.Somu = e;
				insertPoly(x, locatePolyByOrder(pos, header), &header);
				break;
			case 2:
				printf(GREEN "\tHe so phan tu: " WHITE); scanf("%d", &c);
				printf(GREEN "\tSo mu phan tu: " WHITE); scanf("%d", &e);
				x.Heso = c; x.Somu = e;
				appendPoly(x, &header);
				break;
			case 3:
				printf(GREEN "\tHe so phan tu: " WHITE); scanf("%d", &c);
				printf(GREEN "\tSo mu phan tu: " WHITE); scanf("%d", &e);
				x.Heso = c; x.Somu = e;
				prependPoly(x, &header);
				break;
			case 4:
				printf(GREEN "\tHe so phan tu: " WHITE); scanf("%d", &c);
				Position p = locatePolyByCoe(c, header);
				if (p == NULL) printf(GREEN "\t\tKhong tim thay!\n" WHITE);
				else {
					printf(GREEN "\t\tPhan tu dau tien co he so %d la: " WHITE, c); printf("%dx^%d\n", p->GetCoe, p->GetExp);
				}
				break;
			case 5:
				printf(GREEN "\tSo mu phan tu: " WHITE); scanf("%d", &e);
				p = locatePolyByExp(e, header);
				if (p == NULL) printf(GREEN "\t\tKhong tim thay!\n" WHITE);
				else {
					printf(GREEN "\t\tPhan tu dau tien co so mu %d la: " WHITE, e); printf("%dx^%d\n", p->GetCoe, p->GetExp);
				}
				break;
			case 6:
				printf(GREEN "\tHe so phan tu: " WHITE); scanf("%d", &c);
				deletePolyByCoe(c, &header);
				break;
			case 7:
				printf(GREEN "\tSo mu phan tu: " WHITE); scanf("%d", &e);
				deletePolyByExp(e, &header);
				break;
			case 8:
				printf(GREEN "\tVi tri thu: " WHITE); scanf("%d", &pos);
				p = locatePolyByOrder(pos, header);
				if (p == NULL) printf(GREEN "\t\tKhong tim thay!\n" WHITE);
				else {
					printf(GREEN "\t\tPhan tu o vi tri %d la: " WHITE, pos); printf("%dx^%d\n", p->GetCoe, p->GetExp);
				}
			case 9:
				printf(GREEN "\tVi tri thu 1: " WHITE); scanf("%d", &pos1);
				printf(GREEN "\tVi tri thu 2: " WHITE); scanf("%d", &pos2);
				swapPoly(locatePolyByOrder(pos1, header), locatePolyByOrder(pos2, header));
				break;
			case 10:
				printf(GREEN "\tChon lenh\n");
				printf(GREEN "\t\t1. Sap xep theo He so\n");
				printf(GREEN "\t\t2. Sap xep theo So mu\n");
				printf(RED "\n\t\tLenh cua ban: " WHITE); scanf("%d", &pos);
				if (pos == 1) {
					printf(GREEN "\t\t\t1. Sap xep Tang dan\n");
					printf(GREEN "\t\t\t2. Sap xep Giam dan\n");
					printf(RED "\n\t\t\tLenh cua ban: " WHITE); scanf("%d", &pos1);
					if (pos1 == 1) {
						sortPolyByCoe(1, &header);
					}
					else if (pos1 == 2) {
						sortPolyByCoe(-1, &header);
					}
					else {
						break;
					}
				}
				else if (pos == 2) {
					printf(GREEN "\t\t\t1. Sap xep Tang dan\n");
					printf(GREEN "\t\t\t2. Sap xep Giam dan\n");
					printf(RED "\n\t\t\tLenh cua ban: " WHITE); scanf("%d", &pos1);
					if (pos1 == 1) {
						sortPolyByExp(1, &header);
					}
					else if (pos1 == 2) {
						sortPolyByExp(-1, &header);
					}
					else {
						break;
					}
				}
				else {
					break;
				}
				break;
			case 11:
				printf(GREEN "\tNhap vao Da thuc 2 cua ban!\n" WHITE);
				List header2; makeNullPoly(&header2);
				readPoly(&header2);
				header = mergePoly(header, header2);
				break;
			case 12:
				normalizePoly(&header);
				break;
			case 13:
				printf(GREEN "\tNhap vao Da thuc 2 cua ban!\n" WHITE);
				header2; makeNullPoly(&header2);
				readPoly(&header2);
				header = addPoly(header, header2);
				break;
			case 14:
				printf(GREEN "\tNhap vao Da thuc 2 cua ban!\n" WHITE);
				header2; makeNullPoly(&header2);
				readPoly(&header2);
				header = subPoly(header, header2);
				break;
			case 15:
				printf(GREEN "\tNhap vao Da thuc 2 cua ban!\n" WHITE);
				header2; makeNullPoly(&header2);
				readPoly(&header2);
				header = mulPoly(header, header2);
				break;
			case 16:
				printf(GREEN "\tLuy thua: " WHITE); scanf("%d", &pos);
				powPoly(&header, pos);
				break;
			case 17:
				printf(GREEN "\tChon lenh\n");
				printf(GREEN "\t\t1. He so chan\n");
				printf(GREEN "\t\t2. He so le\n");
				printf(RED "\n\t\tLenh cua ban: " WHITE); scanf("%d", &pos);
				if (pos == 1) {
					header = copyPolyByCoe(1, header);
				}
				else if (pos == 2) {
					header = copyPolyByCoe(-1, header);
				}
				else {
					break;
				}
				break;
			case 18:
				printf(GREEN "\tChon lenh\n");
				printf(GREEN "\t\t1. So mu chan\n");
				printf(GREEN "\t\t2. So mu le\n");
				printf(RED "\n\t\tLenh cua ban: " WHITE); scanf("%d", &pos);
				if (pos == 1) {
					header = copyPolyByExp(1, header);
				}
				else if (pos == 2) {
					header = copyPolyByExp(-1, header);
				}
				else {
					break;
				}
				break;
			case 19:
				x = gcdPoly(header);
				printf(GREEN "\tNhan tu chung la: %dx^%d\n" WHITE, x.Heso, x.Somu);
				break;
		}
	}
	return 0;
}




