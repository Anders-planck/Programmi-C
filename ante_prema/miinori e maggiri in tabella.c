#include<stdio.h>
#define dim 40
main() {
	int a[dim],b[dim],c[dim], n,j=1, d=1,s, i;
	printf("n=");
	scanf("%d", &n);
	while (n < 1 || n>20) {
		printf(" che cazzo di numero hai inserito \n");
		printf("n=");
		scanf("%d", &n);
	}

		for (i = 1; i <= n; i++) {
			printf("inserisci  volori");
			scanf("%d", &a[i]);
		}
		printf("soglia s=");
		scanf("%d", &s);

		for (i = 1; i <= n; i++) {
			if (s > a[i]) {
				
				b[j] = a[i];
				j++;
			} 
			
		}
		
			
		for (i = 1; i <= n; i++) {
			 if (s < a[i]) {
						c[d] = a[i];
						d++;
			}

		}printf("\n\nminori\n[");
		for (i = 1; i < j; i++) {
			printf("%d\t", b[i]);
			
		}printf("]\n");
		printf("\n\nmaggior\n[");
		for (i = 1; i < d; i++) {
			printf("%d\t", c[i]);
			
		}printf("]\n");
}
