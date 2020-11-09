typedef struct {
	int idi;
	int q;
	int idt;
	int idp;
	float v;
}pacchetto;
int lettura(char[], pacchetto[]);
int byte(pacchetto [], int);
int sommatoria(pacchetto[], int);
void stampa(int);
int elabora(pacchetto[], int, pacchetto[], int , int*);
int  addattamento(pacchetto[], int, pacchetto[], int);
void verifica(pacchetto[], int);
void risultato(int, int, pacchetto[], int);
void scrittura(pacchetto[], int);

