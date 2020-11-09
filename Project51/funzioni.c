#include"bibli.h"

Tree funzioneA(FILE* f, Tree T, char vocale[]) {
	parole parola;
	while (!feof(f)) {
		fscanf(f, "%s", parola.parola);
		parola.visto = 1;
		if (ricerca(vocale, parola.parola) == 1)
			T = push_tree(T, parola);
	}
	fclose(f);
	return T;
}

Tree New_albero(parole parola) {
	tree* t = (tree*)malloc(sizeof(tree));
	t->letf = NULL;
	t->reight = NULL;
	strcpy(t->x.parola, parola.parola);
	t->x.visto=parola.visto;
	return t;
}


tree* push_tree(tree* T, parole parola) {
	if (T == NULL)
		return New_albero(parola);
	else {
		if (strcmp(parola.parola, T->x.parola) < 0)
			T->letf = push_tree(T->letf, parola);
		else T->reight = push_tree(T->reight, parola);
		return T;
	}
}

int ricerca(char vocale[], char parola[]) {
	int i = 0;
	int gia = 0;
	while (i < 10 && gia != 1) {
		if (parola[0] == vocale[i])
			gia = 1;
		i++;
	}
	return gia;
}

void stampa_tree(tree* T) {
	if (T != NULL) {
		stampa_tree(T->letf);
		printf(" **** %s\t %d\n", T->x.parola,T->x.visto);
		stampa_tree(T->reight);
	}
}

void stampa_file(Tree T, FILE* g) {
	if (T == NULL)
		return;
	else {
		stampa_file(T->letf, g);
		fprintf(g, " **** %s\t%d", T->x.parola, T->x.visto);
		stampa_file(T->reight, g);
		return;
	}
}

void stampa_vet(Tree T, parole v[]) {
	if (T == NULL)
		return;
	else {
		stampa_vet(T->letf, v);
		if (ricerca_vet(T->x.parola, v) == 0) {
			strcpy(v[i].parola, T->x.parola);
			v[i].visto = 1;
			i++;
		}
		else {
			implementa(T->x.parola, v);
		}
		stampa_vet(T->reight, v);
	}
}
void implementa(char parola[], parole v[]) 
{
	int k = 0,gia=0; while (k < i && gia!=1) {
		if (strcmp(parola, v[k].parola) == 0) 
		{
			v[k].visto++; gia = 1;
		}
		k++;
	}
}
int ricerca_vet(char parola[], parole v[])
{
	int k = 0,gia=0; while (k < i && gia!=1) {
		if (strcmp(parola, v[k].parola) == 0)
			gia = 1;
		k++;
	}
	return gia;
}

void stampa(parole v[]) {
	if (j > i - 1)
		return;
	else {
		printf("**** %s\t%d\n", v[i - (i - j)].parola, v[i - (i - j)].visto);
		j++;
		stampa(v);
	}
}

void stampa_file_vet(parole v[], FILE* h) {
	if (c > i - 1)
		return;
	else {
		fprintf(h, "\t%s >><>>>>>\tricurenza:\t %d\n", v[i - (i - c)].parola, v[i - (i - c)].visto);
		c++;
		stampa_file_vet(v, h);
	}
}
tree* clean_tree(tree* li) {
	if (li != NULL)
		return NULL;
	else {
		clean_tree(li->letf);
		free(li);
		li = NULL;
		clean_tree(li->reight);
		return li;
	}
}
tree* insord_list(parole v[], tree* T) {
	int k = 0; while (k < i) {
		T = push_tree(T, v[k]);
		k++;
	}
	return T;
}

int massimo(tree* T, int max) {
	if (T == NULL)
		return max;
	if (max < T->x.visto) {
		max = T->x.visto;
		max = massimo(T->letf, max);
	}
	else
		max = massimo(T->reight, max);
}/////////////////////////////////////////////////////////////ricerca del maximo////////////////////////////////////////////////////////////////////