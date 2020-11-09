#include"bibli.h"

item push_item(Element x, item t) {
	item current = t;
	item precedent = NULL;
	item new = NULL;
	//risearch of the position in the list...
	while (current != 0 && isless(x, current->value)) {
		precedent = current;
		current = current->Next;
	}
	//initialization of the new variable...
	new = new_item(x);
	//insertion of the new variable in the list...
	if (precedent == NULL) {// if we are this place ,is meaning of that event is that we have arrived in start list...
		new->Next = t;
		t = new;
		return t;
	}
	else { //here we are in the middle of the list..... 
		precedent->Next = new;
		new->Next = current;
			return t;
	}
}
item new_item_here(item l,Element x) {
	item new = NULL;
	new = (item)malloc(sizeof(Item));
	item tmp = l;
	item prec = NULL;
	new->value = x;
	new->Next = NULL;
	if (tmp == NULL)return new;
	else {
		while (tmp != NULL) {
			prec = tmp;
			tmp = tmp->Next;
		}
		prec->Next = new;
		return l;
	}
}
item new_item(Element x) {
	item new = NULL;
	 new =(item)malloc(sizeof(Item));
	new->value = x;
	new->Next = NULL;
	return new;
}

void print_item(item t) {
	item tmp = t;
	if (tmp == NULL)return;
	else {
		printElement(tmp->value);
		print_item(tmp->Next);
	}
}
item push_on_item(item *t,item b) {
	Element x;
	do
	{
		x=getElement();
		if (even_number(x))
			b = push_item(x, b);
		else *t = push_item(x, *t);
	} while (!isNULL(x));
	return b;
}

item appen_item(item t, item b) {
	item c = NULL;
	item current = b;
	while (current!=NULL)
	{
		c = new_item_here(c,current->value);
		current = current->Next;
	}
	current =NULL;
	current = t;
	while (current != NULL)
	{
		c = new_item_here(c, current->value);
		current = current->Next;
	}
	return c;
}

item merge(item t, item b) {
	item i = NULL;
	while (t != NULL && b != NULL) {
		if (isless(t->value,b->value)) {
			i = new_item_here(i, b->value);
			b = b->Next;
		}
		else {
			i = new_item_here(i, t->value);
			t = t->Next;
		}
	}
	if (t != NULL) {
		i = new_item_here(i, t->value);
		t = t->Next;
	}
	else {
		i = new_item_here(i, b->value);
		b = b->Next;
	}
	return i;
}
