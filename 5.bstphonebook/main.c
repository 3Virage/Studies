#include <stdio.h>
#include "array.h"
main()
{
int opcja,wpisy=0,wynik;
wezel* root;
wezel* nowy;
char nazwisko[16];
do{
wynik=0;
ClrScr();
printf("Ksiazka telefoniczna\n Menu:\n");
printf(" 1 - nowy wpis\n 2 - przejscie po ksiazce inOrder\n 3 - pierwszy wpis (alfabetycznie)\n 4 - ostatni wpis (alfabetycznie)\n 5 - ilosc wpisow\n 6 - wyszukaj po nazwisku\n 7 - Wysokosc drzewa\n");
printf(" 0 - wyjscie\nTwoj wybor: ");
	scanf("%d",&opcja);
	getchar();
if(wpisy==0)
{
	if(opcja>1)
	{
		printf("Nie ma zadnego wpisu \n");
		opcja=1;
	}
}
switch(opcja){
	case 1:
		if(wpisy==0) 
		{
			root=create(NULL);
			wpisy++;
		}
		else
		{
			nowy=create(NULL);
			insert(nowy,root);
			wpisy++;
		}
		break;
	case 2:
		InOrder(root);
		getchar();
		break;
	case 3:
		minimum(root);
		getchar();
		break;
	case 4:
		maximum(root);
		getchar();
		break;
	case 5:
		wynik=count(root);
		printf("Ilosc wpisow: %d", wynik);
		getchar();
		break;
	case 6:
		printf("Podaj szukane nazwisko: ");
			fgets(nazwisko,16,stdin);

		wynik=find(root,nazwisko);
		if(wynik!=0)
		{
		printf("Osoba o podanym nazwisku nie istnieje.\n");}
		getchar();
		break;
	case 7:
		wynik=height(root);
		printf("Wysokosc drzewa: %d wez³y. ",wynik);
		getchar();
		break;
	case 0:
		printf("Koniec programu");
		break;
}
}while(opcja!=0);
}

