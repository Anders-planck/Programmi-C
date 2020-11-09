#ifndef __BIBLI__H__
#define __BIBLI__H__
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define len 50
typedef enum{true=1,false=0}bool;
typedef struct {
	char nome[len];
	int N_scatole;
}prodotto;
typedef struct List_element {
	prodotto x;
	struct List_element* Next;
}List_element,*List;

List new_List();
List push_List(List,prodotto);
bool is_empty_List(List);
void print_List(List);
List  Push_on_List(FILE*, List);
prodotto* carico_Array(FILE*, int*);
void stampa(prodotto*, int);
prodotto* Ordina_array(prodotto*,int);
List total_clean_list(List);
void scrivi_On_File(prodotto*, int, FILE*,List);
bool ricerca(prodotto, List);
#endif
