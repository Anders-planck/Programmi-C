#ifndef __BIBLI__H__
#define __BIBLI__H__
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define len 20
#define   dim 5
typedef enum {false,true}booleano;

typedef struct list {
	char parola[len];
	struct list* next;
}list,*List;
typedef struct {
	char parola[len];
}consone;
static int i = 0;
static int j = 0;
static int c = 0;
List funzioneA(FILE*, char[]);
int riconoscimento(char[], char[]);
List push_list(list*, char[]);
list* New_list(char[]);
void stampa(List);
void stampa_file(list*, FILE*);
void  racolta(consone[], FILE*, char[]);
void qsort(list*, consone[]);
void stampa_Vet(consone[], int);
void stampa_file_vet(consone[], FILE*, int);
List clean_list(List);
#endif // !__BIBLI__H__

