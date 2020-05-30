#pragma once
#include "pch.h"
using namespace std;

class Handler {

public:
	virtual ~Handler() {};
	virtual void handle(int flag,std::string request) = 0;
	virtual Handler *SetNext(Handler *handler) = 0;
};