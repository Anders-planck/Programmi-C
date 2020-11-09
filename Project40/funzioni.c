#include"Intestazione.h"


int elabora(persona persone[], int  np, Auto auti[], int  na, ricco ricchi[]) {
	int i;
	int j;
	int c = 0;
	for (i = 0; i < np; i++) {
		j = 0;
		if (verifica(persone[i], &j, auti, na) == 0) {
			strcpy(ricchi[c].nome, persone[i].nome);
			ricchi[c].NA = j;
			c++;
		}
	}
	return c;
}