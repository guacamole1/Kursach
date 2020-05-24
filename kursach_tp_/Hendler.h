#pragma once
#include "pch.h"
class Handler {
public:
	virtual ~Handler() {};
	virtual void handle(std::string request) = 0;
};