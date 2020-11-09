#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#define dim 100
#define len 10
#define max 20
typedef struct {
	char crim[max];
	char via[max];
	int Nc2;

}crimini;
typedef struct indirizzi {
	char via[max];
	char Nc;
	int x, y;
}luogo;
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
void calcolo(crimini malva[],luogo comi[] ,char matrice[][len], int nc ,int n) {
	int i;
	int j;
	int k, c,p, l;
	for (i = 0; i < len; i++) {
		for (j = 0; j < len; j++) {
			matrice[i][j] = 32;
		}
	}
	for (i = 0; i < nc; i++) {
		for(p=0;p< n;p++){
		for (k = 0; k < len; k++) {
			for (j = 0; j < len; j++) {
				if (strcmp(malva[i].crim, "Omicidio")==0 && strcmp(malva[i].via,comi[p].via) == 0&& malva[i].Nc2==comi[p].Nc) {
					c=comi[p].x;
					l = comi[p].y;
					matrice[c][l] = 42;
				}
			}
		}
	}
}
}
void stampa_11(luogo comi[], int n) {
	int i;
	printf("\nvisualizzazione des indirizzi\n");
	for (i = 0; i < n; i++) {
		printf("[%s-->%d--->(%d.%d)]", comi[i].via, comi[i].Nc, comi[i].x,comi[i].y);
		printf("\n");
	}
}
void stampa_1(crimini malva[], int nc) {
	int i;
	printf("\nvisualizzazzione dei misfatti\n");
	for (i = 0; i < nc; i++) {
		printf("[%s-->%s--->%d)]", malva[i].crim, malva[i].via, malva[i].Nc2);
		printf("\n");
	}
}
void  lettura_1(luogo comi[], int* n) {
	int i = 0;
	FILE* f;
	f = fopen("indirizzi.txt", "rt");
	if (f == NULL) {
		printf("file2 indisponibile");
		exit(-1);
	}
	else {
		while (!feof(f)) {
			fscanf(f,"%s %d %d %d",comi[i].via, &comi[i].Nc,&comi[i].x,&comi[i].y);
			i++;
		}
	}
	fclose(f);
	*n = i;
}
void  lettura(crimini malva[], int* nc) {
	int i = 0;
	FILE* f;
	f = fopen("misfatti.txt", "rt");
	if (f == NULL) {
		printf("file indisponibile");
		exit(-1);
	}
	else {
		while (!feof(f)) {
			fscanf(f, "%s %s %d", malva[i].crim, malva[i].via, &malva[i].Nc2);
			i++;
		}
	}
	fclose(f);
	*nc = i;
}


main() {
	printf("\n\n\nseconda parte\n\n\n");
	crimini malva[dim];
	luogo comi[dim];
	int nc;
	int n;
	char matrice[len][len];
	lettura(malva, &nc);

	lettura_1(comi, &n);

	stampa_1(malva, nc);

	stampa_11(comi, n);

	calcolo(malva,comi, matrice, nc,n);

	stampa_2(matrice);

	
}