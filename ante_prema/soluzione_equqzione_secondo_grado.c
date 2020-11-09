#include<stdio.h>
#include<math.h>
void radici(float a, float b, float c, float*o, float*r1, float*r2) {
	float t;
	float s;
	t = (b*b) - (4 * a * c);
	if (t < 0)
		*o = 0;
	else
		*o = 1;
		s = (float)sqrt(t);
	*r1 = ((-b + s) / (2 * a));
	*r2 = ((-b - s) / (2 * a));
}
main() {
	float a, b, c;
	float r1, r2;
	float o;
	printf("inserire tre valori tale che Ax2+Bx+C:\n");
	scanf("%f%f%f", &a, &b, &c);
	radici(a, b, c, &o, &r1, &r2);
	if (o == 1) 
		printf("\nl'equazioe ammette soluzione reali\nradice 1=%.1f\nradice2=%.1f\n", r1, r2);
	else
		printf("\nl'equazioe ammette soluzione reali");
}