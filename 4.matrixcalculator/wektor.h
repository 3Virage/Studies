#ifndef wektorh
#define wektorh
#define ROZMWEK 2
#define ROZMMAC 2
#include <iostream>
#include <cmath>
using namespace std;
class wektor {
private:
float *wsp;
int wym;
public:
wektor (int iloscwsp);
wektor ();
wektor (const wektor  &w);
~wektor();


wektor &operator = (const wektor &w);
wektor &operator += (const wektor &w);
wektor &operator -= (const wektor &w);
wektor &operator *= (float k);
float &operator[](int k);

friend wektor operator+(const wektor &w1,const wektor &w2);
friend wektor operator-(const wektor &w1,const wektor &w2);
friend float operator*(const wektor &w1,const wektor &w2);
friend bool operator ==(const wektor &w1, const wektor &w2 );
friend bool operator !=(const wektor &w1,const wektor &w2);
friend istream& operator >> (istream &s,const wektor &w);
friend ostream& operator << (ostream &s,const wektor &w);
};

#endif
