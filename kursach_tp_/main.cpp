// Kursovaya_TEHPROG.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "Cashbox.h"
#include "Plane.h"
#include "Train.h"
#include <iostream>

using namespace std;
 
int main()

{
	setlocale(LC_ALL, "Russian");
	Cashbox *handler1 = new Cashbox;
	Plane *handler2 = new Plane;
	Train *handler3 = new Train;

	Cashbox ob1;
	Plane ob2;
	Train ob3;

	int day;
	int mouth;
	int year;

	int cost;

	string point,request;

	bool flag1=true ,flag=true;
	handler1->SetNext(handler2)->SetNext(handler3);

	while (flag) {
		cout << "Система запросов Касса -> Поезд -> Самолёт" << endl;
		cout << "Введите свой запрос" << endl;
		while (true) {
			cout << "Введите дату:ДД.ММ.ГГ" << endl;
			cout << "Пример:16.06.20" << endl;
			cout << "Пример:1.06.20" << endl;
			cout << "> ";
			cin >> day;
			cout << "\r";
			cout << ".";
			cin >> mouth;
			cout << ".";
			cin >> year;
			
			cout << "Введите цен у(в рублях)" << endl;
			cout << "Пример:1600" << endl;
			cout << "> ";
			cin >> cost;

			cout << "Введите пункт назначения" << endl;
			cout << "Пример:Волгоград" << endl;
			cout << "> ";
			cin >> point;

			request = converter(day, mouth, year, cost, point);
			cout << request << endl;
			handler1-> handle(request); 
			system("pause");
			flag = false;
			break;
		}
	}

    
	delete handler1;
	delete handler2;
	delete handler3;
	return 0;
}

