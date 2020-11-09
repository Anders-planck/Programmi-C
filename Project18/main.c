#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include<string.h>
#define dim 20
typedef struct {
	char nome[dim];
	char cognome[dim];
	int eta;
}persona;
void read(int n) {
	FILE* f;
	FILE* g;
	persona x[dim];
	int i;
	f = fopen("copia_anagrafe.txt", "wt");
	g = fopen("anagrafe.bin", "rb");
	if (f == NULL || g == NULL) {
		printf("file indisponibili 2");
		exit(-1);
	}
	else {
			n=fread(x, sizeof(persona), dim, g);
			for (i = 0; i < n; i++) {
				printf("% s % s % d\n", x[i].nome, x[i].cognome, x[i].eta);
				fprintf(f, "%s %s %d\n", x[i].nome, x[i].cognome, x[i].eta);
			}
	}
	fclose(f);
	fclose(g);
}
int lettura() {
	FILE* f;
	FILE* g;
	int i=0;

	persona x[dim];
	f = fopen("anagrafe.txt", "rt");
	g = fopen("anagrafe.bin", "wb");
	if (f == NULL || g == NULL) {
		printf("file indisponibili");
		exit(-1);
	}
	else {
		while (!feof(f)) {
			fscanf(f, "%s %s %d", x[i].nome, x[i].cognome, &x[i].eta);
			i++;
		}
		fwrite(x, sizeof(persona), i-1, g);

		fclose(f);
		fclose(g);
	}
	return i;
}


main() {
	
	int n;
	n=lettura();
	read( n);
}