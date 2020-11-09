#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define dim 100
#define len 20
typedef struct {
	int x;
	int y;
}punto;
void stampa(punto[], int);
void lettura(punto[], int*);
int verifica(punto[], int, int, int);
void schizzo(int[][len], punto[], int);
void disegno(int[][len]);
void richiesta(punto*);
int interno(punto[], punto, int, int[][len]);
void risposta(int, int[][len], punto);
