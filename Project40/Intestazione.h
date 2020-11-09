#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define len 20
#define max 100
#define dim 50
typedef struct {
	char nome[len];
	int red;
}persona;
typedef struct {
	char nome[len];
	char marca[len];
}Auto;
typedef struct {
	char nome[len];
	int NA;
}ricco;
int lettura_2(Auto[]);
int lettura(persona[]);
void stampa_a(Auto[], int);
void stampa(persona[], int);
int verifica(persona, int*, Auto[], int);
int elabora(persona[], int, Auto[], int, ricco[]);
void richiesta(int*);
void implementa(int*);