#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "funzioni.h"
#define dim 300
#define len 20


main() {
	paziente pazienti[dim];
	int n;
	double dist;
	char s[len];
	n = lettura(pazienti);
	dist = distanza(pazienti, s, n);
	stampa(dist, s);
}
