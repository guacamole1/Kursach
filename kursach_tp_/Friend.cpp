#include "friend.h"
#include "Cashbox.h"
#include "Plane.h"
#include "Train.h"


using namespace std;

void menu() {
	Cashbox *handler1;
	Plane   *handler2;
	Train   *handler3; 
	int day;
	int mouth;
	int year;
	int choice;
	int cost;

	string point,request;

	bool flag1 = true, flag = true;
	int flag2;
	cout << "�������� �������� 0-1";
	cin >> flag2;
	switch (flag2)
	{
	case 0: {
		handler1 = new Cashbox;
		handler1->SetNext(new Plane)->SetNext(new Train);
		handler1->push();
		request = converter(handler1);
		handler1->handle(request);
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
}