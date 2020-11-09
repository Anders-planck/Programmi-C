#include"funzioni.h"

boolean isless(element A, element B) {
	if (strcmp(A.parola, B.parola) >= 0)return true;
	else return false;
}
boolean equals(element A) {
	if (strcmp(A.parola, Base) == 0)return true;
	else return false;
}
boolean equalsPr(element A) {
	if (A.Profondità > Profondo)return true;
	else return false;
}
void 	getelement(element x) {
	static k=0;
	printf("%d____ P:  %s\tS:  %d\tPr:  %d\n",k+1, x.parola, x.stato, x.Profondità);
	k++;
}
