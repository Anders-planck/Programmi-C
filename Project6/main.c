#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#define dim 100
#define len 10
typedef struct deliti {
	char nome[dim];
	int x, y;
}crimini;
void stampa_2(char matrice[][len]) {
	int i;
	int j;
	for (i = 0; i < len; i++) {
		printf("\n");
		for (j = 0; j < len; j++) {
			printf("%c", matrice[i][j]);
		}
	}
}
void calcolo(crimini malva[], char matrice[][len], int nc) {
	int i;
	int j;
	int k ,c=0, l=0;
	for (i = 0; i < len; i++) {
		for (j = 0; j < len; j++) {
			matrice[i][j] = 32;
		}
	}
	for(i=0;i<nc;i++){
	for (k = 0; k < len; k++) {
		for (j = 0; j < len; j++) {
			if (strcmp(malva[i].nome, "Omicidio") == 0) {
				c = malva[i].x;
				l = malva[i].y;
				matrice[c][l] = 42;
			}
		}
		}
	}
}
void stampa_1(crimini malva[], int nc) {
	int i;
	for (i = 0; i < nc; i++) {
		printf("[%s-->(%d,%d)]", malva[i].nome, malva[i].x, malva[i].y);
		printf("\n");
	}
}
void  lettura(crimini malva[], int* nc) {
	int i = 0;
	FILE* f;
	f = fopen("delitti.txt", "rt");
	if (f == NULL) {
		printf("file indisponibile");
		exit(-1);
	}
	else {
		while (!feof(f)) {
			fscanf(f, "%s %d %d", malva[i].nome, &malva[i].x, &malva[i].y);
				i++;
		}
	}
	fclose(f);
	*nc = i;
}


main() {
	crimini malva[dim];
	int nc;
	char matrice[len][len];
	lettura(malva, &nc);
	stampa_1(malva, nc);
	calcolo(malva,matrice, nc);
	stampa_2(matrice);
	printf("\n\n\nseconda parte\n\n\n");
}