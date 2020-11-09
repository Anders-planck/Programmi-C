#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include "funzioni.h"
#define dim 300
#define len 20


main() {
	/*	paziente pazienti[dim];
	int n;
	float dist;
	char s[len];
	n = lettura(pazienti);
	printf("infemiera:\t");
	scanf("%s", s);
	dist = distanza(pazienti, s, n);
	stampa(dist,s);
	*/
	int c, b, d, i, n, e, j, f, g, h;
	printf("inserire un numero");
	scanf("%d", &n);
	i = 0;
	j = 0;
	e = n;
	do {


		n = n + i;
		c = n / 10;
		b = n % 10;
		d = (b + c) / 2;
		i++;

		e = e - j;
		f = e / 10;
		g = e % 10;
		h = (g + f) / 2;
		j++;
	} while (d != b || h != g);
	if (i < j) {
		printf("\nil palindromo vicino e'%d\t", n);
	}
	else if (i >= j) {
		printf("\nil palindromo vicino e'%d\t", e);
	}
}
