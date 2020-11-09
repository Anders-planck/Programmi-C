#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include<string.h>
#define dim 30
#define len 15
typedef struct {
	char nome[len];
}persone;
void risultato(gia) {
	if (gia == 0) 
		printf("\nil nome esiste");
	else 
		printf("\n non esite il nome nel il registro");
}
int insert(persone p[], int n) {
	int i=0;
	char s[len];
	int gia=1;
	printf("inserire un nome:\t");
	scanf("%s", s);
	while (i < n && gia != 0) {
		if (strcmp(p[i].nome, s) == 0)
			gia = 0;
			i++;
	}
	return gia;
}

int  ricerca (char s[], persone p[], int i) {
	int j=0;
	int f=1 ;
	while (j < i && f!=0 ) {
		if (strcmp(p[j].nome, s) == 0)
			f = 0;
		j++;
	}
	return f;
	
}
void lettura(persone p[], int* n) {
	int i = 0;
	FILE* f;
	int o;
	char s[len];
	f = fopen("Input_Es_1.txt", "rt");
	if (f == NULL) {
		printf("file indisponibile");
		exit(-1);
	}
	else {
		while (!feof(f)) {
			if (i == 0) {
				fscanf(f, "%s", p[i].nome);
				printf("\n%s", p[i].nome);
				i++;
			}
			else {
				fscanf(f, "%s", s);
				o=ricerca(s, p, i);
				if (o == 1) {
					strcpy(p[i].nome, s);
					printf("\n%s", p[i].nome);
					i++;
				}
			}
		}
		*n = i;
		fclose(f);
	}
}

main() {
	persone p[dim];
	int n;
	int gia=0;
	lettura(p, &n);
	gia=insert(p, n);
	printf("%d", gia);
	risultato(gia);
}