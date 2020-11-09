#include"funzioni.h"


boolean isClean(tree t) {
	if (t == NULL)return true;
	else return false;
}


tree New_tree(element x) {
	tree t = (tree)malloc(sizeof(Tree));
	assert(t != NULL);
	t->Prodotto = x;
	t->left = NULL;
	t->right = NULL;
	return t;
}
tree push_tree(element x, tree t) {
	if (isClean(t)) return New_tree(x);
	else {
		if (isless(t->Prodotto, x))
			t->left = push_tree(x, t->left);
		else t->right = push_tree(x, t->right);
		return t;
	}
}


tree FunzioneA(tree T, FILE* f) {
	element x;
	while (fread(&x, sizeof(x), 1, f)) {
		if (equalsNumber(x)) {
			T = push_tree(x, T);
		}
	}
	return T;
}

void FunzioneB(tree t) {
	if (isClean(t)) return;
	else {
		FunzioneB(t->left);
		printf("P : %s\tC : %d\n", t->Prodotto.Nome, t->Prodotto.Energia);
		FunzioneB(t->right);
	}
}

void FunzioneC(tree t,FILE*g) {
	if (isClean(t)) return;
	else {
		FunzioneC(t->left,g);
		fprintf(g,"P : %s\tC : %d\n", t->Prodotto.Nome, t->Prodotto.Energia);
		FunzioneC(t->right,g);
	}
}

void Esecizio_2(FILE*h) {
	fprintf(h, "La funzione f5 paragona il suo parametro formale, il carattere i con ogni carattere presento nella lista L,\ndove restitiusce 1 nel caso di uguaglianza e 0 nel caso in cui il carattere i è inferiore a quegli della lista\nNel caso in cui i a un valore maggiore rispetto a quegli della lista allora la nostra funzione dovrà percorrere tutta la lista fino al l uttimo elemento \nE in questo caso  se premettiamo che la lista abbia N elementi allora la nostra funzione eseguirà esattamente N confronti dove ci ritroviamo Nel casa PEGGIORE  e la complessità asintotica sarà pari di consequenza a quella di O(N)\n ");
}
void close(FILE*f,FILE *g,FILE* h) {
	fclose(f);
	fclose(g);
	fclose(h);
}