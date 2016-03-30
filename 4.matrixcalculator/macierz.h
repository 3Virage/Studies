#ifndef macierzh
#define macierzh

#include "wektor.h"

class macierz{
private:
	int ilwierszy;
	int ilkolumn;
wektor *wektory;
public:
macierz(int ilw, int ilk);
macierz();
macierz (const macierz  &m);
~macierz();


macierz &operator = ( macierz &m);
macierz &operator += (const macierz &m);
macierz &operator -= (const macierz &m);
macierz &operator *= (float p);

friend macierz operator+(const macierz &m1,const macierz &m2);
friend macierz operator-(const macierz &m1,const macierz &m2);
friend macierz operator*(const macierz &m1,const macierz &m2);
friend bool operator ==(const macierz &m1,const macierz &m2);
friend bool operator !=(const macierz &m1,const macierz &m2);
friend istream& operator >> (istream &s, macierz &m);
friend ostream& operator << (ostream &s, macierz &m);
};

#endif