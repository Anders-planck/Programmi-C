#include<stdio.h>
#include<string.h>
#include<math.h>
#define dim 30
typedef struct ambulatorio {
	char nome[20];
	int data;
}prenota;
void stampa(int b[], int r) {
	int i;
	printf("sono ancora liberi i giorni seguenti:\n{");
	for (i = 0; i < r; i++)
		printf("%d ", b[i]);
	printf("}");
}
void verifica(prenota x[], int n) {
	int i;
	int j;
	int r;
	int k = 0;
	int m = 0;
	int b[31];
	int a[31];
	for (i = 1; i < 31; i++) {
		a[i] = 0;
	}
	for (i = 0; i < n; i++) {
		for (j = 1; j < 31; j++) {
			if (x[i].data == j)
				a[j] = a[j] + 1;
		}
	}
	for (i = 1; i < 31; i++) {
		if (a[i] == 0) {
			m = 1;
		}
	}
	for (i = 1; i < 31; i++) {
		printf("[%d-->%d]\t", i, a[i]);
	}
	
	if (m == 1)
		printf("\n\nci sono ancora prenotazioni\n");
	else
		printf("\n\n non ci sono prenotazioni\n");


		for (j = 1; j < 31; j++) {
			if (a[j] == 0) {
				b[k] = j;
				k++;
			}
		}

	r = k;
	stampa(b, r);
}


void lettura(prenota x[], int *n) {
	int c;
	c = 21;
	int i;
	prenota y[] = {
		{ "Alberti", 1 },
		{ "Baldoni",17 },
		{ "Bonfe",6 },
		{ "Bottazzi",25 },
		{ "Busi",18 },
		{ "Chesani",15 },
		{ "Franciosi",11 },
		{ "Giordano",27 },
		{ "Lamma",25 },
		{ "Leonardi",23 },
		{ "Martelli",6 },
		{ "Mascardi",26 },
		{ "Mello",22 },
		{ "Maio",16 },
		{ "Naponiello",10 },
		{ "Neri",1 },
		{ "Rossi",3 },
		{ "Toni",11 },
		{ "Torroni",5 },
		{ "Vecchi",5 },
		{ "Verdi",30 }
	};
	for (i = 0; i <c; i++)
		x[i] = y[i];
	*n = c;
	for (i = 0; i < *n; i++)
		printf("[%s-->%d]\t", x[i].nome, x[i].data);
}
main() {
	prenota x[dim];
	int n;

	lettura(x, &n);
	verifica(x, n);

}