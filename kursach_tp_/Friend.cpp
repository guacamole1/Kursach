#include "friend.h"
#include "Cashbox.h"
#include "Plane.h"
#include "Train.h"
#include <string>
#include <Windows.h>

using namespace std;

void menu() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Cashbox *handler1;
	Plane   *handler2;
	Train   *handler3;
	Cashbox ob1;
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
	int check;
	while (flag) {
	system("cls");
	cout << "User's menu:" << endl;
	cout << "1. Make request Cashier -> Train -> Plane" << endl;
	cout << "2. Print ticket's " << endl;
	cout << "3. Add ticket " << endl;
	cout << "4. Remove ticket " << endl;
	cout << "5. Change ticket's data" << endl;
	cout << "6. Add your file to the program input" << endl;
	cout << "0. Exit" << endl;
	cout << "Select an action 0-6:  ";
		cin >> but1;
		switch (but1)
		{
		case 1:
		{
			system("cls");
			while (1) {
				system("cls");
				cout << "1 - Find a request by all parameters" << endl;
				cout << "2 - Find a request by one parameter" << endl;
				cout << "0 - Back" << endl;;
				cout << "Select an action 0-2: ";
				cin >> but1;
				switch (but1)
				{
				case 1: {
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
					cout << "1 - Date" << endl;
					cout << "2 - Cost" << endl;
					cout << "3 - Destination" << endl;
					cout << "Select an action 1-3: ";
					cin >> choice;
					switch (choice)
					{
					case 1: {
						system("cls");
						cout << "Day (1 -31): ";
						cin >> day;
						cout << "Month (1 -12): ";
						cin >> mouth;
						cout << "Year (20 - 21): ";
						cin >> year;
						request = to_string(day) + to_string(mouth) + to_string(year);
						handler1->handle(request);
						break; }
					case 2: {
						cout << "Cost: ";
						cin >> cost;
						request = to_string(cost);
						handler1->handle(request);
						break; }
					case 3: {
						cout << "Destination: ";
						cin >> point;
						handler1->handle(point);
						break; }
					default:"Incorrect input";
						break;
					}
					break;
				}
				default:"Incorrect input";
					break;
				}
			}
		}
		case 2: {
			handler1 = new Cashbox;
			cout << "Choose which tickets you want to output" << endl;
			cout << "1. All" << endl;
			cout << "2. Train" << endl;
			cout << "3. Plane" << endl;
			cout << "4. Tickets" << endl;
			cin >> but3;
			switch (but3)
			{
			case 1: {
				system("cls");
				cout << "Train:" << endl;
				handler1->fprint(filename);
				cout << "Plane:" << endl;
				handler1->fprint(filename2);
				cout << "Tickets:" << endl;
				handler1->fprint(filename3);
				delete handler1;
				system("pause");
				break;
			}
			case 2: {
				system("cls");
				cout << "Train:" << endl;
				handler1->fprint(filename);
				delete handler1;
				break;
			}
			case 3: {
				system("cls");
				cout << "Plane:" << endl;
				handler1->fprint(filename2);
				delete handler1;
				break;
			}
			case 4: {
				system("cls");
				cout << "Tickets:" << endl;
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
			cout << "Choose where you want to add a ticket" << endl;
			cout << "1. Train" << endl;
			cout << "2. Plane" << endl;
			cout << "3. Tickets" << endl;
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
			default:"Incorrect input";
				break;
			}
		}
		case 4: {
			system("cls");
			cout << "Choose in which file you want to delete data" << endl;
			cout << "1. Train" << endl;
			cout << "2. Plane" << endl;
			cout << "3. Tickets" << endl;
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
			system("cls");
			cout << "Input the way to the file" <<endl;
			cin >> point;
			if (ob1.checking(point) == 1) {
				ob1.set_name(point);
				cout << "File recorded successfully" << endl;
			}
			else {
				cout << "There are errors in the records, please use an example when writing to file" << endl;
				cout << "Example1: " << endl << "Day:12 Month:12 Year:2020 Cost:1999 Destination:Anapa" << endl;
				cout << "Example2: " << endl << "Day:09 Month:06 Year:2020 Cost:1999 Destination:Sochi" << endl;
			}
			system("pause");
			break;
		}
		case 0: {
			flag = false;
			break;
		}
		}
	}
}