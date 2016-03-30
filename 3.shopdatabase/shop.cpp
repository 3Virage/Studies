#include "shop.h"
#include <iostream>
#include <string>
#include <iomanip>

Shop::Shop(string n, string i, float p, string s, int nb):name(n),item(i),price(p),street(s),number(nb){}
Shop::Shop() : name("brak"), item("brak"), price(0), street("brak"), number(0){}
bool   Shop::operator==(Shop &s) {
	if (name == s.name && item == s.item && price == s.price)return true;
	else return false;
}
void Shop::print() {
	cout.width(10);

	cout <<left<< name;
	cout.width(10);
	cout << left<<item;
	cout.width(10);
	cout << left << price;
	cout.width(10);
	cout << left<<street;
	cout.width(10);
	cout << left<<number << endl;
}

void Shop::get()
{

	cout << "Nazwa: ";
	getline(cin, name);
	cout << "Zabawka: ";
	getline(cin, item);
	cout << "Cena: ";
	cin >> price;
	cin.get();
	cout << "Ulica: ";
	getline(cin, street);

	cout << "Numer ulicy: ";
	cin >> number;
	cin.get();

}

void Shop::getLine(std::istream &is)
{
	is >> name >> item >> price >> street >> number;
	is.get();
}