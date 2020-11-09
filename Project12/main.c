#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#define dim 100
#define len 20
typedef struct ospedale {
	char Pn[len];
	char In[len];
	int g;
}visita;
int ricerca(visita n, visita v[], int g) {
	int i;
	int t = 0;
	for (i = 0; i < g; i++) {
		if (strcmp(n.Pn, v[i].Pn) == 0 && strcmp( n.In, v[i].In)!=0) {
			t++;
		}
	}
	return t;
}
int calcolo(visita v[], int n, char s[]) {
	printf("\n**fase di calcolo**\n");
	int i;
	int r;
	int ro=0;
	int e;
	
	for (i = 0; i < n; i++) {
		r = ricerca(v[i], v, n);
		if (ro < r) {
			ro = r;
			strcpy(s, v[i].Pn);
		}

	}
	return ro;
}
void lettura(visita v[], int* n) {
	FILE* f;
	int e;
	int i=0;
	f = fopen("visite.txt", "rt");
	if (f == NULL) {
		printf("file indisponibile\n");
		exit(-1);
	}
	else {
		while (!feof(f)) {
			e=fscanf(f, "%s%s%d", v[i].Pn, v[i].In, &v[i].g);
			printf("%s %s %d\n", v[i].Pn, v[i].In, v[i].g);
			i++;
		}
		*n = i;
		fclose(f);
	}
}
main() {
	visita v[dim];
	int n;
	char s[len];
	int nu;
	lettura(v, &n);
	nu = calcolo(v, n, s);
	printf("\nil pui visitato  con infiermiere diverse e' %s con %d\n", s, nu);
}