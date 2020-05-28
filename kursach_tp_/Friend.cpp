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
	cout << "���� ������������:" << endl;
	cout << "1. ������� ������ ����� -> ����� -> ������" << endl;
	cout << "2. �������  ����� " << endl;
	cout << "3. �������� ����� " << endl;
	cout << "4. ������� ����� " << endl;
	cout << "5. �������� ������ ������ " << endl;
	cout << "6. �������� ���� ���� �� ���� ���������" << endl;
	while (flag) {
		cin >> but1;
		switch (but1)
		{
		case 1:
		{
			system("cls");
			while (flag1) {
				system("cls");
				cout << "1 - ����� ������ �� ���� ����������" << endl;
				cout << "2 - ����� ������ �� ������ ���������" << endl;
				cout << "0 - ��������� �����" << endl;;
				cout << "�������� �������� 0-2:  ";
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
					cout << "�������� �� ������ ��������� ����� ��������� ������:" << endl;
					cout << "1 - ����" << endl;
					cout << "2 - ���������" << endl;
					cout << "3 - ����� ����������" << endl;
					cin >> choice;
					switch (choice)
					{
					case 1: {
						system("cls");
						cout << "���� (1 -31): ";
						cin >> day;
						cout << "����� (1 -12): ";
						cin >> mouth;
						cout << "��� (20 - 21): ";
						cin >> year;
						request = to_string(day) + to_string(mouth) + to_string(year);
						handler1->handle(request);
						break; }
					case 2: {
						cout << "���������: ";
						cin >> cost;
						request = to_string(cost);
						handler1->handle(request);
						break; }
					case 3: {
						cout << "����� ����������: ";
						cin >> point;
						handler1->handle(point);
						break; }
					default:"�������";
						break;
					}
					break;
				}
				default:"�������� ����";
					break;
				}
			}
		}
		case 2: {
			handler1 = new Cashbox;
			cout << "�������� ����� ������ �� ������ �������" << endl;
			cout << "1. ���" << endl;
			cout << "2. �����" << endl;
			cout << "3. ������" << endl;
			cout << "4. ������" << endl;
			cin >> but3;
			switch (but3)
			{
			case 1: {
				system("cls");
				cout << "������:" << endl;
				handler1->fprint(filename);
				cout << "�������:" << endl;
				handler1->fprint(filename2);
				cout << "������:" << endl;
				handler1->fprint(filename3);
				delete handler1;
				system("pause");
				break;
			}
			case 2: {
				system("cls");
				cout << "������:" << endl;
				handler1->fprint(filename);
				delete handler1;
				break;
			}
			case 3: {
				system("cls");
				cout << "�������:" << endl;
				handler1->fprint(filename2);
				delete handler1;
				break;
			}
			case 4: {
				system("cls");
				cout << "������:" << endl;
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
			cout << "�������� ���� �� ������ �������� �����" << endl;
			cout << "1. �����" << endl;
			cout << "2. ������" << endl;
			cout << "3. ������" << endl;
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
			default:"�������� ����";
				break;
			}
		}
		case 4: {
			system("cls");
			cout << "�������� � ����� ����� ��������� �������� ������" << endl;
			cout << "1. �����" << endl;
			cout << "2. ������" << endl;
			cout << "3. ������" << endl;
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