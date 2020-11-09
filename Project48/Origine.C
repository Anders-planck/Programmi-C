#include"bibi.h"

int main(void) {

	FILE* f = fopen("parole1.txt", "rt");
	FILE* g = fopen("parole2.txt", "rt");
	Tree L = empty();
	L = insord_on_tree(L, f, g);
	Print_tree(L);
	printf(" \t\tL'altezza del albero e' h=\t%d", altezza_of_tree(L));
	return 0;
}