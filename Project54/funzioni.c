#include"funzioni.h"


list FunzioneA(list l, FILE* f) {
	element x;
	while (!feof(f)) {
		fscanf(f, "%s%d%d", x.parola, &x.stato, &x.Profondità);
		l = push_list(x, l);
	}
	return l;
}
list NewList(element x) {
	list t = (list)malloc(sizeof(Lista));
	assert(t != NULL);
	t->reperto = x;
	t->Next = NULL;
	return t;
}
list push_list(element x, list l) {
	list curr=l;
	list prec = NULL;
	list New = NULL;
	while (curr != NULL && isless(x, curr->reperto)) {
		prec = curr;
		curr = curr->Next;
	}
	New = NewList(x);
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

void FunzioneB(list l) {
	if (l == NULL) return;
	else {
		getelement(l->reperto);
		FunzioneB(l->Next);
	}
}

void FunzioneC(list l, FILE* h,FILE*e)
{
	static int i = 0;
	static int j = 0;
	if (l == NULL) {
		fprintf(h, " il Numero di volte che è stato possibile contare %s è:\n%d\n", Base, i);
		fprintf(e, " il Numero di volte che è stato possibile contare un reperto con profondità %d è:\n%d\n", Profondo, j);
		return;
	}
	else {
		if (equals(l->reperto)) {
			//fprintf(h, "P:  %s\tS:  %d\tPr:  %d\n", l->reperto.parola, l->reperto.stato, l->reperto.Profondità);
			i++;
		}
		if (equalsPr(l->reperto)) {
			//fprintf(e, "P:  %s\tS:  %d\tPr:  %d\n", l->reperto.parola, l->reperto.stato, l->reperto.Profondità);
			j++;
		}
		FunzioneC(l->Next,h,e);
	}
}


Esercizio_2(FILE* e) {
	fprintf(e, "La funzione fun conta il numero di volte in appare il suo parametro formale, il carattere i nell albero binario T \nIn questa situazione  il comportamento della complessità non cambia e rimane asintoto ad un O(N) (con N il numero di elementi del albero) \nCiò si spiega con il fatto che la nostra funzione è obbligata a pecorrere tutto l albero per contare il numero di volte che avvienne l'ugualianza tra il carattere i e ogni altro carattere presento nell albero T.\n");
}
close(FILE*f, FILE* g, FILE* h,FILE*e,FILE*i) {
	fclose(f);
	fclose(g);
		fclose(h);
		fclose(e);
		fclose(i);
}