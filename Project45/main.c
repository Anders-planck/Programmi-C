#include"bibli.h"


int main(void) {
	//Tree* albero = join_albero(join_albero(new_albero(8),new_albero(3),2),new_albero(4),6);
	tree abre=NULL;
	int f;
	int x;
	
	int t;
	printf("\nquanti nodi vou inserire:\t");
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		printf("inserisci un nodo\n");
		scanf("%d", &x);
		abre=Push_nodo(abre,x);
	}
	printf("\n/*-----------------------prefix-------------------------*/\n");
	print_albero_prefix(abre);
	printf("\n/*-----------------------posfix-------------------------*/\n");
	print_albero_posfix(abre);
	printf("\n/*-----------------------posfix-------------------------*/\n");
	print_albero_inorder(abre);
	printf("il numero di nodo e':\t%d\n", count_nodo_albero(abre));


	clean_albero(abre);
	int ris, n, pr, sr, tr, b, q, i = 0;

/*	printf("inserisci un numero");
	scanf("%d", &n);
	do {
		if (n >= 100) {
			pr = n / 100;
			q = n - (pr * 100);
			sr = q / 10;
			tr = q - (sr * 10);
			ris = pr * sr * tr;
			i++;
			n = ris;
		}

		if (n < 100) {
			sr = n / 10;
			tr = n - (sr * 10);
			ris = sr * tr;
			i++;
			n = ris;
		}
	} while (ris > 2);

	printf("\nil numero di volta fatto e' %d\n\t", i);
	printf("\nil numero ricercato e'%d\t", ris);*/
	return 0;
}
