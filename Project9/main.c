#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include<string.h>
#define dim 20
#define len 25


typedef struct films {
	char t[len];
	char reg[len];
	int anno;
}film;

void riscrittura(film x[], int n) {
	int i=0;
	FILE* s;
	s = fopen("riscrittura.cvs", "wt");
	if (s == NULL) {
		printf("non disponibile");
		exit(-1);
	}
	else {
		while (i < n) {
			fprintf(s, "%s,%s,%d\n", x[i].t, x[i].reg, x[i].anno);
			i++;
		}
	}
	fclose(s);
	
}
void lettura(film x[], int* n) {
	FILE* f;
	int e;
	int i=0;
	f = fopen("Input_Es_2.txt", "rt");
	if (f == NULL) {
		printf("file indiponibile");
		exit(-1);
	}
	else {
		while (!feof(f)) {
			e=fscanf(f, "%s%s%d", x[i].t, x[i].reg, &x[i].anno);
			printf("%s %s %d\n", x[i].t, x[i].reg, x[i].anno);
			i++;
		}
	}
	*n = i;
	printf(" E = %d\n", e);
	fclose(f);
}

main() {
	int n;
	film x[dim];
	lettura(x, &n);
	riscrittura(x, n);
	
}