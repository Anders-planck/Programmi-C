#define _CRT_SECURE_NO_WARNINGS
#define lenght 100
#define len 20
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct {char Idraulico[len];char Rappresentante[len];int Giono;	}Visita;
typedef struct Tree{Visita x;struct Tree*left;struct Tree*right;}Tree,*item;

void putVet(Visita x,Visita v[],int *u){
Visita y;
int i=0,j=0;bool gia=false;
for(i=0;i<*u;i++){
	if(x.Giono==v[i].Giono){
		if(strcmp(x.Rappresentante,v[i].Rappresentante)<0){
			y=v[i];
			v[i]=x;
			v[i+1]=y;
			*u++;
			gia=true;
			j=i+2;
		}
	}
	if(gia){
		v[j]=v[i];
	}
}

}

void  StampaVet(item T,Visita v[],int *n){
 int j=(*n);
	if(T!=NULL){
	StampaVet(T->left,v,&j);
	putVet(T->x,v,&j);
	StampaVet(T->right,v,&j);
	(*n)=j;
}
}

void StampaItem(item t){
	if(t!=NULL){
		StampaItem(t->left);
			printf(" %s %s  %d\n", t->x.Idraulico,t->x.Rappresentante,t->x.Giono);
		StampaItem(t->right);
	}
}

item NewItem(Visita y){
	item x=(item)malloc(sizeof(Tree));
	x->x=y;
	x->left=NULL;
	x->right=NULL;
	return x;
}

item putItem(item t,Visita x){
if(t==NULL)return NewItem(x);
else{
	item p=NULL; item current=t;
	while(current!=NULL){
		if(x.Giono<t->x.Giono){
			p=current; current=current->left;
		}
		else{
			p=current; current=current->right;
		}
	}
	if(x.Giono<t->x.Giono){
		p->left=NewItem(x);
	}else p->right=NewItem(x);
	return t;
}
}

item read (item t,FILE*vis){
	Visita x;
	while(!feof(vis)){
		fscanf(vis,"%s%s%d",x.Idraulico,x.Rappresentante,&x.Giono);
	t=putItem(t,x);
	}
	return t;
}


int main(int argc, char const *argv[])
{
	item T=NULL;Visita v[lenght];int n=0;
	FILE*vis=fopen("visite.txt","rt");
	T=read(T,vis);
	StampaItem(T);
	StampaVet(T,v,&n);
	printf("Array \n\n");
	for(int i=0;i<20;i++){
printf(" %s %s  %d\n", v[i].Idraulico,v[i].Rappresentante,v[i].Giono);
	}
	return 0;
}