#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#define dim 300
#define len 20
#define ses 8
typedef struct {
	char nome[len];
	char cognome[len];
	char sesso[ses];
}cliente;
typedef struct {
	char parola[len];
}testo;
int verifica(testo t, testo z[], int  s,int *l) {
	int i;
	int gia = 0;
	for (i = 0; i < s; i++) {
		if (strcmp(t.parola, z[i].parola) == 0) {
			gia = 1;
			*l = i;
		}
	}
	return gia;
}
void crea(testo y[], cliente f, int n,testo z[],int s) {
	int i=0;
	int l=0;
	FILE* g;
	g = fopen(f.nome, "wt");
	if (g == NULL) {
		printf("file indisponibile");
		exit(-1);
	}
	else {
		while (i<n) {

			if (strcmp(f.sesso, "maschio") == 0) {

				if (strcmp(y[i].parola, "%NOME%") == 0) {
					fprintf(g, " %s ", f.nome);
				}
				if (strcmp(y[i].parola, "%COGNOME%") == 0) {
					fprintf(g, " %s ", f.cognome);
				}
				 if (strcmp(y[i].parola, "%NOME%") != 0 && strcmp(y[i].parola, "%COGNOME%") != 0) {
					fprintf(g, " %s ", y[i].parola);
				}
			}
			else if (strcmp(f.sesso, "femmina") == 0) {
				if (strcmp(y[i].parola, "%NOME%") == 0) {
					fprintf(g, " %s ", f.nome);
				}
				if (strcmp(y[i].parola, "%COGNOME%") == 0) {
					fprintf(g, " %s ", f.cognome);
				}
				if (strcmp(y[i].parola, "%NOME%") != 0 && strcmp(y[i].parola, "%COGNOME%") != 0 && verifica(y[i],z,s,&l)==1) {
					if (l + 1 >= s)
						fprintf(g, " %s ",y[i].parola);
					else
						fprintf(g, " %s ", z[l + 1].parola);
				}if (strcmp(y[i].parola, "%NOME%") != 0 && strcmp(y[i].parola, "%COGNOME%") != 0 && verifica(y[i], z, s,&l) != 1) {
					fprintf(g, " %s ", y[i].parola);
				}
			}
			i++;
		}
	}
	fclose(g);
}
int legge(testo y[]) {
	int i=0;
	int e;
	int n;
	FILE* g;
	g = fopen("lettera.txt", "rt");
	if (g == NULL) {
		printf("file indisponibile");
		exit(-1);
	}
	else {
		printf("\n\n\n");
		while (!feof(g)) {
			e=fscanf(g, "%s", y[i].parola);
			printf("%s ", y[i].parola);
			i++;
		}
	}
	n = i;
	fclose(g);
	return n;
}
void lettera(cliente f,testo z[],int s) {
	int n;
	testo y[dim];
	n=legge(y);
	crea(y,f,n,z,s);
}
void elabora(cliente x[], int n,testo z[],int s) {
	int i;
	for (i = 0; i < n; i++) {
		lettera(x[i],z,s);
	}
}
int lettura_1(testo z[]) {
	int i;
	int d;
	FILE*r;
	r = fopen("coniuga.bin","rb");
	if (r == NULL) {
		printf("file insdisponibile");
		exit(-1);
	}
	else {
		i = fread(z, sizeof(testo), dim, r);
		d = i;
		fclose(r);
		printf("\nparole di genere\n");
		for (i = 0; i < d; i++) {
			printf(" %s ", z[i].parola);
		}
	}
	return d;
}
int lettura(cliente x[]) {
	int i = 0;
	int d;
	FILE* f;
	f = fopen("clienti.bin", "rb");
	if (f == NULL) {
		printf("file indisponibile");
		exit(-1);
	}
	else {
		printf("in corso........\n");
		i = fread(x, sizeof(cliente), dim, f);
		fclose(f);
		d = i;
		printf("Elementi del file:\n");
		for (i = 0; i < d; i++) {
			printf("nome:\t%s\tcognome:\t%s\tsesso:\t%s\n", x[i].nome, x[i].cognome, x[i].sesso);
		}
	}
	return i;
}
 int main() {
	cliente x[dim];
	int n;
	testo z[dim];
	int s;
	n = lettura(x);
	s = lettura_1(z);
	elabora(x, n,z,s);
    return 0;
}