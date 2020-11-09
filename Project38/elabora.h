#include"candidat.h"
#include"electeur.h"
void menu();
void risposta_utente(char[]);
int trattamento_dati(char [],int*);
int verifica(char[]);
int identificazione(registro[], int, registro*,int);
int votare(registro[], lista[], int, int, int*);
int  stampa_e(registro[],int);
void abbortire(char[]);
int  vota(lista[], int, int*, int*);
void menu_v(int*, int);
void statistica(int, lista[],registro[],int, int,int);
void VERIFICA(char[]);
void verifica_2(char[]);
void VERIFICA_3(char[], lista[], int);
void VERIFICA_4(char[], registro[], int);
void VERIFICA_6(char[]);
void VERIFICA_5(char[]);
void lettura(lista[], registro[], int, int, int);