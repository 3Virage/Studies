#include <iostream>
#include <string>
using namespace std;
class Shop {
private:
	string name;
	string item;
	string street;
	int number;
	float price;

public:
	Shop(string n, string i, float p, string s, int nb);
	Shop();

	void print();
	void get();
	void getLine(istream &is); //str, str, float, str, int
	bool operator==(Shop &s);
	
};