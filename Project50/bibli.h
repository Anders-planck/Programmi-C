#ifndef __BIBLI__H__
#define __BIBLI__H__
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define len 20
#define   dim 5
#define dimen 100
typedef struct {
    char parola[len];
}parole;
typedef struct tree {
    char parola[len];
    struct tree* letf;
    struct tree* reight;
 }tree,*Tree;
static int j = 0;
static int i = 0;
static int c = 0;
Tree funzioneA(FILE*, Tree, char[]);
void stampa_tree(tree*);
tree* push_tree(tree*, char[]);
void stampa_file(Tree, FILE*);
void stampa(parole[]);
void stampa_vet(Tree, parole[]);
void stampa_file_vet(parole[], FILE*);
#endif