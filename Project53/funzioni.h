#ifndef __FUNZIONI__H__
#define __FUNZIONI__H__


#include"element.h"
#include <stdlib.h>
#include<assert.h>
#include<string.h>

typedef struct Tree{
	element Prodotto;
	struct Tree* left;
	struct Tree* right;
}Tree,*tree;

tree push_tree(element, tree);

tree New_tree(element);

boolean isClean(tree);

tree FunzioneA(tree, FILE*);

void FunzioneB(tree);

void FunzioneC(tree, FILE*);

void close(FILE*, FILE*, FILE*);

void Esecizio_2(FILE*);

#endif // !__FUNZIONI__H__
