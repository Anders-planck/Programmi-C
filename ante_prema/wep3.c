#include<stdio.h>
main() {
	int c, b, d, i, n,e,j, f, g, h;
	printf("inserire un numero");
	scanf("%d", &n);
	i = 0;
	j = 0;
	e = n;
	do {
		
		
		n = n + i;
			c = n / 10;
		b = n % 10;
		d = (b + c) / 2;
		i++;
		
		e = e - j;
		f = e / 10;
		g = e % 10;
		h = (g + f) / 2;
		j++;
	} while (d != b || h != g);
	if (i < j) {
		printf("\nil palindromo vicino e'%d\t", n);
	}
	else if (i>=j) {
		printf("\nil palindromo vicino e'%d\t",e);
	}

}