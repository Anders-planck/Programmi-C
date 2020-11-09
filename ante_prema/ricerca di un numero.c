#include<stdio.h>
#define dim 100
main() {
	int i,a[dim],n,c;
	printf("inserisci un numero ");
	scanf("%d", &n);
	while (n < 0 || n>dim){
		printf("\n devi inserire un valore N compreso tra 0 e 100");
		printf("inserisci un numero ");
		scanf("%d", &n);
		}
	for (i = 1; i <= n; i++) {
		printf("inserisci valori");
		scanf("%d",&a[i]);
	}
	printf("inserisci il valore da ricercare");
	scanf("%d", &c);
	for (i = 1; i <= n; i++) {
		if (c == a[i]) {
			printf(" \nio l ho trovato in posizione \t %d:", i);
		}
	}

	
}