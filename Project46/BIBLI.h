#ifndef __BIBLI__H__
#define __BIBLI__H__
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define len 50
typedef enum{true,false}booleano;
typedef struct {
	char nome[len];
	int N_scatole;
}prodotto,samba;
typedef struct Albero {
	prodotto value;
	struct Albero* destro;
	struct Albero* sinistro;
	struct Albero* parent;
}Albero,*t_albero;

t_albero lettura_file_albero(Albero*, FILE*);
void print_albero_ordinato_prefixo(t_albero);
void clean_albero(t_albero);
booleano is_empty_albero(Albero*);
t_albero new_albero(prodotto);
Albero* Push_albero(t_albero, prodotto);
void print_albero_file(t_albero, FILE*, FILE*);
t_albero ricerca_albero(Albero*, prodotto);
int count_nodo_albero(t_albero);
#endif
