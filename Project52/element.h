#ifndef __ELEMENT__H__
#define __ELEMENT__H__
#include<stdio.h>

typedef enum {false ,true}boolean;
typedef int Element;

boolean even_number(Element);
boolean isless(Element, Element);
boolean isEqual(Element, Element);
Element getElement(void); 
void printElement(Element);
boolean isNULL(Element);

#endif // !__ELEMENT__H__
