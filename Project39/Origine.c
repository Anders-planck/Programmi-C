#include"funzion.h"
#define max 100
main() {
	investimento azioni[max];
	guadagno x[max];
	char azione[len];
	int proffito;
	int j;
	int n;
	int risposta;
	int mese_i, mese_f;
	char ris[len] = { "si" };
	while (strcmp(ris, "si") == 0) {
		menu(&risposta);
		switch (risposta)
		{
		case 1:
			printf("\t\t\tPRIMA  parte compito\n");
			n = lettura(azioni);
			j = elabora(azioni, n, azione, &proffito, x);
			stampa(azione, j, proffito, x, azioni, n);
			break;
		case 2:
			printf("\t\t\t SECONDA  parte compito\n");
			n = lettura(azioni);
			j = elabora_2(azioni, n, azione, &proffito, x, &mese_i, &mese_f);
			stampa_2(azione, j, proffito, x, azioni, n, mese_i, mese_f);
			break;
		default:
			printf("ERRORE DI SELEZIONE CHIUSURA DEL PROGRAMA\n");
			menu(&risposta);
			break;
		}
		printf("\t\t\t\t\t\tVOUI RIESEGUIRE IL PROGRAMA :\t");
		scanf("%s", ris);

	}
	if (strcmp(ris, "si") != 0) {
		printf("\t\t\tGRAZIE E ARRIVEDERCI\n");
	}
	
}