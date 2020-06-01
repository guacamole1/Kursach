#pragma once
#include "pch.h"
using namespace std;
/*
 * Интерфейс Обработчика объявляет метод построения цепочки обработчиков. Он
 * также объявляет метод для выполнения запроса.
 */
class Handler {

public:
	virtual ~Handler() {};
	virtual void handle(int flag,std::string request) = 0;
	virtual Handler *SetNext(Handler *handler) = 0;
};
/**
 * Все Конкретные Обработчики либо обрабатывают запрос, либо передают его
 * следующему обработчику в цепочке.
 */