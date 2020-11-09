#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define dim 100
#define len 20
typedef struct {
	char nome[len];
	char citp[len];
	char cita[len];
	int ora;
}viaggio;
void stampa(viaggio vris[],int n) {
	int i;
	printf("\nGRUPPO:  %s-%s ore %d\n",vris[0].citp, vris[0].cita, vris[0].ora);
	for (i = 0; i < n; i++) {
		printf("%s\n", vris[i].nome);
	}
}
int compare(viaggio f,viaggio viaggi[],int n,viaggio vris[]) {
	int gia,i;
	int j=0;
	for (i = 0; i < n; i++) {
		if (strcmp(viaggi[i].citp, f.citp) == 0 && strcmp(viaggi[i].cita, f.cita) == 0 && viaggi[i].ora == f.ora) {
			vris[j] = viaggi[i];
			j++;
		}	
	}
	gia = j;
	return gia;
}
int verifica_1(viaggio f, viaggio viaggi[], int n) {
	int i;
	int gia=0;
	for (i = 0; i < n; i++) {
		if (strcmp(viaggi[i].citp, f.citp) == 0 && strcmp(viaggi[i].cita, f.cita) == 0 && viaggi[i].ora == f.ora) 
			gia = 1;
		}
	return gia;
}
void elabora(viaggio viaggi[], int  n, viaggio vris[]) {
	int i = 0;
	int gia;
	int anc;
	for (i = 0; i < n; i++) {
		anc=verifica_1(viaggi[i], viaggi, i);
		if (anc == 0) {
			gia = compare(viaggi[i], viaggi, n, vris);
			stampa(vris, gia);
		}
	}
}
void verifica(viaggio viaggi[], int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%s  %s  %s  %d\n", viaggi[i].nome, viaggi[i].citp, viaggi[i].cita, viaggi[i].ora);
}
int lettura(viaggio viaggi[]) {
	int n;
	FILE* f;
	f = fopen("viaggi.bin", "rb");
	if (f == NULL) {
		printf("file indisponibile\n");
		exit(-1);
	}
	else
		n = fread(viaggi, sizeof(viaggio), dim, f);
	fclose(f);
	verifica(viaggi, n);
	return n;
}
main() {
	viaggio viaggi[dim];
	int n;
	viaggio vris[dim];
	n = lettura(viaggi);
	 elabora( viaggi, n, vris);

}