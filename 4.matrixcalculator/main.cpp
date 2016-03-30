
#include "macierz.h"
#include "wektor.h"
#include "stdio.h"
int main(){

	
	macierz m1;
	macierz m2;
	cout<<"macierz m1"<<endl;
	cin>>m1;
	cout<<"macierz m2"<<endl;
	cin>>m2;
	char m;
	float k;
printf("\033[2J");printf("\033[0;0f");
	while(1){
		cout << "Menu:\n0 >> m1,m2 \n1 << m1,m2\n2 m1+=m2\n3 m1-=m2\n4 m1*=a\n5 m1==m2\n6 m1!=m2\n7 m1+m2\n8 m1-m2\n9 m1*m2\nQ Wyjscie\n";
	cin >>m;
	printf("\033[2J");printf("\033[0;0f");
	switch(m){
	case'0':
		cout<<"macierz m1"<<endl;
		cin>>m1;
		cout<<"macierz m2"<<endl;
		cin>>m2;

		break;
	case'1':
		cout<<"macierz m1"<<endl<<m1<<"macierz m2"<<endl<<m2;
		break;
	case'2':
		cout<<m1<<"+="<<endl<<m2<<"="<<endl;
		m1+=m2;
		cout<<m1;
		break;
	case'3':
		cout<<m1<<"-="<<endl<<m2<<"="<<endl;
		m1-=m2;
		cout<<m1;
		break;
	case'4':
		cin>>k;
		printf("\033[2J");printf("\033[0;0f");
		cout<<m1<<"*="<<endl<<k<<endl<<"="<<endl;
		m1*=k;
		cout<<m1;
		break;
	case'5':
		cout<<m1<<"=="<<endl<<m2<<"="<<endl;
		bool a;
		a=m1==m2;
		cout<<a<<endl;
		break;
	case'6':
		cout<<m1<<"!="<<endl<<m2<<"="<<endl;
		bool b;
		b=m1!=m2;
		cout<<b<<endl;
		break;
	case'7':
		{
		cout<<m1<<"+"<<endl<<m2<<"="<<endl;
		macierz m3(m1+m2);		
		cout<<m3;
		break;}
	case'8':
		{
		cout<<m1<<"-"<<endl<<m2<<"="<<endl;
		macierz m3(m1-m2);
		cout<<m3;
		break;}
	case'9':
		{
		cout<<m1<<"*"<<endl<<m2<<"="<<endl;
		macierz m3(m1*m2);
		cout<<m3;
		break;}
	case'q':
		goto end;
		break;
    case'Q':
		goto end;
		break;
	default:break;
	}getchar();
	getchar();
	printf("\033[2J");printf("\033[0;0f");	
	}
end:return 0;
	}
