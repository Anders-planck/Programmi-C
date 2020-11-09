#include<stdio.h>
main() {
	struct persona {
		char nome[20];
		char cognome[20];
		char indirizzo[30];
		char provincia[20];
		int giorno, mese, anno;
}person;
	printf("\ninserire norme\n");
	scanf("%s", person.nome);
	printf("\ninserire cognome\n");
	scanf("%s", person.cognome);
	printf("\ninserire indirizzo\n");
	scanf("%s", person.indirizzo);
	printf("\ninserire provincia\n");
	scanf("%s", person.provincia);
	printf("\ninserire data di nascita");
	scanf("%d%d%d", &person.giorno, &person.mese, &person.anno);
	printf("\n\nnome:\t%s\ncognome:\t%s\nindirizzo:\t%s\nprovincia:\t%s\ndata di nascita:\t%d/%d/%d\n", person.nome, person.cognome, person.indirizzo, person.provincia, person.giorno, person.mese, person.anno);
}