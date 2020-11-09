#ifndef __BIBLI__H__
#define __BIBLI__H__
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define dim 50
/*------------------------------------------------*/
typedef struct {
	char name[dim];
	int calori;
}prodotto;
/*------------------------------------------------*/
typedef enum{true,false}boolean;
/*------------------------------------------------*/
typedef struct List_element {
	prodotto value;
	struct List_element* next;
}List_element, * List;
/*------------------------------------------------*/
static List_element* Fist = NULL;
static List_element* Last = NULL;
static  int nb_element = 0;
static int soglia = 200;
/*------------------------------------------------*/
List push_List(List_element*, prodotto);
/*------------------------------------------------*/
boolean is_empty_list(List_element*);
/*------------------------------------------------*/
List Ricerca_iper_calorie(List_element*, FILE*);
/*--------------------------------------------------*/
void Verify_Allocazione(List_element*);
/*--------------------------------------------------*/
void print_List(List_element*);
/*--------------------------------------------------*/
void fprint_List_media(List_element*, FILE*);
/*---------------------------------------------------*/
List clean_List(List_element*);
/*-------------------------------------------------*/
List total_clean_list(List_element*);
#endif // !__BIBLI__H__

