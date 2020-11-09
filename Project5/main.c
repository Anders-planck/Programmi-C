#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#define dimr 79
#define dimc 66
typedef struct {
	char nome[3];
	int	lr;
	int h;
	int s;
}image;
void calcolo(image x, int y[][dimc], int r, int c) {
	int j, i;

	for (i = 0; i < r; i++) {
		printf("\n");
		for (j = 0; j < c; j++) {
			if (y[i][j]>=(x.s/2)) {
				printf("*");
			}
			else if(y[i][j] <= (x.s / 2)) {
				printf("\t");
			}
		}
	}
}
void stampa_1(int r, int c, int y[][dimc], image x) {
	int i;
	int j;
	printf("\n\t%s\t%d\t%d\n", x.nome, r, c);
	for (i = 0; i < r; i++) {
		printf("\n");
		for (j = 0; j < c; j++) {
			printf("%d\t", y[i][j]);
		}
	}
}

void lettura(image*x,int y[][dimc], int* r, int* c) {
	FILE* f;
	int i = 0, j = 0;
	int gia = 0;
	(*x).lr = 0;
	(*x).s = 0;
	(*x).h = 0;
	printf("\nquante righe e colone vuoi leggere");
	scanf("%d%d", &(*r), &(*c));
	f = fopen("C:\\Users\\Anders\\Desktop\\programa c\\Project5\\image.txt", "rt");
	if (f == NULL) {
		printf("non e' stato trovato i file \n");
		exit(-1);
	}
	else {
				fscanf(f,"%s %d %d %d", &(*x).nome, &(*x).lr, &(*x).h, &(*x).s);
				for (i = 0; i < *r; i++) {
					for (j = 0; j < *c; j++) {
						fscanf(f, "%d", &y[i][j]);
					}
				}
	}
	fclose(f);
}

main() {
	image x;
	int y[dimr][dimc];
	int r, c;
		lettura(&x, y, &r,&c);
		stampa_1(r, c, y, x);
		calcolo(x,y, r, c);
}