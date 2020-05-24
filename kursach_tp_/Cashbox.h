#pragma once
#include "Hendler.h"
class Cashbox : public Handler {
private:
	int day;
	int mouth;
	int year;

	double cost;

	std::string point;

	Cashbox *next_handler;

public:
	Cashbox() : next_handler(nullptr) {};
	Cashbox* SetNext(Cashbox *handler);
	Cashbox* gethandler();
	Cashbox * SetNext(Cashbox * handler);
	void handle(std::string request) override;

};