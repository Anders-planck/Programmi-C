#include"Intestazione.h"

main() {
	punto punti[dim];
	punto p;
	int n, c;
	int piano[len][len];
	lettura(punti, &n);
	stampa(punti, n);
	schizzo(piano, punti, n);
	richiesta(&p);
	c=interno(punti, p, n,piano);
	risposta(c,piano,p);
}