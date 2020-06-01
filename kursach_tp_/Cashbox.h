﻿#pragma once
#include "Handler.h"

using namespace std;
/**
 * Поведение цепочки по умолчанию может быть реализовано внутри базового класса
 * обработчика.
 */
class Cashbox : public Handler {
private:
	string day;//дата
	string mouth;
	string year;

	string cost;//стоимость

	string point;//пункт назначения

	string UserFile;

	Handler *next_handler;//ссылка на следущий обработчик

public:

	Cashbox();
	~Cashbox();
	void push();// ввод данных билета
	void fpush(std::string str);// ввод данных в файл

	void fprint(std::string str);// вывод данных билета в файл
	void change(int choice, string str, Cashbox *ob);
	void function(int flag,std::string request, std::string str);//поиск запроса(request) в (str)файле
	
	int checking(string str);//проверка на корректность добавленого пользователем файла

	void set_name(string userfile);//добавить путь к файлу
	string get_name();//

	int check_point(string str);// проверка содержется ли город в списке следует ли поезд/самолёт в введённый ользователем город
	void handle(int flag, std::string request) override;//переопределяем функцию-обработчик
	Handler *SetNext(Handler *handler) override;//устанавливаем указатель на сл. обработчика

	friend std::string converter(Cashbox *ob);//создание запроса по шаблону
};