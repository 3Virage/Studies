#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "array.h"

void ClrScr()
{
 
  printf("\033[2J"); 
 printf("\033[0;0f"); 
 
}

wezel* create(wezel* up)
{
wezel* nowy=malloc(sizeof(wezel));
if(nowy==NULL) return NULL;
(*nowy).up=up;
(*nowy).left=NULL;
(*nowy).right=NULL;
printf("Imie: ");
	fgets((*nowy).imie,16,stdin);
	fflush(stdin);
printf("Nazwisko: ");
	fgets((*nowy).nazwisko,16,stdin);
	fflush(stdin);
printf("Pierwszy numer telefonu: ");
	scanf("%ld",&(*nowy).numer1);
	fflush(stdin);
printf("Drugi numer telefonu: ");
	scanf("%ld",&(*nowy).numer2);
	fflush(stdin);
return nowy;
}

void print(wezel* wezel)
{
printf("Imie:     %s",(*wezel).imie);
printf("Nazwisko: %s",(*wezel).nazwisko);
printf("Numer 1:  %ld",(*wezel).numer1);
if((*wezel).numer2!=0) printf("\nNumer 2:  %ld\n",(*wezel).numer2);
else printf("\n");
}

int compare(char pierwszy[16],char drugi[16])
{
int i,k;
char wyraz1[16];
char wyraz2[16];
for(i=0; i<16; i++)
	{
	wyraz1[i]=tolower(pierwszy[i]);
	wyraz2[i]=tolower(drugi[i]);
	if(wyraz1[i]=='\n') wyraz1[i]='\0';
	if(wyraz2[i]=='\n') wyraz2[i]='\0';
	}
k=strcmp(wyraz1,wyraz2);
return k;
}

void insert(wezel* nowy, wezel* root)
{
wezel* wezel=root;
int k;
int koniec=1;
do{
k=compare((*nowy).nazwisko,(*wezel).nazwisko);
if(k==0);
{
	k=compare((*nowy).imie,(*wezel).imie);
}
if(k<=0)
{
	if((*wezel).left==NULL)
	{
		(*wezel).left=nowy;
		(*nowy).up=wezel;
		koniec=0;		
	}
	else
	{
		wezel=(*wezel).left;	
	}
}
if(k>0)
{
	if((*wezel).right==NULL)
	{
		(*wezel).right=nowy;
		(*nowy).up=wezel;
		koniec=0;
	}
	else
	{
		wezel=(*wezel).right;
	}
}
}while(koniec!=0);
}

void minimum(wezel* wezel)
{
	if((*wezel).left==NULL)
	{
		print(wezel);
		return;
	}
	else
	{
	minimum((*wezel).left);
	}
}

void maximum(wezel* wezel)
{
	if((*wezel).right==NULL)
	{
		print(wezel);
		return;
	}
	else
	{
		maximum((*wezel).right);
	}
}

void InOrder(wezel* root)
{
if(root==NULL) return;
InOrder((*root).left);
print(root);
printf("\n");
InOrder((*root).right);
return;
}

int find(wezel* root,char wyraz[16])
{
wezel* wsk=root;
int k=1;
int koniec=0;
do{
	if(wsk==NULL) 
	{
		koniec=1;
	}
	else
	{	
	k=compare(wyraz,(*wsk).nazwisko);
	if(k==0){
	koniec=1;
	print(wsk);}
	if(k<0)
	{
		wsk=(*wsk).left;
	}
	if(k>0)
	{
		wsk=(*wsk).right;
	}
	}
}while(koniec!=1);
return k;
}

int count(wezel* root)
{
if(root==NULL) return 0;
else
{
	int iloscl=count((*root).left);
	int iloscp=count((*root).right);
	return iloscl+iloscp+1;
}
}

int height(wezel* root)
{
if(root==NULL) return 0;
else
{
	int wysokoscl=height((*root).left);
	int wysokoscp=height((*root).right);
	if(wysokoscl>wysokoscp) return (wysokoscl+1);
	else return (wysokoscp+1);
   }
}
