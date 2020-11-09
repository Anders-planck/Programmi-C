#include<stdio.h>
main() {
	int ris, n, pr, sr, tr,b,q, i=0;
	
	printf("inserisci un numero");
	scanf("%d", &n);
		do {
			if (n > 100) {
				pr = n / 100;
				q = n - (pr * 100);
				sr = q / 10;
				tr = q - (sr * 10);
				ris = pr*sr*tr;
				i++;
				n = ris;
			}
			
			if (n < 100) {
				sr = n / 10;
				tr = n - (sr * 10);
				ris = sr*tr;
				i++;
				n = ris;
			}
		} while (ris>2);
	
	printf("\nil numero di volta fatto e' %d\n\t", i);
	printf("\nil numero ricercato e'%d\t", ris);
}