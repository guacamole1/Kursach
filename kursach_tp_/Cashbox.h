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
	void push();// ввод данных билета
	void fpush(std::string str);// ввод данных в файл
	void print();// вывод данных билета
	void fprint(std::string str);// вывод данных билета в файл
	void change(int choice, string str, Cashbox *ob);
	void function(std::string request, std::string str);//поиск запроса(request) в (str)файле
	
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