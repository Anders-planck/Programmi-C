#include "el.h"


boolean Equals(indice x,vocaboli y){
    if(strcmp(x.parola.parola,y.parola)==0)return vero;
    else return falso;
}

indice transform(vocaboli y, int Nvolte){
    indice x;
x.indexPanigina=Nvolte;
x.parola=y;
    return x;
}

boolean IsLess(indice x,indice y){
    if (strcmp(x.parola.parola, y.parola.parola)<0)
        return vero;
    else
        return falso;
}

void outElement(indice x){
    printf("%s -- %d\n",x.parola.parola,x.indexPanigina);
}

boolean isSup(indice Max, indice x){
    if(Max.indexPanigina < x.indexPanigina)return vero;
    else return falso;
    }

int assegno(indice x){
return x.indexPanigina;
}

void assegnoChar(indice  x, char parola[]){
    strcpy(parola,x.parola.parola);
}

int Sup(int Max1,int  Max2){
    if(Max1>Max2)return Max1;
    else return Max2;
}
