#include"bibli.h"


List push_List(List_element* L, prodotto P) {
	List_element* E;//(new);
	List_element* prec = NULL;
	List_element* curr = L;
		//F1: ricerca della posizione 
		while (curr != NULL && isless(curr, P) < 0 ) {
			prec = curr;
			curr = curr->next;
		}
		//F2 :allocazione memoria;
		E = malloc(sizeof(*E));
		Verify_Allocazione(E);
		strcpy(E->value.name, P.name);
		E->value.calori = P.calori;
		E->next = NULL;
		//F3 : ricologamento dei nodi
		if (prec == NULL) {
			E->next = L;
			L = E;
			return L;
		}
		else{
			prec->next = E;
			E->next = curr;
			return L;
		}
}

int isless(List_element* curr, prodotto P) {
	int s = strcmp(curr->value.name, P.name);
	return s;
}
boolean is_empty_list(List_element* L) {
	if (L == NULL) {
		return true;
	}
	else {
		return false;
	}
}

List Ricerca_iper_calorie(List_element* L, FILE* f) {
	prodotto x;
	while (fread(&x, sizeof(prodotto), 1, f)!=0) {
		if (x.calori > soglia)
			L = push_List(L, x);
	}
	
	return L;
}
void print_List(List_element* L) {
	List_element* tmp=NULL;
	if (!is_empty_list(L)){
		printf("\nlist vuota\n");
		return;
	}
	
	else {
		tmp = L;
		printf("\nLista prodotti iper_colorici\n");
		while (tmp->next != NULL) {
			printf("\n [ %s  -  %d ] ", tmp->value.name, tmp->value.calori);
			tmp = tmp->next;
		}
	}
}

void Verify_Allocazione(List_element* L) {
	if (L == NULL) {
		fprintf(stderr, "Errore di allocazione memoria.\n");
		exit(EXIT_FAILURE);
	}
}

void fprint_List_media(List_element* L, FILE* G) {
	float somma = 0;
	float Media;
	int j = 0;
	List_element* tmp = L;
	List_element* temp = L;
	int i = 0;
	while (tmp->next != NULL) {
		somma+= tmp->value.calori;
		tmp = tmp->next;
		i++;
	}
	Media = somma / i;
	fputs("\n\n\t\t\t\t\***********LISTA IPER_CALORI***************\n\n",G);
	while (temp->next != NULL) {
		fprintf(G, "\n%d**** %s    --  %d  Kcal*****  \n",j+1, temp->value.name, temp->value.calori);
		temp = temp->next;
		j++;
	}
	printf("\nLa Media delle calori della lista e' %f\n", Media);
	fprintf(G,"\nLa Media delle calori della lista e' %f\n",Media);
}

List clean_List(List_element* L) {
	List_element* tmp;
	tmp = malloc(sizeof(*tmp));
	Verify_Allocazione(tmp);
	if (is_empty_list(L))
		return NULL;
	if (L->next == NULL)
	{
		free(L);
		L = NULL;
		return L;
	}
	else {
		tmp = L->next;
		free(L);
		L = NULL;
		return tmp;
	}
}


List total_clean_list(List_element* L) {
	if (is_empty_list(L))
		return NULL;
	else {
		while (L != NULL) {
			L = clean_List(L);
			L = L->next;
		}
		return L;
	}

}