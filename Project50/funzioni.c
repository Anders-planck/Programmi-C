#include"bibli.h"

Tree funzioneA(FILE* f, Tree T,char vocale[]) {
	char parola[len];
	while (!feof(f)) {
		fscanf(f, "%s", parola);
		if (ricerca(vocale, parola) == 1)
			T = push_tree(T, parola);
	}
	fclose(f);
	return T;
}
Tree New_albero(char parola[]) {
	tree* t = (tree*)malloc(sizeof(tree));
	t->letf = NULL;
	t->reight = NULL;
	strcpy(t->parola, parola);
	return t;
}


tree* push_tree(tree* T, char parola[]) {
	if (T == NULL)
		return New_albero(parola);
	else {
		if (strcmp(parola, T->parola) < 0)
			T->letf = push_tree(T->letf, parola);
		else T->reight = push_tree(T->reight, parola);
		return T;
	}
}

int ricerca(char vocale[], char parola[]) {
	int i = 0;
	int gia = 0;
	while (i < 10 && gia!=1) {
		if (parola[0] == vocale[i])
			gia = 1;
		i++;
	}
	return gia;
}

void stampa_tree(tree* T) {
	if (T != NULL) {
		stampa_tree(T->letf);
		printf(" **** %s\n", T->parola);
		stampa_tree(T->reight);
	}
}

void stampa_file(Tree T, FILE* g) {
	if (T == NULL)
		return;
	else {
		stampa_file(T->letf, g);
		fprintf(g, " %s \n", T->parola);
		stampa_file(T->reight, g);
		return;
	}
}

void stampa_vet(Tree T, parole v[]) {
	if (T == NULL)
		return;
	else {
		stampa_vet(T->letf, v);
		strcpy(v[i].parola, T->parola);
		i++;
		stampa_vet(T->reight, v);
	}
}

void stampa(parole v[]) {
	if (j>i-1)
		return;
	else {
		printf("**** %s \n", v[i - (i - j)].parola);
		j++;
		stampa(v);
	}
}

void stampa_file_vet(parole v[], FILE *h) {
	if (c > i - 1)
		return;
	else {
		fprintf(h,"\t%s \n", v[i - (i - c)].parola);
		c++;
		stampa_file_vet(v,h);
	}
}