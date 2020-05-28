#include "friend.h"
#include "Cashbox.h"
#include "Plane.h"
#include "Train.h"
#include <string>

using namespace std;

void menu() {
	setlocale(LC_ALL, "Russian");
	Cashbox *handler1;
	Plane   *handler2;
	Train   *handler3;
	int day;
	int mouth;
	int year;
	int choice;
	int cost;
	string filename = "train.txt";
	string filename2 = "plane.txt";
	string filename3 = "tickets.txt";
	string point, request;
	bool flag1 = true, flag = true;
	int but1, bu2, but3;
	cout << "Меню пользователя:" << endl;
	cout << "1. Сделать запрос класс -> поезд -> самолёт" << endl;
	cout << "2. Вывести  билет " << endl;
	cout << "3. Добавить билет " << endl;
	cout << "4. Удалить билет " << endl;
	cout << "5. Изменить данные билета " << endl;
	cout << "6. Добавить свой файл на вход программы" << endl;
	while (flag) {
		cin >> but1;
		switch (but1)
		{
		case 1:
		{
			system("cls");
			while (flag1) {
				system("cls");
				cout << "1 - Найти запрос по всем параметрам" << endl;
				cout << "2 - Найти запрос по одному параметру" << endl;
				cout << "0 - Вернуться назад" << endl;;
				cout << "Выберите действие 0-2:  ";
				cin >> but1;
				switch (but1)
				{
				case 1: {
					system("cls");
					handler1 = new Cashbox;
					handler1->SetNext(new Plane)->SetNext(new Train);
					handler1->push();
					request = converter(handler1);
					handler1->handle(request);
					delete handler1;
					break; }
				case 2: {
					system("cls");
					handler1 = new Cashbox;
					handler1->SetNext(new Plane)->SetNext(new Train);
					cout << "Выберите по какому параметру будет отправлен запрос:" << endl;
					cout << "1 - Дата" << endl;
					cout << "2 - Стоимость" << endl;
					cout << "3 - Пункт назначения" << endl;
					cin >> choice;
					switch (choice)
					{
					case 1: {
						system("cls");
						cout << "День (1 -31): ";
						cin >> day;
						cout << "Месяц (1 -12): ";
						cin >> mouth;
						cout << "Год (20 - 21): ";
						cin >> year;
						request = to_string(day) + to_string(mouth) + to_string(year);
						handler1->handle(request);
						break; }
					case 2: {
						cout << "Стоимость: ";
						cin >> cost;
						request = to_string(cost);
						handler1->handle(request);
						break; }
					case 3: {
						cout << "Пункт назначения: ";
						cin >> point;
						handler1->handle(point);
						break; }
					default:"красава";
						break;
					}
					break;
				}
				default:"Неверный ввод";
					break;
				}
			}
		}
		case 2: {
			handler1 = new Cashbox;
			cout << "Выберите какие билеты вы хотите вывести" << endl;
			cout << "1. Все" << endl;
			cout << "2. Поезд" << endl;
			cout << "3. Самолёт" << endl;
			cout << "4. Билеты" << endl;
			cin >> but3;
			switch (but3)
			{
			case 1: {
				system("cls");
				cout << "Поезда:" << endl;
				handler1->fprint(filename);
				cout << "Самолёты:" << endl;
				handler1->fprint(filename2);
				cout << "Билеты:" << endl;
				handler1->fprint(filename3);
				delete handler1;
				system("pause");
				break;
			}
			case 2: {
				system("cls");
				cout << "Поезда:" << endl;
				handler1->fprint(filename);
				delete handler1;
				break;
			}
			case 3: {
				system("cls");
				cout << "Самолёты:" << endl;
				handler1->fprint(filename2);
				delete handler1;
				break;
			}
			case 4: {
				system("cls");
				cout << "Билеты:" << endl;
				handler1->fprint(filename3);
				delete handler1;
				break;
			}
			default:
				break;
			}
		}
		case 3: {
			system("cls");
			cout << "Выберите куда вы хотите добавить билет" << endl;
			cout << "1. Поезд" << endl;
			cout << "2. Самолёт" << endl;
			cout << "3. Билеты" << endl;
			cin >> but3;
			switch (but3)
			{
			case 1: {
				system("cls");
				handler1 = new Cashbox;
				handler1->fpush(filename);
				delete handler1;
				system("pause");
				break;
			}
			case 2: {
				system("cls");
				handler1 = new Cashbox;
				handler1->fpush(filename2);
				delete handler1;
				system("pause");
				break; }
			case 3: {
				system("cls");
				handler1 = new Cashbox;
				handler1->fpush(filename3);
				delete handler1;
				system("pause");
				break; }
			default:"Неверный ввод";
				break;
			}
		}
		case 4: {
			system("cls");
			cout << "Выберите в каком файле требуется удаление данных" << endl;
			cout << "1. Поезд" << endl;
			cout << "2. Самолёт" << endl;
			cout << "3. Билеты" << endl;
			cin >> but3;
			switch (but3)
			{
			case 1: {
				system("cls");
				handler1 = new Cashbox;
				handler1->change(2, filename2, handler1);
				delete handler1;
				system("pause");
				break;
			}
			case 2:
			{
				system("cls");
				break;
			}
			case 3: {
				system("cls");
				break;
			}

			default:
				break;
			}
		}
		case 5: {

		}
		case 6: {

		}
		case 0: {
			flag = false;
			break;
		}
		}
	}
}