#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define len 20
#define max 100
typedef struct {
	int dim;
	int A[max];
}tstack;


typedef struct {
	char c[max];
}Ar;


typedef struct {
	int dim;
	Ar B[max];
}stack;

bool Is_Empty(stack* pila_1) {
	return pila_1->dim == 0;
}

bool Is_Full(stack* pila_1) {
	return pila_1->dim == max;
}


void estrae_tstack(stack* pila_1,char D[]) {
	strcpy(D, pila_1->B[pila_1->dim-1].c);
	pila_1->dim--;
}

void aggunggere_tstack(stack* pila_1, char E[]) {
	strcpy(pila_1->B[pila_1->dim].c, E);
	pila_1->dim++;
}

void distruiggere_tstack(stack* pila_1) {
	pila_1->dim = 0;
}
stack crea_stack() {
	stack pila_1;
	pila_1.dim = 0;
	return pila_1;
}

/*

int estrae_stack(tstack*pila) {
	int x = pila->A[pila->dim-1];
	pila->dim--;
	return x;
}

void aggunggere_stack(tstack*pila, int x){
	pila->A[pila->dim] = x;
	pila->dim++;
}

void distruiggere_stack(tstack*pila) {
	pila->dim = 0;
}
tstack crea_tstack() {
	tstack pila;
	pila.dim = 0;
	return pila;
}*/
main() {
	int x;
	int i;
	int c,e;
	char E[len];
	char D[len];
	//tstack pila;
	stack pila_1;
	/*pila =crea_tstack();
	distruiggere_stack( &pila);
	printf("inserisci il numero d elemento\t");
	scanf("%d", &x);
	for (i = 0; i < x; i++) {
		printf("numero\t");
		scanf("%d", &e);
		aggunggere_stack(&pila, e);
	}	
	for (i = 0; i < x; i++) {
		c = estrae_stack(&pila);
		printf("il tuo numero e \t%d\n", c);
	}	
	*/

	i = 0;
	pila_1 = crea_stack();
	printf("inserisci il numero d elemento\t");
	scanf("%d", &x);
	for (i = 0; i < x; i++) {
		printf("parola\t");
		scanf("%s", E);
		aggunggere_tstack(&pila_1, E);
		printf("\n");
	}
	if (Is_Empty(&pila_1) == true) {
		printf("vuoto\n");
	}
	else if (Is_Full(&pila_1) == true) {
		printf("pieno\n");
	}
	else {
		printf("niente\n");
	}
	printf("\t\t\t\t");
	for (i = 0; i < x; i++) {
		 estrae_tstack(&pila_1,D);
		printf(" %s ", D);
	}
	printf("\n\n\n\n\n");
}





