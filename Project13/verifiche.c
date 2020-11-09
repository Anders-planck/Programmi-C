
#include"Intestazione.h"



int presenza(risultato nota[], int j, comp f) {
	int i=0;
	int gia = 0;
	while (i < j && gia == 0) {
		if (strcmp(f.nom, nota[i].nom) == 0)
			gia = 1;
		i++;
	}
	return gia;
}


int minimo(comp valore[], int ni,comp temp[],int *nc,int *id) {
	int i;
	int j = 0;
	int c=0;
	int min=valore[0].id;
	for (i = 0; i < ni; i++) {
		if (min > valore[i].id) {
			min = valore[i].id;
			c = i;
		}
	}
	*id = c;
	for (i = 0; i < ni; i++) {
		if (strcmp(valore[c].nom, valore[i].nom) != 0) {
			temp[j] = valore[i];
			j++;
		}
	}
	*nc = j;
	return min;
}


int esistenza(comp f, comp valore[], int j) {
	int i=0;
	int gia = 0;
	while (i < j && gia == 0) {
		if (strcmp(f.nom, valore[i].nom) == 0)
			gia = 1;
		i++;
	}
	return gia;
}
