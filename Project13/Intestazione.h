#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#define dim 100
#define len 20
typedef struct {
	char nom[len];
	int voto;
}vera;
typedef struct {
	char nom[len];
	int g, m, a;
	int voto;
}risultato;
typedef struct {
	char nom[len];
	int id;
}comp;
void lettura(risultato[], int*);
void elabora(risultato[], int, vera[], int*, risultato []);
void numerisazione(comp [], risultato[], int);
int inizializazzione(comp[], int, comp[]);
int esistenza(comp, comp[], int);
void stampa(comp [], int);
void carico(risultato[], int, risultato[], int, comp);
int classifica(risultato [], int , comp [], int , risultato []);
int minimo(comp[], int, comp [], int* , int* );
int presenza(risultato[], int,comp);
void ordinate(risultato[], int);
void ordinate(risultato[], int);