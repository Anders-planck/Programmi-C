#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <math.h>
#include<string.h>
#include <stdlib.h>
#define dim 100 
typedef struct {
	int x, y;
	int q;
}tappa;
typedef struct {
	int v;
	int q;
} viaggio;
void registro(viaggio viaggi[], int s) {
	int i=0;
	FILE* f;
	FILE* g;
	f = fopen("carico.txt", "wt");
	g = fopen("carico.bin", "wb");
	if (f == NULL || g == NULL) {
		printf("Apertura sbagliata\n");
		exit(-1);
	}
	else {
		fwrite(viaggi, sizeof(viaggio), s, g);
		while (i < s) {
			fprintf(f, " viaggio %d carico eccessivo: %d\n", viaggi[i].v, viaggi[i].q);
			i++;
		}
	}fclose(f);
	fclose(g);
	
}
void stampa(viaggio viaggi[], int s) {
	int i;
	for (i = 0; i < s; i++) {
		printf("viaggio %d carico eccessivo: %d kg\n", viaggi[i].v, viaggi[i].q);
	}
}
int somma(tappa tappe[], int d, int f) {
	int i;
	int som = 0;
	for (i = d; i < f; i++) {
		som = som + tappe[i].q;
	}
	return som;
}
int  calcolo(int a[], int m, tappa tappe[], int n,viaggio viaggi[]) {
	int i;
	int j=0;
	int som = 0;
	for (i = 0; i < m; i++) {
		som = 0;
		som = somma(tappe, a[i], a[i + 1]);
		if (som > 5000) {
			viaggi[j].v = i + 1;
			viaggi[j].q = som;
			j++;
		}
	}
	return j;
}
int ragruppo(tappa tappe[], int n, int a[]) {
	int i;
	int j = 0;
	for (i = 0; i < n; i++) {
		if (tappe[i].q == tappe[0].q && tappe[i].x == tappe[0].x && tappe[i].y == tappe[0].y) {
			a[j] = i;
			j++;
		}
	}return j;
}
int  elabora(tappa tappe[], int n,viaggio viaggi[]) {
	int a[dim];
	int m;
	int s;
	m = ragruppo(tappe, n, a);
	printf(" numero di viaggi = %d\n", m-1);
	s=calcolo(a, m, tappe, n,viaggi);
	return s;
}
void verifica(tappa tappe[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("(%d , %d) = %d kg\n", tappe[i].x, tappe[i].y, tappe[i].q);
	}
}
int lettura(tappa tappe[]) {
	int n;
	FILE* f;
	f = fopen("camion.bin", "rb");
	if (f == NULL) {
		printf("file indisponibile");
		exit(-1);
	}
	else {
		n = fread(tappe, sizeof(tappa), dim, f);
	}
	fclose(f);
	verifica(tappe, n);
	return n;
}
main() {
	tappa tappe[dim];
	viaggio viaggi[dim];
	int n;
	int s;
	n = lettura(tappe);
	s=elabora(tappe, n,viaggi);
	stampa(viaggi, s);
	registro(viaggi, s);
}