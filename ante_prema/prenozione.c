#include<stdio.h>
#include<string.h>
#define dim 6
#define len 100
typedef struct booking {
	char nome[20];
	int posto;
}prenot;
main() {
	prenot reg[len];
	int i = 1;
	int a = 0;
	char ris1[dim];
	char ris[dim];

	reg[0].posto = 0;
	do {
		printf("\n\nvuoi fare una prenotazione? \nscrivi(fine)se non lo vuoi e \nscrivi (si)se lo vuoi:\t");
		scanf("%s", ris);
		if (strcmp(ris, "fine") != 0 && strcmp(ris, "si")==0) {
			printf("\nnome:\t");
			scanf("%s", reg[i].nome);
			printf("\nnnumero di posto da prenotare:\t");
			scanf("%d", &reg[i].posto);
			printf("i tuoi dati sono questi:\nnome:\t%s\nnumero di posto:\t%d", reg[i].nome, reg[i].posto);


			if (reg[i].posto == reg[i - 1].posto)
				printf("prenotazione rifuitata:\nmotivo:\tnumero di posto gia prenotato");
			else
				printf("\nprenotazione registrata con successo\n.");

		}
		else
			printf("\nriavvia il file per la prenotazione ulteriora");

		i++;
		a = i;
		if (strcmp(ris, "fine") != 0) {
			printf("\nil numero di prenotazione e :\t%d", i);
			printf("\nle prenotazioni prima di te sono:\n");
			for (i = 0; i < a; i++)
				printf("\nnome:\t%s\nnumero di posto:\t%d", reg[i].nome, reg[i].posto);
		}
		printf("\nscrivi fine se soddisfatto\n");
		scanf("%s", ris1);
		if (strcmp(ris1, "fine") == 0)
			printf("\nGrazie");
	} while (i<len&&strcmp(ris1,"fine")!=0);



}