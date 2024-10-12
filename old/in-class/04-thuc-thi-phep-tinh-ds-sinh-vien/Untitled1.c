#include <stdio.h>
#include <string.h>

struct SinhVien{
   char MSSV[10];
   char HoTen[50];
   float DiemLT, DiemTH1, DiemTH2;
};

typedef struct DanhSach {
 	struct SinhVien A[40];
 	int n;
} DanhSach;

DanhSach dsRong() {
	DanhSach tmp;
	tmp.n = 0;
	return tmp;
}

int ktRong(DanhSach ds) {
	return ds.n == 0;
}

void chenCuoi(struct SinhVien x, DanhSach *ds) {
	if (ds->n >= 40) {
		printf("Loi! Danh sach day!\n");
		return;
	}
	ds->A[ds->n] = x;
	(ds->n)++;
}

void xoaTai(int p, DanhSach *ds) {
	if (p < 1 || p > ds->n) return;
	
	for (int i = p-1; i < ds->n - 1; i++) {
		ds->A[i] = ds->A[i+1];
	}
	(ds->n)--;
}

int stringCmp(char x[], char y[]) {
	if (strlen(x) != strlen(y)) return 0;
	int i = 0;
	while (i != strlen(x)) {
		if (x[i] != y[i]) return 0;
		i++;
	}
	return 1;
}

int tim(char x[], DanhSach ds) {
	for (int i = 1; i <= ds.n; i++) {
		if (stringCmp(x, ds.A[i-1].MSSV)) {
			return i;
		}
	}
	return ds.n + 1;
}

void xoaSinhVien(char x[], DanhSach *ds) {
	xoaTai(tim(x, *ds), ds);
}

DanhSach chepKhongDat(DanhSach ds) {
	DanhSach res = dsRong();
	for (int i = 1; i <= ds.n; i++) {
		if (ds.A[i-1].DiemLT + ds.A[i-1].DiemTH1 + ds.A[i-1].DiemTH2 < 4) {
			chenCuoi(ds.A[i-1], &res);
		}
	}
	return res;
}

DanhSach nhap() {
	DanhSach ds;
	ds = dsRong();
	int n; scanf("%d", &n);
//	getchar();
	for (int i = 0; i < n; i++) {
		struct SinhVien x;
		
		getchar();
		fgets(x.MSSV, 10, stdin); x.MSSV[strlen(x.MSSV) - 1] = '\0';
		fgets(x.HoTen, 50, stdin); x.HoTen[strlen(x.HoTen) - 1] = '\0';
		
		scanf("%f%f%f", &x.DiemLT, &x.DiemTH1, &x.DiemTH2);
		
		if (tim(x.MSSV, ds) == ds.n + 1) {
			chenCuoi(x, &ds);
		}
	}
	return ds;
}

void hienthi(DanhSach L) {
	for(int i = 0; i < L.n; i++) {
     	printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
 	}
}

void hienthiDat(DanhSach L) {
	for (int i = 1; i <= L.n; i++) {
		if (L.A[i-1].DiemLT + L.A[i-1].DiemTH1 + L.A[i-1].DiemTH2 >= 4) {
     		printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i-1].MSSV, L.A[i-1].HoTen, L.A[i-1].DiemLT, L.A[i-1].DiemTH1, L.A[i-1].DiemTH2);
		}
	}
}

int main(){ 
	return 0;
}





