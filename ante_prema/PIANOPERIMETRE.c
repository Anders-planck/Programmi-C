#include<stdio.h>
#include<math.h>
typedef struct {
		float x;
		float y;
}punto;
float distanza( punto x, punto y) {
	float g = 0;
	g= sqrt(pow((x.x - y.x), 2.0) + pow((x.y - y.y), 2.0));
	return g;
}

main() {
	float q, w, e, r;
	float perim;
	punto a, b, c, d;
	printf("iniserire i valori 1\t");
	scanf("%f%f", &a.x,&a.y);
	
	printf("\niniserire i valori 2\t");
	scanf("%f%f", &b.x, &b.y);
	
	printf("\niniserire i valori 3\t");
	scanf("%f%f", &c.x, &c.y);
	
	printf("iniserire i valori 4\t");
	scanf("%f%f", &d.x, &d.y);

	printf("\n il valori che hai inserito sono :\n");

	printf("\nil valore :\t(%.1f,%.1f)", a.x, a.y);

	printf("\nil valore :\t(%.1f,%.1f)", b.x, b.y);

	printf("\nil valore :\t(%.1f,%.1f)", c.x, c.y);

	printf("\nil valore :\t(%.1f,%.1f)", d.x, d.y);

	printf("\ncalcolo delle distanze\n");

	/*SECONSA POSSIBILITA CON DEFINIZIONE DI TIPO
	q = sqrt(pow((a.x - b.x), 2.0)+pow((a.y - b.y),2.0));
	printf("\nla distanza tra (%.1f,%.1f) e (%.1f,%.1f) e' :%.1f\t",a.x,a.y,b.x,b.y, q);
	
	w = sqrt(pow((a.x - d.x), 2.0) + pow((a.y - d.y), 2.0));
	printf("\nla distanza tra (%.1f,%.1f) e (%.1f,%.1f) e' :%.1f\t", a.x, a.y, d.x, d.y, w);
	
	e = sqrt(pow((d.x - c.x), 2.0) + pow((d.y - c.y), 2.0));
	printf("\nla distanza tra (%.1f,%.1f) e (%.1f,%.1f)  e' :%.1f\t", d.x, d.y, c.x, c.y, e);
	
	r = sqrt(pow((b.x - c.x), 2.0) + pow((b.y - c.y), 2.0));
	printf("\nla distanza tra (%.1f,%.1f) e (%.1f,%.1f)  e' :%.1f\t", b.x, b.y, c.x, c.y, r);
	*/
	q = distanza(a, b);
	printf("\nla distanza tra (%.1f,%.1f) e (%.1f,%.1f) e' :%.1f\t", a.x, a.y, b.x, b.y, q);
	w=  distanza(a, d);
	printf("\nla distanza tra (%.1f,%.1f) e (%.1f,%.1f) e' :%.1f\t", a.x, a.y, d.x, d.y, w);
	e= distanza(d, c);
	printf("\nla distanza tra (%.1f,%.1f) e (%.1f,%.1f)  e' :%.1f\t", d.x, d.y, c.x, c.y, e);
	r= distanza(b, c);
	printf("\nla distanza tra (%.1f,%.1f) e (%.1f,%.1f)  e' :%.1f\t", b.x, b.y, c.x, c.y, r);
	
	perim = q + w + e + r;
	
	printf("\nle perimerte e' :\t%.1f", perim);

}