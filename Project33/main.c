#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include<math.h>
#include <stdio.h>
#include<stdlib.h>
#include"funzioni.h"
#define dim 20

main() {
	int a[dim][dim];
	int b[dim][dim];
	int c[dim][dim];
	int n;
	int ris;
	n = lettura(a,b);
	ris=somma(a, b,c,n);
	stampa(c, n);
}