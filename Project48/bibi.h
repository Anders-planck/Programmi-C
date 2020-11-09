#ifndef __BIBLI__H__
#define __BIBLI__H__
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define len 20
typedef enum{false,true}booleano;
typedef struct tree {
	char parola[len];
	struct tree* left;
	struct tree* right;
}tree, * Tree;

tree* new_albero(char[]);

booleano is_empty_albero(tree*);

tree* push_on_Tree(tree*, char[]);

tree* insord_on_tree(tree*, FILE*,FILE*);

int ricerca(char*, FILE*);

int presenza(char*, tree*);

void Print_tree(tree*);

tree* empty();

int altezza_of_tree(tree*);

int altezza_of_tree_aux(tree*);

int maximo(int, int);

#endif // !__BIBLI__H__