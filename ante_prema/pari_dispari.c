#include<stdio.h>
#define dim 100
main() {
	int n, m = 0, d = 0, i, a[dim];

	printf("\nil numero va considerato da 0 a 100\n inserisci un altro numero ");
	scanf("%d", &n);
	m = 0;
	while (n<0 || n>dim) {
		printf("\nil numero va considerato da 0 a 100\n inserisci un altro numero ");
		scanf("%d", &n);
	}
	for (i = 0; i <= n - 1; i++) {
		printf("\ninserisci valori ");
		scanf("%d", &a[i]);
	}
	for (i = 0; i <= n - 1; i++) {
		if (a[i] % 2 == 0) 
			m = m++;
		else 
			d = d++;

	}printf("\ni numeri pari sono in\t %d ", m);
	printf("\ni numeri dispari sono in\t %d ", d);
}