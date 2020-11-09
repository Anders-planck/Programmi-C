#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#define dim 100
typedef struct banca {
	int giorno;
	float cifra;
}mouv;
void stampa(mouv inizio, mouv fine, int n) {
	printf("\nil conto corrente è andato in negativo il giorno %d e conteneva %.2f € e ne è uscito il giorno %d e contenendo %.2f", inizio.giorno, inizio.cifra, fine.giorno, fine.cifra);
}
void calcolo(mouv euro[], int nt) {
	int i = 0;
	int neg = 0;
	int n;
	mouv inizio, vale, fine;
	vale.cifra = 0;
	inizio.cifra = 0;
	fine.cifra = 0;
	do {
		vale.cifra = vale.cifra + euro[i].cifra;
		vale.giorno = euro[i].giorno;
		if (vale.cifra < 0 && inizio.cifra == 0 && neg == 0) {
			inizio.cifra = vale.cifra;
			inizio.giorno = vale.giorno;
			neg = 1;
		}if (vale.cifra > 0 && inizio.cifra != 0 && neg != 0 && fine.cifra == 0) {
			fine.cifra = vale.cifra;
			fine.giorno = vale.giorno;
		}
		i++;
	} while (fine.cifra == 0);
	n = fine.giorno - inizio.giorno;
	stampa(inizio, fine, n);
}
void lettura(mouv euro[], int* nt) {
	int i = 0;
	FILE* f;
	f = fopen("C:\\Users\\Anders\\Desktop\\programa c\\Project1\\movimenti.txt", "rt");
	if (f == NULL) {
		printf("nom si trova il file\n");
		exit(-1);
	}
	else {
		while (!feof(f)) {
			fscanf(f, "%d %f", &euro[i].giorno, &euro[i].cifra);
			i++;
		}
		*nt = i;
		fclose(f);
		for (i = 0; i < *nt; i++) {
			printf("%d--->%.2f\n", euro[i].giorno, euro[i].cifra);
		}
	}
}

main() {
	mouv euro[dim];
	int nt;
	lettura(euro, &nt);
	calcolo(euro, nt);
}