// Kursovaya_TEHPROG.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include "Cashbox.h"
#include "Plane.h"
#include "Train.h"
#include <iostream>
#include <Windows.h>//используется для красиваого ввода даты в формате ДД.ММ.ГГ


using namespace std;
 
int main()

{
	setlocale(LC_ALL, "Russian");
	Cashbox *handler1 = new Cashbox;
	Plane *handler2 = new Plane;
	Train *handler3 = new Train;


	delete handler1;
	delete handler2;
	delete handler3;
	return 0;
}

