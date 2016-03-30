#include "class.h"
int main()
{

	cout<<"Postfix calculator"<<endl;
	calc c1;	
	char znak='a';	
	while(znak!='q'){
		char temp[20];
		int k=0;
	do{	
	cout<<"Enter numbers and operators (c to calculate, q to quit)"<<endl;
	cin>>znak;
	if(znak=='c'){break;}
	if(znak=='q'){return 0;}
	if((znak!=42 && znak!=43 && znak!=45) && (znak<48 || znak>57))
	cout<<"Wrong character!";
	else{
	temp[k]=znak;
	cout << "Your data:";
	for(int i=0;i<=k;i++){
		cout<<temp[i]<<" ";
		}
	k++;
	}
	cout <<endl;
	
}while(znak!='q'&& znak!='c');
	cout<<"Result: "<<c1.count(temp,k)<<endl;
	}	
	return 0;
}
