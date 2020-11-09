#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#define dim 300
#define len 5 
#define lem 100
typedef struct ospedale {
	int  nu[len];
}buste;
int verifica_5(int b[], int n, int h) {
	int i;
	int gia = 0;
	for (i = 0; i < h; i++) {
		if (n == b[i])
			gia = 1;
	}
	return gia;
}
void risposta_2(int b[],int c[],int l) {
	int i;
	int k = 0;
	printf("\n[");
	for (i = 0; i < l; i++) {
		if (b[i] != b[i - 1] && verifica_5(b, b[i], i) != 1 && k<10) {
			printf(" << %d--->%d >>\n ", b[i], c[i]);
			k++;
		}
	}printf("]\n");
}
int  verifica_4(int n, int b[], int l) {
	int i;
	int gia = 0;
	for (i = 0; i < l; i++) {
		if (n == b[i])
			gia = 1;
	}
	return gia;
}
int  verifica_3(int n, int c[], int l) {
	int i;
	int gia = 0;
	for (i = 0; i < l; i++) {
		if (n == c[i])
			gia = 1;
	}
	return gia;
}
int guarda(int max, int a[],int h,int*val,int b[],int l) {
	int i=h;
	int r=0;
	
	while ( i < lem && verifica_4(i, b, l) != 1 ) {
		if (max < a[i]) {
			max = a[i];
			*val = a[i];
			r = i;
		}
		i++;
	}return r+1;
}

void dici_primi(int a[], int  b[], int c[]) {
	int i; int l=0;
	int k=0;
	int val=0;
	k = guarda(a[0], a, 0, &val,b,l);
	b[l] = k;
	c[l] = val;
	l = 1;
	for (i = 1; i < lem; i++) {
		k = guarda(a[i], a,i,&val,b,l);
		if (verifica_4(i, b,l) != 1) {
			b[l] = k;
			c[l] = val;
			l++;
		}
	}
	risposta_2(b,c,l);
}
void risposta(int N, int s,int a[]) {
	int i;
	if (s == 1) {
		printf("\nil bambino e' riuscito a reimpire l album dopo << %d >> buste\n", N);
	}
	else {
		printf("\nle buste non sono bastate affinche il bambino riempisca tutto l album\n");
	}
	printf("\n[");
	for (i = 0; i < lem; i++) {
		printf(" %d ",a[i]);
	}
	printf("]\n");
}
int controllo(int a[]) {
	int i=0;
	int f = 1;
	while (f !=0 && i < lem) {
		if (a[i] == 0)
			f = 0;
		i++;
	}
	return f;
}
void verifica(buste x[], int a[], int n) {
	int i=0;
	int j=0;
	int f;
	int s=0;
	int N;
	int o=0;
	int l = 0;
	do{
		l = 0;
		for (i = 0; i < len; i++) {
			f = x[j].nu[i];
			l = l + 1;
			a[f-1] =l ;
		}
		s = controllo(a);
		printf("%d\t", s);
		j++;
	} while (j < n && s!=1);
	N = j-1;
	risposta(N, s,a);
}
void lettura(buste x[], int* n,int a[]) {
	FILE* f;
	int e;
	int j=0,i = 0;
	f = fopen("buste.txt", "rt");
	if (f == NULL) {
		printf("file indisponibile\n");
		exit(-1);
	}
	else {
		while (!feof(f)) {
			for (i = 0; i < len; i++) {
				e=fscanf(f, "%d", &x[j].nu[i]);
			}
			j++;
		}
		*n = j;
		fclose(f);
		for (j = 0; j < *n; j++) {
			printf("%d busta:\t[", j + 1);
			for (i = 0; i < len; i++) {
				printf(" %d ", x[j].nu[i]);
			}printf("]\n");
		}
	}
	for (i = 1; i < lem; i++) {
		a[i] = 0;
	}
}
main() {
	buste x[dim];
	int n;
	int a[lem];
	int b[lem];
	int c[lem];
	lettura(x, &n,a);
	verifica(x, a, n);
	dici_primi(a,b,c);
}