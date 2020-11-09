#include"fun.h"

list FunzionA(list l, FILE* f, FILE* g) {
	finaly x;
	offerte y;
	Progetto tmp;
	while (fread(&tmp, sizeof(tmp), 1, f)) {
		if (verifica(tmp, g,&y)) {
			x = Newfinaly(tmp,y);
			l = pushList(x, l);
		}
	}

	return l;
}
boolean verifica(Progetto x, FILE* g, offerte *y) {
	boolean t = false;
	offerte s;
	rewind(g);
	while (fread(&s, sizeof(offerte), 1, g) && t != true) {
		printf("%s\n", s.Offerente);
		if (isEqualsCC(x, s) ) {
			if(isMinor(x, s))
			t = !t;
			*y = s;
		}
	}
	return t;
}

list Newlist(finaly x) {
	list t = (list)malloc(sizeof(List));
	assert(t != NULL);
	t->info = x;
	t->Next = NULL;
	return t;
}
list pushList(finaly x, list l) {
	list curr = l;
	list prec = NULL;
	list New = NULL;
	while (curr != NULL && isMagior_CC(x, l->info)) {
		prec = curr;
		curr = curr->Next;
	}
	New = Newlist(x);
	if (prec == NULL) {
		New->Next = l;
		l = New;
		return l;
	}
	else {
		prec->Next = New;
		New->Next = curr;
		return l;
	}
}

void FunzionB(list l) {
	list tmp = l;
	if (tmp == NULL)return;
	else {
		getFinaly(tmp->info);
		FunzionB(tmp->Next);
	}
}

void FunzionC(list l) {
	list tmp = l;
	list curr = l->Next;
	while (curr != NULL) {
		if (isMinor_OO(tmp->info, curr->info)) {
			tmp = curr;
		}
		curr = curr->Next;
	}
	printf("\n MINORE :\n");
	getFinaly(tmp->info);
}

int FunzionD(list l) {
	list t = l;
	if (t == NULL) return 0;
	else {
		if (isEqualsOO(t->info)) {
			getFinaly(t->info);
			return 1 + FunzionD(t->Next);
		}
		else return FunzionD(t->Next);
	}
}


void Esercizio2(FILE* h) {

	fprintf(h, "La funzione seme verifica se esiiste almemo un elemento della lista L che appartiene a l albero T \nIn questa situazione ci sono 3 casi per individuare qual è il comportamento della complessita della funzione:\n - il caso MIGLIORE : qua la complessita è asintotico a O(1) poiche la funzione seme esegue 1 solo paragone\n-Caso MEDIO: qua l uguaglianza fra gli elementi può essere ritrovata in mezzo agli elementi della lista o del albero  e dunque a questo punto la complessita sarà asintotica a O(N^2/2) visto che ha scorso la meta degli elementi della lista e la meta degli elementi dell albero\n-Caso PEGGIORE dove la nostra funzione scorre tutti gli elementi della lista e quegli dell albero trovando o no la l ugualianza all'ultimo confronto .A questo punto la complessita è asintotica a O(N^2)\n.");
}