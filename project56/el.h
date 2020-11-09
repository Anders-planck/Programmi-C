#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define len 20

typedef enum{falso,vero}boolean;

typedef struct 
{
   char parola[len];
}vocaboli;


typedef struct
{
  vocaboli parola;
    int indexPanigina;
}indice;

boolean Equals(indice,vocaboli);

indice transform(vocaboli , int );

boolean IsLess(indice , indice );

void outElement(indice);

boolean isSup(indice , indice );
int assegno(indice );

void assegnoChar(indice , char[]);

int Sup(int , int );