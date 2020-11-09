#define _CRT_SECURE_NO_WARNINGS
#define dim 100
#include"funzioni.h"
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int  lettura(paziente pazienti[]) {
	int i = 0;
	FILE* f;
	f = fopen("pazienti.txt", "rt");
	if (f == NULL) {
		printf("file indiponibile\n");
		exit(-1);
	}
	else {
		while (!feof(f)) {
			fscanf(f, "%s%f%f", pazienti[i].inf, &pazienti[i].x, &pazienti[i].y);
			printf("%s   %.1f - %.1f\n", pazienti[i].inf, pazienti[i].x, pazienti[i].y);
			i++;
		}
	}
	fclose(f);
	return i;
}
int raggruppa(paziente f, paziente pazienti[], int n, paziente a[]) {
	int i, j = 1;
	a[0].x = 0;
	a[0].y = 0;
	for (i = 0; i < n; i++) {
		if (strcmp(f.inf, pazienti[i].inf) == 0) {
			a[j] = pazienti[i];
			j++;
		}
	}return j;
}
float  distanza(paziente pazienti[], char s[], int  n) {
	int i;
	float somma = 0;
	float max = 0;
	int  d;
	paziente a[dim];
	d = raggruppa(pazienti[0], pazienti, n, a);
	max = percorso(d, a);
	strcpy(s, pazienti[0].inf);
	for (i = 1; i < n; i++) {
		d = raggruppa(pazienti[i], pazienti, n, a);
		somma = percorso(d, a);
		if (verifica(pazienti[i], pazienti, i-1) != 1 && max < somma) {
			max = somma;
			strcpy(s, pazienti[i].inf);
		}
	}return  max;
}
float calcolo(paziente y, paziente f) {
	float  somma;
	float a, b;
	a = pow((f.x - y.x), 2);
	b = pow((f.y - y.y), 2);
	somma = (float)sqrt(a + b);
	return somma;
}
void stampa(float x, char s[]) {
	printf(" %s ha percorso il piu lungo traeitto con   %.1f km \n", s, x);
}
int verifica(paziente f, paziente pazienti[], int n) {
	int i=0;
	int gia = 0;
	while (i < n && gia != 1) {
		if (strcmp(f.inf, pazienti[i].inf) == 0)
			gia = 1;
		i++;
	}
	return gia;
}
float percorso(int d, paziente a[]) {
	int i;
	float somma = 0;
	for (i = 0; i < d; i++) {
		if (i + 1 < d)
			somma = somma + calcolo(a[i], a[i + 1]);
	}
	return somma;
}