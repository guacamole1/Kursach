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
	setlocale(LC_ALL, "");
	Cashbox *handler1 = new Cashbox;
	Plane *handler2 = new Plane;
	Train *handler3 = new Train;
	Cashbox ob1;
	Plane ob2;
	Train ob3;
	int day;
	int mouth;
	int year;

	double cost;

	std::string point;

	handler1->SetNext(handler2)->SetNext(handler3);
    
}

