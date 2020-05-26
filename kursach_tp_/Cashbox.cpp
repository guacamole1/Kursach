#include "Cashbox.h"
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>//используется для красиваого ввода даты в формате ДД.ММ.ГГ

using namespace std;

Cashbox::Cashbox(){
	day = 0;
	mouth = 0;
	year = 0;
	cost = 0;
	point = "";
	next_handler = nullptr;
}

Cashbox::~Cashbox(){
	delete next_handler;
}

int Cashbox::get_day() { return day; }
int Cashbox::get_mouth(){ return mouth; }
int Cashbox::get_year(){ return year; }
int Cashbox::get_cost(){ return cost; }
std::string Cashbox::get_point() { return point; }

Handler* Cashbox:: SetNext(Handler *handler) {

	this-> next_handler = handler;
	return handler;
}
void Cashbox::handle(std::string request) {
	if (this->next_handler) {
		return this->next_handler->handle(request);
	}
	return;
}

void Cashbox::function(std::string request, std::string str) {
	vector <std::string> vec_string;
	vector <std::string> vec_string1;
	bool flag1 = false;
	string str1;
	int  check = 0, p = -1;
	int pos, num = -1;

	unsigned i=0,pp=0;
	ifstream fin;
	ofstream fot;
	string chek = "некорректный ввод";

	try {
		fin.open(str, ios::in);
		if (!fin.is_open()) {
			fin.close();
			throw exception("Файл не открылся.");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		system("pause");
	}

	try {
		fot.open("tickets.txt", ios_base::app);
		if (!fot.is_open()) {
			fot.close();
			throw exception("Файл 'билеты' не открылся.");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		system("pause");
	}

	while (!fin.eof()) {
		getline(fin, str1);
		pos = str1.find(request);//ищем конвертированную запись целую/отдельный параметр
		if (string::npos != pos) {
			flag1 = true;
			vec_string.push_back(str1);
			cout << vec_string.size() << " " << str1;
		}
	}
	if (flag1) {
		while (1) {
			check = num;
			cout << "Выберите билет,который хотите купить" << endl;
			cout << "Для завершения обзора введите '0'" << endl;
			cout << ">";
			cin >> num;
			num = num - 1;
			pp = num;
			try {
				if (num >= -1 && num <= vec_string.size()) 
				{
					if (num == -1)
						break;
					if (num == check && p >= 6)
						cout << "Превышен лимит покупки одного билета" << endl;
					else {
						vec_string1.at(i) = vec_string[pp];
						i++;
						if (num == check)
						{
							p++;
							if (p > 5)
							{
								cout << "Превышен лимит покупки одного билета" << endl;
							}
						}
					}
				}

				else
					throw chek;
			}
			catch (string str) {
				cout << str << endl;
				system("pause");
				break;
			}
		}

		for (i = 0; i < vec_string1.size(); i++) {
			fot << vec_string[i];
		}

	}
	else {
		if(next_handler)
			next_handler->handle(request);
		else
			cout << "Не дал результатов" << endl; system("pause");
	}
	fin.close();
	fot.close();
}

void Cashbox::push() {
	// ввод данных билета
	COORD position;										// Объявление необходимой структуры для работы с кареткой в консоли
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool flag1 = true;
	string  str = "Некорректный ввод, используйте пример";
	system("cls");
	cout << "Система запросов Касса -> Поезд -> Самолёт" << endl;
	cout << "Введите свой запрос" << endl;
		cout << "Введите дату:ДД.ММ.ГГ" << endl;
		cout << "Пример:\n Дата:16.06.20 Стоимость:1999 рублей Пункт назначения:Волгоград" << endl;
		cout << "Дата: ";
		while (flag1) {
			flag1 = false;
			position.X = 5;//меняем положение каретки для более удобного ввода
			position.Y = 5;
			SetConsoleCursorPosition(hConsole, position);//устанавливаем новое значение каретки
			cin >> day;
			if (day > 9)//условия с размером данных если 2значное число то передвинуть каретку на 2
				position.X = 7;
			else
				position.X = 6;
			position.Y = 5;
			SetConsoleCursorPosition(hConsole, position);
			cout << ".";
			cin >> mouth;
			if (mouth > 9) {
				if (day < 10)
					position.X = 9;
				else
					position.X = 10;
			}
			else
				position.X = 8;
			position.Y = 5;
			SetConsoleCursorPosition(hConsole, position);
			cout << ".";
			cin >> year;
			try {//с 1 по 31 / по месяцам расписывать не стал
				if (!((day > 0 && day < 32) && (mouth > 0 && mouth < 32) && (year >= 20 && year < 22))) {
					throw str;
				}
			}
			catch (string str) {
				cout << str << endl;
				flag1 = true;

			}
		}
		position.X = 2;
		position.Y = 8;
		SetConsoleCursorPosition(hConsole, position);
		cout << "Введите цену (в рублях)" << endl;

		cout << "Стоимость:";
		while (!(cin >> cost) || (cin.peek() != '\n'))//проверка на ввод целого числа в пределах типа int
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Некорректный ввод,пожалуйста,используйте пример" << endl;
		}

		cout << "Введите пункт назначения" << endl;
		cout << "Пункт назначения:";
		cin >> point;
}

void Cashbox::print() {
	cout << "Дата:" << day << "." << mouth << "." << year << " " << "Стоимость:" << cost << " " << "Пункт назначения:" << point << endl;
}


std::string converter(Cashbox *ob) {
	std::string request ;
	
	request =to_string(ob->day) + "." + to_string(ob->mouth) + "." + to_string(ob->year) + " " + to_string(ob->cost) + " " + ob->point;
	return request;
}

void Cashbox::fpush(std::string str)
{
	ofstream fot;
	try {
		fot.open(str, ios_base::app);
		if (!fot.is_open()) {
			fot.close();
			throw exception("Файл не открылся.");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		system("pause");
	}
	push();
	fot << day << "." << mouth << "." << year << " " << cost << " " << point << endl;
}

void Cashbox::fprint(std::string str)
{
	string line;
	ifstream fout("example.txt");
	try {
		if (fout.is_open())
		{
			while (!fout.eof())
			{
				getline(fout, line);
				cout << line << endl;
			}
			fout.close();
		}

		else
			throw exception("Файл не открылся");
	}
	catch (exception &ex) {
		cout << ex.what() << endl << endl;
		system("pause");
	}

}

void change(int choice, std::string str) {


}