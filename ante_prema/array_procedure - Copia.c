#include<stdio.h>
#define dim 100

void stampa (int x[], int n) {
	int i;
	printf("\n[");
	for (i = 0; i < n; i++) {
		printf("%d  ", x[i]);
	}
	printf("]");
}


void lettura(int a[],int b[],int *s,int*n,int*c) {
	int i=0,j=0;
	do  {
		printf("inserire il  %d valore dell array:\n", i+1);
		scanf("%d", &a[i]);
		i++;
	} while (a[i-1] != -1);
	*n = i-1;
	printf("\n%d", *n);
	printf("\nverifica\n");
	stampa(a, *n);
	printf("\nqual 'e la soglia che vuoi stabilire?:\t");
	scanf("%d", s);
	for (i = 0; i < *n; i++) {
		if (a[i] < *s) {
			b[j] = 0;
			j++;
		}
		else if (a[i] >= *s) {
			b[j] = a[i];
			j++;
		}
	}*c = j;
}
main() {
	int n;
	int c;
	int s;
	int a[dim];
	int b[dim];
	lettura(a,b,&n,&s,&c);
	printf("\nrisultatato:\n");
	stampa(b, c);
	
}