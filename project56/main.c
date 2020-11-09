#include "fonzioni.h"

int main(int argc, char const *argv[])
{
    tree T=null();
    FILE* voc=fopen("vocaboli.txt","rt");
    if(voc==NULL){
        printf("Errore nell Apertura del file vocaboli.txt riga 8");
        exit(-1);
    }
    FILE*ind=fopen("indice.bin","rb");
    if (ind == NULL)
    {
        printf("Errore nell Apertura del file indice.bin riga 11");
        exit(-1);
    }


T=fonzioneA(voc,ind);
outtree(T);


char Parola[len];
int Max = fonzioneB(T, Parola, voc, ind);
printf(" la parola piu scritta è : %s --- %d\n",Parola,Max);


FILE*out=fopen("out.txt","wt");
int NParole=outfile(T,out);
printf("Numero di parole:\t%d\n",NParole-1);



fclose(voc);
fclose(ind);
fclose(out);
    return 0;
}
