#include "el.h"
#include<stdlib.h>

typedef struct Tree
{
    indice x;
    struct Tree* left;
    struct Tree*right;
}Tree,*tree;


tree null();

tree pushTree(tree , indice );

void outtree(tree);

tree NewTree(indice );

tree pushTreeNumber(tree , indice );

tree ricercaMax(tree);
int outfile(tree , FILE *);