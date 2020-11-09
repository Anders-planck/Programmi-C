#define len 20
typedef struct {
	char cni[len];
	char nome[len];
	char cognome[len];
	char sesso[len];
	float voto;
}lista;
int gestion_des_canditat(int*, int*, int*, char[], lista [], int*, char[]);
void agguinta(int, int, lista[]);
void affliggere(lista[], int);
void menu_GS(char[]);
void menu_GS_SOTTO(char[]);
int esiste(lista , lista  [], int );
void modifica(lista[], int);
void AGGUINGGERE_CANDIDATO(int*, int*, int*, char[], lista[],int*);
void MODIFICA_DATI(int*, lista[], char[]);
void AFFLIGGERE(int*, lista[], char[]);