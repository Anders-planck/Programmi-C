#include "fonzioni.h"


tree fonzioneA(FILE*voc,FILE*ind){
    vocaboli y;
    int Nvolte;
    indice x;
    tree t=null();
    while (!feof(voc))
    {
        Nvolte=0;
     fscanf(voc,"%s",y.parola);
    Nvolte=ricerca(y,ind);
    x=transform(y,Nvolte);
    t=pushTree(t,x);
    }
    rewind(voc);
    return t;
}

int ricerca(vocaboli y,FILE* ind){
indice z;
int somme=0;
while (fread(&z,sizeof(z),1,ind))
{
  if(Equals(z,y)){
      somme+=1;
  }
}
rewind(ind);
return somme;
}

int fonzioneB(tree t,char Parola[],FILE*voc,FILE*ind)
{
tree tmp=null();
vocaboli y;
int Nvolte;
indice x;

while (!feof(voc))
{
    Nvolte = 0;
    fscanf(voc, "%s", y.parola);
    Nvolte = ricerca(y, ind);
    x = transform(y, Nvolte);
    tmp = pushTreeNumber(tmp, x);
}
printf("\n\ntmp\n\n\n");
outtree(tmp);
tree Max=ricercaMax(tmp);
assegnoChar(Max->x,Parola);
return Max->x.indexPanigina;
}