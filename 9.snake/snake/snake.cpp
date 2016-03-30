#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
using namespace std;
#define SIZE 10  //set size 
#define SPEED 2  //set speed


class point {
public:
	int x;
	int y;

	point();
	point(int xx, int yy);
	int random(int size);
};

point::point() {
	x = random(SIZE);
	y = random(SIZE);
}
point::point(int xx, int yy) {
	x = xx;
	y = yy;
}
int point::random(int size) {
	int a = 0;

	a = rand() % SIZE + 1;
	return a;
}

class snake {
public:
	point headpoint;
	int dir;
	point *memory;

	int count();
	void move();
	void turn(int turnkey);
	int getkey();
	int eat(point &p);

	snake();
};

snake::snake() {
	headpoint.x = SIZE / 2;
	headpoint.y = SIZE / 2;
	dir = 2;
	memory = new point[SIZE*SIZE];
	for (int i = 0; i <= SIZE*SIZE - 1; i++) {
		memory[i].x = 0;
		memory[i].y = 0;
	}
	memory[0].x = headpoint.x;
	memory[0].y = headpoint.y;
}
int  snake::count() {
	for (int i = 0; i <= SIZE*SIZE; i++) {
		if (memory[i].x == 0)
			return i + 1;
	}
	return 0;
}
void snake::move() {
	int k = count();

	switch (dir) {
	case 0:
	{
		for (int i = SIZE*SIZE - 1; i >= 1; i--)
		{
			memory[i].x = memory[i - 1].x;
			memory[i].y = memory[i - 1].y;
		}
		memory[0].x = headpoint.x;
		memory[0].y = headpoint.y;
		headpoint.x--;
		memory[k - 1].x = 0;
		memory[k - 1].y = 0;
		break;
	}
	break;
	case 1:
		for (int i = SIZE*SIZE - 1; i >= 1; i--)
		{
			memory[i].x = memory[i - 1].x;
			memory[i].y = memory[i - 1].y;

		}
		memory[0].x = headpoint.x;
		memory[0].y = headpoint.y;
		headpoint.y--;
		memory[k - 1].x = 0;
		memory[k - 1].y = 0;
		break;
	case 2:
		for (int i = SIZE*SIZE - 1; i >= 1; i--)
		{
			memory[i].x = memory[i - 1].x;
			memory[i].y = memory[i - 1].y;
		}
		memory[0].x = headpoint.x;
		memory[0].y = headpoint.y;
		headpoint.x++;
		memory[k - 1].x = 0;
		memory[k - 1].y = 0;
		break;
	case 3:
		for (int i = SIZE*SIZE - 1; i >= 1; i--)
		{
			memory[i].x = memory[i - 1].x;
			memory[i].y = memory[i - 1].y;
		}
		memory[0].x = headpoint.x;
		memory[0].y = headpoint.y;
		headpoint.y++;
		memory[k - 1].x = 0;
		memory[k - 1].y = 0;
		break;

	}

}
void snake::turn(int turnkey) {
	switch (dir) {
	case 0:
		if (turnkey == 1)
			dir = 1;
		if (turnkey == 2)
			dir = 3;
		break;
	case 1:
		if (turnkey == 1)
			dir = 2;
		if (turnkey == 2)
			dir = 0;
		break;
	case 2:
		if (turnkey == 1)
			dir = 3;
		if (turnkey == 2)
			dir = 1;
		break;
	case 3:
		if (turnkey == 1)
			dir = 0;
		if (turnkey == 2)
			dir = 2;
		break;
	}

}
int snake::getkey() {
	int num = 0;
	for (int i = 0; i <= 10; i++) {
		Sleep(10000 / (SPEED * 100));
		if (_kbhit()) //key pressed
		{
			int	a;
			int b;
			a = _getch();
			b = _getch();
			if (a == 224 && b == 75) {
				num = 1;
			}
			if (a == 224 && b == 77) {
				num = 2;
			}
		}
	}
	return num;
}
int snake::eat(point &p) {
	int t = 0;
	int k = count();
	if (headpoint.x == p.x && headpoint.y == p.y) {
		for (int i = k; i >= 2 - 1; i--) {
			memory[i - 1].x = memory[i - 2].x;
			memory[i - 1].y = memory[i - 2].y;
			t = 1;
		}
	}
	return t;
}


int crash(snake &s);
void show(int score);
void over();
void win();
void print(snake &s, point &randpoint);
int randcheck(point &p, snake &s);


int crash(snake &s) {
	int t = 0;
	if (s.headpoint.x == SIZE + 1 || s.headpoint.x == 0 || s.headpoint.y == 0 || s.headpoint.y == SIZE + 1)
		t = 1;
	for (int i = 0; i <= SIZE*SIZE; i++) {
		if (s.headpoint.x == s.memory[i].x && s.headpoint.y == s.memory[i].y)
			t = 1;
	}
	return t;
}
void show(int score) {
	cout << "Wynik: " << score << " Pkt" << endl;
	return;
}
void over() {
	cout << "Przegrales" << endl;
	return;
}
void win() {
	cout << "Wygrales";
}
void print(snake &s, point &randpoint) {
	for (int i = 0; i <= SIZE + 1; i++) {
		cout << "#";
	}
	cout << endl;

	for (int i = 1; i <= SIZE; i++) {
		cout << "#";
		for (int j = 1; j <= SIZE; j++) {
			int t = 0;
			for (int k = 0; k <= SIZE*SIZE - 1; k++) {
				if (s.memory[k].x == i && s.memory[k].y == j)
				{
					t = 1;
				}
				if (randpoint.x == i && randpoint.y == j)
				{
					t = 2;
				}
				if (s.headpoint.x == i && s.headpoint.y == j)
				{
					t = 3;
				}
			}
			if (t)
			{
				if (t==1)
				cout << "@";
				else if (t==2)
					cout << "*";
				else if (t==3)
					cout << "&";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "#" << endl;
	}


	for (int i = 0; i <= SIZE + 1; i++) {
		cout << "#";
	}
	cout << endl;
}
int randcheck(point &p, snake &s) {
	int k = s.count();
	for (int i = 0; i < k; i++)
	{
		if ((s.memory[i].x == p.x && s.memory[i].y == p.y) || (s.headpoint.x == p.x || s.headpoint.y == p.y)) {
			return 1;
		}
	}
	return 0;
}



int main() {
	srand((int)time(NULL));
	point p = point();
	while (1) {
		system("cls");
		snake s;
		s.memory[0].x = s.headpoint.x - 1; s.memory[0].y = s.headpoint.y;
		s.memory[1].x = s.headpoint.x - 2; s.memory[1].y = s.headpoint.y;
		print(s, p);
		show(s.count());
		while (1) {
			if (s.eat(p)) {
				cout << "+1";
				do {
					p = point();
				} while (randcheck(p, s));
			}
			s.turn(s.getkey());
			system("cls");
			s.move();
			print(s, p);
			show(s.count());
			if (crash(s))
			{
				over();
				cout << "Wcisnij enter aby grac ponownie" << endl;
				getchar();
				break;
			}
			if (s.count() == SIZE*SIZE)
			{
				win();
				cout << "Gratulacje, wcisnij enter aby grac ponownie" << endl;
				getchar();
				break;
			}
		}
	}
	return 0;
}


