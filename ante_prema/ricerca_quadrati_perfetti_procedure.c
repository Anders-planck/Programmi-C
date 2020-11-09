#include<stdio.h>
#include<math.h>
void quadratoPerfett(int a, int*o, int*r) {
	int cont = 0;
	int i, t = 0;
	for (i = 0; i < a; i++) {
		if (i*i == a) {
			cont++;
			t = a;
		}
	}
	if (t != 0)
		*r = t;
	*o = 0;
	if (cont == 1)
		*o = 1;	
}
	
void quadratoPerfetto(int a, int*o, int*r) {
	int cont = 0;
	int i;
	for (i = 0; i < a; i++) {
		if (i*i==a) {
			cont++;
		}
	}
	if (cont == 1) {
		*o = 1;
		*r = (int)sqrt(a);
	}
	else 
		*o = 0;
}

main()
{
	int a;
	int r;
	int o;
	int i;
	printf("inserire un numero\t");
	scanf("%d", &a);
	quadratoPerfetto(a, &o, &r);
	if (o == 1) {
		printf("\nil numero inserito e' un quadrato perfetto\nla sua radice e':\t%d\n", r);
	}
	else {
		printf("\nil numero inserito non e' un quadrato perfetto\n");
		for (i = 0; i < a; i++) {
			quadratoPerfett(i,&o, &r);
			if (o == 1) 
				printf("\t%d", r);
		}

	}
}/*while (i<a) {
	if (a % i == 0 && cont == 0) {
		t = i;
		cont++;
	}
	if (a % i == 0 && cont != 0) {
		if (t*i == a) {
			cont++;
		}
	}
	i++;*/