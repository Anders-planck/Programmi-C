#include"bibli.h"

List funzioneA(FILE* f, char vocale[]) {
	list* L = NULL;
	char parola[len];
	while (!feof(f)) {
		fscanf(f, "%s", parola);
		if (riconoscimento(vocale, parola) == 1)
			L = push_list(L, parola);
	}
	fclose(f);
	return L;
}


int riconoscimento(char vocale[], char parola[]) {
	int gia = 0;
	size_t i=0;
	while (i<9 && gia!=1) {
		if (vocale[i] == parola[0])
			gia = 1;
		i++;
	}
	return gia;
}

List push_list(list* L, char parola[]) {
	if (L == NULL)
		return New_list(parola);
	else {
		List New=NULL;
		List prec = NULL;
		List curr=L;
		while (curr != NULL && strcmp(parola, curr->parola) > 0) {
				prec = curr;
			curr = curr->next;
		}
		New = New_list(parola);
		New->next = curr;
		if (prec == NULL)
		{
			New->next = L;
			L = New;
			return L;
		}
		else {
			prec->next = New;
			New->next = curr;
			return L;
		}
	}
}


list* New_list(char parola[]) {
	List li = NULL;
	li = (List)malloc(sizeof(list));
	li->next = NULL;
	strcpy(li->parola, parola);
	return li;
}

void stampa(List L) {
	if (L == NULL) {
		printf("\t\t\t\tlista vuota.\n");
		return;
	}
	int i = 0;
	printf("*******************parole con vocale**********************+\n");
	while (L !=NULL) {
		printf("%d** %s \n", i + 1, L->parola);
		L=L->next;
		i++;
	}
}

void stampa_file(list* L, FILE* g) {
	if (L == NULL)
		return;
	else {
		fprintf(g, "\t%s\n", L->parola);
		stampa_file(L->next, g);
	}
}
void stampa_file_vet(consone V[], FILE* h,int n) {
	if (n < 0)
		return;
	else {
		if (c < dim) {
			fprintf(h, " %s\t\n", V[n - (n - c)].parola);
			c++;
			stampa_file_vet(V, h, n - 1);
		}
		else return;
	}
}

void  racolta(consone V[], FILE* f, char  vocale[]) {
	int i=0;
	char parola[len];
	List li=NULL;
	while (i < dim) {
		fscanf(f, "%s", parola);
		if (riconoscimento(vocale, parola) == 0) {
			li = push_list(li, parola);
			i++;
		}
	}
	qsort(li, V);
}

void qsort(list*li, consone V[]) {
	if (li == NULL)
		return;
	else {
		strcpy(V[i].parola, li->parola);
		i++;
		qsort(li->next, V);
	}
}
void stampa_Vet(consone V[],int n) {
	if (n < 0)
		return;
	else {
		if (j < dim) {
			printf(" %s \n", V[n - (n - j)].parola);
			j++;
			stampa_Vet(V, n - 1);
		}
		else return;
	}
}

List clean_list(List L) {
	if (L == NULL)
		return NULL;
	else {
		List tmp;
		tmp = malloc(sizeof(*tmp));
		tmp = L->next;
		free(L);
		L = NULL;
		return	clean_list(tmp->next);
	}
}