#ifndef __ELEMENT__H__
#define __ELEMENT__H__
#define len 50
#define _CRT_SECURE_NO_WARNINGS
#define Ipercalorico 200
#include<stdio.h>

typedef struct {
	char Nome[len];
	int Energia;
}element;

typedef enum{false, true}boolean;

boolean isless(element, element);
boolean equalsNumber(element);

#endif // !__ELEMENT__H__

