#ifndef __ELEMENT__H__
#define __ELEMENT__H__
#define _CRT_SECURE_NO_WARNINGS
#define len 30
#define  Profondo 3
#include<stdio.h>

typedef struct {
	char parola[len];
	int stato;
	int Profondità;
}element;

typedef enum{false,true}boolean;

boolean isless(element, element);
boolean equals(element);
void getelement(element);
boolean equalsPr(element);
#endif // !__ELEMENT__H__
