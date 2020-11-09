#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#define dim 100
typedef struct banca {
	int giorno;
	int mese;
	int anno;
	float cifra;
}mouv;
void stampa(mouv inizio[], mouv fine[], int k, int j) {
	int l = 0, m = 0;
	do {
		printf("\nil conto corrente è andato in negativo il  %d-%d-%d e conteneva %.2f € e ne è uscito il %d-%d-%d e contenendo %.2f", inizio[l].giorno, inizio[l].mese, inizio[l].anno, inizio[l].cifra, fine[m].giorno, fine[m].mese, fine[m].anno, fine[m].cifra);
		l++;
			m++;
	} while (l < j && m < k);
}
void calcolo(mouv euro[], int nt){
	int i = 0;
	int n;
	int j = 0;
	int k = 0;
	mouv inizio[dim], vale, fine[dim];
	vale.cifra = 0;
	inizio[j].cifra = 0;
	fine[k].cifra = 0;
	do {
		vale.cifra = vale.cifra + euro[i].cifra;
		vale.giorno = euro[i].giorno;
		vale.mese = euro[i].mese;
		vale.anno = euro[i].anno;
		if (vale.cifra < 0 ) {
			inizio[j].cifra = vale.cifra;
			inizio[j].giorno = vale.giorno;
			inizio[j].mese = vale.mese;
			inizio[j].anno = vale.anno;
			
			j++;
		}if (vale.cifra > 0 && inizio[j].cifra != 0 ) {
			fine[k].cifra = vale.cifra;
			fine[k].giorno = vale.giorno;
			fine[k].mese = vale.mese;
			fine[k].anno = vale.anno;
			k++;
		}
		i++;
	} while (i<nt);
	printf("\n%d,%d",j, k);
	stampa(inizio, fine,k,j);
}
void lettura(mouv euro[], int* nt) {
	int i = 0;
	FILE* f;
	f = fopen("C:\\Users\\Anders\\Desktop\\programa c\\Project4\\movanno.txt", "rt");
	if (f == NULL) {
		printf("nom si trova il file\n");
		exit(-1);
	}
	else {
		while (!feof(f)) {
			fscanf(f, "%d %d %d %f", &euro[i].giorno,&euro[i].mese,&euro[i].anno, &euro[i].cifra);
			i++;
		}
		*nt = i;
		fclose(f);
		for (i = 0; i < *nt; i++) {
			printf("%d-%d-%d--->%.2f\n", euro[i].giorno,euro[i].mese,euro[i].anno, euro[i].cifra);
		}
	}
}

main() {
	mouv euro[dim];
	int nt;
	lettura(euro, &nt);
	calcolo(euro, nt);
}