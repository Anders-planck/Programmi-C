#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define len 20
#define dim 30
#include<stdlib.h>
#include<string.h>
typedef struct {
	char nome[len];
	char profitto[dim];
}investimento;
typedef struct {
	char nome[len];
	int guadagno;
}guadagno;
int lettura(investimento[]);
int elabora(investimento[], int,char[],int*,guadagno[]);
int calcolo(investimento, guadagno[], int);
void stampa(char[], int, int, guadagno[],investimento[],int n);
int elabora_2(investimento[], int, char[], int*, guadagno[], int*, int*);
int revenu(investimento, int, int, guadagno[], int);
stampa_2(char [], int , int , guadagno [], investimento [], int , int, int );
void verifica(int*, int*);
void menu(int*);