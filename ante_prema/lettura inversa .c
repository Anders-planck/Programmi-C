#include<stdio.h>
#define dim 100
main() {
	int n, a[dim],i;
	char c;
	printf("inserisci un numero");
	scanf("%d", &n);
	while (n < 0 || n>dim) {
		printf("il numero deve essere compreso tra 0 e 100");
		printf("inserisci un numero");
		scanf("%d", &n);
	} for (i = 1; i <= n; i++) {
		printf("inscerisci valori");
		scanf("%d", &a[i]);
	}
	printf("\nvuole che la sequenza si stanpata in ordine:\ts=lo stesso,\ti=inverso\n");
	scanf("\n%c", &c);
	if (c == 's') {
		for (i = 1; i <= n; i++) {
			printf("\n ecco i volori imseriti\n %d", a[i]);
		}
		
	}
	else if (c == 'i') {
		for (i = n; i >= 1; i--) {
			printf("\n ecco i volori inseriti\n %d", a[i]);
		}
	}




}