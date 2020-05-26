#pragma once
#include "Cashbox.h"
class Plane : public Cashbox {
protected:

public:
	Plane();
	~Plane();
	void handle(std::string request) override;

};