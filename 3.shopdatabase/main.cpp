#include "VectorT.cpp"
#include "shop.h"
#include <string>
#include <fstream>
using namespace std;

int main() {
	vector<Shop> sklep;
	const char* FILE = "dane.txt";
	ifstream dataFile(FILE);
	if (!dataFile.is_open())
	{
		cout << "Blad pliku" << endl;
		return -1;
	}

	while (!cin.eofbit)
	{
		Shop Elem;
		Elem.getLine(dataFile);

		sklep.add(Elem);
	}
	cout << "Dodano dane z pliku" << endl;
	dataFile.close();

	Iter<Shop> its(sklep.start());
	Iter<Shop> itf(sklep.stop());

	for (its = sklep.start(); its != itf; ++its)
	{
		(*its).print();
	}

	while (1)
	{
		string name, item, street;
		float price;
		int number;
		cout << "Wyszukaj (0 aby zakonczyc)" << endl;

		cin >> name;
		if (name == "0")
			break;
		cin >> item;
		if (item == "0")
			break;
		cin >> price;
		if (price == 0)
			break;
		

		cin.get();

		Shop record(name, item, price, "brak", 0);
		bool found = false;

		for (its = sklep.start(); its != itf; ++its)
		{
			if ((*its) == record)
			{
				(*its).print();
				found = true;
			}
		}

		if (!found)
			cout << "Nie znaleziono podanego rekordu\n";
	}

	
	return 0;

}