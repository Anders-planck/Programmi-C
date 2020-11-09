#include<stdio.h>
#include<string.h>
#include<math.h>
typedef struct carte {
	char tipo[7];
	int y;
}carta;
typedef struct giocatori {
	carta x;
}giocatore;
giocatore risultato_presa2(giocatore gio[], int n,int tr) {
	int i;
	giocatore v;
	v = gio[tr];
	for (i = 0; i < n; i++) {
		if (strcmp(v.x.tipo, gio[i].x.tipo) == 0 && v.x.y < gio[i].x.y) {
			v = gio[i];
		}
	}return v;
}

giocatore risultato_presa(giocatore gio[], int n) {
	int i;
	giocatore v;
	v = gio[0];
	for (i = 0; i < n; i++) {
		if (strcmp(v.x.tipo, gio[i].x.tipo) == 0 && v.x.y < gio[i].x.y) {
			v = gio[i];
		}
	}return v;
}

void lettura(giocatore gio[], int n) {
	int i, j,tr=0;
	int s = 0;
	giocatore m;
	for (j = 0; j < n; j++) {
		printf("\n%d torno di gioco\n", j + 1);
		printf("inserirai le carte dei 4 giocatori\n");
		for (i = 0; i < n; i++) {
			printf("\ngiocatore %d:\ntipo carta: cuori, quadri, fiori o picche:\n", i);
			scanf("%s", gio[i].x.tipo);
			printf("numero carta:\n(tra 0---13):\n");
			scanf("%d", &gio[i].x.y);
		}
		for (i = 0; i < n; i++) {
			printf("\n\ngiocatore %d\n[%s,%d]", i, gio[i].x.tipo, gio[i].x.y);
		}
		if(j==0)
		m = risultato_presa(gio, n);
		else
			m = risultato_presa2(gio, n,tr);
		if (strcmp(m.x.tipo, gio[0].x.tipo) == 0 && gio[0].x.y == m.x.y) {
			s++;
		}
		for (i = 0; i < n; i++) {
			if (strcmp(m.x.tipo, gio[i].x.tipo) == 0 && m.x.y == gio[i].x.y) {
				printf("\n\n il giocatore vincitore della %d presa e':giocatore %d \n[%s,%d]", j, i, gio[i].x.tipo, gio[i].x.y);
				tr = i;
			}
		}
	}
	printf("il giocatore 0 ha vinto :%d ", s);
}
main() {
	int n = 4;
	giocatore gio[4];
	lettura(gio, n);
}