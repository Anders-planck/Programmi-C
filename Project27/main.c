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
void stampa(int ris, viaggio vris) {
	if (ris == 1)
		printf("%s effettua lo stesso viaggio:  %s-%s ore %d\n", vris.nome, vris.citp, vris.cita, vris.ora);
	else
		printf("non esistono viaggi compatibilli\n");
}
int compare(viaggio vinp, viaggio f) {
	int gia;
	if (strcmp(vinp.citp, f.citp) == 0 && strcmp(vinp.cita, f.cita) == 0 && vinp.ora == f.ora)
		gia = 1;
	else
		gia = 0;
	return gia;
}
int elabora(viaggio vinp, viaggio viaggi[], int  n, viaggio* vris) {
	int i=0;
	int gia=2;
	while (i < n && gia != 1) {
		gia = compare(vinp, viaggi[i]);
		if (gia == 1) {
			*vris = viaggi[i];
		}
		i++;
	}
	return gia;
}
void verifica(viaggio viaggi[],int n) {
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
	verifica(viaggi,n);
	return n;
}
main() {
	viaggio viaggi[dim];
	viaggio vinp;
	int n;
	int ris;
	viaggio vris;
	n = lettura(viaggi);
	printf(" inserisci il tuo nome:\n");
	scanf("%s", vinp.nome);
	printf(" inserisci la citta di partenza:\n");
	scanf("%s", vinp.citp);
	printf(" inserisci la citta di arrivo:\n");
	scanf("%s", vinp.cita);
	printf(" inserisci l'ora di partenza:\n");
	scanf("%d", &vinp.ora);
	printf("%s  %s  %s  %d\n", vinp.nome, vinp.citp, vinp.cita,vinp.ora);
	ris = elabora(vinp, viaggi, n, &vris);
	stampa(ris, vris);
}