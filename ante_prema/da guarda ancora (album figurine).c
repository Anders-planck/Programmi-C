#include<stdio.h>
#define dim 11
typedef struct bustine
{
	int bustina[5];
}busta;
main() {
	busta bus[11] = {
		{ 1,3,7,9,10 },
		{ 1,7,5,4,9 },
		{ 2,24,25,21,22 },
		{ 17,16,15,14,19 },
		{ 1,3,2,4,5 },
		{ 2,6,5,4,8 },
		{ 11,13,14,15,12 },
		{ 19,18,17,16,15 },
		{ 2,4,6,3,12 },
		{ 4,5,2,18,17 },
		{ 13,5,4,6,12 } };
	int i,f=0, c, v;
	int trovato, memo = 0, gia = 0;
	int a[25], d[25];
	/*verificazione*/
	printf("verificazione\n");
	for (v = 0; v < dim; v++) {
		printf("[");
		for (c = 0; c < 5; c++) {
			printf("%d  ", bus[v].bustina[c]);
		}
		printf("]\t");
	}

	printf("\n\n\nverificazione 2\n");
	for (i = 0; i < 25; i++) {
		a[i] = i + 1;
	}
	for (i = 0; i < 25; i++) {
		printf("%d  ", a[i]);
	}

	printf("\n\n\nverificazione 3\n");
	for (i = 0; i < 25; i++) {
		d[i] = 0;
	}
	for (i = 0; i < 25; i++) {
		printf("%d  ", d[i]);
	}
	printf("\n\nelaborazione 3\n");
	for (v = 0; v < dim; v++) {
		for (c = 0; c < 5; c++) {
			for (i = 0; i < 25; i++) {
				if (a[i] == bus[v].bustina[c])
					d[i = bus[v].bustina[c]]++;
			}

		}
	}
	




	printf("\n\n\nverificazione 4\n");

	for (i = 0; i < 25; i++) {
		printf("%d  ", d[i]);
	}

	printf("\n\n\nrisultati\n");
	for (i = 0; i < 25; i++) {
		if (d[i] >= 1) {
			trovato = 1;
			printf("\nil numero %d e stato trovato:\t%d volte\n", i + 1, d[i]);
			memo++;
		}
		else {
			trovato = 0;
			printf("\nil numero %d  non e stato trovato", i + 1);
		}

	}
	if (memo < 25)
		printf("\nnon e' riuscito a rempire l album\n");
	else
		printf("\nsono bastati");
/*
	for (i = 0; i < 25; i++) {
		gia = 0;
		for (v = 0; v < dim; v++) {
			for (c = 0; c < 5; c++) {
				if (i + 1 == bus[v].bustina[c] && gia!=1) {
	
					gia = 1;
				}
					
			}
		}
		}
	printf("gli e servito :%d", f);*/
}