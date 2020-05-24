#pragma once
#include "Hendler.h"
class Cashbox : public Handler {
private:
	int day;
	int mouth;
	int year;

	int cost;

	std::string point;

	Cashbox *next_handler;

public:
	Cashbox();
	~Cashbox();
	Cashbox* SetNext(Cashbox *handler);
	Cashbox* gethandler();
	void handle(std::string request) override;

};