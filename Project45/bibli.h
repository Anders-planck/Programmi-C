#ifndef __BIBLI__H__
#define __BIBLI__H__
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct tree {
	int value;
	struct tree* sinistra;
	struct tree* destra;
	struct tree* parent;
}Tree,*tree;
Tree* new_albero(int x);
void clean_albero(Tree*);
Tree* join_albero(Tree*, Tree*, int);
void print_albero_prefix(Tree*);
void print_albero_posfix(tree);
int count_nodo_albero(tree);
tree Push_nodo(tree, int);
void print_albero_inorder(Tree*);
int count_nodo_albero_aux(tree);
int maxx(int x, int y);
#endif