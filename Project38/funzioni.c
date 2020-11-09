#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include "elabora.h"
#define N_c 10
#define N_e 1000
#define len 20
#define tentativo 2


void VERIFICA(char risposta_menu[]) {
	while (strcmp(risposta_menu, "GC") != 0 && strcmp(risposta_menu, "GE") != 0 && strcmp(risposta_menu, "CS") != 0 && strcmp(risposta_menu, "V") != 0 && strcmp(risposta_menu, "Q") != 0) {
		printf("[[[ERRORE  COMANDO NON RICONOSCUITO\n devi inserire una sigla tra quelle tra parentesi]]]\n");
		menu();
		risposta_utente(risposta_menu);
	}
 }
void menu() {
	printf("\t\t\t\t\tSISTEMA ELETTORALE\n");
	printf("** Gestion des candidats(GC)\n** Gestion des electeurs(GE)\n** Voter(V)\n** Consulter les statistiques(CS)\n** Quitter(Q)\n");
}

void risposta_utente(char risposta_menu[]) {
	printf("\nqualunque desidera fare lei verra riscritto nel campo seguente <ris> con la sigla prosseguita da la funzione  desiderata\n\t*ris:\t");
	scanf("%s",risposta_menu);
}

int trattamento_dati(char risposta_menu[], int* Ap_Ch) {
	char mot_passe[len];
	char ris_gs[len];
	char ris_ge[len];
	lista candidati[N_c];
	registro elettori[N_e];
	int t = 0;
	int n = 0;
	int s;
	int te = 0;
	int ne = 0;
	int se;
	int ris = 0;
	int bull_nul = 0;
	VERIFICA(risposta_menu);
	if (strcmp(risposta_menu, "GC") == 0 && verifica(mot_passe) == 1) {
		while (strcmp(risposta_menu, "GC") == 0) {
			if (strcmp(risposta_menu, "GC") == 0) {
				menu_GS(ris_gs);
				int r = gestion_des_canditat(&n, &t, &s, ris_gs, candidati, &(*Ap_Ch), risposta_menu);
			}
			else {
				printf("\n NB: non avendo in conoscenza la password;\n utente sarrebbe dunque un elettore percio non puo che usufrire del parte <<voter(v)>>\nvoglia digita la sigla prosegguita o se vuole lasciare il programa sciva (Q)\n\t*ris:\t");
				scanf("%s", risposta_menu);
			}
			menu();
			risposta_utente(risposta_menu);
			VERIFICA(risposta_menu);
		}
	}
	if (strcmp(risposta_menu, "GE") == 0 && verifica(mot_passe) == 1) {
		while (strcmp(risposta_menu, "GE") == 0) {
			if (strcmp(risposta_menu, "GE") == 0) {
				menu_ge(ris_ge);
				int re = gestion_des_elettori(&ne, &te, &se, ris_ge, elettori, &(*Ap_Ch), risposta_menu);
			}
			else {
				printf("\n NB: non avendo in conoscenza la password;\n utente sarrebbe dunque un elettore percio non puo che usufrire del parte <<voter(v)>>\nvoglia digita la sigla prosegguita o se vuole lasciare il programa sciva (Q)\n\t*ris:\t");
				scanf("%s", risposta_menu);
			}
			menu();
			risposta_utente(risposta_menu);
			VERIFICA(risposta_menu);
		}


		if (strcmp(risposta_menu, "GC") == 0 && verifica(mot_passe) == 1) {
			while (strcmp(risposta_menu, "GC") == 0) {
				if (strcmp(risposta_menu, "GC") == 0) {
					menu_GS(ris_gs);
					int r = gestion_des_canditat(&n, &t, &s, ris_gs, candidati, &(*Ap_Ch), risposta_menu);
				}
				else {
					printf("\n NB: non avendo in conoscenza la password;\n utente sarrebbe dunque un elettore percio non puo che usufrire del parte <<voter(v)>>\nvoglia digita la sigla prosegguita o se vuole lasciare il programa sciva (Q)\n\t*ris:\t");
					scanf("%s", risposta_menu);
				}
				menu();
				risposta_utente(risposta_menu);
				VERIFICA(risposta_menu);
			}
		}
		if (strcmp(risposta_menu, "GE") == 0 && verifica(mot_passe) == 1) {
			while (strcmp(risposta_menu, "GE") == 0) {
				if (strcmp(risposta_menu, "GE") == 0) {
					menu_ge(ris_ge);
					int re = gestion_des_elettori(&ne, &te, &se, ris_ge, elettori, &(*Ap_Ch), risposta_menu);
				}
				else {
					printf("\n NB: non avendo in conoscenza la password;\n utente sarrebbe dunque un elettore percio non puo che usufrire del parte <<voter(v)>>\nvoglia digita la sigla prosegguita o se vuole lasciare il programa sciva (Q)\n\t*ris:\t");
					scanf("%s", risposta_menu);
				}
				menu();
				risposta_utente(risposta_menu);
				VERIFICA(risposta_menu);
			}
		}
	}

		if (strcmp(risposta_menu, "V") == 0) {
			while (strcmp(risposta_menu, "V") == 0) {
				ris = votare(elettori, candidati, ne, n, &bull_nul) + ris;
				if (ris >= 1)
					*Ap_Ch = 1;
				menu();
				risposta_utente(risposta_menu);
				while (strcmp(risposta_menu, "GC") != 0 && strcmp(risposta_menu, "GE") != 0 && strcmp(risposta_menu, "MD") != 0 && strcmp(risposta_menu, "Q") != 0) {
					printf("\t\tERRORE  COMANDO NON RICONOSCUITO\n devi inserire una sigla tra quelle tra parentesi\n");
					menu();
					risposta_utente(risposta_menu);
					VERIFICA(risposta_menu);
				}
			}
			if (strcmp(risposta_menu, "GC") == 0 && verifica(mot_passe) == 1) {
				while (strcmp(risposta_menu, "GC") == 0) {
					if (strcmp(risposta_menu, "GC") == 0) {
						menu_GS(ris_gs);
						int r = gestion_des_canditat(&n, &t, &s, ris_gs, candidati, &(*Ap_Ch), risposta_menu);
					}
					else {
						printf("\n NB: non avendo in conoscenza la password;\n utente sarrebbe dunque un elettore percio non puo che usufrire del parte <<voter(v)>>\nvoglia digita la sigla prosegguita o se vuole lasciare il programa sciva (Q)\n\t*ris:\t");
						scanf("%s", risposta_menu);
					}
					menu();
					risposta_utente(risposta_menu);
					VERIFICA(risposta_menu);
				}
			}
			if (strcmp(risposta_menu, "GE") == 0 && verifica(mot_passe) == 1) {
				while (strcmp(risposta_menu, "GE") == 0) {
					if (strcmp(risposta_menu, "GE") == 0) {
						menu_ge(ris_ge);
						int re = gestion_des_elettori(&ne, &te, &se, ris_ge, elettori, &(*Ap_Ch), risposta_menu);
					}
					else {
						printf("\n NB: non avendo in conoscenza la password;\n utente sarrebbe dunque un elettore percio non puo che usufrire del parte <<voter(v)>>\nvoglia digita la sigla prosegguita o se vuole lasciare il programa sciva (Q)\n\t*ris:\t");
						scanf("%s", risposta_menu);
					}
					menu();
					risposta_utente(risposta_menu);
					while (strcmp(risposta_menu, "GC") != 0 && strcmp(risposta_menu, "GE") != 0 && strcmp(risposta_menu, "MD") != 0 && strcmp(risposta_menu, "Q") != 0) {
						printf("\t\tERRORE  COMANDO NON RICONOSCUITO\n devi inserire una sigla tra quelle tra parentesi\n");
						menu();
						risposta_utente(risposta_menu);
						VERIFICA(risposta_menu);
					}
				}
			}
		
		}
		if (strcmp(risposta_menu, "CS") == 0 && verifica(mot_passe) == 1) {
			while (strcmp(risposta_menu, "CS") == 0) {
				if (strcmp(risposta_menu, "CS") == 0)
					statistica(ris, candidati,elettori,ne, n,bull_nul);
				else {
					printf("\n NB: non avendo in conoscenza la password; utente sarrebbe dunque un elettore percio non puo che usufrire del parte <<voter(v)>>\nvoglia digita la sigla prosegguita o se vuole lasciare il programa sciva (Q)\n\t*ris:\t");
					scanf("%s", risposta_menu);
				}
				menu();
				risposta_utente(risposta_menu);
				VERIFICA(risposta_menu);
			}
			
			if (strcmp(risposta_menu, "GC") == 0 && verifica(mot_passe) == 1) {
				while (strcmp(risposta_menu, "GC") == 0) {
					if (strcmp(risposta_menu, "GC") == 0) {
						menu_GS(ris_gs);
						int r = gestion_des_canditat(&n, &t, &s, ris_gs, candidati, &(*Ap_Ch), risposta_menu);
					}
					else {
						printf("\n NB: non avendo in conoscenza la password;\n utente sarrebbe dunque un elettore percio non puo che usufrire del parte <<voter(v)>>\nvoglia digita la sigla prosegguita o se vuole lasciare il programa sciva (Q)\n\t*ris:\t");
						scanf("%s", risposta_menu);
					}
					menu();
					risposta_utente(risposta_menu);
					VERIFICA(risposta_menu);
				}
			}
			if (strcmp(risposta_menu, "GE") == 0 && verifica(mot_passe) == 1) {
				while (strcmp(risposta_menu, "GE") == 0) {
					if (strcmp(risposta_menu, "GE") == 0) {
						menu_ge(ris_ge);
						int re = gestion_des_elettori(&ne, &te, &se, ris_ge, elettori, &(*Ap_Ch), risposta_menu);
					}
					else {
						printf("\n NB: non avendo in conoscenza la password;\n utente sarrebbe dunque un elettore percio non puo che usufrire del parte <<voter(v)>>\nvoglia digita la sigla prosegguita o se vuole lasciare il programa sciva (Q)\n\t*ris:\t");
						scanf("%s", risposta_menu);
					}
					menu();
					risposta_utente(risposta_menu);
					VERIFICA(risposta_menu);
				}
				if (strcmp(risposta_menu, "CS") == 0 && verifica(mot_passe) == 1) {
					while (strcmp(risposta_menu, "CS") == 0) {
						if (strcmp(risposta_menu, "CS") == 0)
							statistica(ris, candidati,elettori,ne, n,bull_nul);
						else {
							printf("\n NB: non avendo in conoscenza la password; utente sarrebbe dunque un elettore percio non puo che usufrire del parte <<voter(v)>>\nvoglia digita la sigla prosegguita o se vuole lasciare il programa sciva (Q)\n\t*ris:\t");
							scanf("%s", risposta_menu);
						}
						menu();
						risposta_utente(risposta_menu);
						VERIFICA(risposta_menu);
					}
				}
			}
		}
		if (strcmp(risposta_menu, "Q") == 0) {
			printf("Arrivederci...\n");
			return 0;
		}
		
		return 0;
	}

