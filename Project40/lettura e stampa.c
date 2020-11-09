#include"Intestazione.h"

void implementa(int* scelta) {
	int c;
	while (*scelta != 1 && *scelta != 2) {
		richiesta(&c);
		*scelta = c;
	}
}

void richiesta(int* scelta) {
	printf("\t\t\t\t\tMENU FUNZIONE\n");
	printf("**** 1 ****\ \t\t\t FUNZIONE PRIMARIA\n");
	printf("**** 2 ****\ \t\t\t FUNZIONE SECONDARIA\n");
	printf("\t\t\t\t\t CHE FUNZIONI SCEGLI DI ESEGUIRE:\t");
	scanf("%d", &(*scelta));
}
int lettura(persona persone[]) {
	int i=0;
	FILE* f;
	f = fopen("indigenti.txt", "rt");
	if (f == NULL) {
		printf("\t\t\t\t\tERRORE NELLA L APPERTURA DEL FILE 1 \n");
	}
	else {
		while (!feof(f)) {
			fscanf(f, "%s %d", persone[i].nome, &persone[i].red);
			i++;
		}
	}
	fclose(f);
	return i;
}


int lettura_2(Auto auti[]) {
	int i = 0;
	FILE* f;
	f = fopen("auto.bin", "rb");
	if (f == NULL) {
		printf("\t\t\t\t\tERRORE NELLA L APPERTURA DEL FILE 2 \n");
	}
	else {
		i=fread(auti, sizeof(Auto), max, f);
	}
	fclose(f);
	return i;
}

void stampa(persona persone[], int np) {
	int i;
	printf("\t\t\t\t\t\tSTAMPA DATI\n");
	for (i = 0; i < np; i++) {
		printf("%d\   %s    %d\n", i + 1, persone[i].nome, persone[i].red);
	}
}

void stampa_a(Auto auti[], int na) {
	int i;
	printf("\t\t\t\t\t\tSTAMPA DATI\n");
	for (i = 0; i < na; i++) {
		printf("%d\   %s    %s\n", i + 1, auti[i].nome, auti[i].marca);
	}
}