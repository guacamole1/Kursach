#include <Windows.h>//������������ ��� ���������� ����� ���� � ������� ��.��.��
#include "friend.h"
#include "Cashbox.h"


using namespace std;

string converter(int day, int mouth, int year, int cost, string str) {
	string request;
	request = to_string(day) + "." + to_string(mouth) + "." + to_string(year) + " " + to_string(cost) + " " + str;
	return request;
}


string menu(int flag2) {
	COORD position;										// ���������� ����������� ���������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int day;
	int mouth;
	int year;
	int choice;
	int cost;

	string str1,point, request, str = "������������ ����, ����������� ������";

	bool flag1 = true, flag = true;
	switch (flag2)
	{
	case 0: {
		while (flag) {
			cout << "������� �������� ����� -> ����� -> ������" << endl;
			cout << "������� ���� ������" << endl;
			while (true) {
				cout << "������� ����:��.��.��" << endl;
				cout << "������:\n ����:16.06.20 ���������:1999 ������ ����� ����������:���������" << endl;
				cout << "����: ";
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
				cout << "������� ���� (� ������)" << endl;

				cout << "���������:";
				while (!(cin >> cost) || (cin.peek() != '\n'))
				{
					cin.clear();
					while (cin.get() != '\n');
					cout << "������������ ����,����������,����������� ������" << endl;
				}

				cout << "������� ����� ����������" << endl;
				cout << "����� ����������:";
				cin >> point;
				request = converter(day, mouth, year, cost, point);
			}
		}
		break; }
	case 1: {
		cout << "�������� �� ������ ��������� ����� ��������� ������:" << endl;
		cout << "1 - ����" << endl;
		cout << "2 - ���������" << endl;
		cout << "3 - ����� ����������" << endl;
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
	default:"�������� ����";
		break;
	}
	return request;
}