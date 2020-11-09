#include<stdio.h>
#define G1 100
#define G2 100
#define G3 100
#define G4 100
#define G5 100
main() {
	float g[G1],g2[G2],g3[G3],g4[G4],g5[G5],medio,somma,totale1=0,totale2=0, totale3 = 0,min1,min2,min3,min4,min5, totale4 = 0, totale5 = 0, tmp1,max2,max1, max3, max4, max5, tmp2,tmp3,tmp4,tmp5;
	int n,m,me,je,ve,v,d,j,c, i;
	printf("\nprimo giorno1\n");
	printf("\ninserire il numero di acquisto");
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		printf("\ninserire valori\n");
		scanf("%f", &g[i]);
	}
		for (i = 1; i <=n; i++) {
			tmp1 = totale1;
			totale1 = tmp1 + g[i];
			
		}printf("\n il totale e' %.2f\t", totale1);
		max1 = g[1];
		for (i = 2; i <= n; i++) {
			if (g[i] > max1) {
				max1 = g[i];
			}min1 = g[1];
			for (i = 2; i <= n; i++) {
				if (g[i] < min1) {
					min1 = g[i];
				}
			}
	}printf("\nil minimo della giornata 1 e' %.2f\t", min1);
		printf("\nil massimo della giornata 1 e' %.2f\t", max1);

	/*----------------------------------------------------------------------*/
	printf("\nprimo giorno2\n");
	printf("\ninserire il numero di acquisto");
	scanf("%d", &m);
	for (j = 1; j <= m; j++) {
		printf("\ninserire valori\n");
		scanf("%f", &g2[j]);
	}
	for (j = 1; j <= m; j++) {
		tmp2 = totale2;
		totale2 = tmp2 + g2[j];

	}printf("\n il totale e' %.2f\t", totale2);
	max2 = g2[1];
	for (j = 2; j <= m; j++) {
		if (g[j] > max2) {
			max2 = g2[i];
		}min2 = g2[1];
		for (j = 2; j <= m; j++) {
			if (g2[j] < min2) {
				min2 = g2[j];
			}
		}printf("\nil minimo della giornata 2 e' %.2f\t", min2);
	}printf("\nil massimo della giornata 2 e' %.2f\t", max2);
	/*----------------------------------------------------------------------*/

	printf("\nprimo giorno3\n");
	printf("\ninserire il numero di acquisto");
	scanf("%d", &me);
	for (c = 1; c <= me; c++) {
		printf("\ninserire valori\n");
		scanf("%f", &g3[c]);
	}
	for (c = 1; c <= me; c++) {
		tmp3 = totale3;
		totale3 = tmp3 + g3[c];

	}printf("\n il totale e' %.2f\t", totale3);
	max3 = g3[1];
	for (c = 2; c <= me; c++) {
		if (g3[c] > max3) {
			max3 = g3[c];
		}min3 = g3[1];
		for (c = 2;c <= me; c++) {
			if (g3[c] < min3) {
				min3 = g3[c];
			}
		}printf("\nil minimo della giornata 3 e' %.2f\t", min3);
	}printf("\nil massimo della giornata 3 e' %.2f\t", max3);

/*----------------------------------------------------------------------------*/
	printf("\nprimo giorno4\n");
	printf("\ninserire il numero di acquisto");
	scanf("%d", &je);
	for (d = 1; d <= je; d++) {
		printf("\ninserire valori\n");
		scanf("%f", &g4[d]);
	}
	for (d = 1; d <= je; d++) {
		tmp4 = totale4;
		totale4 = tmp4 + g4[d];

	}printf("\n il totale e' %.2f\t", totale4);
	max4 = g4[1];
	for (d = 2; d <= je; d++) {
		if (g4[d] > max4) {
			max4 = g4[d];
		}min4 = g4[1];
		for (d = 2; d<= je; d++) {
			if (g4[d] < min4) {
				min4 = g4[d];
			}
		}printf("\nil minimo della giornata 3 e' %.2f\t", min4);
	}printf("\nil massimo della giornata 4 e' %.2f\t", max4);

	/*----------------------------------------------------------------------------*/
	printf("\nprimo giorno5\n");
	printf("\ninserire il numero di acquisto");
	scanf("%d", &ve);
	for (v = 1; v <= ve; v++) {
		printf("\ninserire valori\n");
		scanf("%f", &g5[v]);
	}
	for (v = 1; v <= ve; v++) {
		tmp5 = totale5;
		totale5 = tmp5 + g5[v];

	}printf("\n il totale e' %.2f\t", totale5);
	max5 = g5[1];
	for (v = 2; v <= ve; v++) {
		if (g5[v] > max5) {
			max5 = g5[v];
		}min5 = g5[1];
		for (v = 2; v <= ve; v++) {
			if (g5[v] < min5) {
				min5 = g5[v];
			}
		}printf("\nil minimo della giornata 3 e' %.2f\t", min5);
	}printf("\nil massimo della giornata 5 e' %.2f\t", max5);
	somma = totale1 + totale2 + totale3 + totale4 + totale5;
	medio = somma / 5;
	printf("\n la media della settimana e' %.2f", medio);
	printf("\n il totale della settimana e' %.2f", somma);

}