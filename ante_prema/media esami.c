#include<stdio.h>
#include<string.h>
#include<math.h>
typedef struct esami {
	char nome[40];
	int cfu;
	int voto;
}esam;
float media(esam tip[], int n) {
	float c=0;
	float d=0;
	int i;
	float e;
	for (i = 0; i < n; i++) {
		c = c + (tip[i].voto*tip[i].cfu);
		d = d + tip[i].cfu;
	}
	e = c / d;
	return e;
}


void lettura(esam tip[], int *n) {
	printf("quanti esami voui inserire");
	scanf("%d", n);
	int i;
	for (i = 0; i < *n; i++) {
		printf("nome esam:\t");
		scanf("%s", tip[i].nome);
		printf("\ni cfu:\t");
		scanf("%d", &tip[i].cfu);
		printf("\ni voto:\t");
		scanf("%d", &tip[i].voto);
	}printf("\nverifica\n");
	for (i = 0; i < *n; i++) {
		printf("[%s-->%d,%d]\n", tip[i].nome, tip[i].cfu, tip[i].voto);
	}
}


main() {
	esam tip[50];
	int n;
	float M;
	lettura(tip, &n);
	M=media(tip, n);
	printf("\t\tM=%.2f\n\n",M);
}