void lettura(lista candidati[], registro elettori[], int  ne, int  n, int ris) {
	int i = 0;
	FILE* f;
	FILE* g;
	f = fopen("risultati des election", "wt");
	g = fopen("electeur participazione", "wt");
	if (ris == 0) {
		printf("NESSUN VOTO REGISTRATO\n");
	}
	else {
		if (f == NULL) {
			printf("file ERRORE");
		}
		else {
			fprintf(f, "\t\t\t\t\tRISULTATI ELECTION\n");
			while (i < n) {
				fprintf(f, "%s  %s   %.2f %%\n", candidati[i].nome, candidati[i].cognome, candidati[i].voto);
				i++;
			}
		}
		fclose(f);
		if (g == NULL) {
			printf("file ERRORE");
		}
		else {
			fprintf(g, "\t\t\t\t\tRIgistro ELECTeur\n");
			while (i < ne) {
				fprintf(g,"%s  %s  %s  %d\n", elettori[i].nome, elettori[i].cognome, elettori[i].cni, elettori[i].stato);
				i++;
			}
		}
		fclose(g);
		printf("registrazione effettuata per bene\n");
	}
}
void statistica(int ris, lista candidati[],registro elettori[],int ne, int n,int bull_nul) {
		int i;
		int s;
		if (ris != 0) {
			printf("\t\t\t\t\t\tSTATISTICA DELL ELEZIONE\n");
			printf(" i resultati ottenuti dall elezione con %d voti totali sono:\n", ris);
			for (i = 0; i < n; i++) {
				candidati[i].voto = (candidati[i].voto / ris)*100;
			}
			for (i = 0; i < n; i++) {
				printf("%s  %s  %.2f %% \n", candidati[i].nome, candidati[i].cognome, candidati[i].voto);
			}
			s = bull_nul / ris;
			printf("con un totale di %d %% voti nulli\n", s*100);
		}
		else
			printf("Ancora nessun voto registrato\n");
		lettura(candidati, elettori, ne, n, ris);
	}


