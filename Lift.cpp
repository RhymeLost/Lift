#include <windows.h>
#include <iostream>
#include <string>

using namespace std;


class LIFT {
	short status = 1;
	short floor=1;
	short *pfloor =&floor;
	short maxfloor=0;
	short minfloor=0;
public:
	LIFT() {
		cout << "Лифт выключен\n";
		maxmin();
	}
	void maxmin() {
		short temp = 0;
		while (!temp) {
			cout << "\nВведите верхний этаж: ";
			cin >> maxfloor;
			cout << "Введите нижний этаж: ";
			cin >> minfloor;
			if (maxfloor <= minfloor) {
				cout << "\nНеверное значение!";
			}
			else { temp = 1; }
		}
	}
	void move(){
		if (status) {
			short temp = 0;
			while (!temp) {
				cout << "\nВыберите этаж: ";
				cin >> *pfloor;
				if (*pfloor < minfloor || *pfloor > maxfloor) { 
					cout << "\nНеверное знавчение!\n"; 
				}
				else { temp = 1; }
			}
		}
		else {
			cout << "\nЛифт выключен!\n";
		}
	}
	void show_floor() {
		cout << "\nСейчас лифт на этаже " << floor << endl;
	}
	void off_on() {
		short temp = 0;
		while (!temp) {
			cout << "\n1 - Вкл. 0 - Выкл\n";
			cin >> status;
			if (status != 0 && status != 1) {
				cout << "\nНеверное значение!";
			}
			else { temp = 1; }
		}
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	LIFT lift;

	while (1) {
		short action=0;
		cout << "\nВыберите действие: \n1 - Включить/выключить\n2 - Сменить границы\n3 - Выбрать этаж\n4 - Узнать текущий этаж\n";
		cin >> action;
		switch (action) { 
		case 1:
			lift.off_on();
			break;
		case 2:
			lift.maxmin();
			break;
		case 3:
			lift.move();
			break;
		case 4:
			lift.show_floor();
			break;
		default:
			cout << "\nНеверное значение!";
			break;
		}
	}

	cout << endl << endl;
}