#pragma once
#include "Cashbox.h"
class Plane : public Cashbox {
private:
	string file;
public:
	Plane();
	~Plane();
	void handle(int flag, std::string request) override;

};