void menu_v( int* r,int ne) {
	printf("Quanti elettori vuoi fare votare:\t");
	scanf("%d", &(*r));
	while (*r<1 && *r>ne) {
		printf("Quanti elettori vuoi fare votare (la magirne da scegliere e' tra [ 1 , %d ]\n <<con %d il numero di elettori in registro>>:\t",ne,ne);
		scanf("%d", &(*r));
	}
}

void verifica_2(char ris[]) {
	while (strcmp(ris, "YES") != 0 && strcmp(ris, "NO") != 0 ) {
		printf("[[[ERRORE  COMANDO NON RICONOSCUITO\n devi inserire una sigla tra quelle tra parentesi]]]\n");
		menu();
		risposta_utente(ris);
	}
}
void VERIFICA_3(char cni[], lista candidati[], int n) {
	int i = 0;
	int s = 0;
	while (s == 0) {
		i = 0;
		while (i < n && s == 0) {
			if (strcmp(cni, candidati[i].cni) == 0)
				s = 1;
			i++;
		}
		if (s == 0) {
			printf("inserisci il numero della cni del candidato valido:\t");
			scanf("%s", cni);
		}
	}
}
int  vota(lista candidati[], int n,int*j,int *bull_nul) {
	int i = 0;
	int s=0;
	char cni[len];
	char ris[len];
	printf("Voui fare un voto nullo (YES O NO):\t");
	scanf("%s", ris);
	verifica_2(ris);
	if (strcmp(ris, "YES") == 0) {
		*bull_nul = *bull_nul + 1;
		s = -1;
		return s;
	}
	else if (strcmp(ris, "NO") == 0) {
		printf("inserisci il numero della cni del candidato:\t");
		scanf("%s", cni);
		 VERIFICA_3(cni, candidati, n);
		while (i < n ) {
			if (strcmp(cni, candidati[i].cni) == 0) {
				candidati[i].voto = candidati[i].voto + 1;
				s = 1;
				*j = i;
			}
			i++;
		}
		return s;
	}
}

