#include"fun.h"



boolean isMinor(Progetto x, offerte y) {
	if (x.infoCO.budget > y.Offerta)return true;
	else return false;
}

boolean isMagior_CC(finaly x, finaly y) {
	if (x.info.codice > y.info.codice)return true;
	else return false;
}
boolean isMinor_OO(finaly x, finaly y) {
	if (x.info.Offerta > y.info.Offerta)return true;
	else return false;
}

boolean isEqualsCC(Progetto x, offerte y) {
	if (x.codice == y.codice)return true;
	else return false;
}

finaly Newfinaly(Progetto x, offerte y) {
	finaly final;
	final.info = y;
	final.infoCO = x.infoCO;
	return final;
}

void getFinaly(finaly x) {
	
	printf(" C: %d\tCo: %s\tOf:  %s\t[B: %d ___  O: %d ]\n  ", x.info.codice, x.infoCO.committente, x.info.Offerente, x.infoCO.budget, x.info.Offerta);
		
}
boolean isEqualsOO(finaly x) {
	if (strcmp(x.info.Offerente, "CESA") == 0)return true;
	else return false;
}