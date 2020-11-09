#include"bibli.h"

int main(void) {
	FILE* f = fopen("parole1.txt", "rt");
	FILE *g = fopen("uscita.txt", "wt");
	FILE* h = fopen("out.txt", "wt");
	consone V[dim];
	char vocale[10] = { 'a','e','i','u','o','A','E','I','O','U' };
	List L = NULL;
	racolta(V, f, vocale);
	L = funzioneA(f, vocale);
	stampa(L);
	printf("***************************stampa array****************************\n");
	stampa_Vet(V, dim);
	stampa_file_vet(V, h,dim);
	fclose(h);
	stampa_file(L, g);
	fclose(g);
	L=clean_list(L);
	if (L == NULL)
		printf("****************************deallocazione riuscita********************\n");
	return 0;
}