void VERIFICA_4(char cni[], registro elettori[], int ne) {
	int i = 0;
	int s = 0;
	while (s == 0) {
		i = 0;
		while (i < ne && s == 0) {
			if (strcmp(cni, elettori[i].cni) == 0)
				s = 1;
			i++;
		}
		if (s == 0) {
			printf("inserisci il numero della cni dell elettore valido:\t");
			scanf("%s", cni);
		}
	}
}
int  stampa_e(registro elettori[],int i) {
	char ris[len];
	printf("\t\t\t\t\tVerificazione dati\n");
	printf("\t%s  %s   %s  %s  \n", elettori[i].nome,elettori[i].cognome, elettori[i].cni, elettori[i].sesso);
	printf("\t\t\t\t\tSONO CORRETTI I DATI S(YES O NO):\n");
	scanf("%s", ris);
	verifica_2(ris);
	if (strcmp(ris, "YES") == 0)
		return 0;
	else if(strcmp(ris, "NO") == 0)
		return -1;
}
int  identificazione(registro elettori[], int ne, registro*x,int e) {
	int i=0;
	char cni[len];
	int s=0;
	printf("inserisci il numero della CNI del %d elettore:\t",e+1);
	scanf("%s", cni);
	VERIFICA_4(cni, elettori, ne);
	while ( i<ne ){
		if (strcmp(cni, elettori[i].cni) == 0) {
			s = i;
		}	
		i++;
	}
	return s;
}
int  votare(registro elettori[], lista candidati[], int  ne, int  n ,int *bull_nul) {
	int ris;
	int e = 0;
	int f=0;
	int i;
	int r;
	int s = 0;
	int j=0;
	char decisione[len];
	registro x;
	printf("\t\t\t\t\tPROCEDURA DI VOTO \n");
	menu_v(&r,ne);
		affliggere_e(elettori, ne);
		while (e < r) {
			i = identificazione(elettori, ne, &x,e);
			ris = stampa_e(elettori, i);
			while (ris != 0) {
				i = identificazione(elettori, ne, &x,e);
				ris = stampa_e(elettori, i);
			}
			affliggere(candidati, n);
			if (elettori[i].stato == 0)
				f = vota(candidati, n, &j, &(*bull_nul));
			else printf("\n\tERRORE:\t\t Questo elettore a gia votato E NON LO PUO PUI VOTARE DI NUOVO\n");
			if (f == 1)
				elettori[i].stato = 1;
			if (f == -1)
				elettori[i].stato = 1;
			abbortire(decisione);
			if (strcmp(decisione, "NO") == 0) {
				elettori[i].stato = 0;
				f = 0;
				if (f != -1) {
					candidati[j].voto = candidati[j].voto - 1;
					f = 0;
				}
				printf("voto annullato per bene\n");
			}
			else if (strcmp(decisione, "YES") == 0) {
				printf("voto registrato per bene\n");
				f = 1;
			}
			s = s + f;
			e++;
		}
	return s;
}


