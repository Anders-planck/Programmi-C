#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#define N_c 10
#define N_e 1000
#define dim_risposta 10
#include"elabora.h"


main() {
	char risposta_menu[dim_risposta];
	int Ap_Ch = 0;
	menu();
	risposta_utente(risposta_menu);
	VERIFICA(risposta_menu);
	int t=trattamento_dati(risposta_menu,&Ap_Ch);
}