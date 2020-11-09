#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#define dim 100
#define len 31
#define lg 20
typedef struct {
	char nota[lg];
	int posto[len];
}camera;
void risposta(int ris, char s[],int a,int p) {
	if (ris == 1)
		printf("la camera %s sara libera per il vostro soggiorno\n", s);
	else
		printf("non c'e' alcuna stanza disponibile, perche' nessuna delle stanze e' libera sia il %d sia il %d.", a, p);
	printf("\n");
}
int guarda(camera f,int a, int p) {
	int i;
	int gia = 1;
	for (i = a-1; i < p-1; i++) {
		if (f.posto[i] == 1)
			gia = 0;
	}
	return gia;
}
int verifica(camera x[],int n, int  a, int  p,char s[]) {
	int i;
	int j;
	int gia = 0;
	for (i = 0; i <n; i++) {
		for (j = 0; j < len; j++) {
			if (guarda(x[i], a, p) == 1) {
				strcpy(s, x[i].nota);
				gia = 1;
			}
		}
	}
	return gia;
}
void intput(int* p, int* a) {
	printf("\ninserisci il giorno di arrivo:\t");
	scanf("%d", &(*a));
	printf("\ninserisci il giorno di partenza:\t");
	scanf("%d", &(*p));
}
void elabora(camera x[], int n) {
	int i;
	int p, a;
	int ris;
	char s[lg];
	intput(&p, &a);
	ris = verifica(x, n, a, p, s);
	risposta(ris, s,a,p);
}
int lettura(camera x[dim]) {
	int i=0;
	int j=0;
	int d;
	FILE* f;
	f = fopen("stanze.txt", "rt");
	if (f == NULL) {
		printf("file indisponibile");
		exit(-1);
	}
	else {
		while (!feof(f)) {
			fscanf(f, "%s", x[j].nota);
			for (i = 0; i < len; i++) {
				fscanf(f, "%d", &x[j].posto[i]);
			}
			j++;
		}
	}d = j;
	fclose(f);
	printf("lettura in corso.....\n");
	for (j = 0; j < d; j++) {
		printf("%s :[ ", x[j].nota);
		for (i = 0; i < len; i++) {
			printf("%d ", x[j].posto[i]);
		}printf("]\n");
	} return d;
}

main() {
	camera x[dim];
	int n;
	n = lettura(x);
	elabora(x, n);
}