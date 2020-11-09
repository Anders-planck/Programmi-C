#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#define dim 1000
typedef struct {
	char nome[20];
	double ris;
}rep;
typedef struct {
	char nome[20];
	double lg;
	double lr;
}paese;
double  distanza(paese citta[], int i, int j) {
	double s, c, f;
	c = (citta[j].lg - citta[i].lg);
	f = citta[j].lr - citta[i].lr;
	s = (pow(c, 2) + pow(f, 2));
	return s;
}
void elabara(paese citta[], int n) {
	rep repi[dim];
	double d, g = 0;
	rep a[dim];
	int i;
	int j;
	double min = 1000;
	for (i = 0; i < n; i++) {
		g = 0;
		for (j = 0; j < n; j++) {
			strcpy(repi[j].nome, citta[j].nome);
			d = distanza(citta, i, j);
			repi[j].ris = sqrt(d);
			g = g + repi[j].ris;
		}
		strcpy(a[i].nome, citta[i].nome);
		a[i].ris = g / n;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("\nper andare a %s-->%.2f km", repi[j].nome, repi[j].ris);
		}
		printf("\nla media e':\t%.2f", a[i].ris);
	}
	for (i = 0; i < n; i++) {
		if (min > a[i].ris) {
			min = a[i].ris;
		}
	}for (i = 0; i < n; i++) {
		if (min == a[i].ris) {
			printf("\nla schelta migliore e quella di istallare il magazzino a: \n{%s perche ha corto di %.2f", a[i].nome, a[i].ris);
		}
	}
}


void lettura(paese citta[], int* n) {
	int m = 24;
	*n = m;
	int i;
	paese fcitta[] = {
		{"Ferrara",44.830551,11.617699},
		{"Focomorto",44.831528,11.678467},
		{"Palmirano",44.780617,11.695290},
		{"Portomaggiore",44.696968,11.804466},
		{"Molinella",44.617355,11.668510},
		{"Cento",44.728931,11.289482},
		{"Bondeno",44.887257,11.420975},
		{"Mirandola",44.886524,11.063919},
		{"Cenacchio",44.694286,11.430931},
		{"Minerbio",44.623955,11.490326},
		{"Consandolo",44.653023,11.775627},
		{"Argenta",44.614666,11.833305},
		{"Filo",44.587044,11.929092},
		{"Comacchio",44.692577,12.182808},
		{"Lagosanto",44.761604,12.139549},
		{"Codigoro",44.828846,12.107964},
		{"Mesola",44.919842,12.228470},
		{"Alberazzo",44.888229,12.250099},
		{"Goro",44.853191,12.298508},
		{"Donzella",44.930050,12.328033},
		{"Copparo",44.891392,11.825409},
		{"Tamara",44.875580,11.771851},
		{"Pontelagoscuro",44.874119,11.606712},
		{"Spinazzino",44.709904,11.630745}
	};
	for (i = 0; i < m; i++) {
		citta[i] = fcitta[i];
	}
}
main() {
	paese citta[dim];
	int n;
	lettura(citta, &n);
	elabara(citta, n);
	printf("\n\nwaawwwwwww\n");

}