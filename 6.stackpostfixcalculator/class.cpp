#include <iostream>
#include "class.h"
#define SIZE 100
using namespace std;


calc::calc(){
		stack = new int[SIZE];
		position=0;
		}

calc::calc(int size)	{
		stack=new int[size];
		position=0;
	}
calc::calc(calc &copy){
		stack=copy.stack;
		position=copy.position;
		}
calc::~calc(){
		delete [] stack;
		}
void calc::push(int x){
	//if((x!=42 && x!=43 && x!=45) && (x<48 || x>57))
	//cout<<"Wrong character!"<<endl;
	//else
	{stack[position]=x;
	position++;}
}

void calc::pop(){
	stack[position]='NULL';
	position--;
}

int calc::top(){
	return (char)stack[position-1];
}

int calc::isempty(){
if (position==0)return 1;
else return 0;
}

int calc::size(){
return position;
}


void calc::print(){
	cout<< "Stack: ";
for (int i=0;i<position;i++)
{
	cout<<stack[i]<<" ";
}
cout<<endl;
}

int calc::count(char temp[],int k){
int x;
int y;
char znak;
for(int i=0;i<k;i++){
	if(temp[i]=='+' || temp[i]=='-' ||temp[i]=='*')
	{push(temp[i]);}
else
	push(temp[i]-48);
	//print();
	znak=top();
	if(znak=='+')
	{		
	pop();
	x=top();
	pop();
	if(isempty())
		{cout<<"Wrong data!"<<endl;
		return 0;}
	y=top();
	pop();
	push(x+y);
	//print();
}
	if(znak=='*')
	{
	pop();
	x=top();
	pop();
	if(isempty())
		{cout<<"Wrong data!"<<endl;
		return 0;}
	y=top();
	pop();
	push(x*y);
	//print();
}
	if(znak=='-')
	{pop();
	x=top();
	pop();
	if(isempty())
		{cout<<"Wrong data!"<<endl;
		return 0;}
	y=top();
	pop();
	push(y-x);
	//print();
}
}
return top();
}
