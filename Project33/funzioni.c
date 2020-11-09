#define dim 100
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void inizializza(int a[][dim], int b[][dim], int n) {
	int i;
	int j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("insirisci (%d,%d)\n", i + 1, j + 1);
			scanf("%d", &a[i][j]);
		}
	}
	printf("seconda matrice \n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("insirisci (%d,%d)\n", i + 1, j + 1);
			scanf("%d", &b[i][j]);
		}
	}
 }
int lettura(int a[][dim],int b[][dim]) {
	int n;
	printf("inserisci la dimensione delle matrici:\t");
	scanf("%d", &n);
	if (n > 20) {
		while (n > 20) {
			printf("errore di dimensione");
			printf("\ninserisci la dimensione delle matrici:\t");
			scanf("%d", &n);
		}
	}
	else
		printf("somma in corso...\n");

	inizializza(a, b, n);
	return n;
}
int somma(int a[][dim], int b[][dim], int c[][dim],int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	return 1;
}
void stampa(int c[][dim], int n) {
	int i, j;
	printf("la matrice risultante\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}