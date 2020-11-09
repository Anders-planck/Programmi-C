#include"Intestazione.h"

void lettura(punto punti[], int* n) {
	int i=0;
	FILE* f;
	f = fopen("poligono.txt", "rt");
	if (f == NULL) {
		printf("\t\t\t\tAPPERTURA MANCATA DEL FILE\n");
		exit(-1);
	}
	else {
		while (!feof(f)) {
			fscanf(f, "%d %d", &punti[i].x, &punti[i].y);
			i++;
		}
	}
	*n = i;
	fclose(f);
}


void stampa(punto punti[], int n) {
	int i;
	printf("\t\t\t\tSTAMPA DATI\n");
	for (i = 0; i < n; i++) {
		printf("%d\   ( %d , %d )\n", i + 1, punti[i].x, punti[i].y);
	}
}

void schizzo(int piano[][len], punto punti[], int n) {
	int i=0, j=0;
	printf("\t\t\t\tSTAMPA DATI\n\n\n");
	for (i = 0; i < len; i++) {
		for (j = 0; j < len; j++) {
			piano[i][j] =".";
		}
	}

	for (i = 0; i < len; i++) {
		for (j = 0; j < len; j++) {
			if (verifica(punti, i, j, n) == 0)
				piano[i][j] = "1";
		}
	}
	disegno(piano);
}
void disegno(int piano[][len]) {
	int i, j;
	for (i = 0; i < len; i++) {
		printf("\t\t\t\t\t");
		for (j = 0; j < len; j++) {
			printf("%s", piano[i][j]);
		}
		printf("\n");
	}
}


int verifica(punto punti[], int  i, int j, int  n) {
	int c = 0, gia = 1;
	while (c < n&&gia==1) {
		if (i == punti[c].x && j == punti[c].y) {
			gia = 0;
		}
		c++;
	}
	return gia;
}


void richiesta(punto* p) {
	printf("\t\t\t\t\tRICHIESTA\n");
	printf("printf inserici le coordinate di un punto a,b \t");
	scanf("%d %d", &(p->x), &(p->y));
	printf("( %d , %d )", p->x, p->y);
}

int interno(punto punti[], punto p, int n, int piano[][len]) {
	int i; int gia = 0;
	for (i = 0; i < n; i++) {
		if (p.x <= punti[i].x && p.x>=punti[i+1].x || p.x >= punti[i].x && p.x <= punti[i + 1].x) {
			gia = gia + 1; 
		}
	}
	piano[p.x][p.y] = "1";
	return gia;
}

void risposta(int c,int piano[][len],punto p) {
	if (c >= 3) {
		printf("RISULTATO ANALISI:\t\t Il punto ( %d , %d ) appartiene al poligono\n\n",p.x,p.y);
		disegno(piano);
	}
	else {
		printf("RISULTATO ANALISI:\t\t Il punto ( %d , %d ) non appartiene al poligono\n\n", p.x, p.y);
		disegno(piano);
	}
}