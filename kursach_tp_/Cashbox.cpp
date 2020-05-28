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
	int  check = 0, p = 0;
	int pos, num = -1,pp=0;

	unsigned i=0;
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
			cout << vec_string.size() << " " << str1 <<endl;
		}
	}
	if (flag1) {
		while (1) {
			pp = (int)vec_string.size();
			check = num;
			cout << "Выберите билет,который хотите купить" << endl;
			cout << "Для завершения обзора введите '0'" << endl;
			cout << ">";
			cin >> num;
			num = num - 1;
			try {
				if (num <= pp) 
				{
					if (num == -1) {
						break;
					}
					if (num == check && p >= 6) {
						cout << "Превышен лимит покупки одного билета" << endl;
						continue;
					}
					else {
						fot << vec_string[num] << "\n";
						if (num == check)
						{
							p++;
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
	bool flag1 = true;
	string  str = "Некорректный ввод, используйте пример";
	system("cls");
	cout << "Система запросов Касса -> Поезд -> Самолёт" << endl;
	cout << "Введите свой запрос" << endl;
		cout << "Введите дату:ДД.ММ.ГГ" << endl;

		cout << "Пример:"<< endl;
		cout << "Дата:16.06.20 Стоимость:1999 рублей Пункт назначения:Волгоград" << endl;
		cout << "Введите дату:"<<endl;
		while (flag1) {
			flag1 = false;
			cout << "День:";
			cin >> day;
			cout << "Месяц:";
			cin >> mouth;
			cout << "Год:";
			cin >> year;
			try {//с 1 по 31 / по месяцам расписывать не стал
				if (!((day > 0 && day < 32) && (mouth > 0 && mouth < 32) && (year >= 1920 && year < 1922))) {
					throw str;
				}
			}
			catch (string str) {
				cout << str << endl;
				flag1 = true;

			}
		}
		cout << "Введите цену (в рублях)" << endl;

		cout << "Стоимость:";
		while (!(cin >> cost) || (cin.peek() != '\n'))//проверка на ввод целого числа в пределах типа int
		{
			cin.clear();
			while (cin.get() != '\n') {
				cout << "Некорректный ввод,пожалуйста,используйте пример" << endl;
			}
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
	fot << endl << day << "." << mouth << "." << year << " " << cost << " " << point;
	fot.close();
	cout << "Запись успешно добавлена";
}

void Cashbox::fprint(std::string str)
{
	string line;
	ifstream fout(str);
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
		fout.close();
		system("pause");
	}

}

void Cashbox::change(int choice,string str, Cashbox *ob) {
	ofstream fot;
	ifstream fin;
	int p,i=0;
	vector <string> vec_string;
	string str1;
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

	while (!fin.eof()) {
		getline(fin, str1);//
		vec_string.push_back(str1);
		cout << vec_string.size() << " " << vec_string[i] << endl;
		i++;
		}
	fin.close();
	try {
		fot.open(str);
		if (!fot.is_open()) {
			fot.close();
			throw exception("Файл  не открылся.");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		system("pause");
	}
	cout << "Введите необходимый номер строки ";
	cin >> p;
	try {
		if (p <= 0 && p > (int)vec_string.size())
			throw exception("Нет такой запсиси");
	}
	catch(exception &ex){
		cout << ex.what() << endl;
		system("pause");
	}
	if (choice == 2) {
		cout << "Введите новые данные";
		ob->push();
		str1 = converter(ob);
		vec_string.at(p - 1) = str1;
	}
	for (i = 0; i < vec_string.size();i++) {
		if ((choice == 1) && (i == (p - 1))) {
			continue;
		}
		else
			if ((choice == 2) && (i == (p - 1))) {
				if (i)
					fot << endl;
				fot << vec_string[i];
			}
			else {
				if (i)
					fot << endl;
				fot << vec_string[i];
			}
	}
	fot.close();
}

int checking(string str)
{
	ifstream fin;
	string str1;
	int i = 0,j=0;
	int f = 0,m;
	int day;
	int mouth;
	int cost;

	string point;
	vector <string> data;
	const char *data1;
	char day1[2];
	string str2;
	try {
		fin.open(str, ios::in);
		if (!fin.is_open()) {
			fin.close();
			throw exception("Файл не открылся.");
		}
		if (fin.peek() == EOF) {
			fin.close();
			throw exception("Файл пуст");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		system("pause");
	}

	while (!fin.eof()) {
		try {
			for (i = 0; i < 5; i++) {
				getline(fin, str1,' ');
				data.push_back(str);
			}
		}
		catch (...) {
			cout << "Записи в файле не соответствуют требованиям";
		}
		for (i = 0; i < (int)data.size(); i++) {
			if (i == 0 || i % 5 == 0)//разбор первого слова
			{
				data1 = data[i].c_str();
				for (m=0;m>3;m++) {
					if (f <=2) {
						for (j = 0; data1[j] == '.'; j++) {
							str2 = to_string(data1[j-1]) + to_string(data1[j]);
							f++;
						}
					}

				}
				f = 0;

			}
		}
	}
}