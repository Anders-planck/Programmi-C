#include"Intestazione.h"


int verifica(persona f, int* j, Auto auti[], int  na) {
	int i = 0; int gia = 1; int c = 0;
	while (i < na && gia == 1) {
		if (strcmp(f.nome, auti[i].nome) == 0) {
			c = c + 1;
			gia = 0;
		}
		i++;
	}
	*j = c;
	return gia;
}