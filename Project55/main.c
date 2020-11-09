#include"fun.h"

main() {
	list L = NULL;
	FILE* f = fopen("progetti.bin", "rb");
	assert(f != NULL);
	FILE* g = fopen("offerte.bin", "rb");
	assert(g != NULL);
	FILE* h = fopen("teoria", "wt");
	assert(h != NULL);

	L = FunzionA(L, f, g);

	printf("LISTA:\n");
	FunzionB(L);

	FunzionC(L);

	int tot=FunzionD(L);
	printf("il numero totale di offerte di offerte di CESA e' %d\n", tot);
	   
	Esercizio2(h);


	fclose(f);
	fclose(g);
	return 0;
}