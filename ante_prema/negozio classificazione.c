#include<stdio.h>
#define dim 20
#define len 200
#include<string.h>
typedef struct magasin {
	char nome[dim];
	int quantita;
	int anno;
}reg;
main(){
 reg registro1[len];
 int data[len];
 reg scaduti[len];
 int i=0;
 int b,d,c=0;
 int oggi;
 char ris[dim],ris1[dim], ris3[dim];
	do {
		
		printf("\n prodotti da clasificare:\t\nscrivi(si) per si o(no) per no  ");
		scanf("%s", ris);
		if (strcmp(ris, "si") == 0) {
			printf("\ninserisci il numero di prodotto da classificare:\t ");
			scanf("%d", &b);
			while (i < b) {
				printf("\n inserire il nome del %d prodotto:\t", i + 1);
				scanf("%s", registro1[i].nome);
				printf("\ninserisci il numero di prodotto:\t ");
				scanf("%d", &registro1[i].quantita);
				printf("\ninserisci la data di  scandenza:\t ");
				scanf("%d", &registro1[i].anno);
				i++;
			}
			printf("\nvuoi visualizzare la data base:\nrispondi con  (si) o (no):\t");
			scanf("%s", ris1);
			if (strcmp(ris, "si") == 0) {
				printf("\nla tua data base e':\n");
				for (i = 0; i < b; i++)
					printf("\n prodotto nome:\t%s\nprodotto quantita:\t%d\nanno scandenza:\t%d", registro1[i].nome, registro1[i].quantita, registro1[i].anno);
			}
			else
				printf("\nGrazie\n");

			/*printf("\ninserisci le date di scandenza dei prodotti in modo elecato:\n");
			for (i = 0; i < b; i++) {
				printf("\ndata scadenza %d prodotto:\t", i + 1);
				scanf("%d", &data[i]);
			}

			for (i = 0; i < b; i++) {
				if (registro1[i].anno == data[i] || registro1[i].anno >= data[i]) {
					scaduti[c].anno = registro1[i].anno;
					strcpy(scaduti[c].nome, registro1[i].nome);
					scaduti[c].quantita = registro1[i].quantita;
					d = c++;
				}*/

			printf("\ninserici anno di oggi :\t");
			scanf("%d", &oggi);

			for (i = 0; i < b; i++) {
				if (registro1[i].anno == oggi || registro1[i].anno <= oggi) {
					scaduti[c].anno = registro1[i].anno;
					strcpy(scaduti[c].nome, registro1[i].nome);
					scaduti[c].quantita = registro1[i].quantita;
					d = c++;
				}
				else {
					scaduti[c].anno = registro1[i].anno;
					strcpy(scaduti[c].nome, registro1[i].nome);
					scaduti[c].quantita = registro1[i].quantita;
					printf("\n non e scaduto :\nprodotto nome : \t%s\nprodotto quantita : \t%d\nanno scandenza : \t%d", scaduti[c].nome, scaduti[c].quantita, scaduti[c].anno);
		}
				printf("\n");
			}
			for (c = 0; c < d; c++)
				printf("\n prodotto nome : \t%s\nprodotto quantita : \t%d\nanno scandenza : \t%d", scaduti[c].nome, scaduti[c].quantita, scaduti[c].anno);

		} else {
			printf("\nGrazie\n");
		}
		printf("\nscrivi (fine) per chuidere il programma o scrivi (si) per continuare:\t");
		scanf("%s", ris);
	} while (strcmp(ris, "fine") != 0);
}