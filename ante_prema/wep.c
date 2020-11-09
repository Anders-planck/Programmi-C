#include<stdio.h>
main() {
	int n, tmp1b, tmp1r, tmp2b, tmp2r, tmp3b, cestob, cestor, somma, tmp3r, tmp4b, tmp4r, tmp5b, tmp5r, m, o, p, q, r, s, t, tmp6b, tmp6r, tmp7b, tmp7r ;

	/*---------------lunedi-------------------------*/
	printf("inserire il numero di cocci");
	scanf("%d", &n);
	if (n <= 1) {
		tmp1b = n;
	}
	else if (n > 1) {
		tmp1r = n;
	}
	/*---------------mardi---------------------*/
	printf("inserire il numero di cocci");
	scanf("%d", &m);
		 if (m <= 2) {
			tmp1b = m;
		}
		else if (m> 2) {
			tmp1r = m;
		}
		/*---------------mercredi---------------------*/
		printf("inserire il numero di cocci");
		scanf("%d", &o);
			if (o <= 3) {
				tmp3b = o;
			}
			else if (o> 3) {
				tmp3r = o;
			}
			/*---------------jeudi---------------------*/
			printf("inserire il numero di cocci");
			scanf("%d", &p);
				if (p <= 4) {
					tmp4b = p;
				}
				else if (o> 4) {
					tmp4r = p;
				}
				/*---------------vemdredi---------------------*/
				printf("inserire il numero di cocci");
				scanf("%d", &q);
					if (q <= 5) {
						tmp5b = q;
					}
					else if (q> 5) {
						tmp5r = q;
					}
					/*---------------samedi---------------------*/
					printf("inserire il numero di cocci");
					scanf("%d", &r);
						if (r <= 6) {
							tmp6b = r;
						}
						else if (r> 6) {
							tmp6r = r;
						}
						/*---------------dimanche---------------------*/
						printf("inserire il numero di cocci");
						scanf("%d", &t);
							if (t <= 7) {
								tmp7b = t;
							}
							else if (t> 7) {
								tmp7r = t;
							}
							somma = n + m + p + q + r + t + o;
							printf("\nil numero totale di cocci sono %d\t", somma);
							if (n <= 1 && m <= 2 && o <= 3 && p <= 4 && q <= 5 && r <= 6 && t <= 7) {
								cestob = tmp1b + tmp2b + tmp3b + tmp4b + tmp5b + tmp6b + tmp7b;
								printf("\nil numero totale di cocci nel cesto blu sono %d\t", cestob);
							}
							if (n > 1 && m > 2 && o > 3 && p > 4 && q > 5 && r > 6 && t > 7) {
								cestor = tmp1r + tmp2r + tmp3r + tmp4r + tmp5r + tmp6r + tmp7r;
								printf("\nil numero totale di cocci nel cesto blu sono %d\t", cestor);
							}
							
}