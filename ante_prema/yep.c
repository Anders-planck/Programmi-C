#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
main() {
	int a,q=0,r=0,b;
	printf("inserisci un numero");
	scanf("%d", &a);
	printf("inserisci un numero");
	scanf("%d", &b);
	while (a < 0 || b < 0) {
		printf("problema con i numeri\n\n");
		printf("inserisci un numero");
		scanf("%d", &a);
		printf("inserisci un numero");
		scanf("%d", &b);
	}
	 if (b== 0) {
		printf("il MCD tra i tue due nimeri e'%d", a);
	}
	else  {
		do {
			q = a / b;
			r = a%b;
			a = b;
			b = r;

		} while (b != 0);
		printf("\nil MCD tra i tue due numeri e'%d\t", a);
		
	}


}