void abbortire(char decisione[]) {
	printf("CON LA PRESENTE OPERAZIONE L ELETTORE CONFERMA O NO IL VOTO EFFETUATO (YES O NO):\t");
	scanf("%s", decisione);
	verifica_2(decisione);
}
int verifica(char mot_passe[]) {
	int i=0;
	int gia = 0;
	printf("questa area puo essere visulizzata solo in quanto AMMINISTRATORE:\n");
	while (i < tentativo && gia == 0) {
		printf("\tinserire la password:\t");
		scanf("%s", mot_passe);
		if (strcmp(mot_passe, "alice3000") == 0)
			gia = 1;
		else 
			printf("\tpassword ERRATA\n");
		i++;
}
	return gia;
}

void menu_GS_SOTTO(char ris_gs[]) {
	printf(" \n\t\t\t\t\t\t\tGESTIONE CANDIDATI\n");
	printf("**AGGUINGGERE UN CANDIDATO(AD_C)\n**MODIFICARE DATI CANDIDATO(MD)\n**AFFLIGGERE LA LISTA DI CANDIDATI INSCITI(AF_C)\n**QUITER( DELLA GESTION DES CANDIDAT (Q)\n");
	printf("\nqualunque desidera fare lei verra riscritto nel campo seguente <ris> con la sigla prosseguita da la funzione  desiderata\n\t*ris:\t");
	scanf("%s", ris_gs);
}
void menu_GS(char ris_gs[]) {
	printf(" \t\t\t\t\tGestion des candidats\n");
	printf("**AGGUINGGERE UN CANDIDATO(AD_C)\n**MODIFICARE DATI CANDIDATO(MD)\n**AFFLIGGERE LA LISTA DI CANDIDATI INSCITI(AF_C)\n**QUITER( DELLA GESTION DES CANDIDAT (Q)\n");
	printf("\nqualunque desidera fare lei verra riscritto nel campo seguente <ris> con la sigla prosseguita da la funzione  desiderata\n\t*ris:\t");
	scanf("%s", ris_gs);
	VERIFICA_6(ris_gs);
}
void VERIFICA_6(char ris_gs[]) {
	while (strcmp(ris_gs, "AD_C") != 0 && strcmp(ris_gs, "MD") != 0 && strcmp(ris_gs, "AF_C") != 0 && strcmp(ris_gs, "Q") != 0) {
		printf("[[[ERRORE  COMANDO NON RICONOSCUITO\n devi inserire una sigla tra quelle tra parentesi]]]\n");
		menu_GS_SOTTO(ris_gs);
	}
}

void affliggere(lista candidati[], int n) {
	int i;
	if (n == 0) {
		printf("\n\t\t\t\t\t\tREGISTRO DI CANDIDATI\n");
		printf("registro vuoto\n");
	}
	else {
		printf("\n\t\t\t\t\t\tREGISTRO DI CANDIDATI\n");
		for (i = 0; i < n; i++) {
			printf("%d**\t%s  %s   %s  %s  \n", i + 1, candidati[i].nome, candidati[i].cognome, candidati[i].cni, candidati[i].sesso);
		}
	}
}
void agguinta(int n, int t, lista candidati[]) {
	int i;
	lista x;
	for (i = t; i < n; i++) {
		printf("nome:\t");
		scanf("%s", x.nome);
		printf("cognome:\t");
		scanf("%s", x.cognome);
		printf("CNI:\t");
		scanf("%s", x.cni);
		printf("sesso:\t");
		scanf("%s", x.sesso);
		x.voto = 0;
		if (esiste(x, candidati, n) != 1) {
			candidati[i] = x;

			printf("registrazione con successo\n");
		}
		else {
			printf("Candidato gia presente in lista.\n");
		}
	}
}

int esiste(lista x, lista  candidati[], int n) {
	int i=0; 
	int gia = 0;
	while (i < n && gia == 0) {
		if (strcmp(x.cni, candidati[i].cni) == 0)
			gia = 1;
		i++;
	}
	return gia;
}

