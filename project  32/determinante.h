#ifndef DETERMINANTE_H
#define DETERMINANTE_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct matrix {// struttura che rappresenta una matrice
	size_t rows, cols;
	double *data;

};
extern void T1(struct matrix *m, int i, int j);//la trasformazione che scambia due righe della matrice
extern void T2(struct matrix *m, int i, int j);// la trasformazione che a una righa data aggiunge il moltiplo di una altra righa
extern void T3(struct matrix *m, double scalare);
extern void determinante(struct matrix *m, double *det, bool *flag);
extern void stampa(struct matrix *m);
#endif