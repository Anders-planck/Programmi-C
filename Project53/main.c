#include"funzioni.h"

int main(void) {
	tree T=NULL;
	FILE*f = fopen("alimenti.bin", "rb");
	assert(f != NULL);
	FILE* g = fopen("ipertree.txt", "wt");
	assert(g != NULL);
	FILE* h = fopen("teoria5.txt", "wt");
	assert(h != NULL);
	T = FunzioneA(T, f);
	FunzioneB(T);
	FunzioneC(T, g);

	Esecizio_2(h);
	close(f, g, h);
	return;
}