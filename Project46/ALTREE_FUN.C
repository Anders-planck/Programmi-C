#include"BIBLI.h"


booleano is_empty_albero(Albero* T) {
	if (T == NULL)
		return true;
	return false;
}

void print_albero_file(t_albero T, FILE* f_file_2, FILE* f_file_3) {
	prodotto P,y;
	Albero* x=NULL;
	x =(Albero*) malloc(sizeof(Albero));
	printf("\n****************LISTA ALIMENTI DA CONSEGNARE*************\n");
	fputs("\n****************LISTA ALIMENTI DA CONSEGNARE*************\n", f_file_3);
	while (!feof(f_file_2)) {
		fscanf(f_file_2, "%s %d", P.nome, &(P.N_scatole));
		x = ricerca_albero(T, P);
		if (P.N_scatole <= x->value.N_scatole) {
			fprintf(f_file_3, "************* %s -------->  %d  ordinati*************\n", P.nome, P.N_scatole);
			printf("************ %s -------->  %d  ordinati****************\n", P.nome, P.N_scatole);
		}
	}
	free(x);
}


t_albero ricerca_albero(Albero* T, prodotto P) {   
	if (T==NULL || strcmp(P.nome, T->value.nome) == 0) 
		return T;
	else {
		if (strcmp(P.nome, T->value.nome) > 0) 
			return  ricerca_albero(T->destro, P);
		else
			return ricerca_albero(T->sinistro, P);
	}
}