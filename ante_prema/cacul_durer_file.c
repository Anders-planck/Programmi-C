#include<stdio.h>
void sommatempi(int o1, int m1, int s1, int o2, int m2, int s2, int*Or, int*Mr, int*Sr,int*jr) {
	int i = 0;
	int a = 0;
	int t = m1 + m2 + i;
	int f = s1 + s2;
	int s=a + o1 + o2;
	int e=0;
	while (f >= 60) {
		i++;
		f = f - 60;
	}
	*Sr = f;
	while (t >= 60) {
		a++;
		t = t - 60;
	}
	*Mr = t;
	
	while (s > 24) {
		e++;
		s = s - 24;
	}
	*Or = s;
	*jr = e;
}
main() {
	int jr, o1, o2, m1, m2, s1, s2, Or, Mr, Sr;
	printf("inserisci il primo tempo\n");
	scanf("%d%d%d", &o1, &m1, &s1);
	printf("inserisci il secondo  tempo\n");
	scanf("%d%d%d", &o2, &m2, &s2);
	sommatempi(o1, m1, s1, o2, m2, s2, &Or, &Mr, &Sr, &jr);

	if(jr>0)
	printf("\nora di fine è:\t%dj:%dh.%dmin.%dsec",jr, Or, Mr, Sr);
	else
	printf("\nora di fine è:\t%dh:%dmin.%dsec", Or, Mr, Sr);
}