void modifica(lista candidati[], int n) {
	int i;
	char cni[len];
	lista x;

	printf("MODIFICA DATI\n");
	printf("lista attuale des candidati\n");
	affliggere(candidati, n);
	printf("Inserisci il numero di cni del candadati da modifica i dati:\t");
	scanf("%s", cni);
	VERIFICA_3(cni, candidati, n);
	printf("\ninserici i dati  modificati del candidato in registro:\n");
	printf("nome:\t");
	scanf("%s", x.nome);
	printf("cognome:\t");
	scanf("%s", x.cognome);
	printf("CNI:\t");
	scanf("%s", x.cni);
	printf("sesso:\t");
	scanf("%s", x.sesso);
	x.voto = 0;
	for (i = 0; i < n; i++) {
		if (strcmp(cni, candidati[i].cni) == 0) {
			candidati[i] = x;
		}
		else
			printf("candidato non esistente in registro\n");
	}
}
int gestion_des_canditat(int* n, int* t, int* s, char ris_gs[],lista candidati[],int*Ap_Ch,char risposta_menu[]) {
	
	if (strcmp(ris_gs, "AF_C") == 0) {
		while (strcmp(ris_gs, "AF_C") == 0) {
			AFFLIGGERE(&(*n), candidati, ris_gs);
		}
		if (strcmp(ris_gs, "Q") == 0) {
			return 0;
		}
	}
	if (strcmp(ris_gs, "AD_C") == 0 && *Ap_Ch == 0) {
		while (strcmp(ris_gs, "AD_C") == 0) {
			AGGUINGGERE_CANDIDATO(&(*t), &(*n), &(*s), ris_gs, candidati, &(*Ap_Ch));
		}
		
		if (strcmp(ris_gs, "AF_C") == 0) {
			while (strcmp(ris_gs, "AF_C") == 0) {
				AFFLIGGERE(&(*n), candidati, ris_gs);
			}
		}
		if (strcmp(ris_gs, "MD") == 0) {
			while (strcmp(ris_gs, "MD") == 0) {
				MODIFICA_DATI(&(*n), candidati, ris_gs);
			}
		}
		if (strcmp(ris_gs, "AD_C") == 0) {
			while (strcmp(ris_gs, "AD_C") == 0) {
				AGGUINGGERE_CANDIDATO(&(*t), &(*n), &(*s), ris_gs, candidati,&(*Ap_Ch));
			}
		}
		if (strcmp(ris_gs, "AF_C") == 0) {
			while (strcmp(ris_gs, "AF_C") == 0) {
				AFFLIGGERE(&(*n), candidati, ris_gs);
			}
		}
		if (strcmp(ris_gs, "Q") == 0){
			return 0;
		}
	}
	if (strcmp(ris_gs, "MD") == 0) {
		while (strcmp(ris_gs, "MD") == 0) {
			MODIFICA_DATI(&(*n), candidati, ris_gs);
		}
		if (strcmp(ris_gs, "AF_C") == 0) {
			while (strcmp(ris_gs, "AF_C") == 0) {
				AFFLIGGERE(&(*n), candidati, ris_gs);
			}
		}
		if (strcmp(ris_gs, "AD_C") == 0) {
			while (strcmp(ris_gs, "AD_C") == 0) {
				AGGUINGGERE_CANDIDATO(&(*t), &(*n), &(*s), ris_gs, candidati, &(*Ap_Ch));
			}
		}
		if (strcmp(ris_gs, "AF_C") == 0) {
			while (strcmp(ris_gs, "AF_C") == 0) {
				AFFLIGGERE(&(*n), candidati, ris_gs);
			}
		}
		if (strcmp(ris_gs, "MD") == 0) {
			while (strcmp(ris_gs, "MD") == 0) {
				MODIFICA_DATI(&(*n), candidati, ris_gs);
			}
		}
		if (strcmp(ris_gs, "AF_C") == 0) {
			while (strcmp(ris_gs, "AF_C") == 0) {
				AFFLIGGERE(&(*n), candidati, ris_gs);
			}
		}
		if (strcmp(ris_gs, "Q") == 0) {
			return 0;
		}
	}
	return 0;
}

void AGGUINGGERE_CANDIDATO(int *t, int* n, int* s, char ris_gs[], lista candidati[],int *Ap_Ch) {
	printf("AGGUINGGERE CANDIDATO");
	if (*Ap_Ch == 0) {
		printf("\nQuanti sono i candidati che vuole agguinggere:\t");
		scanf("%d", &(*s));
		*t = *n;
		*n = *n + *s;
		agguinta(*n, *t, candidati);
		menu_GS_SOTTO(ris_gs);
	}
	else {
		printf("\nLE ELEZIONI AVENDO INIZIATO NON SI PUOI PUI AGGUINGERE NESSUNO\n");
	}
	
}

