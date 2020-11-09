#include<stdio.h>
#include<math.h>
#include<string.h>
#define dim 100
typedef struct paesi {
	char nome[20];
	double lg;
	double lr;
}album;

typedef struct {
	char nome[20];
	double ris[dim];
	
}risu;

void elabora(album p[], int n) {
	int i;
	album b[dim];
	risu a[dim];
	int j = 0;
	for (i = 0; i < n; i++) {
		
			strcpy(a[i].nome, p[j].nome);
			a[j].ris[i] = sqrt(((pow((p[i+1].lg - p[i].lg), 2)) + pow((p[i+1].lr - p[i].lr), 2)));
	}
	for (i = 0; i < n; i++) {

			printf("%s-->%f\n", a[i].nome, a[i].ris[i]);
		}
	}
void lettura(album p[], int *n) {
	int i, m=21;
	album y[]= {
		{ "Ferrara",44.830551,11.617699 },
		{ "Focomorto",44.831528,11.678467 },
		{ "Palmirano",44.780617,11.695290 },
		{ "Portomaggiore",44.696968,11.804466 },
		{ "Molinella",44.617355,11.668510 },
		{ "Cento",44.728931,11.289482 },
		{ "Bondeno",44.887257,11.420975 },
		{ "Mirandola",44.886524,11.063919 },
		{ "Cenacchio",44.694286,11.430931 },
		{ "Minerbio",44.623955,11.490326 },
		{ "Consandolo",44.653023,11.775627 },
		{ "Argenta",44.614666,11.833305 },
		{ "Filo",44.587044,11.929092 },
		{ "Comacchio",44.692577,12.182808 },
		{ "Lagosanto",44.761604,12.139549 },
		{ "Codigoro",44.828846,12.107964 },
		{ "Mesola",44.919842,12.228470 },
		{ "Alberazzo",44.888229,12.250099 },
		{ "Goro",44.853191,12.298508 },
		{ "Donzella",44.930050,12.328033 },
		{ "Copparo",44.891392,11.825409 },
		{ "Tamara",44.875580,11.771851 },
		{ "Pontelagoscuro",44.874119,11.606712 },
		{ "Spinazzino",44.709904,11.630745 }
	}; for (i = 0; i < m; i++)
		p[i] = y[i];
	*n =m;
}
main() {
	album p[dim];
	int n;
	lettura(p, &n);
	elabora(p, n);
}