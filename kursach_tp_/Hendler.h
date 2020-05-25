#pragma once
#include "pch.h"
class Handler {

public:
	virtual ~Handler() {};
	virtual void handle(string request) = 0;
	virtual Handler *SetNext(Handler *handler) = 0;
};