#pragma once
#include "Cashbox.h"
#include "friend.h"

class Train : public Cashbox {
public:
	Train();
	~Train();
	void handle(string request) override;

	friend string converter(int day, int mouth, int year, int cost, string str);
	friend void function(string request, string str);
};