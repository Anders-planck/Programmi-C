#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<math.h>
#include<stdlib.h>
#define dim 100
#define len 20
#define giorno 5
typedef struct {
	char corso[len];
	int g;
	int ora_in;
	int ora_fi;
}lezione;
void stampa(int n, int f) {
	printf("il giorno   %d   e' il giorno in cui i studenti passano pui tempo al l univerisita;\nin quanto fanno  %d  ore di corso \n", n, f);
}
int durata(int l, lezione lezioni[], int n) {
	int i; 
		int somma = 0;
	for (i = 0; i < n; i++) {
		if (lezioni[i].g == l) {
			somma = somma + (lezioni[i].ora_fi - lezioni[i].ora_in);
		}
	}
	return somma;
}
int elabora(lezione lezioni[], int n,int *tot) {
	int i;
	int max = 0;
	int g;
	for (i = 0; i < giorno; i++) {
		if (max < durata(i + 1, lezioni, n)) {
			max = durata(i + 1, lezioni, n);
			g = i + 1;
			*tot = max;
		}
	}
	return g;
}
void verifica(lezione lezioni[],int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%s g=%d  %d-%d \n", lezioni[i].corso, lezioni[i].g, lezioni[i].ora_in, lezioni[i].ora_fi);
}
int lettura(lezione lezioni[]) {
	int i;
	FILE* f;
	f = fopen("orario.bin", "rb");
	if (f == NULL) {
		printf("File indisponibile\n");
		exit(-1);
	}
	else
		i = fread(lezioni, sizeof(lezione), dim, f);
	fclose(f);
	verifica(lezioni, i);
	return i;
}

main() {
	lezione lezioni[dim];
	int n;
	int gris;
	int tot;
	n = lettura(lezioni);
	gris = elabora(lezioni, n,&tot);
	stampa(gris, tot);
}