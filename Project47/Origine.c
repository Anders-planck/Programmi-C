#include"BIBLI.h"

void main() {
	prodotto* pranzo=NULL;

	int n;
	FILE* f=fopen("alimenti.bin","rb");
	if (f == NULL) {
		printf("Eroore nell apertura del file 1.\n");
		exit(EXIT_FAILURE);
	}
	List_element* L = new_List();
	L = Push_on_List(f, L);
	fclose(f);
	print_List(L);
	FILE* g = fopen("pranzo.txt", "rt");
	if (g == NULL) {
		printf("Errore nell apertura del file 2.\n");
		exit(EXIT_FAILURE);
	}
	pranzo = carico_Array(g,&n);
	stampa(pranzo, n);
	pranzo=Ordina_array(pranzo, n);
	stampa(pranzo, n);
	fclose(g);
	 FILE* h = fopen("out.txt","wt");
	 if (h == NULL) {
		 printf("Eroore nell apertura del file 3.\n");
		 exit(EXIT_FAILURE);
	 }
	 scrivi_On_File(pranzo, n, h,L);
	 fclose(h);
	 //free(pranzo);
	 L = total_clean_list(L);
	 if (L == NULL)
		 printf("Deallocazione confermata.\n");
	 return;
}