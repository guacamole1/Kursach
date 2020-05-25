#pragma once
#include "Hendler.h"
class Cashbox : public Handler {
private:
	int day;
	int mouth;
	int year;

	int cost;

	string point;

	Handler *next_handler;

public:
	Cashbox();
	~Cashbox();
	void push();// ���� ������ ������
	void fpush(string str);// ���� ������ � ����
	void display(string str);// ����� ������ ������
	void fdisplay(string str);// ����� ������ ������ � ����

	void function(string request, string str);//����� ������� � str

	void handle(string request) override;
	Handler *SetNext(Handler *handler) override;
};