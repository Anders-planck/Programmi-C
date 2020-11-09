#include <stdio.h>
#define dim 4
main() {
	int a[dim],stella,j, i;
		for (i = 1; i <= dim; i++) {
			printf("inserisci  volori");
			scanf("%d", &a[i]);
		}
		for (i = 1; i <= dim; i++) {
			stella = a[i];
			for (j = 1; j <= stella; j++) {
				printf("*");
			}printf("\n");
		}
}