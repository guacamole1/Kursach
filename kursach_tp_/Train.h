#pragma once
#include "Cashbox.h"

using namespace std;

class Train : public Cashbox {
private:
	string file;
public:
	Train();
	~Train();
	void handle(int flag, string request) override;

};