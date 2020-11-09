#define _CRT_SECURE_NO_WARNINGS
#define dim 100
#include"funzioni.h"
#include<stdio.h>
#include<math.h>
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
int raggruppa(paziente pazienti[], char s[], int n, paziente a[]) {
	int i,j=1;
	a[0].x = 0;
	a[0].y = 0;
	for (i = 0; i < n; i++) {
		if (strcmp(s, pazienti[i].inf) == 0) {
			a[j] = pazienti[i];
			j++;
		}
	}return j;
}
float  distanza(paziente pazienti[], char s[], int  n) {
	int i;
	float somma = 0;
	float  d;
	paziente a[dim];
	d = raggruppa(pazienti, s, n, a);
	for (i = 0; i < d; i++) {
		if (i + 1 < d)
			somma = somma + calcolo(a[i], a[i + 1]);
	}
	return somma;
}
float calcolo(paziente y, paziente x) {
	float  somma;
	float a, b;
	a = pow((x.x - y.x), 2);
	b = pow((x.y - y.y), 2);
	somma =(float) sqrt(a + b);
	return somma;
}
void stampa(float x,char s[]) {
	printf(" %s ha percorso %.1f km",s, x);
}