#include <iostream>
#define SIZE 100
using namespace std;

class calc{
private:
	int *stack;
	int position;
public:
	calc();
	calc(int size);
	calc(calc &copy);
	~calc();

void push(int x);
void pop();
int top();
int isempty();
int size();
void print();
int count(char temp[],int k);
	};



