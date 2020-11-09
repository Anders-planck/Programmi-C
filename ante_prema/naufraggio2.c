#include<stdio.h>
main() {
	int s,ris,n,m;
	printf("inserisci un numero ");
	scanf("%d%d%d",&s,&n,&m);
	if (n >= m) {
		ris = s - (n / m);
		printf("\ne' possibile soppravivere ma dovrete richierdere provisti per %d\t", ris);
	}
	else if (n < m) {
		printf("non potrete sopravivere perche il numero di cibo xconsumato al giorno e' tropp importante");
	}
}