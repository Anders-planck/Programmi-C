#define _CRT_SECURE_NO_WARNINGS
#define len 20
typedef struct {
	char inf[len];
	float x, y;
}paziente;
int  lettura(paziente[]);
float distanza(paziente[], char[], int);
int raggruppa(paziente, paziente[], int, paziente[]);
float calcolo(paziente, paziente);
void stampa(float, char[]);
float percorso(int, paziente[]);
int verifica(paziente, paziente[], int);

