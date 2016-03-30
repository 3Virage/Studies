#include "emp.h"
#include<vector>

void print(vector<pracownik*> v) {
	for (int i = 0; i < v.size(); i++){
		(*v[i]).print();
	cout << endl;
}
	}

void menu() {
	cout << "1 - wyswietl baze\n2 - nowy pracownik\n3 - usun pracownika\n4 - Wyszukaj\n5 - zamknij program" << endl;
}
int main()
{
vector<pracownik*> workers;
	pracownik p1("Michal", "Kot", "04928249394", "342-543-23-23");		
	staly p2("Maciek", "Staniszewski", "49393929402", "424-434-76-73", 2700);
	zlecenie p3("Karol", "Lipnicki", "39204929422", "423-864-01-53",20,180);
	handlowiec p4("Janusz", "Gora", "39294029492", "428-454-87-45", 9, 23000);
	workers.push_back(&p1);
	workers.push_back(&p2);
	workers.push_back(&p3);
	workers.push_back(&p4);
	staly s("2","3","2","3",3);

	while(1){
		
		menu();
		char wybor;
		string temp;
		cin >> wybor;
		switch (wybor) {
		case'1':
			print(workers);
			break;
		case'2': {
			cout << "Prosze podac typ zatrudnienia (1 - stale; 2 - zlecenie; 3 - handlowiec; 4 - nieokreslony)" << endl;
			char w;
			cin >> w;
			switch (w) {
			case '1':
				workers.push_back(new staly());
				break;
			case '2':
				workers.push_back(new zlecenie());
				break;
			case '3':
				workers.push_back(new handlowiec());
				break;
			case '4':
				workers.push_back(new pracownik());
				break;
			default:
				break;
			}
			break; 
		}
		case'3':
			cout << "Prosze podac nazwisko" << endl;
			cin >> temp;
			for (int i = 0; i < workers.size(); i++) {
				if ((*workers[i]).getNazwisko() == temp){ 
					workers.erase(workers.begin() + i);
				cout << "Usunieto" << endl;
			}
			}
			break;
		case '4':
			cout << "Prosze podac nazwisko" << endl;
			cin >> temp;
			for (int i = 0; i < workers.size(); i++) {
				if ((*workers[i]).getNazwisko() == temp) {
					(*workers[i]).print();
				}
			}
			break;
		case'5':
			goto finish;
		default:
			break;
					}

}
		
	finish:
	return 0;

	
}
