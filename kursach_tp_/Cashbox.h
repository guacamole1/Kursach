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
	void push();// ввод данных билета
	void fpush(string str);// ввод данных в файл
	void display(string str);// вывод данных билета
	void fdisplay(string str);// вывод данных билета в файл

	void function(string request, string str);//поиск запроса в str

	void handle(string request) override;
	Handler *SetNext(Handler *handler) override;
};