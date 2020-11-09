#define len 20
typedef struct {
	char cni[len];
	char nome[len];
	char cognome[len];
	char sesso[len];
	int stato;
}registro;
int gestion_des_elettori(int*, int*, int* s ,char[], registro[], int*, char[]);
void affliggere_e(registro[], int);
void menu_ge(char []);
void menu_GE_SOTTO(char[]);
void AGGUINGGERE_ELETTORI(int*, int*, int*, char[], registro[]);
void agguinta_e(int, int, registro[]);
int esiste_e(registro, registro[], int);
void MODIFICA_DATI_e(int*, registro[], char[]);
void modifica_e(registro[], int);
void AFFLIGGERE_e(int*, registro[], char[]);
