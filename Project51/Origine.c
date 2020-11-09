#include"bibli.h"

int main(void) {

	FILE* f = fopen("parole1.txt", "rt");
	FILE* g = fopen("uscita.txt", "wt");
	FILE* h = fopen("out.txt", "wt");
	tree* T = NULL;
	parole v[dimen];
	char vocale[10] = { 'a','A','e','E','i','I','u','U','o','O' };
	T = funzioneA(f, T, vocale);
	printf("********************************stampa dell albero**************************\n");
	stampa_tree(T);
	stampa_file(T, g);
	stampa_vet(T, v);
	printf("********************************stampa del vettore**************************\n");
	stampa(v);
	T = clean_tree(T);
	if (T == NULL)
		printf("\nriuscita di clean\n");
	T=insord_list(v, T);
	printf("********************************stampa dell albero**************************\n");
	stampa_tree(T);
	printf(" max: \t%d\n", massimo(T,max));
	stampa_file_vet(v, h);
	fclose(h);
	fclose(g);
	return 0;
}