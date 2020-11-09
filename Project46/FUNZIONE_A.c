#include"BIBLI.h"
t_albero lettura_file_albero(Albero*T, FILE*f_file_1) {
	prodotto x;
	while (fread(&x, sizeof(prodotto), 1, f_file_1)) {
		T = Push_albero(T, x);
	}
	
	return T;
}

Albero* Push_albero(t_albero T, prodotto x) {
	Albero* f = new_albero(x);
	if (T == NULL) {
		T = new_albero(x);
		return T;
	}
	else {
		if (strcmp(f->value.nome, T->value.nome)<0 ) 
			T->sinistro = Push_albero(T->sinistro, x);

		else 
			T->destro = Push_albero(T->destro, x);			
		return T;
	}
}

t_albero new_albero(prodotto x) {
	Albero* tmp=NULL;
	tmp = (Albero*)malloc(sizeof(Albero));
	if (tmp == NULL) {
		fprintf(stderr, "ERRORE DI ALLOCAZIONE MEMORIA.\n");
		exit(EXIT_FAILURE);
	}
	tmp->destro = NULL;
	tmp->sinistro = NULL;
	tmp->parent = NULL;
	strcpy(tmp->value.nome, x.nome);
	tmp->value.N_scatole = x.N_scatole;
	return tmp;
}


void print_albero_ordinato_prefixo(t_albero T) {
	if (is_empty_albero(T)) {
		print_albero_ordinato_prefixo(T->sinistro);
		printf("( %s --- %d )\n", T->value.nome, T->value.N_scatole);
		print_albero_ordinato_prefixo(T->destro);
	}
}
void clean_albero(Albero* T) {
	if (T == NULL)
		return;
	else {
		Albero* tmp = T;
		printf("cancellazione di %s____%d\n", T->value.nome, T->value.N_scatole);
		clean_albero(T->sinistro);
		clean_albero(T->destro);
		free(tmp);
	}
	
}
int count_nodo_albero(t_albero tr) {
	if (tr == NULL)
		return 0;
	return (count_nodo_albero(tr->sinistro) + count_nodo_albero(tr->destro) + 1);
}