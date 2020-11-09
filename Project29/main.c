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
	printf("registro di stipendio:\n");
	for (i = 0; i < n; i++) {
		printf("%s  %d\n", registro[i].prof, registro[i].paga);
	}
}
int pagare(int som, corso f,int fondo) {
	int paga;
	paga = ((f.cred * fondo) / som);
	return paga;
}
int somma_crediti(corso corsi[], int n) {
	int i;
	int somma=0;
	for (i = 0; i < n; i++) {
		somma = somma + corsi[i].cred;
	}
	return somma;
}
void elabora(corso corsi[], int n, stip registro[],int fondo) {
	int i;
	int som;
	som = somma_crediti(corsi, n);
	for (i = 0; i < n; i++) {
		strcpy(registro[i].prof, corsi[i].prof);
		registro[i].paga = pagare(som, corsi[i],fondo);
	}
 }
void verifica(corso corsi[], int n) {
	int i;
	for (i = 0; i < n; i++) 
		printf("%s %s %d\n", corsi[i].lezione, corsi[i].prof, corsi[i].cred);
}
int lettura(corso corsi[],int *fondo) {
	int i;
	FILE* f;
	f = fopen("corsi.bin", "rb");
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
	int n;
	int fondo;
	n = lettura(corsi,&fondo);
	elabora(corsi, n, registro,fondo);
	stampa(registro, n);
}