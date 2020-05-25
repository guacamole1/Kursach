#pragma once
#include "Cashbox.h"
#include "friend.h"
class Plane : public Cashbox {
protected:
	string filename;
public:
	Plane();
	~Plane();
	void handle(std::string request) override;

	friend string converter(int day, int mouth, int year, int cost, string str);
	friend void function(string request, string str);
};