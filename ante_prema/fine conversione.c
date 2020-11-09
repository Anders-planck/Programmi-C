#include<stdio.h>
#include<math.h>
main() {
	struct misuraUK {
		int miglia, yarde, piede, polici;
	}dato1;
	struct misuraEU
	{
		float km, metri, mm;
	}dato2;
	float a, b, c, d;
	printf("\ninserire le misure \n");
	printf("milgia:\t");
	scanf("%d", &dato1.miglia);
	printf("yarde:\t");
	scanf("%d", &dato1.yarde);
	printf("piede:\t");
	scanf("%d", &dato1.piede);
	printf("polici:\t");
	scanf("%d", &dato1.polici);

	printf("\nmiglia:\t%d\nyarde:\t%d\npiede:\t%d\npolice:\t%d\ni vostri dati sono questi.\n converzione in corso", dato1.miglia, dato1.yarde, dato1.piede, dato1.polici);
	a = dato1.miglia*1760.0;
	b = ((dato1.yarde * 3.0)*a) / dato1.yarde;
	c = ((dato1.piede * 12.0)*b) / dato1.piede;
	d = ((dato1.polici*25.4)*c) / dato1.polici;

	a = d / 1000;
	b = d / 1000000;
	printf("\n\t il valore totale  in mm e':%.3f:\t", d);
	printf("\n\t il valore totale  in metri e':%.3f:\t", a);
	printf("\n\t il valore totale  in km e':%.3f:\t", b);

	dato2.km = (int)d / 1000000;
	dato2.metri =(int)( d - (dato2.km* 1000000))/1000;
	dato2.mm = (d - (dato2.km * 1000000)) - (dato2.metri*1000);
	printf("\nresultato del calcolo\n\n");
	printf("risultato:\t%.1f km\t%.1f m\t%.1f mm", dato2.km, dato2.metri, dato2.mm);
	printf("\n\WAAAAWWWWWWWWWWW\n\n\n");
	
}