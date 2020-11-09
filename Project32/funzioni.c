#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"funzioni.h"
int lettura(char file[], pacchetto traccia[]) {
	int i = 0;
	FILE* f;
	f = fopen(file, "rt");
	if (f == NULL) {
		printf("file imdisponibile\n");
		exit(-1);
	}
	else {
		while (!feof(f)) {
			fscanf(f, "%d%d%d%d%f", &traccia[i].idi, &traccia[i].q, &traccia[i].idt, &traccia[i].idp, &traccia[i].v);
			printf("%d - %d - %d - %d - %f \n", traccia[i].idi, traccia[i].q, traccia[i].idt, traccia[i].idp, traccia[i].v);
			i++;
		}
	}fclose(f);
	return i;
}
void stampa(int somma) {
	printf("la grandezza totale in byte del flusso video originale: %d\n", somma);
}
int sommatoria(pacchetto traccia[], int n) {
	int i;
	int som = 0;
	for (i = 0; i < n; i++) {
		som = som + traccia[i].q;
	}
	return som;
}
int byte(pacchetto traccia[], int n) {
	int somma;
	somma = sommatoria(traccia, n);
	stampa(somma);
	return somma;
}
int elabora(pacchetto traccia[], int  n, pacchetto fine[],int x,int *totf) {
	int val;
	val=addattamento(traccia, n, fine,x);
	*totf = byte(fine, val);
	verifica(fine, val);
	return val;
}
int  addattamento(pacchetto traccia[], int  n, pacchetto fine[],int x) {
	int i;
	int j = 0;
	for (i = 0; i < n; i++) {
		if (traccia[i].idt < x) {
			fine[j] = traccia[i];
				j++;
		}
	}
	return j;
}
void verifica(pacchetto fine[], int val) {
	int i;
	for (i = 0; i < val; i++) {
		printf("%d - %d - %d - %d - %f \n", fine[i].idi, fine[i].q, fine[i].idt, fine[i].idp, fine[i].v);
		i++;
	}
}
void risultato(int totf, int toto,pacchetto fine[],int val) {
	int dif;
	dif = toto - totf;
	stampa(totf);
	printf(" la differenza di grandezza in byte tra il file originale e il file modificato:\n difference de: %d\n", dif);
	scrittura(fine, val);
}
void scrittura(pacchetto fine[], int val) {
	int i=0;
	FILE* f;
	f = fopen("traccia_mod.txt", "wt");
	if (f == NULL) {
		printf("file indisponibile\n");
		exit(-1);
	}
	else {
		while (i < val) {
			fprintf(f,"%d %d %d %d %f\n", fine[i].idi, fine[i].q, fine[i].idt, fine[i].idp, fine[i].v);
			i++;
		}
	}fclose(f);
}