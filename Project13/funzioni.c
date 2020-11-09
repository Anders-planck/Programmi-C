
#include"Intestazione.h"



void numerisazione(comp valeur[], risultato esam[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		valeur[i].id = esam[i].nom[0];
		strcpy(valeur[i].nom, esam[i].nom);
	}
}

void carico(risultato esam[], int n, risultato nota[],int j,comp g) {
	int gia = 0;
	int i = 0;
	while (i < n && gia == 0) {
		if (strcmp(esam[i].nom, g.nom) == 0) {
			nota[j] = esam[i];
			gia = 1;
}
		i++;
	}
}




int classifica(risultato esam[], int n, comp valore[], int ni, risultato nota[]) {
	int i;
	int j = 0;
	int c = 0;
	int min = 0;
	int nc;
	int id;
	comp temp[dim];
	int d = ni;
	for (i = 0; i < d; i++) {
		min = minimo(valore, ni, temp, &nc, &id);
		if (presenza(nota, j, valore[id]) == 0) {
			carico(esam, n, nota,j,valore[id]);
			j++;
		}
		for (c = 0; c < nc; c++) {
			valore[c] = temp[c];
		}
		ni = nc;
	}
	return j;
}



int inizializazzione(comp valeur[], int  n, comp valore[]) {
	int i;
	int j=0;
	for (i = 0; i < n; i++) {
		if (esistenza(valeur[i], valore,j) == 0) {
			valore[j] = valeur[i];
			j++;
		}
	}
	return j;
}



void elabora(risultato esam[], int n, vera list[], int* nc,risultato nota[]) {
	int i;
	int ni;
	comp valeur[dim];
	comp valore[dim];
	numerisazione(valeur, esam, n);
	stampa(valeur, n);
	ni = inizializazzione(valeur,n,valore);
	stampa(valore, ni);
	*nc = classifica(esam,n, valore,ni,nota);
}