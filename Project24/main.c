#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define dim 100
typedef struct {
	char squadra[15];
	int x, y;
}idrante;


int distanza(idrante f,idrante u) {
	int m;
	int a, b;
	a = (int)(((f.x) - (u.x)) * ((f.x) - (u.x)));
	b = (int)(((f.y) - (u.y)) * ((f.y) - (u.y)));
	m = (int)sqrt(a + b);
	return m;
}
int somma(idrante f, idrante a[], int n) {
	int i;
	int som = 0;
	for (i = 0; i < n; i++) {
		if (strcmp(f.squadra, a[i].squadra) == 0) {
			som = som + distanza(f, a[i]);
		}
	}
}
int elabora(idrante a[], int n, char nome[]) {
	int i;
	int d;
	d = 0;
	for (i = 0; i < n; i++) {
		if (d < somma(a[i],a,n)) {
			d = somma(a[i],a,n);
			strcpy(nome, a[i].squadra);
		}
	}return d;
}
int lettura(idrante a[]) {
	FILE* f;
	int b,i;
	f = fopen("idranti.bin", "rb");
	if (f == NULL) {
		printf("il file non e stato aperto correttamente\n");
		exit(-1);
	}
	else {
		b = fread(a, sizeof(idrante), dim, f);
		for (i = 0; i < b; i++) {
			printf("%s %d %d\n", a[i].squadra, a[i].x, a[i].y);
		}
	}
	fclose(f);
	return b;
}
main() {
	int n;
	char nome[15];
	int dist;
	idrante a[dim];
	printf("operazione di lettura del file\n");
	n = lettura(a);
	dist= elabora(a, n, nome);
	printf("\nil risultato e %s con la distanza di %d\n", nome, dist);
}