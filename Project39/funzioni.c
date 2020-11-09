#define max 100
#include "funzion.h"
int lettura(investimento azioni[]) {
	int i = 0;
	int j=0;
	FILE *f;
	f=fopen("azioni.txt", "rt");
	if (f == NULL) {
		printf("Errore di lettura\n");
		exit(-1);
	}
	else {
		while (!feof(f)) {
			fscanf(f, "%s", azioni[i].nome);
			printf("%d** %s ", i + 1, azioni[i].nome);
			printf("[");
			for (j = 0; j < 30; j++) {
				fscanf(f, "%d", &azioni[i].profitto[j]);
				printf(" %d ", azioni[i].profitto[j]);
			}
			printf("]\n");
			i++;
		}
	}
	fclose(f);
	return i;
}


int elabora(investimento azioni[], int n,char azione[],int*proffito,guadagno x[]) {
	int i;
	int maxx = 0;
	int revenu = 0;
	int position;
	int j = 0;
	for (i = 0; i < n; i++) {
		revenu = calcolo(azioni[i],x,j);
		if (maxx < revenu ) {
			maxx = revenu;
			position = i;
		}
		j = j + 1;
	}
	*proffito = maxx;
	strcpy(azione, azioni[position].nome);
	return position;
}

int calcolo(investimento f,guadagno x[],int j) {
	int i;
	int som = 0;
	for (i = 0; i < dim; i++) {
		som = som + f.profitto[i];
	}
	x[j].guadagno = som;
	strcpy(x[j].nome, f.nome);
	return som;
}

void stampa(char azione[], int j, int proffito, guadagno x[],investimento azioni[],int n) {
	int i;
	printf("\t\t\t\t\tLISTA DI TUTTI I PROFFITI PER SCIASCUNA AZIONE\n");
	for (i = 0; i < n; i++) {
		printf(" %d*** %s al termine dei 30 mesi avrebbe datto :   %d\n",i+1, x[i].nome, x[i].guadagno);
	}
	printf("\t\t\t\t\t\tL INVESTIMENTO PUI RENTABLE:\n ");
	printf("-->  %s al termine dei 30 mesi avrebbe datto   %d\n", azione, proffito);
	printf("-->  %s [",azioni[j].nome);
	for (i = 0; i < dim; i++) {
		printf(" %d ",azioni[j].profitto[i]);
	}
	printf("]\n");
}


int elabora_2(investimento azioni[], int n, char azione[], int* proffito, guadagno x[], int* mese_i, int* mese_f) {
	int i;
	int maxx = 0, recu = 0;
	int j = 0;
	int position=0;
	printf("inserisci la fascia di mese tra il 0 e il 29 mese:\n");
	printf("mese di INIZIO:\t");
	scanf("%d", &(*mese_i));
	printf("mese di FINE:\t");
	scanf("%d", &(*mese_f));
	if (*mese_i < 0 || *mese_i>29 || *mese_f < 0 || *mese_f>29 || *mese_i > *mese_f) {
		verifica(&(*mese_i), &(*mese_f));
	}
		for (i = 0; i < n; i++) {
			recu = revenu(azioni[i], *mese_i, *mese_f, x, j);
			if (maxx < recu) {
				maxx = recu;
				position = i;

			}
			j++;
		}
		*proffito = maxx;
		strcpy(azione, azioni[position].nome);
	return position;
}

int revenu(investimento f, int in,int fi,guadagno x[],int j) {
	int i;
	int som = 0;
	for (i = in; i <= fi; i++) {
		som = som + f.profitto[i];
	}
	x[j].guadagno = som;
	strcpy(x[j].nome, f.nome);
	return som;
}
stampa_2(char azione[],int j,int proffito,guadagno x[],investimento azioni[],int n,int mese_i,int mese_f) {
	int i;
	printf("\t\t\t\t\tLISTA DI TUTTI I PROFFITI PER SCIASCUNA AZIONE\n");
	for (i = 0; i < n; i++) {
		printf(" %d*** %s al termine dei %d--%d mesi avrebbe datto :   %d\n", i + 1, x[i].nome,mese_i,mese_f, x[i].guadagno);
	}
	printf("\t\t\t\t\t\tL INVESTIMENTO PUI RENTABLE:\n ");
	printf("-->  %s al termine dei  %d--%d mesi avrebbe datto   %d\n", azione, mese_i , mese_f, proffito);
	printf("-->  %s [", azioni[j].nome);
	for (i = mese_i; i <= mese_f; i++) {
		printf(" %d ", azioni[j].profitto[i]);
	}
	printf("]\n");
}
void verifica(int *mese_i,int *mese_f) {
	while (*mese_i < 0 || *mese_i>29 || *mese_f < 0 || *mese_f>29 || *mese_i > * mese_f) {
		printf("ERRORE IL MESE DI INIZIO E QUELLO DI FINE\n");
		printf("mese di INIZIO:\t");
		scanf("%d", &(*mese_i));
		printf("mese di FINE:\t");
		scanf("%d", &(*mese_f));
	}
}

void menu(int* risposta) {
	printf("\t\t\t\t\tMENU\n");
	printf("\t\t\t 1  :  I prima parte compito\n");
	printf("\t\t\t 2  :  II prima parte compito\n");
	printf("NOMINA L OPERAZIONE CHE DESIDERI FARE COL SUO  NUMERO INDICATIVO:\t");
	scanf("%d", &(*risposta));
}