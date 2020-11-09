#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<math.h>
#include<stdlib.h>
#define dim 100
#define len 20
typedef struct {
	char lezione[len];
	char prof[len];
	int  cred;
}corso;
typedef struct {
	char prof[len];
	int paga;
}stip;
void stampa(stip registro[], int n) {
	int i;
	printf("\nregistro di stipendio:\n");
	for (i = 0; i < n; i++) {
		printf("%s  %d\n", registro[i].prof, registro[i].paga);
	}
}
int add(corso stesso[], int n) {
	int i;
	int somma = 0;
	for (i = 0; i < n; i++) {
		somma = somma + stesso[i].cred;
	}
	return somma;
}
int pagare(int som, corso stesso[],int j,int fondo) {
	int paga, somma_cred;
	somma_cred = add(stesso, j);
	paga = ((somma_cred * fondo) / som);
	return paga;
}
int somma_crediti(corso corsi[], int n) {
	int i;
	int somma = 0;
	for (i = 0; i < n; i++) {
		somma = somma + corsi[i].cred;
	}
	return somma;
}
int verifica_3(corso f, int n, corso corsi[]) {
	int i=0;
	int gia = 0;
	while(i<n && gia!=1) {
		if (strcmp(f.prof, corsi[i].prof) == 0)
			gia = 1;
		i++;
	}
	return gia;
}
int raggruppa(corso stesso[], corso corsi[], int n,corso f) {
	int i;
	int j=0;
	for (i = 0; i < n; i++) {
		if (strcmp(f.prof, corsi[i].prof) == 0) {
			stesso[j] = corsi[i];
			j++;
		}
	}return j;
}
void elabora(corso corsi[], int n, stip registro[],int*k,int fondo) {
	int i;
	int som;
	corso stesso[dim];
	int j, l = 0;
	int gia;
	som = somma_crediti(corsi, n);
	for (i = 0; i < n; i++) {
		j = raggruppa(stesso, corsi, n, corsi[i]);
		gia = verifica_3(corsi[i], i, corsi);
		if (gia != 1) {
			strcpy(registro[l].prof, corsi[i].prof);
			registro[l].paga = pagare(som, stesso, j,fondo);
			l++;
		}
	}*k = l;
}
void verifica(corso corsi[], int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%s %s %d\n", corsi[i].lezione, corsi[i].prof, corsi[i].cred);
}
int lettura(corso corsi[],int*fondo) {
	int i;
	FILE* f;
	f = fopen("corsi2.bin", "rb");
	if (f == NULL) {
		printf("file dìindeisponibile\n");
		exit(-1);
	}
	else
		i = fread(corsi, sizeof(corso), dim, f);
	fclose(f);
	verifica(corsi, i);
	printf("\ninserisci la somma totale a disposizione:\n");
	scanf("%d", &(*fondo));
	return i;
}
main() {
	corso corsi[dim];
	stip registro[dim];
	int k;
	int n;
	int fondo;
	n = lettura(corsi,&fondo);
	elabora(corsi, n, registro,&k,fondo);
	stampa(registro, k);
}