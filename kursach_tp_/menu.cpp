#include "menu.h"
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
	Cashbox ob1;
	string day;
	string mouth;
	string year;
	int i;
	string cost;
	string filename = "train.txt";
	string filename2 = "plane.txt";
	string filename3 = "tickets.txt";
	string point, request;
	bool flag1 = true, flag = true;
	string str_but;
	int but[10];
	int flags[6];
	while (flag) {
		for (i = 0; i < 6; i++)
			flags[i] = 1;
		system("cls");
		cout << "User's menu:" << endl;
		cout << "1. Make request Cashier -> Train -> Plane" << endl;
		cout << "2. Print ticket's " << endl;
		cout << "3. Add ticket " << endl;
		cout << "4. Remove ticket " << endl;
		cout << "5. Change ticket's data" << endl;
		cout << "6. Add your file to the program input" << endl;
		cout << "0. Exit" << endl;
		while (1) {
			cout << "Select an action 0-6:  ";
			cin >> str_but;
			try {
				but[0] = stoi(str_but);
			}
			catch (...) {
				cout << "Please enter a numerical value" << endl;
				system("pause");
				continue;
			}
			break;
		}
		switch (but[0])
		{
		case 1:
		{
			while (flags[1]) {
				system("cls");
				cout << "1 - Find a request by all parameters" << endl;
				cout << "2 - Find a request by key word" << endl;
				cout << "3 - Use your file" << endl;
				cout << "0 - Back" << endl;;
				while (1) {
					cout << "Select an action 0-3:  ";
					cin >> str_but;
					try {
						but[1] = stoi(str_but);
					}
					catch (...) {
						cout << "Please enter a numerical value" << endl;
						system("pause");
						continue;
					}
					break;
				}
				switch (but[1])
				{
				case 1: {
					handler1 = new Cashbox;
					handler1->SetNext(new Train)->SetNext(new Plane);
					handler1->push();
					request = converter(handler1);
					handler1->handle(1, request);
					delete handler1;
					break;
				}
				case 2: {
					system("cls");
					cout << "Input key word for search:" << endl;
					handler1 = new Cashbox;
					handler1->SetNext(new Train)->SetNext(new Plane);
					cin >> day;
					handler1->handle(2, request);
					delete handler1;
					break;
				}
				case 3: {
					if (ob1.get_name() == "") {
						cout << "Not find your file,pls try again"<< endl;
						system("pause");
						break;
					}
					handler1 = new Cashbox;
					handler1->SetNext(new Train)->SetNext(new Plane);
					handler1->push();
					request = converter(handler1);
					handler1->function(1,request,ob1.get_name());
					delete handler1;
					break;
				}
				case 0: {
					flags[1] = 0;
					break;
				}
				default: {
					cout << "Incorrect,try again" << endl;
					system("pause");
					break;
				}
				}
			}
			break;
			}
		case 2: {
			while (flags[3]) {
			system("cls");
			handler1 = new Cashbox;
			cout << "Choose which tickets you want to print" << endl;
			cout << "1. All" << endl;
			cout << "2. Train" << endl;
			cout << "3. Plane" << endl;
			cout << "4. Tickets" << endl;
			cout << "4. Tickets" << endl;
			cout << "5. Your file" << endl;
			cout << "0 - Back" << endl;;
				while (1) {
					cout << "Select an action 0-5:  ";
					cin >> str_but;
					try {
						but[3] = stoi(str_but);
					}
					catch (...) {
						cout << "Please enter a numerical value" << endl;
						system("pause");
						continue;
					}
					break;
				}
				switch (but[3])
				{
				case 1: {
					system("cls");
					cout << "Train:" << endl;
					handler1->fprint(filename);
					cout << "Plane:" << endl;
					handler1->fprint(filename2);
					cout << "Tickets:" << endl;
					handler1->fprint(filename3);
					if (ob1.get_name() != "") {
						cout << "Your file:" << endl;
						handler1->fprint(ob1.get_name());
					}
					delete handler1;
					system("pause");
					break;
				}
				case 2: {
					system("cls");
					cout << "Train:" << endl;
					handler1->fprint(filename);
					delete handler1;
					system("pause");
					break;
				}
				case 3: {
					system("cls");
					cout << "Plane:" << endl;
					handler1->fprint(filename2);
					delete handler1;
					system("pause");
					break;
				}
				case 4: {
					system("cls");
					cout << "Tickets:" << endl;
					handler1->fprint(filename3);
					delete handler1;
					system("pause");
					break;
				}
				case 5:
				{
					if (ob1.get_name() == "") {
						cout << "Not find your file,pls try again" << endl;
						system("pause");
						break;
					}
					system("cls");
					cout << "Your file:" << endl;
					handler1->fprint(ob1.get_name());
					delete handler1;
					system("pause");
					break;
				}
				case 0: {flags[3] = 0; break; }
				default:
				{
					cout << "Incorrect input" << endl;
					system("pause");
					break; }
				}
			}
			break;
		}
		case 3: {
			while (flags[4]) {
			system("cls");
			cout << "Choose where you want to add a ticket" << endl;
			cout << "1. Train" << endl;
			cout << "2. Plane" << endl;
			cout << "3. Tickets" << endl;
			cout << "4. Your file" << endl;
			cout << "0 - Back" << endl;;
				while (1) {
					cout << "Select an action 0-4:  ";
					cin >> str_but;
					try {
						but[4] = stoi(str_but);
					}
					catch (...) {
						cout << "Please enter a numerical value" << endl;
						system("pause");
						continue;
					}
					break;
				}
				switch (but[4])
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
				case 4:
				{
					if (ob1.get_name() == "") {
						cout << "Not find your file,pls try again" << endl;
						system("pause");
						break;
					}
					system("cls");
					handler1 = new Cashbox;
					handler1->fpush(ob1.get_name());
					delete handler1;
					system("pause");
					break;

				}
				case 0: {flags[4] = 0;
					break; }
				default: {
					cout << "Incorrect input" << endl;
					system("pause");
					break; }
				}
			}
			break;
		}
		case 4: {
			system("cls");
			cout << "Choose in which file you want to delete data" << endl;
			cout << "1. Train" << endl;
			cout << "2. Plane" << endl;
			cout << "3. Tickets" << endl;
			cout << "4. Your file" << endl;
			cout << "0 - Back" << endl;;
			while (1) {
				cout << "Select an action 0-4:  ";
				cin >> str_but;
				try {
					but[5] = stoi(str_but);
				}
				catch (...) {
					cout << "Please enter a numerical value" << endl;
					system("pause");
					continue;
				}
				break;
			}
			switch (but[5])
			{
			case 1: {
				system("cls");
				handler1 = new Cashbox;
				handler1->change(1, filename, handler1);
				delete handler1;
				system("pause");
				break;
			}
			case 2:
			{
				system("cls");
				handler1 = new Cashbox;
				handler1->change(1, filename2, handler1);
				delete handler1;
				system("pause");
				break;
			}
			case 3: {
				system("cls");
				handler1 = new Cashbox;
				handler1->change(1, filename3, handler1);
				delete handler1;
				system("pause");
				break;
			}
			case 4: {
				if (ob1.get_name() == "") {
					cout << "Not find your file,pls try again" << endl;
					system("pause");
					break;
				}
				system("cls");
				handler1 = new Cashbox;
				handler1->change(1, ob1.get_name(), handler1);
				delete handler1;
				system("pause");
				break;
			}
			default:
			{
				cout << "Incorrect input" << endl;
				system("pause");
				break; }
			}
			break;
		}
		case 5: {
			system("cls");
			cout << "Choose in which file you want to change data" << endl;
			cout << "1. Train" << endl;
			cout << "2. Plane" << endl;
			cout << "3. Tickets" << endl;
			cout << "4. Your file" << endl;
			cout << "0 - Back" << endl;;
			while (1) {
				cout << "Select an action 0-4:  ";
				cin >> str_but;
				try {
					but[6] = stoi(str_but);
				}
				catch (...) {
					cout << "Please enter a numerical value" << endl;
					system("pause");
					continue;
				}
				break;
			}
			switch (but[6])
			{
			case 1: {
				system("cls");
				handler1 = new Cashbox;
				handler1->change(2, filename, handler1);
				delete handler1;
				system("pause");
				break;
			}
			case 2:
			{
				system("cls");
				handler1 = new Cashbox;
				handler1->change(2, filename2, handler1);
				delete handler1;
				system("pause");
				break;
			}
			case 3: {
				system("cls");
				handler1 = new Cashbox;
				handler1->change(2, filename3, handler1);
				delete handler1;
				system("pause");
				break;
			}
			case 4: {
				if (ob1.get_name() == "") {
					cout << "Not find your file,pls try again" << endl;
					system("pause");
					break;
				}
				system("cls");
				handler1 = new Cashbox;
				handler1->change(2, ob1.get_name(), handler1);
				delete handler1;
				system("pause");
				break;
			}
			default: {
				cout << "Incorrect input" << endl;
				system("pause");
				break; }
			}
			break;
		}
		case 6: {
			system("cls");
			cout << "Input the way to the file" << endl;
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
		default: {
			cout << "Incorrect input, input within(0-6)" << endl;
			system("pause");
			break;
		}
			}
		}
}