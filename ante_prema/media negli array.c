#include<stdio.h>
#define dim 100
main() {
	int n,m, i,a[dim];
	char c;
	float somma=0, media=0;
	printf("\nil numero va considerato da 0 a 100\n inserisci un altro numero ");
	scanf("%d", &n);
	m = 1;
	while (n<0 || n>dim) {
		printf("\nil numero va considerato da 0 a 100\n inserisci un altro numero ");
		scanf("%d", &n);
	}
	for (i = 1; i <= n; i++) {
		printf("\ninserisci valori ");
		scanf("%d", &a[i]);
	}
	for (i = 1; i <= n; i++) {
		somma = somma;
		somma = (somma + a[i]);
			
	}media = somma / n;
	printf("\nla media dei valori e'\t %.3f\n", media);
	printf("come vuole stampare i valori :\n\t:'<'=minore o uguale\t'>'=maggiore\n");
	scanf("\n%c", &c);
	if (c == '<') {
		for (i = 1; i <= n; i++) {
			if (media >= a[i]) {
				printf("\n %d \t", a[i]);
			}	
		}
	}
	if (c == '>') {
		for (i = 1; i < n; i++) {
			if (media < a[i]) {
				printf("\n%d\t", a[i]);
			}
		}



	}
}