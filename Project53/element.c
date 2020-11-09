#include"funzioni.h"

boolean isless(element A, element B) {
	if (strcmp(A.Nome, B.Nome) >= 0)return true;
	else return false;
}

boolean equalsNumber(element A) {
	if (A.Energia > Ipercalorico)return true;
	else return false;
}

