#define _CRT_SECURE_NO_WARNINGS
#define len 20
typedef struct {
	char inf[len];
	float x, y;
}paziente;
int  lettura(paziente[]);
float distanza(paziente[], char[], int);
int raggruppa(paziente[], char[], int, paziente[]);
float calcolo(paziente, paziente);
void stampa(float, char[]);

