#include"bibli.h"

int main(void) {
	FILE* f = fopen("alimenti.bin", "rb");
	FILE* G = fopen("iper.txt", "wt");
	List_element* L = NULL;
	/*-------------------------------------------------*/
	if (f == NULL) {
		fprintf(stderr, "Errore di Appertura del file .1\n");
		exit(EXIT_FAILURE);
	}
	if (G == NULL) {
		fprintf(stderr, "Errore di Creazione del file .2\n");
		exit(EXIT_FAILURE);
	}
	/*------------------------------------------------*/

	L = Ricerca_iper_calorie(L, f);
	print_List(L);
	fprint_List_media(L, G);
	

	/*------------------------------------------------*/

	fclose(f);
	fclose(G);
	L = total_clean_list(L);
	
	return 0;
}