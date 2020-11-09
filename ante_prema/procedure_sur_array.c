#include<stdio.h>
#define dim 100
void pari(int a[], int i, int*o, int*p) {
		if (a[i] % 2 == 0) {
			*o = 1;
			*p = a[i];
		}
}
void media(int s, int n, int*m) {
	*m = s / n;
}

void somma(int a[], int n, int*s) {
	int i;
	int ss = 0;
	for (i = 0; i < n; i++) {
		ss = ss + a[i];
	}*s = ss;
}
void stampa(int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("\t%d",a[i]);
	}
}

void lettura(int a[],int*n) {
	int i;
	printf("inserire un numero:\t");
	scanf("%d", n);
	printf("inserisci gli elementi dell array:\n");
	for (i = 0; i < *n; i++) {
		scanf("%d", &a[i]);
	}
}

main()
{
	int a[dim];
	int n;
	int s;
	int m;
	int o, p, i;
	lettura(a, &n);
	stampa(a, n);
	somma(a, n, &s);
	printf("\nla somma totale dell array e':%d", s);
	media(s, n, &m);
	printf("\nla media  dell array e':%d\n", m);

	for (i = 0; i < n; i++) {
		o = 0;
		pari(a, i, &o, &p);
		if (o == 1) {
			printf("\t%d", p);
		}
	}
}