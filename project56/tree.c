#include "tree.h"

tree null(){
    return NULL;
}

tree NewTree(indice x){
tree t=(tree)malloc(sizeof(Tree));
t->x=x;
t->left=null();
t->right=null();
return t;
}


tree pushTree(tree t,indice x){
if(t==null()) return NewTree(x);
else{
    if(IsLess(x,t->x))
     t->left=pushTree(t->left,x);
     else
     t->right=pushTree(t->right,x);
 return t;    
    }
}


void outtree(tree t){
    if(t==null())return;
    else{
        outtree(t->left);
        outElement(t->x);
        outtree(t->right);
    }
}

tree pushTreeNumber(tree t,indice x){
    if (t == null())
        return NewTree(x);
    else
    {
        if (isSup(x, t->x))
            t->left = pushTreeNumber(t->left, x);
        else
            t->right = pushTreeNumber(t->right, x);
        return t;
    }
}

 tree ricercaMax(tree t){
    if (t==null())return null();

    else if(t->right==null())return t;

    else{
        tree Max=ricercaMax(t->right);
    return Max;
    }
}


int outfile(tree t,FILE* out){
if(t==null()) return 0;
else{
 
        fprintf(out,"%s  : %d  volte\n",t->x.parola.parola,t->x.indexPanigina);
        return  1+ outfile(t->left, out) + outfile(t->right, out);
    }
}