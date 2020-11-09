
#include"Intestazione.h"



main() {
	risultato esam[dim];
	int n;
	int nc;
	vera ris[dim];
	vera list[dim];
	risultato nota[dim];
	lettura(esam, &n);
	diordinate(esam, n);
	elabora(esam, n, list, &nc,nota);
	ordinate(nota, nc);
	riscrittura(nota, nc);
}