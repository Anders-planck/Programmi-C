#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include<string.h>
#define dim 21
#define len 4

typedef struct {
	char corso[dim];
	int voto;
}libretto;
void verifica_2(libretto z[], int n) {
	int l;
	FILE* f;
	f = fopen("risposta_file.bin", "rb");
	if (f == NULL) {
		printf("file indisponibile 4\n");
		exit(-1);
	}
	else {
		fread(z, sizeof(libretto), n, f);
		printf("\n\nil libretto desiderato e':\n\n");
		for (l = 0; l < n; l++)
			printf("%s    =  %d\n", z[l].corso, z[l].voto);
	}
	fclose(f);
}
void risposta(libretto z[], int n) {
	FILE* f;

	f = fopen("risposta_file.bin", "wb");
	if (f == NULL) {
		printf("file indisponibile 3\n");
		exit(-1);
	}
	else {
		fwrite(z, sizeof(libretto), n, f);
	}
	fclose(f);
	verifica_2(z, n);

}
int  ricerca(libretto f, libretto y[],libretto z[], int m,int j) {
	int i;
	int gia = 0;
	for (i = 0; i < m; i++) {
		if (strcmp(f.corso, y[i].corso) == 0 && f.voto < y[i].voto) {
			z[j] = y[i];
			gia = 1;
		}if (strcmp(f.corso, y[i].corso) == 0 && f.voto > y[i].voto) {
			z[j] = f;
			gia = 1;
		}
	}
	return gia;
}
void elabora(libretto z[], libretto x[], libretto y[], int n, int m) {
	int i,j=0, s;
	for (i = 0; i < n; i++) {
		if (ricerca(x[i], y, z, m, j) == 1) {
			j++;
		}
	}
	risposta(z,j);
}
void verifica_1(libretto y[], int n) {
	int i;
	printf("\n\nsecondo\n\n");
	for (i = 0; i < n; i++) {
		printf("%s  =  %d\n", y[i].corso, y[i].voto);
	}
}
int read(libretto y[]) {
	FILE* f;
	int n;
	f = fopen("libretto2.bin", "rb");
	if (f == NULL) {
		printf("file indisponibile 2\n");
		exit(-1);
	}
	else {
		n = fread(y, sizeof(libretto), dim, f);
	}
	fclose(f);
	verifica_1(y, n);
	return n;
}
void verifica(libretto x[], int n) {
	int i = 0;
	for (i = 0; i < n; i++) {
		printf("%s  =  %d\n", x[i].corso, x[i].voto);
	}

}
int lettura(libretto x[]) {
	FILE* f;
	int n;
	f = fopen("libretto.bin", "rb");
	if (f == NULL) {
		printf("file indisponibile 1\n");
		exit(-1);
	}
	else {
		n = fread(x, sizeof(libretto), dim, f);
		printf("\n il numero di materia presente nel file e':\tn = %d\n\n", n);
	}
	fclose(f);
	verifica(x, n);
	return n;
}
void main() {
	libretto x[dim];
	libretto y[dim];
	int n;
	libretto z[dim];
	int m;
	n = lettura(x);
	m = read(y);
	elabora(z, x, y, n, m);
}