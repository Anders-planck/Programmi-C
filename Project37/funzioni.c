#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"funzioni.h"
#define dim 10



int  lettura(int m[][dim]) {
	int t;
	FILE* f;
	f = fopen("magic.bin", "rb");
	if (f == NULL) {
		printf("file indisponibile\n");
		exit(-1);
	}
	else {
		fread(&t, sizeof(int), 1, f);
		fread(m, sizeof(int),dim*dim, f);
		
	}
	verifica(t,m);
	fclose(f);
	return t;
}
void verifica(int t,int m[][dim]) {
	int i,j;
	printf("la dimensione:\t%d\n", t);
	for (i = 0; i < t; i++) {
		for (j = 0; j < t; j++) {
			printf(" %d ", m[i][j]);
		}
		printf("\n");
	}
}



void elabora