#pragma once
#include "Hendler.h"

using namespace std;

class Cashbox : public Handler {
private:
	int day;
	int mouth;
	int year;

	int cost;

	std::string point;

	Handler *next_handler;

public:
	Cashbox();
	~Cashbox();
	void push();// ���� ������ ������
	void fpush(std::string str);// ���� ������ � ����
	void print();// ����� ������ ������
	void fprint(std::string str);// ����� ������ ������ � ����
	void change(int choice, string str, Cashbox *ob);
	void function(std::string request, std::string str);//����� �������(request) � (str)�����
	
	int checking(string str);

	int get_day();
	int get_mouth();
	int get_year();
	int get_cost();
	std::string get_point();

	void handle(std::string request) override;
	Handler *SetNext(Handler *handler) override;

	friend std::string converter(Cashbox *ob);
};