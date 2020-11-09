#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include<string.h>
#define dim 20
typedef struct {
	int citta;
	int srt;
}grafo;
int guarda(grafo f, grafo w[], int  k, int* l) {
	int i;
	int gia = 0;
	for (i = 0; i < k; i++) {
		if (f.srt == w[i].srt) {
			gia = 1;
			*l = w[i].srt;
		}	
	}
	return gia;
}
void impogni(grafo f,grafo w[], int a[],int k) {
	int i;
	int l;
	a[0] = 1;
		if (f.citta == 0)
			a[f.srt] = 1;
		if (f.citta != 0 && guarda(f,w,k,&l)==1)
			a[l] = 1;
}
void ragruppa(grafo w[],grafo x[], int *k) {
	int i;

	for (i = 0; i < dim; i++) {
		if (x[i].citta == 0){
			w[*k] = x[i];
		(*k)++;
	}
	}


}
void elabora(grafo x[], int a[], int n) {
	int i;
	int k=0;
	grafo w[dim];
	ragruppa(w,x,&k);
	for (i = 0; i < n; i++) {
		impogni(x[i],w,a,k);
	}
}
void verifica_1(grafo x[], int m) {
	int i;
	printf("\n ");
	for (i = 0; i < m; i++)
		printf("%d  %d\n ", x[i].citta,x[i].srt);
	printf("\n ");
};
void verifica(int a[]) {
	int i;
	printf("\n[ ");
	for (i = 0; i < dim; i++)
		printf("%d ",a[i]);
	printf("]\n ");
}
void inizia(int a[]) {
	int i;
	for (i = 0; i < dim; i++)
		a[i] = 0;
	verifica(a);
}
void lettura(grafo x[], int a[],int *n) {
	FILE* f;
	int i=0;
	inizia(a);
	f = fopen("grafo.txt", "rt");
	if (f == NULL) {
		printf("file indisponibile");
		exit(-1);
	}
	else {
		while (!feof(f)) {
			fscanf(f, "%d %d", &x[i].citta, &x[i].srt);
			i++;
		}
		*n = i;
		verifica_1(x, *n);
	}
	fclose(f);
}
main() {
	int a[dim];
	grafo x[dim];
	int n;
	lettura(x, a,&n);
	elabora(x, a, n);
	verifica(a);
}