void MODIFICA_DATI(int* n, lista candidati[], char ris_gs[]) {
	modifica(candidati, *n);
	menu_GS_SOTTO(ris_gs);
}

void AFFLIGGERE(int* n, lista candidati[], char  ris_gs[]) {
	affliggere(candidati, *n);
	menu_GS_SOTTO(ris_gs);
}
void AFFLIGGERE_e(int* ne, registro elettori[], char ris_ge[]) {
	affliggere_e(elettori, *ne);
	menu_GE_SOTTO(ris_ge);
}
void AGGUINGGERE_ELETTORI(int* te, int* ne, int* se, char ris_ge[],registro elettori[]) {
	printf("AGGUINGGERE elettori");
	printf("\nQuanti sono i elettori che vuole agguinggere:\t");
	scanf("%d", &(*se));
	*te = *ne;
	*ne = *ne + *se;
	agguinta_e(*ne, *te, elettori);
	menu_GE_SOTTO(ris_ge);
}
void agguinta_e(int ne, int te, registro elettori[]) {
	int i;
	registro x;
	for (i = te; i < ne; i++) {
		printf("nome:\t");
		scanf("%s", x.nome);
		printf("cognome:\t");
		scanf("%s", x.cognome);
		printf("CNI:\t");
		scanf("%s", x.cni);
		printf("sesso:\t");
		scanf("%s", x.sesso);
		x.stato = 0;
		if (esiste_e(x, elettori, ne) != 1) {
			elettori[i] = x;

			printf("registrazione con successo\n");
		}
		else {
			printf("elettore gia presente in lista.\n");
		}
	}
}

int esiste_e(registro x, registro  elettori[], int ne) {
	int i = 0;
	int gia = 0;
	while (i < ne && gia == 0) {
		if (strcmp(x.cni, elettori[i].cni) == 0)
			gia = 1;
		i++;
	}
	return gia;
}

void MODIFICA_DATI_e(int* ne, registro elettori[], char ris_ge[]) {
	modifica_e(elettori, *ne);
	menu_GE_SOTTO(ris_ge);
}
void modifica_e(registro elettori[], int ne) {
	int i;
	char CNI[len];
	registro x;
	
	printf("MODIFICA DATI\n");
	printf("lista attuale des elettori\n");
	affliggere_e(elettori, ne);
	printf("Inserisci il numero di cni del elettore da modifica i dati:\t");
	scanf("%s",CNI);
	VERIFICA_4(CNI, elettori, ne);
	printf("\ninserici i dati  modificati del candidato in registro:\n");
	printf("nome:\t");
	scanf("%s", x.nome);
	printf("cognome:\t");
	scanf("%s", x.cognome);
	printf("CNI:\t");
	scanf("%s", x.cni);
	printf("sesso:\t");
	scanf("%s", x.sesso);
	for (i = 0; i < ne; i++) {
		if (strcmp(CNI, elettori[i].cni) == 0) {
			elettori[i] = x;
		}
		else
			printf("elettore non esistente in registro\n");
	}
}


