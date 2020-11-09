#include"BIBLI.h"

int main(void) {
	t_albero T=NULL;

	FILE* f_file_1 = fopen("alimenti.bin", "rb");
	if (f_file_1 == NULL) {
		fprintf(stderr, "\nERROre nell apertura del file_1.\n");
		exit(EXIT_FAILURE);
	}
	T = lettura_file_albero(T, f_file_1);
	printf("\tALBERO\n");
	print_albero_ordinato_prefixo(T);
	FILE* f_file_2 = fopen("pranzo.txt", "rt");
	FILE* f_file_3 = fopen("out.txt", "wt");
	if (f_file_2 == NULL) {
		fprintf(stderr, "\nERROre nell apertura del file_2.\n");
		exit(EXIT_FAILURE);
	}
	if (f_file_3 == NULL) {
		fprintf(stderr, "\nERROre nell apertura del file_3.\n");
		exit(EXIT_FAILURE);
	}
	print_albero_file(T, f_file_2,f_file_3);
	fclose(f_file_1);
	fclose(f_file_2);
	fclose(f_file_3);
	clean_albero(T);

	return 0;
}