#include<stdio.h>
#include<string.h>
#include<math.h>
#define dim 12
#define len 20
typedef struct visite
{
	char paziente[len];
	char inf[len];
	int giorno;
	
}visita;
main() {
	/*dichiarazione delle variabili*/
	visita v[dim] = {
		{ "Matusalemme","Rossi",1 },
		{ "Geremia","Verdi",2 },
		{ "Matusalemme","Verdi",2 },
		{ "Gioele","Rossi",2 },
		{ "Matusalemme","Verdi",3 },
		{ "Giobbe","Verdi",3 },
		{ "Matusalemme","Rossi",3 },
		{ "Geremia","Bianchi",4 },
		{ "Giobbe","Verdi",4 },
		{ "Geremia","Rossi",5 },
		{ "Matusalemme","Rossi",4 },
		{ "Geremia","Neri",6 } };
	int i;
	int Mu = 0, Ge = 0, Gi = 0;
	/*verificazione dati*/
	for (i = 0; i < dim; i++)
		printf("\n{%s,%s,%d}", v[i].paziente, v[i].inf, v[i].giorno);
	/*elaborazione*/
	printf("\n");
	for (i = 0; i < dim; i++) {
		if (strcmp(v[i].paziente, "Matusalemme") == 0) {
			Mu = Mu + v[i].giorno;
		}if (strcmp(v[i].paziente, "Geremia") == 0) {
			Ge = Ge + v[i].giorno;
		}if (strcmp(v[i].paziente, "Giobbe") == 0) {
			Gi = Gi + v[i].giorno;
		}
	}
	/*verificazione 2*/
	printf("\ni pazienti hanno avuto questa frequebza di visita:\n");
	printf("\nMatusalemme:\t%d ore", Mu);
	printf("\nGeremia:\t%d ore", Ge);
	printf("\nGiobbe:\t%d ore", Gi);
	/*seguito elaborazione*/
	if (Mu < Ge && Gi < Mu) 
		printf("\nil paziente piu visitato e stato :\nGeremia,con %d ore", Ge);
	if (Mu < Gi && Ge < Mu) 
		printf("\nil paziente piu visitato e stato :\nGiobbe,con %d ore", Gi);
	if (Ge<Gi && Mu>Gi) 
		printf("\nil paziente piu visitato e stato :\nMatusalemme,con %d ore\n", Mu);
	
}