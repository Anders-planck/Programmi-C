#ifndef __FUNZION__H__
#define __FUNZION__H__
#include"element.h"
#include<stdlib.h>
#include<string.h>
#include<assert.h>

static char const Base[] = "anfora";
typedef struct Lista {
	element reperto;
	struct Lista* Next;
}Lista,*list;


list push_list(element, list);

list NewList(element);

list FunzioneA(list, FILE*);

void FunzioneB(list);

void FunzioneC(list, FILE*);

close(FILE*, FILE*, FILE*, FILE*, FILE*);

Esercizio_2(FILE*);
#endif // !__FUNZION__H__
