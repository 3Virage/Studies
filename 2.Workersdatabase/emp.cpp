#include "emp.h"
#include <iomanip>
void pracownik::print() {
	cout << left << setw(15) <<"Imie:" << imie << endl;
	cout << left << setw(15) << "Nazwisko:" << nazwisko << endl;
	cout << left << setw(15) << "NIP:" << NIP << endl;
	cout << left << setw(15) << "PESEL:" << PESEL << endl;
}

pracownik::pracownik() {
	cout << "Dane pracownika:" << endl;
	cout << "Imie:" << endl;
	cin >> imie;
	cout << "Nazwisko:" << endl;
	cin >> nazwisko;
	cout << "NIP:" << endl;
	cin >> NIP;
	cout << "PESEL:" << endl;
	cin >> PESEL;
}
pracownik::pracownik(string i, string n, string psl, string np) {
	imie = i;
	nazwisko = n;
	PESEL = psl;
	NIP = np;
}

pracownik::~pracownik() {}

int pracownik::wylicz_zarobki() { return 0; }



staly::staly() :pracownik() {
	cout << "Pensja:" << endl;
	cin >> pensja;
}

staly::staly(string i, string n, string psl, string np, int pen) : pracownik(i, n, psl, np) {
	pensja = pen;
}

staly::~staly() {}

int staly::wylicz_zarobki() {
	return pensja;
}

void staly::print() {
	pracownik::print();
	cout << left<<setw(15)<<"Pensja:" << pensja <<"zl"<< endl;
	cout << left << setw(15) << "Wynagrodzenie:" << wylicz_zarobki() << "zl"<<endl;
}



zlecenie::zlecenie() :pracownik() {
	cout << "Stawka:" << endl;
	cin >> stawka;
	cout << "Godziny:" << endl;
	cin >> godziny;
}

zlecenie::zlecenie(string i, string n, string psl, string np, int stw, int g) :pracownik(i, n, psl, np) {
	stawka = stw;
	godziny = g;
}

zlecenie::~zlecenie() {}


int zlecenie::wylicz_zarobki() {
	if (godziny>160)
	{
		return 160 * stawka + (godziny - 160)*stawka*1.5;
	}
	else {
		return godziny*stawka;
	}
}

void zlecenie::print() {
	pracownik::print();
	cout << left << setw(15) << "Stawka:" << stawka <<"zl"<< endl;
	cout << left << setw(15) << "Godziny:" << godziny << endl;
	cout << left << setw(15) << "Wynagrodzenie:" << wylicz_zarobki() <<"zl"<< endl;
}


handlowiec::handlowiec() :pracownik() {
	cout << "Procent:" << endl;
	cin >> procent;
	cout << "Sprzedaz:" << endl;
	cin >> sprzedaz;
}
handlowiec::handlowiec(string i, string n, string psl, string np, int pr, int s) :pracownik(i, n, psl, np) {
	sprzedaz = s;
	procent = pr;
}

handlowiec::~handlowiec() {}

int handlowiec::wylicz_zarobki() {
	double temp = procent*0.01*sprzedaz;
	return (int)temp;
}
void handlowiec::print() {
	pracownik::print();
	cout << left << setw(15) << "Procent:" << procent <<"%"<< endl;
	cout << left << setw(15) << "Sprzedaz:" << sprzedaz <<"zl"<< endl;
	cout << left << setw(15) << "Wynagrodzenie:" << wylicz_zarobki() <<"zl"<< endl;
}

ostream & operator<< (ostream &wyjscie, const pracownik & p) {
	wyjscie << p.imie << " " << p.nazwisko << " " << p.PESEL << " " << p.NIP << endl;
	return wyjscie;
}

