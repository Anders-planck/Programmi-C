#include<stdio.h>
#include<string.h>
#define dim 100

typedef  struct direzione
{
	char sens[dim];
int metri;
}inst;
int val_assoluto(int x) {
	int v;
	if (x < 0) {
		v = -x;
		return v;
	}
	else {
		v = x;
		return v;
	}
}

main() {
	inst a[dim], fin[dim];
	int b;
	printf("quanti inst vuoi inscrivere");
	scanf("%d", &b);
	int i = 1, c = 1, x=0, y=0;
	
	for (i = 1; i <= b; i++) {
		printf("inserire la %d coordinata\n (N,S,O,E):\t", i);
		scanf("%s", a[i].sens);
		printf("\ninserire il numero di metri:\t");
		scanf("%d", &a[i].metri);
	}
	for (i = 1; i <= b; i++) {
		printf("\n%s\t%d", a[i].sens, a[i].metri);
	}
	printf("\n\n\n");
	for (i = 1; i <= b; i++) {
		if (strcmp(a[i].sens, "nord") == 0)
			y = y + a[i].metri;
		if(strcmp(a[i].sens, "sud") == 0)
			y = y - a[i].metri;
		if (strcmp(a[i].sens, "est") == 0)
			x=x+ a[i].metri;
		if (strcmp(a[i].sens, "ovest") == 0)
			x = x - a[i].metri;
		}
	if (y > 0)printf("Nord\t%d", y);
	else printf("sud\t%d", -y);
	if (x > 0)printf("est\t%d", x);
	else printf("ovest\t%d", -x);
	}

	