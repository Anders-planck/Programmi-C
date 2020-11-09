#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#define dim 100
#define len 20
typedef struct {
	char nome[len];
	char citta[len];
	char C[len];
}viaggio;
typedef struct {
	char viaggio[len];
}vai;
void traeitto(vai Y[], viaggio  x[], int k) {
	int i;
	
	strcpy(Y[0].viaggio, x[0].citta);
	for (i = 0; i < k; i++) {
		if (strcmp(Y[i].viaggio, x[i].C) != 0) {
			strcpy(Y[i+1].viaggio, x[i].C);
		
		}
		if (strcmp(Y[i].viaggio, Y[i - 1].viaggio) != 0 && strcmp(x[i].citta, x[i].C) != 0) {
			strcpy(Y[i + 1].viaggio, x[i].C);
		
		}
	}
	
}
void risposta(int ris, char V[], char S[], viaggio x[],int k) {
	int i;

	vai Y[dim];
	if (ris == 0) {
		printf("\nERRORE il viaggiatore %s non ha un treno in partenza di %s\n", V, S);
		printf("%s:\t", V);
		traeitto(Y, x, k);
		for (i = 0; i < k; i++) {
			printf("%s ", Y[i].viaggio);
		}printf("\n");
	}
	else if (ris == 1) {
		printf("\nTutto e in ordine con il viaggiatore %s\n ", V);
		printf("%s:\t", V);
		traeitto(Y, x, k);
		for (i = 0; i < k; i++) {
			printf("%s ", Y[i].viaggio);
		}printf("\n");
	}
}
int confronto(viaggio g, viaggio x[], int k, char V[], char S[]) {
	int i;
	int gia = 1;
	strcpy(V, g.nome);
	for (i = 1; i < k; i++) {
		if (strcmp(g.citta, x[i].C) != 0) {
			strcpy(V, g.nome);
			strcpy(S, x[i].C);
			gia = 0;
		}if ( strcmp(g.C, x[i].citta) != 0) {
			strcpy(V, g.nome);
			strcpy(S, x[i].citta);
			gia = 0;
		}if (strcmp(g.citta, x[i].C) == 0 && strcmp(g.C, x[i].citta) == 0) {
			strcpy(V, g.nome);
			gia = 1;
		}
	}
	return gia;
}
int compare(viaggio f, viaggio reg[], int n,viaggio x[]) {
	int i;
	int j = 0;
	
	for (i = 0; i < n; i++) {
		if (strcmp(f.nome, reg[i].nome) == 0) {
			x[j] = reg[i];
			j++;
		}
	}
	return j;
}
int verifica(viaggio f, viaggio reg[], int n, char V[], char S[], viaggio x[],int *k) {
	int i=0;
	int gia=1;
	int z;
	z = compare(f, reg, n, x);
	*k = z;
		gia=confronto(x[i], x, z, V, S);

	return gia;
}
int gia_(viaggio f, viaggio reg[], int k) {
	int i;
	int tro = 0;
	for (i = 0; i < k; i++) {
		if (strcmp(f.nome, reg[i].nome) == 0) {
			tro = 1;
		}
	}
	return tro;
}
int lettura(viaggio reg[]) {
	int i=0; FILE* f;
	f = fopen("viaggi.txt", "rt");
	if (f == NULL) {
		printf("file indisponibile\n");
		exit(-1);
	}
	else {
		while (!feof(f)) {
			fscanf(f, "%s%s%s", reg[i].nome, reg[i].citta, reg[i].C);
			printf("nome:  %s\t\tPartenza:%s  \t\tArrivo:  %s\n", reg[i].nome, reg[i].citta, reg[i].C);
			i++;
		}
	}
	fclose(f);
	return i;
}

main() {
	viaggio reg[dim];
	int n;
	int i = 0;
	int ris;
	int k;
	int tro = 0;
	viaggio x[dim];
	char V[len], S[len];
	n = lettura(reg);
	while (i < n) {
		ris = 1;
		tro = gia_(reg[i], reg, i);
		if (tro == 0) {
			ris = verifica(reg[i], reg, n, V, S,x,&k);
			risposta(ris, V, S,x,k);
		}
		i++;
	}
	}