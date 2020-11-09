#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<math.h>
#include<stdlib.h>
#include "funzioni.h"
#define dim 300
#define len 20

main() {
	pacchetto traccia[dim];
	int n,x;
	int toto;
	int totf;
	int val;
	char file[len];
	pacchetto fine[dim];
	printf("file:\t");
	scanf("%s", file);
	n = lettura(file, traccia);
	toto = byte(traccia, n);
	printf("inserire  l'adattamento di velocità di riproduzione compreso tra 1-3:\n ");
	scanf("%d", &x);
	val = elabora(traccia, n, fine,x,&totf);
	risultato(totf, toto,fine,val);
}