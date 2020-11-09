#include<stdio.h>
#include<math.h>
#include<string.h>
#define dim 6
#define len 100
typedef struct studende {
	char nome[20], cognome[30];
	int matricola;
}aluno;
main() {
	aluno registro[len];
	int i = 1;
	int b = 0;
	int c=0;
	char nom[len], prenom[len];
	char ris[len];
	i = 1;
	registro[0].matricola = 1;
	while (registro[i - 1].matricola != 0) {
		printf("\n inserire i tuoi dati:\ninserisci il tuo norme:\t");
		scanf("%s", registro[i].nome);
		printf("\ninserisci il tuo cognome:\t");
		scanf("%s", registro[i].cognome);
		printf("\ninscerisci una matricola di 6 chifre:\t");
		scanf("%d", &registro[i].matricola);
		i++;
	}

	i = 1;
	printf("\ni  dati  del registro sono questi :");
	do {
		printf("\n\nnome:\t%s\ncognome:\t%s\nmatrila:\t%d", registro[i].nome, registro[i].cognome, registro[i].matricola);
		i++;
		b++;
	} while (registro[i - 1].matricola != 0);
	printf("\nnil numero di studente registrato e':%d", b);
	printf("\ninserisci il tuo nome:\t ");
	scanf("%s", nom);
	printf("\ninserisci il tuo cognome:\t");
	scanf("%s", prenom);
	i = 1;
	do {
		if (strcmp(registro[i].nome, nom) == 0 && strcmp(registro[i].cognome, prenom) == 0) {
			printf("\ni tuoi dati sono questi :\nnome:\t%s\ncognome:\t%s\nmatrila:\t%d", registro[i].nome, registro[i].cognome, registro[i].matricola);
		}
		else {
			printf("\ni dati da te inserito non compaiono in registro\n");
		}
		i++;
	} while (registro[i].matricola != 0);

	printf("\nwaaawwwwwwwwww\n");
	
	i = b + 1;
	do {
		printf("\n\n\nnuovo studente\n\n\n ");
		scanf("%s", ris);
		if (strcmp(ris, "si") == 0) {


			printf("\n inserire i tuoi dati:\ninserisci il tuo norme:\t");
			scanf("%s", registro[i = b + 1].nome);
			printf("\ninserisci il tuo cognome:\t");
			scanf("%s", registro[i = b + 1].cognome);
			printf("\ninscerisci una matricola di 6 chifre:\t");
			scanf("%d", &registro[i = b + 1].matricola);


			printf("\ni  dati  del registro sono questi :");
			for (i = 1; i <= b + 1; i++) {
				printf("\n\nnome:\t%s\ncognome:\t%s\nmatrila:\t%d", registro[i].nome, registro[i].cognome, registro[i].matricola);
				c++;
			}printf("\nil numero totale di studente e':\t %d", c);
		}
		else {
			printf("OKK");
		}
		
	} while (i < len);
	printf("\ni  dati  del registro sono questi :");
	for (i = 0; i <= b + 1; i++) {
		printf("\n\nnome:\t%s\ncognome:\t%s\nmatrila:\t%d", registro[i].nome, registro[i].cognome, registro[i].matricola);
	}printf("\nil numero totale di studente e':\t %d", c);
}