#include"Intestazione.h"

main() {
	persona persone[dim];
	ricco ricchi[dim];
	Auto auti[max];
	int scelta;
	int np, na,nr;
	richiesta(&scelta);
	if ( scelta != 1 && scelta != 2) {
		implementa(&scelta);
	}
	else {
		switch (scelta)
		{
		case 1:
			np = lettura(persone);
			na = lettura_2(auti);
			stampa(persone, np);
			stampa_a(auti, na);
			nr = elabora(persone, np, auti, na, ricchi);
			stampa(ricchi, nr);
			break;
		case 2:
			printf("\t\t\tNON ANCORA DIPONIBILE\n");
			printf("************************************* DA FINIRE CON IL MIO GRSANDE DI MODENA *****************************");
			break;
		default:printf("ERRORE NEL IDENTIFACAZIONE ");
			exit(-1);
			break;
		}
	}
}