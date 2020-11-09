#include<stdio.h>
typedef struct {
	float x, y;
}complessi;
/*complessi somma(complessi a, complessi b) {
	complessi f;
	f.x = a.x + b.x;
	f.y = a.y + b.y;
	return f;
}*/
void somma_complex(complessi a, complessi b, float*g,float*t) {
	*g = a.x + b.x;
	*t = a.y + b.y;
}
main() {
	complessi a,/*s*/ b;
	float t=0, g=0;
	printf("inserire due complessi:\nparte reale\t:");
	scanf("%f", &a.x);
	printf("\nparte imaginaria\t:");
	scanf("%f", &a.y);
	printf("inseriscine un altro:\nparte reale\t:");
	scanf("%f",& b.x);
	printf("\nparte imaginaria\t:");
	scanf("%f", &b.y);
	/*s = somma(a, b);
	printf("la somma e':\t%.0f + %.0f i\n", s.x, s.y);*/
	
	somma_complex(a,b,&t,&g);
	printf("la somma e':\t%.0f + %.0f i\n", t, g);
}