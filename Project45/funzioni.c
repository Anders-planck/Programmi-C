#include"bibli.h"

tree new_albero(int x) {
	Tree* tr = NULL;
	tr = malloc(sizeof(*tr));
	if (tr == NULL) {
		fprintf(stderr, "Errore di allocazione memoria.\n");
		exit(EXIT_FAILURE);
	}
	tr->value = x;
	tr->sinistra = NULL;
	tr->destra = NULL;
	tr->parent = NULL;
	
	return tr;
}

void clean_albero(Tree* tr) {
	if (tr == NULL)
		return;
	printf("cancellazione di %d\n", tr->value);
	clean_albero(tr->destra);
	clean_albero(tr->sinistra);
	free(tr);
}

tree join_albero(Tree* sinistra, Tree* destra, int nodo) {
	Tree* tr = new_albero(nodo);
	tr->sinistra = sinistra;
	tr->destra = destra;

	if (sinistra != NULL)
		sinistra->parent = tr;
	if (destra != NULL)
		destra->parent = tr;
	return tr;
}

void print_albero_prefix(Tree* tr) {
	if (tr == NULL)
		return;
	if (tr->parent != NULL)
		printf("( %d ) -> ( %d )\n", tr->parent->value, tr->value);
	else
		printf("( %d )\n", tr->value);

	if (tr->sinistra != NULL)
		print_albero_prefix(tr->sinistra);
	if (tr->destra != NULL)
		print_albero_prefix(tr->destra);

}
void print_albero_inorder(Tree* tr) {
	if (tr == NULL)
		return;
	else {

		print_albero_inorder(tr->sinistra);
		printf("( %d )\n", tr->value);
		print_albero_inorder(tr->destra);
	}

}


void print_albero_posfix(Tree* tr) {
	if (tr == NULL)
		return;
	if (tr->parent != NULL)
		printf("( %d ) ->  ( %d ) \n", tr->parent->value, tr->value);
	else
		printf("( %d )\n", tr->value);

	if (tr->destra != NULL)
		print_albero_posfix(tr->destra);
	if (tr->sinistra != NULL)
		print_albero_posfix(tr->sinistra);
	

}
int count_nodo_albero(tree tr) {
	if (tr == NULL)
		return 0;
	return maxx(count_nodo_albero_aux(tr->sinistra) ,count_nodo_albero_aux(tr->destra));
}
int count_nodo_albero_aux(tree tr) {
	if (tr == NULL)
		return 0;
	return 1+maxx(count_nodo_albero_aux(tr->sinistra) , count_nodo_albero_aux(tr->destra));
}

int maxx(int x, int y) {
	if (x > y) return x;
	else return y;
}
tree Push_nodo(tree abre,int x) {
	if (abre == NULL) {
		abre=new_albero(x);
		return abre;
	}
	tree f = new_albero(x);
	 if (f->value < abre->value) {
		abre->sinistra = Push_nodo(abre->sinistra, x);
		return abre;
	}
	else {
		abre->destra = Push_nodo(abre->destra, x);
		return abre;
	}
}