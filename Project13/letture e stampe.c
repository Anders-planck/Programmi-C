

#include"Intestazione.h"

void lettura(risultato esam[], int* n) {
	FILE* f;
	int i = 0;
	f = fopen("risultati.txt", "rt");
	if (f == NULL) {
		printf("file indisponibile");
	}
	else {
		while (!feof(f)) {
			fscanf(f, "%s%d%d%d%d", esam[i].nom, &esam[i].g, &esam[i].m, &esam[i].a, &esam[i].voto);
			i++;
		}
	}
	*n = i;
	fclose(f);
}

void ordinate(risultato nota[], int nc) {
	int i;
	printf("\n\t\t\t\t\t STAMPA ORDINATA\n\n\n\n");
	for (i = 0; i < nc; i++) {
		printf("nome:\t%s data:\t %d %d %d    voto:\t% d\n", nota[i].nom, nota[i].g, nota[i].m, nota[i].a, nota[i].voto);
	}
}

void stampa(comp valore[], int ni) {
	int i;
	printf("\n\t\t\t\t\tNOUVA STAMPA\n\n\n\n");
	for (i = 0; i < ni; i++) {
		printf("%d--- %d---%s\n", i + 1, valore[i].id, valore[i].nom);
	}
}



void diordinate(risultato esam[], int n) {
	int i;
	printf("\n\t\t\t\t\t STAMPA DIORDINATA\n\n\n\n");
	for (i = 0; i < n; i++) {
		printf("nome:\t%s data:\t %d %d %d    voto:\t% d\n", esam[i].nom, esam[i].g, esam[i].m, esam[i].a, esam[i].voto);
	}
}




void riscrittura(risultato nota[], int nc) {
	int i = 0; 
	FILE* g;
	g = fopen("STAMPA ORDINATA.doc", "wt");
	if (g == NULL) {
		printf("ERRORE NELL APPERTURA DEL FILE\n");
	}
	else {
		fprintf(g, "\n\t\t\t\t\t STAMPA DIORDINATA\n\n\n\n");
		while (i < nc) {
			fprintf(g, "nome:\t % s data : \t % d % d % d    voto : \t % d\n", nota[i].nom, nota[i].g, nota[i].m, nota[i].a, nota[i].voto);
				i++;
		}
	}
	fclose(g);
}