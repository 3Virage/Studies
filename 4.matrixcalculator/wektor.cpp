
#include "wektor.h"


wektor::wektor(int iloscwsp){
	wym=iloscwsp;
	wsp = new float[wym];
     for(int i=0; i<wym; i++){
         wsp[i]=0;
     }
 }
wektor::wektor(){
	wym=ROZMWEK;
	wsp = new float[wym];
     for(int i=0; i<wym; i++){
         wsp[i]=0;
     }
 }
wektor::wektor(const wektor &w)
{
wym=w.wym;
	wsp = new float[wym];
     for(int i=0; i<wym; i++){
         wsp[i]=w.wsp[i];
     }
}

wektor::~wektor(){
	delete []wsp;

}




wektor &wektor :: operator=(const wektor &w){
for(int i=0;i<=w.wym;i++)
    {  wsp[i]=w.wsp[i];
    }
	 return *this;
}
wektor &wektor ::operator+=(const wektor &w)
{for(int i =0;i<w.wym;i++)
{wsp[i]+=w.wsp[i];
}
return *this;
}
wektor &wektor ::operator-=(const wektor &w)
{for(int i =0;i<w.wym;i++)
{wsp[i]-=w.wsp[i];
}
return *this;
}
wektor &wektor ::operator*=(float k)
{
for(int i =0;i<wym;i++){
	wsp[i]=k*wsp[i];
}
return *this;
}
float &wektor ::operator[](int k)
{
 return wsp[k-1];
}

wektor operator+(const wektor &w1,const wektor &w2){
	wektor w3(w1.wym);
	if(w1.wym!=w2.wym){cout<<"Nie mozna odjac wektorow w roznych wymiarach"<<endl;}
	 for(int i = 0; i<w1.wym;i++){
         w3.wsp[i]=w1.wsp[i]+w2.wsp[i];
		 
     }
 return  w3;
}
wektor operator-(const wektor &w1,const wektor &w2){
	wektor w3(w1.wym);
	if(w1.wym!=w2.wym){cout<<"Nie mozna odjac wektorow w roznych wymiarach"<<endl;}
	 for(int i = 0; i<w1.wym;i++){
         w3.wsp[i]=w1.wsp[i]-w2.wsp[i];
     }
 return w3;
}
float operator*(const wektor &w1,const wektor &w2){
	float k=0;
	if(w1.wym!=w2.wym){cout<<"Nie mozna pomnozyc wektorow w roznych wymiarach"<<endl;}
	 for(int i = 0; i<w1.wym;i++){
        k+=w1.wsp[i]*w2.wsp[i];
     }
 return k;
}
bool operator==(const wektor &w1,const wektor &w2){
    bool k=1;
    if(w1.wym!=w2.wym){k=0;return k;}
	for(int i=0; i<w1.wym;i++)
    {if(w1.wsp[i]!=w2.wsp[i])
    {k=0;}
	}
    return k;
}
bool operator!=(const wektor &w1,const wektor &w2){
	bool k = (&w1==&w2);
	bool p;
	if (k==1){p=0;}
	else {p=1;}
	return p;
}

istream& operator >> (istream &s,const wektor &w)
	{
		for(int i=0; i<w.wym; i++){
         cout << "Podaj " << i+1 << " wspolrzedna" << endl;
         float k;
         cin >> k;
         w.wsp[i]=k;
     }
	 return s;
	}
ostream& operator << (ostream &s,const wektor &w)
	{
     for(int i=0;i<w.wym;i++){
           cout << w.wsp[i] << " ";
     }
cout << endl;
		return s;

	}

