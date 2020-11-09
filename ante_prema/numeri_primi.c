#include<stdio.h> 
int primo(int x) {
	int i=1;
	int cont = 0;
	while (cont<3 && i<=(x/2) ) {
		if (x % i == 0)
		cont++;
		i++;
	}
	if (cont == 1)
		return 1;
	else
		return 0;
}
main() {
	int n;
	int i,z=0;
	int p;
	printf("inserire un numero");
	scanf("%d", &n);

	p=primo(n);
	
	if (p == 1) {
		printf("il numero da lei inserito è primo\n");
	}
	else {
		printf("il numero non lo e'");
	}
	int s;
	printf("\ninserisci un numero");
	scanf("%d", &s);
	for (i = 1; i <= s; i++) {
		p = primo(i);
		if (p == 1) {
			
			printf("%d\t", i);
			z++;
		}
	}
	if(z==0)
		printf("non c'e un numero primo");
	
}