#include "macierz.h"



macierz::macierz(int ilw, int ilk)
{
    ilwierszy=ilw;
	ilkolumn=ilk;
	wektory=new wektor[ilw];
	for(int i=0;i<ilw;i++){
    wektory[i]=wektor(ilk);
	}
}
macierz::macierz(){
ilwierszy=ROZMMAC;
ilkolumn=ROZMWEK;
wektory=new wektor[ilwierszy];
for(int i=0;i<ilwierszy;i++){
wektory[i]=wektor(ilkolumn);
}
}

macierz::macierz(const macierz &m)
{
ilwierszy=m.ilwierszy;
ilkolumn=m.ilkolumn;
	wektory = new wektor[m.ilwierszy];
     for(int i=0; i<ilwierszy; i++){
         wektory[i]=m.wektory[i];
     }
}

macierz::~macierz(){
delete[] wektory;
}



macierz &macierz :: operator=( macierz &m){
 if(ilwierszy!=m.ilwierszy || ilkolumn!=m.ilkolumn){cout<<"Nie mozna przypisac macierzy w roznych wymiarach"<<endl;return *this;}
   else

	for(int i=0;i<=m.ilwierszy;i++)
    {  wektory[i]=m.wektory[i];
    }
	 return *this;
}
macierz &macierz ::operator+=(const macierz &m){
 if(ilwierszy!=m.ilwierszy || ilkolumn!=m.ilkolumn){cout<<"Nie mozna dodac macierzy w roznych wymiarach"<<endl;return *this;}
   else
for(int i =0;i<m.ilwierszy;i++)
{wektory[i]+=m.wektory[i];
}
return *this;
}
macierz &macierz ::operator-=(const macierz &m){
 if(ilwierszy!=m.ilwierszy || ilkolumn!=m.ilkolumn){cout<<"Nie mozna odjac macierzy w roznych wymiarach"<<endl;return *this;}
   else
for(int i =0;i<m.ilwierszy;i++)
{wektory[i]-=m.wektory[i];
}
return *this;
}
macierz &macierz ::operator*=(float p)
{
	for(int i=0;i<ilwierszy;i++){
		wektory[i]*=p;}
	return *this;
}

macierz operator+(const macierz &m1,const macierz &m2){
    macierz m3;
    if(m1.ilwierszy!=m2.ilwierszy || m1.ilkolumn!=m2.ilkolumn){cout<<"Nie mozna dodac macierzy w roznych wymiarach"<<endl;return m1;}
   else
   for(int i=0;i<m1.ilwierszy;i++){
   m3.wektory[i]=m1.wektory[i]+m2.wektory[i];
        }
    return m3;
}
macierz operator-(const macierz &m1,const macierz &m2){
    macierz m3;
    if(m1.ilwierszy!=m2.ilwierszy || m1.ilkolumn!=m2.ilkolumn){cout<<"Nie mozna odjac macierzy w roznych wymiarach"<<endl;return m1;}
   else
   for(int i=0;i<m1.ilwierszy;i++){
   m3.wektory[i]=m1.wektory[i]-m2.wektory[i];
        }
    return m3;
}

macierz operator*(const macierz &m1,const macierz &m2){
    if (m1.ilwierszy!=m2.ilkolumn){cout<<"Nie mozna pomnozyc macierzy o takich wymiarach"<<endl;return m1;}
	else{
	macierz m3;	
           float suma = 0;
	for (int i = 0; i < m1.ilwierszy; i++)
	{
	for (int j = 0; j < m2.ilkolumn;j++)
	{
	suma = 0;
	for (int k = 0; k < m1.ilkolumn; k++)
	suma += m1.wektory[i][k+1] * m2.wektory[k][j+1];
	m3.wektory[i][j+1] = suma;	
	}
	}
	return m3;}
	}

bool operator==(const macierz &m1,const macierz &m2){
    bool k = 1;
     if(m1.ilwierszy!=m2.ilwierszy || m1.ilkolumn!=m2.ilkolumn){k=0; return k;}
     for(int i=0;i<m1.ilwierszy;i++){
         if(m1.wektory[i]!=m2.wektory[i]){k=0;}
		 }
        return k;
}
bool operator!=(const macierz &m1,const macierz &m2){
	bool k=1;
	if(&m1==&m2)
	k=0;
	return k;
}

istream& operator >> (istream &s, macierz &m){
		for(int i=0;i<m.ilwierszy;i++){
	cout << "Wektor "<< i+1<<endl;
	cin >> m.wektory[i];}
		return s;
	}
ostream& operator << (ostream &s, macierz &m){
		for(int i=0;i<m.ilwierszy;i++){
			cout << m.wektory[i];}
		return s;
		}

