#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>
#define dim 10
#define len 600
#define r 3
typedef struct {
	char code[len];
}mosse;


void lavoro(mosse mossa[], int n, int mat[][3], int ris[]) {
	int i, j, k = 0, l = 0, a = 0;
	int m = 0, p = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			l = l + 1;
			mat[i][j] = l;
			printf("%d ", mat[i][j]);
		}printf("\n");
	}
	i = 0;
	for (i = 0; i < n; i++) {
		j = 0;
		a = 0;
		while (mossa[i].code[j] != '\0') {
			if (a == 0) {
				if (mossa[i].code[j] == 'U') {
					a = mat[1][1];
				}
				if (mossa[i].code[j] == 'D') {
					a = mat[2][1];
				}
				if (mossa[i].code[j] == 'L') {
					a = mat[1][0];
				}
				if (mossa[i].code[j] == 'R') {
					a = mat[1][2];
				}
			}
			else {

				while (a == mat[m][p] && m < 3 && p < 3)
				{
					if (mossa[i].code[j] == 'U') {
						if (m - 1 < 0 || p >= 3 || p < 0) {
							a = mat[m][p];
						}
						a = mat[m - 1][p];
						ris[k] = a;
					}
					if (mossa[i].code[j] == 'D') {
						if (m + 1 >= 0 || p >= 3 || p < 0) {
							a = mat[m][p];
						}
						a = mat[m + 1][p];
						ris[k] = a;
					}
					if (mossa[i].code[j] == 'L') {
						if (m < 0 || m >= 3 || p - 1 < 0) {
							a = mat[m][p];
						}
						if (a == mat[m][p]) {
							if (mossa[i].code[j] == 'U') {
								if (m - 1 < 0 || p >= 3 || p < 0) {
									a = mat[m][p];
								}
								a = mat[m - 1][p];
								ris[k] = a;
							}
							if (mossa[i].code[j] == 'D') {
								if (m + 1 < 0 || p >= 3 || p < 0) {
									a = mat[m][p];
								}
								a = mat[m + 1][p];
								ris[k] = a;
							}
							if (mossa[i].code[j] == 'L') {
								if (m < 0 || m >= 3 || p - 1 < 0) {
									a = mat[m][p];
								}
								a = mat[m][p - 1];
								ris[k] = a;
							}
							if (mossa[i].code[j] == 'R') {
								if (m < 0 || m >= 3 || p + 1 >= 3) {
									a = mat[m][p];
								}
								a = mat[m][p + 1];
								ris[k] = a;
							}

						}
						if (mossa[i].code[j] == 'R') {
							if (m < 0 || m >= 3 || p + 1 >= 3) {
								a = mat[m][p];
							}
							a = mat[m][p + 1];
							ris[k] = a;
						}
					}

				}


			}
			m++;
			p++;
			j++;
		}
		k++;
		printf("%d ", ris[k]);
	}
}
void lettura(mosse mossa[],int *n) {
	int i = 0;
	int s;
	FILE* f;
	f = fopen("codice.txt", "rt");
	if (f == NULL) {
		printf("file indisponibile\n");
		exit(-1);
	}
	else {
		while (!feof(f)) {
			s=fscanf(f, "%s", mossa[i].code);
			printf("%s\n", mossa[i].code);
			i++;
		}
		*n= i;
		printf("%d\n", *n);
		fclose(f);
	}
}
main() {
	mosse mossa[dim];
	int n;
	int ris[dim];
	int mat[3][3];
	lettura(mossa, &n);
	lavoro(mossa, n,mat,ris);
}
	