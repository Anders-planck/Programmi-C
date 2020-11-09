#include<stdio.h>
#include<string.h>
typedef struct notabili {
	char nome[20];
	int voto;
}nota;
void calcolo(nota x[], nota y[], int n) {
	int i;
	int d;
	int j = 0;
	nota z;
	for (i = 0; i < n; i++) {
		for (d = 0; d < n; d++) {
			if (strcmp(x[d].nome, x[i].nome) == 0) {
				strcpy(y[j].nome, x[i].nome);
				y[j].voto = x[d].voto + x[i].voto;
			}
			else {
				strcpy(y[j].nome, x[i].nome);
				y[j].voto = x[i].voto;
				j++;
			}
		}d =j;
		printf("\n\n");
		for (i = 0; i < d; i++) {
			printf("[%s-->%d]\n", y[i].nome, y[i].voto);
		}
	}
}

void lettura(nota x[], int *n) {
	printf("inserire il numero di voti:\t");
	scanf("%d", n);
	int i = 0;
	for (i = 0; i < *n; i++) {
		printf("\ninserisci il nome del candidato:\t");
		scanf("%s", x[i].nome);
		printf("\nvoti:\t");
		scanf("%d", &x[i].voto);
	}
	for (i = 0; i < *n; i++) {
		printf("[%s-->%d]\n", x[i].nome, x[i].voto);
	}
}

main() {
	nota x[100];
	nota y[100];
	int n;
	lettura(x, &n);
	calcolo(x, y, n);


}