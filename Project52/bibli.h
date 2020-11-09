#ifndef __BIBLI__H__
#define __BIBLI__H__
#include "element.h"
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct Item {
	Element value;
	struct Item* Next;
}Item,*item;

item appen_item(item,item);
item new_item_here(item, Element);
item new_item(Element);
item push_item(Element, item);
void print_item(item);
item push_on_item(item*,item);
item merge(item ,item);
#endif // !__BIBLI__H__


