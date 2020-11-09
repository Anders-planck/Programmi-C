#include"bibli.h"

void main(void) {

	item b = NULL, t=NULL,c=NULL,d=NULL;
	b=push_on_item(&t, b);
	printf("\nitem of even number\n");
	print_item(b);
	printf("\nitem of not even number\n");
	print_item(t);
	c=appen_item(t, b);
	printf("\nitem of appen item\n");
	print_item(c);
	d = merge(t, b);
	printf("\nitem of merge item\n");
	print_item(d);
}