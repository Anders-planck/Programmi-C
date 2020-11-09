#include<stdio.h>
#include<math.h>
#include<string.h>
#define dim 100

typedef struct vet {
	float x, y;
}vettore;
float scalare(vettore x, vettore y) {
	float s;
	s = (x.x * y.x) + (x.y * y.y);

	return s;
}
void costruzione(vettore t[], int  n) {
	printf("**ortogonalisazione**(esso si fa grazie alla formula di gram schimdt basata sull uso del coeffieciente di fourrier)\nil sistamo verra aggiornato tra un po");
	//ortogonalizzazione
	int i = 1;
	float s;
	float e;
	float z;
	do {

		s = scalare(t[i], t[0]);
		e = scalare(t[0], t[0]);
		t[i].x = t[i].x - ((s / e)*t[0].x);
		t[i].y = t[i].y - ((s / e)*t[0].y);
		i++;
	} while (i < n);
	printf("\n**ortogonalisazione**consiste solo a fare diventare versori ogni ellemento delle base ortogonale ottenuta");
	i = 0;
	do {
		z = (sqrt((t[i].x*t[i].x) + (t[i].y*t[i].y)));
		t[i].x = (float)t[i].x / z;
		t[i].y = (float)t[i].y / z;
		i++;
	} while (i < n);
}
vettore  punti_base(vettore w[], int n1, vettore v, vettore s) {
	int i = 0;
	do {
		s.x = (v.x * w[i].x) + (v.y * w[i].y);
		s.y = (v.x * w[i + 1].x) + (v.y * w[i + 1].y);
		i = i + 2;
	} while (i > n1);
	return s;
}
void ortonomalita(vettore a[], int n, int*o, int*o2, int*o1) {
	printf("\nverifica del ortogonalita");
	int i;
	float c, r;
	vettore b;
	b.x = a[0].x;
	b.y = a[0].y;
	for (i = 1; i < n; i++) {
		c = (float)sqrt((a[i].x*a[i].x) + (a[i].y*a[i].y));
		r = (float)sqrt((b.x*b.x) + (b.y*b.y));
		if (((b.x * a[i].x) + (b.y * a[i].y)) == 0 && c == 1 && r == 1) {
			*o = 1;
		}
		else {
			*o = 0;
			*o1 = 0;
			if (r != 1)
				* o2 = 0;
		}
	}
}
void stampa(vettore a[], int n) {
	printf("\n");
	int i;
	for (i = 0; i < n; i++) {
		printf("\t[%.1f,%.1f]", a[i].x, a[i].y);
	}
}
void lettura(vettore a[], int*n) {
	int i;
	printf("\nqunati vettori vuoi inserire?\t");
	scanf("%d", n);
	for (i = 0; i < *n; i++) {
		printf("inserici i volori del %d vettore:\n", i + 1);
		scanf("%f%f", &a[i].x, &a[i].y);

	}
}
main()
{

	//algoritmo che verifica se dei  vettori fomano una base ortonormale
	printf("algoritmo che verifica se dei  vettori fomano una base ortonormale\n");
	printf("inserisci una base qualunque dormata al piu da 2 vettori poiche  nostro lavoro si tiene in R2");
	int n, n2;
	int o, o1, o2;
	char ris[dim] = { "no" };
	char ris1[dim];
	char ris2[dim];
	vettore a[dim];
	vettore w[dim];
	vettore v;
	vettore s;
	vettore t[dim];
	do {
		lettura(a, &n);
		printf("\nverifica dati:\n");
		stampa(a, n);
		printf("\nIn generale due vettori fomano una base ortonormale se:-sono ortogonali 2 a 2(V1*V2=0).\n-sono versori(ovvero hanno una norma uguale a 1(||v||=1)\n");
		ortonomalita(a, n, &o, &o2, &o1);
		if (o == 0) {
			if (o1 == 0)
				printf("\ni tuoi vettori non sono ortogonali");
			else if (o2 == 0)
				printf("\ni tuoi vettori non sono versori");
			else if (o1 == 0 && o2 == 0)
				printf("\ni tuoi vettori non formano una base perche non soddisfano le condizioni:\nDue vettori fomano una base ortonormale se:\n-sono ortogonali 2 a 2(V1*V2=0).\n-sono versori(ovvero hanno una norma uguale a 1(||v||=1\n\n");
			printf("\nvoui riprovare un inserimento(si/no):\t");
			scanf("%s", ris);
		}
		else {
			printf("\ni tue vettori sono ortogonali e versori .....percio **fomano una base ortonormale** di R%d", n);
			stampa(a, n);
			printf("\nvoui continuare la lezione sugli spazi eclidei reali(s.e.r)?(si/no)\t");
			scanf("%s", ris1);
		}
		if (strcmp(ris1, "si") != 0)
			printf("\nGrazie e Arrivederci");
		else if (strcmp(ris1, "si") == 0) {
			printf("\nCoordinate di un punto rispetto ad una base ortonamale \n\n");
			printf("Per proseguire questa lezione ci occore una base ortonormale.....\nvuoi che consideriamo quella accertata prima(si)?\nvuoi inserire un altra(altra)\nrisposta:\t");
			scanf("%s", ris2);

			if (strcmp(ris2, "si") == 0) {
				printf("\nlavorero con questa base qua:\n");
				stampa(a, n);
				printf("\ninserire le coordinate del vettore originale :\n");
				scanf("%f%f", &v.x, &v.y);
				s = punti_base(a, n, v, s);
				printf("\nLe coordinate di questo vettore rispetto a lq nuova base e':\nv=(%.1f,%.f)", s.x, s.y);
			}
			else if (strcmp(ris2, "altra") == 0) {


				printf("inserire le coordinate del vettore originale :\n");
				scanf("%f%f", &v.x, &v.y);
				int n1;
				printf("\ncon n=2");
				lettura(w, &n1);
				printf("\nverifica dati:\n");
				stampa(w, n1);
				ortonomalita(w, n1, &o, &o2, &o1);
				if (o == 0) {
					if (o1 == 0)
						printf("\ni tuoi vettori non sono ortogonali");
					else if (o2 == 0)
						printf("\ni tuoi vettori non sono versori");
					else if (o1 == 0 && o2 == 0)
						printf("\ni tuoi vettori non formano una base perche non soddisfano le condizioni:\nDue vettori fomano una base ortonormale se:-sono ortogonali 2 a 2(V1*V2=0).\n-sono versori(ovvero hanno una norma uguale a 1(||v||=1\n\n");
				}
				else {
					printf("\ni tue vettori sono ortogonali e versori .....percio **fomano una base ortonormale** di R%d", n1);
					stampa(a, n);
					s = punti_base(a, n, v, s);
					printf("Le coordinate di questo vettore rispetto a lq nuova base e':\nv=(%.1f,%.1f)", s.x, s.y);
				}
			}
		}

		printf("\nfatto cio vorresti continuare con  la costruzione di una base ortonomale(si/no):  ");
		scanf("%s", ris2);
		if (strcmp(ris2, "si") != 0)
			printf("\nGrazie e Arrivederci");
		else if (strcmp(ris2, "si") == 0) {
			printf("\n\nPer costruire une base ortonormale(base che ci sara molto utile nella diagonalizzazione delle matrice quadrate) ci occore :\n--ortogonalizzarla\n--rendere ogni componente delle base ottenuta in versore...\n\nper fare cio inserisci una base qualunque dormata al piu da 2 vettori poiche  nostro lavoro si tieni in R2\n\n");
			lettura(t, &n2);
			printf("\nverifica daati\n");
			stampa(t, n);
			costruzione(t, n);
			printf("\nla tua base ortonale e':\n");
			stampa(t, n);
		}
		printf("vuoi chuidere il programa (si/no)?    ");
		scanf("%s", ris);
	} while (strcmp(ris, "si") != 0);
}