					/* Jipwouo chiege planck anders */
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#define len 30

typedef struct {
	char parola[len];
	int stato;
	int profondita;
}Reperto;
typedef struct Tree {
	int value;
	struct Tree* left, * rigth;
}Tree,*tree;

typedef struct List {
	Reperto value;
	struct List* Next;
}List,*list;

/*int somma(tree T) {
	if (T == NULL)return 0;
	else {
		return T->value + somma(T->left) + somma(T->rigth);
	}
}
tree put(tree t, int i) {
	if (t == NULL) {
		tree New = (tree)malloc(sizeof(Tree));
		New->value = i;
		New->left = NULL;
		New->rigth = NULL;
		return New;
	}
	else {
		if (i < t->value)
			t->left = put(t->left, i);
		else t->rigth = put(t->rigth, i);
		return t;
	}
}*/
void funzione2(list l, FILE* Parola) {
	list tmp = l; int somma=0;
	while (tmp != NULL) {
		if (strcmp(tmp->value.parola, "amuleto") == 0) {
			somma++;
		}
		tmp = tmp->Next;
	}
	fprintf(Parola, " Il numero di reperti con la parola amuleto sono in %d ", somma);
}


list NewList(Reperto x) {
	list l = (list)malloc(sizeof(List));
	l->value = x;
	l->Next = NULL;
	return l;
}

list  putList(Reperto x, list l) {
	if (l == NULL)return NewList(x);
	else {
		list New = NewList(x);
		list prec = NULL;
		list current = l;
		while (current != NULL && strcmp(x.parola,current->value.parola)>0)
		{
			prec = current;
			current = current->Next;
		}
		if (prec == NULL) {
			New->Next = l;
			l = New;
			return l;
		}
		else {
			prec->Next = New;
			New->Next = current;
			return l;
		}
	}
}

list funzione1(FILE* mara, list l) {

	Reperto x;
	while (!feof(mara)) {
		fscanf(mara, "%s%d%d", x.parola, &x.stato, &x.profondita);
		l = putList(x, l);
	}
	return l;
}

int main() {
	list L = NULL;
	FILE* mara = fopen("mara.txt", "rt");
	if (mara == NULL) {
		printf("Errore nell appertura del file mara");
		exit(-1);
	}
	L = funzione1(mara, L);

	FILE* Parola = fopen("parola.txt", "wt");
	if (Parola == NULL) {
		printf("Errore nell appertura del file Parola");
		exit(-1);
	}
	funzione2(L, Parola);

	fclose(mara);
	fclose(Parola);
	tree T = NULL;
	/*int i; scanf("%d ", &i);
	while (i != 0) {
			T = put(T, i);
		scanf("%d ", &i);
	}
		i = somma(T);
		printf("somma: %d", i);*/
	/*fine*/
	return 0;
}