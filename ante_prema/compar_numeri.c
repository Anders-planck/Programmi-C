#include<stdio.h>
void minmax(int a, int b, int c, int*min, int*max) {
	if (a <= b && b <= c) {
		*max = c;
		*min = a;
	}
	else if (a <= c && c <= b) {
		*max = b;
		*min = a;
	}
	else if (c <= b && b <= a) {
		*max = a;
		*min = c;
}
	else if (b <= c && c <= a) {
		*max = a;
		*min = b;
	}
	else if (c <= a && a <= b) {
		*max = b;
		*min = c;
	}
	else if (c == a && a == b) {
		*max = b;
		*min = c;
	}
}

main() {
	int a, b, c;
	int min, max;
	printf("inserire numeri :\n");
	scanf("%d%d%d", &a, &b, &c);
	minmax(a, b, c, &min, &max);
	printf("\nil massimo e':\t%d\nil minimo e':%d", max, min);
}