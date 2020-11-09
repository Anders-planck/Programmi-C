#define _CRT_SECURE_NO_WARNINGS
#define len 20
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum {false,true}boolean;
typedef struct { char nome[len]; int age; char  state[len]; }persona;
typedef struct list { persona x; struct list* Next; }list ,*li;
typedef struct albero { persona x; struct albero* left; struct albero* right; }albero,*al;

void stampaR(li l) {
	if (l == NULL)return;
	else {
		printf(" Nome: %s  \tAge: %d   \tState:  %s\n ", l->x.nome, l->x.age, l->x.state);
		stampaR(l->Next);
	}
}
void stampaI(li l ,FILE*dato2) {
	li tmp = l; 
		while (tmp != NULL) {
			persona x = tmp->x;
			fwrite(&x,sizeof(x),1,dato2);
			fflush(dato2);
			tmp = tmp->Next;
		}
}
void printalR(al a) {
	if (a == NULL)return;
	else {
		printalR(a->left);
		printf(" Nome: %s  \tAge: %d   \tState:  %s\n ", a->x.nome, a->x.age, a->x.state);
		printalR(a->right);
	}
}

int height_aux(al a) {
	if (a == NULL)return 0;
	else
		return (1 + max(height_aux(a->left), height_aux(a->right)));
}
int height(al a) {
	if (a == NULL)return 0;
	else
		return max(height_aux(a->left), height_aux(a->right));
}

al newal(persona x) {
	al new = (al)sizeof(albero);
	new->x = x;
	new->left = new->right = NULL;
	if (new->right == NULL && new->left == NULL)printf("valide");
	else printf("echec");
	return new;
}
al putalI(al n, persona x) {
	if (n == NULL)return newal(x);
	else {
		al prec = NULL, current = n;
		while (current!=NULL)
		{
			if (strcmp(x.nome, current->x.nome) < 0) {
				prec = current; current = current->left;
			}
			else {
				prec = current; current = current->right;
			}
		}
		al new = newal(x);
		if (strcmp(x.nome, prec->x.nome) < 0)
			prec->left = new;
		else
			prec->right = new;

			return n;
	}
}
al funtionD(al n, FILE*dato2) {
	persona x;
	while (fread(&x, sizeof(persona),1, dato2)) {
		n = putalI(n, x);
	}
	rewind(dato2);
	return n;
}

al putalR(al a, persona x) {
	if (a == NULL)return newal(x);
	else {
		if (strcmp(x.nome, a->x.nome) < 0)
			a->left = putalR(a->left, x);
		else a->right = putalR(a->right, x);
		return a;
	}
}
al funtionC(al a, FILE* dato2) {
	persona x;
	while (fread(&x, sizeof(persona), 1, dato2)) {
		a = putalR(a, x);
	}
	return a;
}


li newli(persona x) {
	li tmp = (li)malloc(sizeof(list));
	tmp->x = x;
	tmp->Next = NULL;
	return tmp;
}
li putli_I(li m, persona x) {

	if (m == NULL)return newli(x);
	else {
		li new = newli(x);
		li current = m;
		li prec = NULL;
		while (current!=NULL && strcmp(x.nome,current->x.nome)>0){
			prec = current;
			current = current->Next;
		}
		if (prec == NULL) { new->Next = m; return new; }
		else { prec->Next = new; new->Next = current; return m; }
	}
}
li fountionB(li m, FILE* dato) {
	rewind(dato);
	persona x;
	while (!feof(dato)) {
		fscanf(dato, "%s %d %s ", x.nome, &x.age, x.state);
		m = putli_I(m, x);
	}
	return m;
}
li putli_R(li l, persona x) {
	if (l == NULL)return newli(x);
	else if (strcmp(x.nome, l->x.nome) < 0) { 
		li new = newli(x); 
		new->Next = l; return new; }
	else {
		l->Next = putli_R(l->Next, x);
		return l;
	}
}
li funtionA(li l ,FILE*dato) {
	persona x;
	while (!feof(dato)) {
		fscanf(dato, "%s %d %s ", x.nome, &x.age, x.state);
		l = putli_R(l, x);
	}
	return l;
}

void main(void) {
	
	li l=NULL,m = NULL;
	FILE* dato = fopen("dato.txt", "rt");
	FILE* dato2 = fopen("dato.bin", "wb");
	if (dato2 == NULL)printf("file error");
	/*ordinamento Ricorsivo*/
	l = funtionA(l,dato);
	/*ordinamento interattivo */
	m = fountionB(m,dato);
	/*stampa degliu elementi in ordine dipente*/;
	/*stampa ricosiva*/
	printf("stampa ricosiva\n");
	stampaR(l);
	/*stampa interativa*/
	printf("stampa stampa interactiva\n");
	stampaI(m,dato2);
	
	fclose(dato2);

	dato2 = fopen("dato.bin", "rb");
	if (dato2 == NULL)printf("file error");
	al a = NULL, n = NULL;
	printf("\n\n\n\n\n\n\n\n\n\n");
	a=funtionC(a,dato2);
		n=funtionD(n,dato2);
		int i=height(a);
		int c = height(n);

		printf("albero binario ricosivo\n\n");
		printalR(a);
		printf("l altezza del albero a e:  %d\n\n", i);

		printf("albero binario interattivo\n\n");
		printalR(n);
		printf("l altezza del albero a e:  %d\n\n", c);

		fclose(dato2);
		fclose(dato);
}
