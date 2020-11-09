#include"bibi.h"

//////perché l allocazione memoria non fonziona da cercare .................
tree* new_albero(char c[]) {
	Tree t=NULL;
	t = (tree*)malloc(sizeof(tree));
	if (is_empty_albero(t)) {
		fprintf(stderr, "Errore di allocazione.\n");
		exit(EXIT_FAILURE);
	}
	t->left = NULL;
	t->right = NULL;
	strcpy(t->parola, c);
	return t;
}

booleano is_empty_albero(tree* t) {
	if (t == NULL)
		return true;
	return false;
}

tree* push_on_Tree(tree* li, char c[]) {
	if (is_empty_albero(li))
		return new_albero(c);
	else {
		if (strcmp(c,li->parola) < 0)
			li->left = push_on_Tree(li->left, c);
		else
			li->right = push_on_Tree(li->right, c);
		return li;
	}
}

tree* insord_on_tree(tree* li, FILE* f,FILE*g) {
	if (f == NULL) {
		printf("Errore di appertura 1.\n");
		exit(-1);
	}
	if (g == NULL) {
		printf("Errore di appertura 1.\n");
		exit(-1);
	}
	char* p=NULL;
	p = malloc(sizeof(*p));
	if (p==NULL) {
		fprintf(stderr, "Errore di allocazione.\n");
		exit(EXIT_FAILURE);
	}
	while (!feof(f)) {
		fscanf(f, "%s", p);
		if (ricerca(p, g) ==0 && presenza(p,li)==0)
			li = push_on_Tree(li, p);
	}
	fclose(f); fclose(g);
	return li;
}


int ricerca(char* c, FILE* g) {
	char* p = NULL;
	int gia = 0;
	p = (char *)malloc(sizeof(char));
	if (p == NULL) {
		fprintf(stderr, "Errore di allocazione.\n");
		exit(EXIT_FAILURE);
	}
	while (!feof(g) && !gia) {
		fscanf(g, "%s", p);
		if (strcmp(c, p) == 0)
			gia = 1;
	}
	return gia;
}

int presenza(char* c, tree* li) {
	if (is_empty_albero(li))
		return 0;
	else {
		if (strcmp(c, li->parola) != 0)
		return 0;
		else {
			if (strcmp(c, li->parola) <= 0)
				return 1+presenza(c, li->left);
			else
				return 1+presenza(c, li->right);
		}
	}
}


void Print_tree(tree* li) {
	if (li != NULL) {
		Print_tree(li->left);
		printf("** %s \n", li->parola);
		Print_tree(li->right);
	}
}

tree* empty() {
	return NULL;
}
int altezza_of_tree(Tree li) {
	if (li == NULL )
		return 0;
	else
		return 1+(maximo(altezza_of_tree(li->left), altezza_of_tree(li->right)));
}
int maximo(int a, int b) {
	if (a > b)
		return a;
	if (a < b)
		return b;
	if (a == b)
		return a;
}

/*int altezza_of_tree(Tree li) {
	if (li == NULL)
		return 0;
	else
		return (maximo(altezza_of_tree_aux(li->left), altezza_of_tree_aux(li->right)));
}

int altezza_of_tree_aux(tree*li) {
	if (li == NULL)
		return 0;
	else
		return (1 + maximo(altezza_of_tree_aux(li->left) , altezza_of_tree_aux(li->right)));
}
int maximo(int a, int b) {
	if (a > b)
		return a;
	if (a < b)
		return b;
	if (a == b)
		return a;
}*/