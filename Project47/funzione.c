#include"BIBLI.h"


List new_List() {
	return NULL;
}

List push_List(List_element* li, prodotto x) {
		List_element*new = NULL;
		List_element* prec = NULL;
		List_element* curr = NULL;
		//Ricerca posizione ...
		curr = li;
		while (curr!= NULL && strcmp(x.nome, curr->x.nome) > 0) {
				prec=curr;
			curr = curr->Next;
		}
		//allocazione in memoria...
		new = malloc(sizeof(*new));
		if (new == NULL) {
			fprintf(stderr, "Errore di allocazione memoria.\n");
			exit(EXIT_FAILURE);
		}
		strcpy(new->x.nome, x.nome);
		new->x.N_scatole = x.N_scatole;
	new->Next = NULL;
		//ricollogamento ...
		if (prec == NULL) {
			new->Next = li;
			li=new;
			return li;
		}
		else {
			prec->Next = new;
			new->Next = curr;
			return li;
		}
}
bool is_empty_List(List li) {
	if (li == NULL)
		return true;
	return false;
}
void print_List(List li) {
	List tmp=li;
	size_t i = 0;
	while (tmp->Next != NULL) {
		printf("%d**** %s --- %d \n",i+1, tmp->x.nome, tmp->x.N_scatole);
		tmp = tmp->Next;
		i++;
	}
}

List  Push_on_List(FILE* f, List L) {
	prodotto x;
	while (fread(&x, sizeof(x), 1, f)) {
		L = push_List(L, x);
	}
	return L;
}

prodotto* carico_Array(FILE* g,int *n) {
	prodotto* s = NULL;
	int i = 0;
	s =(prodotto*) malloc(sizeof(*s));
	if (s == NULL) {
		fprintf(stderr, "Errore di allocazione memoria.\n");
		exit(EXIT_FAILURE);
	}
	while (!feof(g)) {
		fscanf(g, "%s %d", s[i].nome, &(s[i].N_scatole));
		i++;
	}
	*n = i;
	return s;
}
void stampa(prodotto* pranzo, int n) {
	int i;
	printf("\n\n\n\t\t\tstampa array\n");
	for (i = 0; i < n; i++) {
		printf("%d**** %s --- %d \n", i + 1, pranzo[i].nome, pranzo[i].N_scatole);
	}
}

prodotto* Ordina_array(prodotto* pranzo, int n) {
	List_element* l = new_List();
	prodotto* s=NULL;
	s =(prodotto*) malloc(sizeof(*s));
	int i = 0;
	for ( i = 0; i < n; i++) {
		l = push_List(l, pranzo[i]);
	}
	List_element* tmp=l;
	i = 0;
	while (tmp != NULL && i<n) {
		strcpy(s[i].nome, tmp->x.nome);
		s[i].N_scatole = tmp->x.N_scatole;
		tmp = tmp->Next;
		i++;
	}
	return s;
}
List total_clean_list(List L) {
	if (is_empty_List(L))
		return NULL;
	if (L->Next == NULL) {
		free(L);
		return NULL;
	}
	else
		return total_clean_list(L->Next);
}


void scrivi_On_File(prodotto* pranzo, int n, FILE* h,List L) {
	int i=0,j=0;
	fprintf(h, "\t\t*********Stampa Alimenti Da Consegnare**********\n");
	printf("\t\t*********Stampa Alimenti Da Consegnare**********\n");
	while (i < n) {
		if (ricerca(pranzo[i], L)) {
			fprintf(h, "%d***** %s  --  %d \n",j+1, pranzo[i].nome, pranzo[i].N_scatole);
			printf("%d *****%s  --   %d \n", j + 1, pranzo[i].nome, pranzo[i].N_scatole);
			j++;
		}
		i++;
	}
	fprintf(h, "\t\t**************FINE*************\n");
	printf("\t\t**************FINE*************\n");
}


bool ricerca(prodotto f, List L) {
	List tmp=L;
	while (tmp != NULL) {
		if (strcmp(f.nome, tmp->x.nome) == 0 && f.N_scatole <= tmp->x.N_scatole)
			return true;
		tmp = tmp->Next;
	}
	return false;
}