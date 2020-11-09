#ifndef __FUN__H__
#define __FUN__H__
#include"el.h"
#include<stdlib.h>
#include<string.h>
#include<assert.h>


typedef struct List {
	finaly info;
	struct List* Next;
}List,*list;

list pushList(finaly, list);

list FunzionA(list, FILE*, FILE*);

boolean verifica(Progetto, FILE*, offerte*);

void FunzionB(list);

void FunzionC(list);

int FunzionD(list);

void Esercizio2(FILE*);
#endif // !__FUN__H__
