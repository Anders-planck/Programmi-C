#include"bibli.h"

boolean even_number(Element x) {
	if (x % 2 == 0)return true;
	else return false;
}
boolean isless(Element x, Element y) {
	if (x > y)return true;
	else return false;
}

boolean isEqual(Element x, Element y) {
	if (x == y) return true;
	else return false;
}
Element getElement(void) {
	Element element;
	printf("\n");
	printf("inserisci un numero :\t");
	scanf_s("%d", &element);
	return element;
}

void printElement(Element x) {
	printf("\t%d", x);
}
boolean isNULL(Element x) {
	if (x == 0)return true;
	else return false;
 }