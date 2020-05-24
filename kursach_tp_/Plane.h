#pragma once
#include "Cashbox.h"
#include "friend.h"
class Plane : public Cashbox {
public:
	void handle(std::string request) override;

	friend string converter(int day, int mouth, int year, double cost, string str);
	friend void function(string request, string str);
};