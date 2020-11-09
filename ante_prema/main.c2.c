#include<stdio.h>

main() {
	int ris,n,pr,sr,tr,i;
	float b;
	printf("inserisci un numero");
	scanf("%d", &n);
	do {
		if (n >= 1000) {
			pr = n%1000;
			sr = pr % 100;
			tr = sr % 10;
			ris = pr*sr*tr;
			i++;
			b = ris/ 10;
		}
	
	} while (b < 1);
	printf("il numero di volta fatto e' %d", i);
	printf("il numero ricercato e'%d", ris);
}