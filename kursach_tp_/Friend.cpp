#include <Windows.h>//используется для красиваого ввода даты в формате ДД.ММ.ГГ
#include "friend.h"
#include "Cashbox.h"


using namespace std;

string converter(int day, int mouth, int year, int cost, string str) {
	string request;
	request = to_string(day) + "." + to_string(mouth) + "." + to_string(year) + " " + to_string(cost) + " " + str;
	return request;
}


string menu(int flag2) {
	COORD position;										// Объявление необходимой структуры
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int day;
	int mouth;
	int year;
	int choice;
	int cost;

	string str1,point, request, str = "Некорректный ввод, используйте пример";

	bool flag1 = true, flag = true;
	switch (flag2)
	{
	case 0: {
		while (flag) {
			cout << "Система запросов Касса -> Поезд -> Самолёт" << endl;
			cout << "Введите свой запрос" << endl;
			while (true) {
				cout << "Введите дату:ДД.ММ.ГГ" << endl;
				cout << "Пример:\n Дата:16.06.20 Стоимость:1999 рублей Пункт назначения:Волгоград" << endl;
				cout << "Дата: ";
				while (flag1) {
					flag1 = false;
					position.X = 5;
					position.Y = 5;
					SetConsoleCursorPosition(hConsole, position);
					cin >> day;
					if (day > 9)
						position.X = 7;
					else
						position.X = 6;
					position.Y = 5;
					SetConsoleCursorPosition(hConsole, position);
					cout << ".";
					cin >> mouth;
					if (mouth > 9) {
						if (day < 10)
							position.X = 9;
						else
							position.X = 10;
					}
					else
						position.X = 8;
					position.Y = 5;
					SetConsoleCursorPosition(hConsole, position);
					cout << ".";
					cin >> year;
					try {
						if (!((day > 0 && day < 32) && (mouth > 0 && mouth < 32) && (year >= 20 && year < 22))) {
							throw str;
						}
					}
					catch (string str) {
						cout << str << endl;
						flag1 = true;

					}
				}
				position.X = 2;
				position.Y = 8;
				SetConsoleCursorPosition(hConsole, position);
				cout << "Введите цену (в рублях)" << endl;

				cout << "Стоимость:";
				while (!(cin >> cost) || (cin.peek() != '\n'))
				{
					cin.clear();
					while (cin.get() != '\n');
					cout << "Некорректный ввод,пожалуйста,используйте пример" << endl;
				}

				cout << "Введите пункт назначения" << endl;
				cout << "Пункт назначения:";
				cin >> point;
				request = converter(day, mouth, year, cost, point);
			}
		}
		break; }
	case 1: {
		cout << "Выберите по какому параметру будет отправлен запрос:" << endl;
		cout << "1 - Дата" << endl;
		cout << "2 - Стоимость" << endl;
		cout << "3 - Пункт назначения" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:{
			request = to_string(day) + "." + to_string(mouth) + "." + to_string(year);
			break; }
		case 2:{
			
			break; }
		case 3:{
			
			break; }
		default:
			break;
		}
		break; 
	}
	default:"Неверный ввод";
		break;
	}
	return request;
}