int gestion_des_elettori(int* ne, int* te, int* se, char ris_ge[], registro elettori [], int* Ap_Ch, char risposta_menu[]) {
	if (strcmp(ris_ge, "AF_E") == 0) {
		while (strcmp(ris_ge, "AF_E") == 0) {
			AFFLIGGERE_e(&(*ne), elettori, ris_ge);
		}
		if (strcmp(ris_ge, "Q") == 0) {
			return 0;
		}
	}
	if (strcmp(ris_ge, "AD_E") == 0 ) {
		while (strcmp(ris_ge, "AD_E") == 0) {
			AGGUINGGERE_ELETTORI(&(*te), &(*ne), &(*se), ris_ge, elettori);
		}

		if (strcmp(ris_ge, "AF_E") == 0) {
			while (strcmp(ris_ge, "AF_E") == 0) {
				AFFLIGGERE_e(&(*ne), elettori, ris_ge);
			}
		}
		if (strcmp(ris_ge, "MD") == 0) {
			while (strcmp(ris_ge, "MD") == 0) {
				MODIFICA_DATI_e(&(*ne), elettori, ris_ge);
			}
		}
		if (strcmp(ris_ge, "AD_E") == 0) {
			while (strcmp(ris_ge, "AD_E") == 0) {
				AGGUINGGERE_ELETTORI(&(*te), &(*ne), &(*se), ris_ge, elettori);
			}
		}
		if (strcmp(ris_ge, "AF_E") == 0) {
			while (strcmp(ris_ge, "AF_E") == 0) {
				AFFLIGGERE_e(&(*ne), elettori, ris_ge);
			}
		}
		if (strcmp(ris_ge, "Q") == 0) {
			return 0;
		}
	}
	if (strcmp(ris_ge, "MD") == 0) {
		while (strcmp(ris_ge, "MD") == 0) {
			MODIFICA_DATI_e(&(*ne), elettori, ris_ge);
		}
		if (strcmp(ris_ge, "AF_E") == 0) {
			while (strcmp(ris_ge, "AF_E") == 0) {
				AFFLIGGERE_e(&(*ne), elettori, ris_ge);
			}
		}
		if (strcmp(ris_ge, "AD_E") == 0) {
			while (strcmp(ris_ge, "AD_E") == 0) {
				AGGUINGGERE_ELETTORI(&(*te), &(*ne), &(*se), ris_ge, elettori);
			}
		}
		if (strcmp(ris_ge, "AF_E") == 0) {
			while (strcmp(ris_ge, "AF_E") == 0) {
				AFFLIGGERE_e(&(*ne), elettori, ris_ge);
			}
		}
		if (strcmp(ris_ge, "MD") == 0) {
			while (strcmp(ris_ge, "MD") == 0) {
				MODIFICA_DATI_e(&(*ne), elettori, ris_ge);
			}
		}
		if (strcmp(ris_ge, "AF_E") == 0) {
			while (strcmp(ris_ge, "AF_E") == 0) {
				AFFLIGGERE_e(&(*ne), elettori, ris_ge);
			}
		}
		if (strcmp(ris_ge, "Q") == 0) {
			return 0;
		}
	}
	return 0;
}


void menu_GE_SOTTO(char ris_ge[]) {
	printf(" \n\t\t\t\t\t\t\tGESTIONE ELLETORI\n");
	printf("**AGGUINGGERE  ELETTORE(AD_E)\n**MODIFICARE DATI ELETTORI(MD)\n**AFFLIGGERE LA LISTA DI ELETTORI INSCITI(AF_E)\n**QUITER( DELLA GESTION DES ELETTORI (Q)\n");
	printf("\nqualunque desidera fare lei verra riscritto nel campo seguente <ris> con la sigla prosseguita da la funzione  desiderata\n\t*ris:\t");
	scanf("%s", ris_ge);
	
}

void VERIFICA_5(char ris_ge[]) {
	while (strcmp(ris_ge, "AD_E") != 0 && strcmp(ris_ge, "MD") != 0 && strcmp(ris_ge, "AF_E") != 0 && strcmp(ris_ge, "Q") != 0) {
		printf("[[[ERRORE  COMANDO NON RICONOSCUITO\n devi inserire una sigla tra quelle tra parentesi]]]\n");
		menu_GE_SOTTO(ris_ge);
	}
}
void menu_ge(char ris_ge[]) {
	printf(" \t\t\t\t\tGestion des elettori\n");
	printf("**AGGUINGGERE  ELETTORE(AD_E)\n**MODIFICARE DATI ELETTORI(MD)\n**AFFLIGGERE LA LISTA DI ELETTORI INSCITI(AF_E)\n**QUITER( DELLA GESTION DES ELETTORI (Q)\n");
	printf("\nqualunque desidera fare lei verra riscritto nel campo seguente <ris> con la sigla prosseguita da la funzione  desiderata\n\t*ris:\t");
	scanf("%s", ris_ge);
	VERIFICA_5(ris_ge);
}

void affliggere_e(registro elettori[], int ne) {
	int i;
	if (ne == 0) {
		printf("\n\t\t\t\t\t\tREGISTRO DI ELETTORI\n");
		printf("registro vuoto\n");
	}
	else {
		printf("\n\t\t\t\t\t\tREGISTRO DI ELETTORI\n");
		for (i = 0; i < ne; i++) {
			printf("%d**\t%s  %s   %s  %s  %d \n", i + 1, elettori[i].nome, elettori[i].cognome, elettori[i].cni, elettori[i].sesso,elettori[i].stato);
		}
	}
}