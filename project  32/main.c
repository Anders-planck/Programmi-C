#include"determinante.h"

int main() {
	double data1[] = { 1,2,5,1,
					   1,4,-1,1,
					   2,0,9,1,
					   4,5,5,-1 };

	struct matrix m1 = { 4,4,data1 };
	double det1, flag1 = false;
	printf("---la matrice di partenza e:---\n");
	stampa(&m1);
	printf("---reduzione a gradini:---\n ");
	determinante(&m1, &det1, &flag1);
	printf("il determinante della matrice e: %lf\n", det1);



	return 0;
}