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
typedef enum {
	lundi = 1,mardi,mercredi,jeudi,vendredi
}giorni;
void stampa(int n, int f) {
	printf("il giorno   %d   e' il giorno in cui i studenti passano pui tempo al l univerisita;\nin quanto fanno  %d  ore di corso \n", n, f);
}
int durata(int l, lezione lezioni) {
	int i;
	int somma = 0;
			somma = somma + (lezioni.ora_fi - lezioni.ora_in);
	return somma;
}
int lettura(lezione lezioni) {
	int i=0;
	int max = 0;
	FILE* f;
	f = fopen("orario.bin", "rb");
	if (f == NULL) {
		printf("File indisponibile\n");
		exit(-1);
	}
	else {
		while (fread(&lezioni, sizeof(lezione), 1, f)==0) {
			fread(&lezioni, sizeof(lezione), 1, f);
			if (max < durata(i + 1, lezioni)) {
				max = durata(i + 1, lezioni);
			}
		}
	}
		
	fclose(f);
	verifica(lezioni, i);
	return i;
}

main() {
	lezione lezioni;
	int n;
	int gris;
	int tot;
	gris = lettura(lezioni,&tot);
	stampa(gris, tot);
}