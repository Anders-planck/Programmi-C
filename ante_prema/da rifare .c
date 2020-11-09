#include<stdio.h>
#include<math.h>
#include<string.h>
//dichiarazione costante
#define dim 100
//dichiarazione procedura di stampa
void stampa(int c[], int Nc) {
	int i;
	printf("%d",Nc);
	printf("Nouvo Array=[ ");
	for (i = 0; i < Nc; i++) {
		printf("%d  ", c[i]);
	}printf("]");
}
//dichiarazione procedura di eliminazione
void elimina_elementi(int a[], int b[], int c[], int Na, int Nb, int*Nc) {
	int i = 0;
	int j = 0;
	int k = 0;
	int f = 0;
			
	*Nc = k;


//dichiarazione procedura di  lettura
void lettura(int a[], int *Na) {
	int i=0;
	int c = 0;
	printf("inserisci elementi dell Array che si teminerano da un -1\n");
	while (a[i - 1] != -1) {
		printf("\n");
		scanf("%d", &a[i]);
		i++;
		c++;
	}*Na = c - 1;
}
main() {
//dichiarazione variabile
	int a[dim];
	int b[dim];
	int c[dim];
	int Na, Nb, Nc=0;
//lettura imput(1)
	lettura(a, &Na);
//lettura imput(2)
	lettura(b, &Nb);
// elaborazione
	elimina_elementi(a, b, c, Na, Nb, &Nc);
//stampa output
	stampa(c, Nc);
}