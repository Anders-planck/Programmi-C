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
	char nom[len], prenom[len];
	i = 1;
	registro[0].matricola =1;
	while (registro[i-1].matricola != 0){
		printf("\n inserire i tuoi dati:\ninserisci il tuo norme:\t");
		scanf("%s", registro[i].nome);
		printf("\ninserisci il tuo cognome:\t");
		scanf("%s", registro[i].cognome);
		printf("\ninscerisci una matricola di 6 chifre:\t");
		scanf("%d", &registro[i].matricola);
		i++;
	} 
	
	i = 1;
	do {
		printf("\ni  dati  del registro sono questi :\nnome:\t%s\ncognome:\t%s\nmatrila:\t%d", registro[i].nome, registro[i].cognome, registro[i].matricola);
		i++;
	} while (registro[i-1].matricola != 0);

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
			printf("\nricerca in corso");
		}
		i++;
	} while (registro[i].matricola != 0);
	
	printf("\nwaaawwwwwwwwww\n");

}