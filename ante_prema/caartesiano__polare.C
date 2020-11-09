#include<stdio.h>
#include<math.h>


typedef struct polare {
	float r, t;
}polare;
typedef struct punto {
	float x, y;
}punto;

polare  polare_2_cartesiano(punto p) {
	punto orig;
	orig.x = 0.0;
	orig.y = 0.0;
	polare n;
	float i, r;
	i = p.x - orig.x;
	r = p.y - orig.y;
	n.r = sqrt((i*i) + (r*r));
	n.t = (double)atan2(p.y,p.x);
	return n;
}

punto cartesiano_2_polare(polare f) {
	punto c;
	c.x = (double) f.r*cos(f.t);
	c.y =(double) f.r*sin(f.t);
	return c;
}
float distanza(punto a, punto b) {
	float d;
	float i, r;
	i = b.x - a.x;
	r = b.y - a.y;
	d = (float) sqrt((i*i)+(r*r));
	return d;
}


main() {
	punto a, b,s,q;
	polare t, p;
	float d;
	printf("insserisci valori di a\n");
	scanf("%f%f", &a.x, &a.y);
	printf("\ninsserisci valori di b\n");
	scanf("%f%f", &b.x, &b.y);
	printf("\na=(%.1f,%.1f)", a.x, a.y);
	printf("\nb=(%.1f,%.1f)", b.x, b.y);
	d = distanza(a, b);
	printf("\nla distanza e':\td=%.1f", d);
	p = polare_2_cartesiano(a);
	t = polare_2_cartesiano(b);
	printf("\nle coordinate polari sono\np.r=%.1f\np.t=%.1f\n", p.r, p.t);
	printf("\nle coordinate polari sono\nt.r=%.1f\nt.t=%.1f\n", t.r, t.t);
	q = cartesiano_2_polare(p);
	s = cartesiano_2_polare(t);
	printf("\nle coordinate cartesiane sono\nq.x=%.1f\nq.y=%.1f\n", q.x, q.y);
	printf("\nle coordinate cartesiane sono\ns.x=%.1f\ns.y=%.1f\n", s.x, s.y);
}
/*
float ipotenusa(float a, float b) {
float f;
f = (float) sqrt((a*a) + (b*b));
return f;
}

main() {
float a,ip, b;
printf("inserire due lati del triangolo");
printf("\na=");
scanf("%f", &a);
printf("\nb=");
scanf("%f", &b);
ip = ipotenusa(a, b);
printf("l ipotenus e':\t%.1f\n", ip);
}*/