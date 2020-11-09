#include<stdio.h>
void lettura(long int *millisec) {
	printf("inserisci un numero\t");
	scanf("%d", millisec);
}
void fromMillisec(int millisec, int* sec, int* min, int*mm) {
	int i = 0;
	int f;
	
	*sec = millisec / 1000;
	f = *sec;
	while (f > 60) {
		i = i+1;
		f = f - 60;
	}
	*min = i;
	*sec = f;
		*mm = millisec-((millisec/1000)*1000) ;
}
main() {
	long int  millisec;
	int sec;
	int min;
	int mm;
	lettura(&millisec);
	fromMillisec(millisec, &sec, &min, &mm);
	printf("\n%d min:\t%d sec . %d ms\n", min, sec, mm);
}