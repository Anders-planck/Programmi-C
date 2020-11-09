#include"funzioni.h"


void main(void) {
	list L = NULL;
	FILE* f = fopen("mara.txt", "rt");
	assert(f != NULL);
	FILE* g = fopen("lucia.txt","rt");
	assert(g != NULL);
	FILE* h = fopen("parole.txt", "wt");
	assert(h != NULL);
	FILE* e = fopen("teoria.txt", "wt");
	assert(e != NULL);
	FILE* i = fopen("Profondità.txt", "wt");
	assert(i != NULL);

	L = FunzioneA(L, f);
	
	L = FunzioneA(L, g);

	FunzioneB(L);

	FunzioneC(L, h,i);

	Esercizio_2(e);
	close(f, g, h,e,i);
}