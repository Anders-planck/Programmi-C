#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include<string.h>
#define dim 21
#define len 4
typedef struct {
	char corso[dim];
	char sigla[len];
}ambito;
typedef struct {
	char corso[dim];
	int voto;
}libretto;
void verifica_2(libretto d[],int i) {
	int l;
	FILE* f;
	f = fopen("risposta_file.bin", "rb");
	if (f == NULL) {
		printf("file indisponibile 4\n");
		exit(-1);
	}
	else {
		fread(&d, sizeof(libretto), i, f);
		printf("il libretto desiderato e':\n");
		for(l=0;l<i;l++)
		printf("%s    =  %d\n", d[l].corso, d[l].voto);
	}
	fclose(f);
}
void risposta(libretto d[],int i) {
	FILE* f;
	
	f = fopen("risposta_file.bin", "wb");
	if (f == NULL) {
		printf("file indisponibile 3\n");
		exit(-1);
	}
	else {
		fwrite(&d, sizeof(libretto), i, f);
	}
	fclose(f);
	verifica_2(d,i);

 }
void  recherche(libretto d[], libretto y[], int m) {
	int i=0;
	int j = 0;
	while (i < m) {
		if (strcmp(d[j].corso, y[i].corso) == 0){
			d[j].voto = y[i].voto;
		j++;
	}
		i++;
	}
	
}
int ricerca(char s[],libretto d[], ambito x[], int n) {
	int i=0;
	int j=0;
	while (i < n) {
		if (strcmp(s, x[i].sigla) == 0) {
			strcpy(d[j].corso, x[i].corso);
			j++;
		}
		i++;
	} return j;
}
void elabora(char s[], ambito x[], libretto y[], int n, int m) {
	int i;
	libretto d[dim];
	
	i=ricerca(s,d, x, n);
recherche(d, y, m);

	risposta(d,i);
}

void input(char s[]) {
	printf("\ninserisci un ambito di studio: ");
	scanf("%s", s);
}

void verifica_1(libretto y[], int n) {
	int i;
	printf("secondo\n\n");
	for (i = 0; i < n; i++) {
		printf("%s--->%d\n", y[i].corso, y[i].voto);
	}
}
int read(libretto y[]) {
	 FILE* f;
	int n;
	f = fopen("libretto.bin", "rb");
	if (f == NULL) {
		printf("file indisponibile 2\n");
		exit(-1);
	}
	else {
		n = fread(y, sizeof(libretto), dim, f);
	}
	fclose(f);
	verifica_1(y, n);
	return n;
}
void verifica(ambito x[], int n) {
	int i=0;
	for (i = 0; i < n; i++) {
		printf("%s--->%s\n", x[i].corso, x[i].sigla);
	}
	
}
int lettura(ambito x[]) {
 FILE* f;
	int n;
	f = fopen("ambito.bin", "rb");
	if (f == NULL) {
		printf("file indisponibile 1\n");
		exit(-1);
	}
	else {
		n = fread(x, sizeof(ambito), dim, f);
	}
	fclose(f);
	verifica(x, n);
	return n;
}
main() {
	ambito x[dim];
	libretto y[dim];
	int n;
	char s[len];
	int m;
	n = lettura(x);
	m = read(y);
	input(s);
	elabora(s, x, y, n, m);
}