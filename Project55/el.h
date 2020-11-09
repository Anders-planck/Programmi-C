#ifndef __EL__H__
#define __EL__H__
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define len 20
typedef enum{false,true}boolean;

typedef struct {
	char committente[len];
	int budget;
}Coinfo;
typedef struct {
	int codice;
	Coinfo infoCO;
}Progetto;

typedef struct {
	int codice;
	char Offerente[len];
	int Offerta;
}offerte;

typedef struct {
	offerte info;
	Coinfo infoCO;
}finaly;

boolean isMinor(Progetto, offerte);

boolean isMagior_CC(finaly, finaly);

boolean isEqualsCC(Progetto, offerte);

finaly Newfinaly(Progetto, offerte);

void getFinaly(finaly);

boolean isMinor_OO(finaly, finaly);

boolean isEqualsOO(finaly);

#endif // !__EL__H__
