#include<stdio.h>
#define dim 30
main() {
	int n, a[dim], z, i=1;
	printf("n=");
	scanf("%d", &n);
	while (n < 1 || n>30) {
		printf("\nmi prendi per ill culo\n ");
		printf("\ninseriscine un altro\m");
		scanf("%d", &n);
	}
	for (i = 1; i <= n; i++) {
		printf("\ninserisci un numero\n");
		scanf("%d", &a[i]);
	}
	for (i = 1; i <= n; i++) {
		printf("%d\t", a[i]);
	}
	z = 1;
	for (i = 1; i <= n && z == 1; i++) {
		if (a[i] <= a[i - 1]) 
			z = 0;
	}
	if (z == 0) {
printf("\nnon e ordinato\n");
	}
	else {
printf("%d\t", a[i]);
	}
	
	
}