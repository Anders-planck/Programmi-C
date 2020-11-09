#include<stdio.h>
#include<string.h>
#define dim 100


void stampa(char decode[]) {
	printf("\nil resultato ottenutto dalla decodifica e':\n %s",decode);
}
void decodifica (char s[], char decode[],char code[], int n, int t) {
	int a, j;
	
	for (a = 0; a < n; a++) {
		for (j = 0; j < t; j++) {
			if (code[a] == s[j])
				strncpy(decode, s, j + 1);
		}
	}
	stampa(decode);
}



void lettura(char code[],char s[],int*t, int*n) {
	printf("\ninserisci il codice sptritato:\n");
	scanf("%s", code);
	printf("\ninserisci il codice decodificante:\n");
	scanf("%s", s);
	*t = strlen(s);
	*n = strlen(code);
	printf("t=%d\nn=%d", *t, *n);
	printf("\nverifica :\n %s\n", code);
	printf("%c", code[2]);
}

main() {
	char s[dim];
	char code[dim];
	int n;
	int t;
	char decode[dim];
	lettura(code,s,&t,&n);
	decodifica(s, decode,code, n, t);
}