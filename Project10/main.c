#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include<string.h>
#define dim 20

void stampa(int r, int c, int mat3[][dim]) {
	int i, j;
	for (i = 0; i < r; i++) {
		printf("\n");
		for (j = 0; j < c; j++) {
			printf("%d ", mat3[i][j]);
		}
	}
}

	void additione(int mat1[][dim], int  mat2[][dim], int  mat3[][dim], int r, int r1, int c, int c1) {
		int i = 0, k = 0, l = 0, j = 0;

		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++) {
				if (r <= r1 && c <= c1) {
					mat3[i][j] = mat1[i][j] + mat2[i][j];
				}
				else if (r > r1&& c > c1) {
					mat3[i][j] = mat1[i][j];
				}
				else if (r > r1&& c < c1) {
					mat3[i][j] = mat1[i][j];
				}
				else if (r < r1 && c > c1) {
					mat3[i][j] = mat1[i][j];
				}
			}
		}stampa(r, c, mat3);
	}
	

void lettura(int mat1[][dim],int* r, int* c) {
	int i,j=0;
	printf("numero di rige e colone");
	scanf("%d%d", &(*r), &(*c));
	for (i = 0; i < *r; i++) {
		printf("(%d,%d):\n",i,j);
		for (j = 0; j < *c; j++) {
			scanf("%d", &mat1[i][j]);
		}
	}

}
main() {
	int mat1[dim][dim];
	int mat2[dim][dim], mat3[dim][dim];
	int r, c, r1, c1;
	lettura(mat1, &r, &c);
	lettura(mat2, &r1, &c1);
	additione(mat1, mat2,mat3, r, r1, c, c1);
}