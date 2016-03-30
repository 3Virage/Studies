#include <iostream>
#include<string>
using namespace std;

class pracownik {
public:
	pracownik();
	pracownik(string i, string n, string psl, string np);
	virtual ~pracownik();
	string imie;
	string nazwisko;
	string PESEL;
	string NIP;
	virtual void  print();
	int virtual  wylicz_zarobki();
	friend ostream & operator<< (ostream &wyjscie, const pracownik & p);
	string getNazwisko() { return nazwisko; }
	pracownik(int);
};



class staly :public pracownik {
public:
	staly();
	staly(string i, string n, string psl, string np, int pen);
	virtual ~staly();
	int pensja;
	int wylicz_zarobki();
	void print();
	
	};

class zlecenie :public pracownik {
public:
	zlecenie();
	zlecenie(string i, string n, string psl, string np, int stw, int g);
	virtual ~zlecenie();
	int stawka;
	int godziny;
	int wylicz_zarobki();
	void print();
	
};

class handlowiec :public pracownik {
public:
	handlowiec();
	handlowiec(string i, string n, string psl, string np, int pr, int s);
	virtual ~handlowiec();
	int procent;
	int sprzedaz;
	int wylicz_zarobki();
	void print();
};

