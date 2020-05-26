#pragma once
#include "Cashbox.h"

using namespace std;

class Train : public Cashbox {
public:
	Train();
	~Train();
	void handle(string request) override;

};