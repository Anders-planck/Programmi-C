#include<stdio.h>
int espo(int c,int b) {
	int d=1,i;
	for (i =0; i < b; i++)
		d = d*c;
	return d;
}
main() {
	int a;
	int b;
	printf("inserisci un numero");
	scanf("%d", &a);
	printf("inserisci un numero");
	scanf("%d", &b);
	a = espo(a,b);
	printf("\n a=%d\n",a);
}